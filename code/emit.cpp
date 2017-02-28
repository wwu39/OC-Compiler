#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <cstring>

#include "symtable.h"
#include "astree.h"
#include "lyutils.h"
using namespace std;
FILE *oilfile;

size_t reg_nr = 1, str_nr = 1;
#define INDENT "        "
vector<const string *> globalstrings;

static string *register_alloc(const char *type)
{
    return new string(string(type) + to_string(reg_nr++));
}


void emitter_register_string(astree *node)
{
    node->oilname = new string(string("s") + to_string(str_nr++));
    globalstrings.push_back(node->lexinfo);
}

string *strip_zeros(const string *lexstr)
{
    string *stripped = new string(*lexstr);
    stripped->erase(0, stripped->find_first_not_of('0'));
    if(*stripped == string(""))
        *stripped += string("0");
    return stripped;
}

int test_is_operand(astree *node)
{
    return node->symbol == TOK_IDENT
        || node->symbol == TOK_INTCON
        || node->symbol == TOK_CHARCON;
}


#define INT  0
#define BOOL 1
#define CHAR 2
#define PTR  3
static const char *rcategory[4] = {
    "i", "b", "c", "p"
};


const char *get_result_type_name(astree *node)
{
    attr_bitset attr = get_node_attributes(node);
    if(attr.test(ATTR_struct))
        assert(node->type_name);
    const char *base;
    if(attr.test(ATTR_int))
        base = "int";
    else if(attr.test(ATTR_string))
        base = "char*";
    else if(attr.test(ATTR_struct))
        base = "struct ";
    else
        assert(0);

    string *str = new string(string(base) +
            (attr.test(ATTR_struct) ? 
                string("s_") + *node->type_name 
                + string("*") : string("")) +
            (attr.test(ATTR_array) ? string("*") : string("")) + 
            (node->symbol == '.' ? string("*") : string("")));
    return str->c_str();
}


const char *register_category(astree *node)
{
    const char *cat = NULL;
    switch(node->symbol) {
        case '+': case '-': case '*': case '/':
        case '%': case TOK_POS: case TOK_NEG:
        case TOK_ORD:
            cat = rcategory[INT];
            break;
        case '>': case '<': case TOK_EQ:
        case TOK_NE: case TOK_LE: case TOK_GE: 
        case '!':
            cat = rcategory[BOOL];
            break;
        case TOK_CHR:
            cat = rcategory[CHAR];
            break;
        case TOK_CALL:
            const char *result_type = get_result_type_name(node);
            if(strchr(result_type, '*'))
                cat = rcategory[PTR];
            else if(get_node_attributes(node).test(ATTR_int))
                cat = rcategory[INT];
            else
                assert(0);
            break;
    }
    return cat;
}

string *mangle_name(astree *node)
{
    assert(node->symentry);
    if(node->symbol == TOK_FIELD) {
        return new string(string("f_") +
                *node->symentry->definition->parent->
                    parent->children[0]->lexinfo + 
                string("_") + 
                *node->symentry->definition->lexinfo);
    }
    if(node->symentry->block_nr == 0)
        return new string(string("__") + 
                *node->symentry->definition->lexinfo);
    else
        return new string(string("_") + 
                to_string(node->symentry->block_nr) + 
                string("_") + 
                *node->symentry->definition->lexinfo);
}


void emit_recursive(astree *node)
{
    switch(node->symbol) {
        case TOK_STRUCT: case TOK_FUNCTION:
        case TOK_PROTOTYPE: case TOK_STRINGCON:
            return;
        case TOK_WHILE:
            fprintf(oilfile, "while_%ld_%ld_%ld:;\n",
                    node->lloc.filenr, node->lloc.linenr,
                    node->lloc.offset);
            emit_recursive(node->children[0]);
            fprintf(oilfile, INDENT 
                    "if (!%s) goto break_%ld_%ld_%ld;\n",
                    node->children[0]->oilname->c_str(),
                    node->lloc.filenr, node->lloc.linenr,
                    node->lloc.offset);
            emit_recursive(node->children[1]);
            fprintf(oilfile, INDENT "goto while_%ld_%ld_%ld;\n",
                    node->lloc.filenr, node->lloc.linenr,
                    node->lloc.offset);
            fprintf(oilfile, "break_%ld_%ld_%ld:;\n",
                    node->lloc.filenr, node->lloc.linenr,
                    node->lloc.offset);
            return;
        case TOK_IF:
            emit_recursive(node->children[0]);
            fprintf(oilfile, INDENT "if (!%s) goto fi_%ld_%ld_%ld;\n",
                    node->children[0]->oilname->c_str(),
                    node->lloc.filenr, node->lloc.linenr,
                    node->lloc.offset);
            emit_recursive(node->children[1]);
            fprintf(oilfile, "fi_%ld_%ld_%ld:;\n",
                    node->lloc.filenr, node->lloc.linenr,
                    node->lloc.offset);
            return;
        case TOK_IFELSE:
            emit_recursive(node->children[0]);
            fprintf(oilfile, INDENT "if (!%s) goto else_%ld_%ld_%ld;\n",
                    node->children[0]->oilname->c_str(),
                    node->lloc.filenr, node->lloc.linenr,
                    node->lloc.offset);
            emit_recursive(node->children[1]);
            fprintf(oilfile, INDENT "goto fi_%ld_%ld_%ld;\n",
                    node->lloc.filenr, node->lloc.linenr,
                    node->lloc.offset);
            fprintf(oilfile, "else_%ld_%ld_%ld:;\n",
                    node->lloc.filenr, node->lloc.linenr,
                    node->lloc.offset);
            emit_recursive(node->children[2]);
            fprintf(oilfile, "fi_%ld_%ld_%ld:;\n",
                    node->lloc.filenr, node->lloc.linenr,
                    node->lloc.offset);
            return;
    }
    for(size_t child = 0;child < node->children.size();++child) {
        emit_recursive(node->children[child]);
    }
    string *reg;
    const char *sym;
    switch(node->symbol) {
        case '+': case '-': case '*': case '>':
        case '/': case '%': case '<':
        case TOK_EQ: case TOK_NE: case TOK_LE:
        case TOK_GE: 
            node->oilname = register_alloc(register_category(node));
            fprintf(oilfile, INDENT "%s %s = %s %s %s;\n",
                    get_result_type_name(node),
                    node->oilname->c_str(), 
                    node->children[0]->oilname->c_str(), 
                    node->lexinfo->c_str(),
                    node->children[1]->oilname->c_str());
            
            break;
        case TOK_POS: case TOK_NEG: case '!':
        case TOK_ORD: case TOK_CHR:
            node->oilname = register_alloc(register_category(node));
            if(node->symbol == TOK_ORD)
                sym = "(int)";
            else if(node->symbol == TOK_CHR)
                sym = "(char)";
            else
                sym = node->lexinfo->c_str();
            
            fprintf(oilfile, INDENT "%s %s = %s%s;\n",
                    get_result_type_name(node),
                    node->oilname->c_str(), sym,
                    node->children[0]->oilname->c_str());
            break;
        case '=':
            node->oilname = node->children[0]->oilname;
            fprintf(oilfile, INDENT "%s = %s;\n",
                    node->children[0]->oilname->c_str(),
                    node->children[1]->oilname->c_str());
            break;
        case TOK_VARDECL:
            fprintf(oilfile, INDENT);
            if(node->parent->symbol == TOK_ROOT) {
                if(node->children[0]->symbol == TOK_ARRAY)
                    fprintf(oilfile, "%s ", 
                            node->children[0]->
                            children[1]->oilname->c_str());
                else
                    fprintf(oilfile, "%s ",
                            node->children[0]->
                            children[0]->oilname->c_str());
            } else {
                fprintf(oilfile, "%s ", 
                        node->children[0]->oilname->c_str());
            }
            fprintf(oilfile, "= %s;\n", 
                    node->children[1]->oilname->c_str());
            break;
        case TOK_CALL:
            if(!get_node_attributes(node).test(ATTR_void)) {
                node->oilname = register_alloc(register_category(node));
                fprintf(oilfile, INDENT "%s %s = ",
                        get_result_type_name(node),
                        node->oilname->c_str());
            } else {
                fprintf(oilfile, INDENT);
            }
            fprintf(oilfile, "__%s (",
                    node->children[0]->lexinfo->c_str());
            for(size_t child = 1;child < node->children.size();
                    child++) {
                if(child != 1)
                    fprintf(oilfile, ", ");
                fprintf(oilfile, "%s", 
                        node->children[child]->oilname->c_str());
            }
            fprintf(oilfile, ");\n");
            break;
        case TOK_INTCON:
            node->oilname = strip_zeros(node->lexinfo);
            break;
        case TOK_CHARCON:
            node->oilname = node->lexinfo;
            break;
        case TOK_RETURN:
            fprintf(oilfile, INDENT "return %s;\n", 
                    node->children[0]->oilname->c_str());
            break;
        case TOK_RETURNVOID:
            fprintf(oilfile, INDENT "return;\n");
            break;
        case TOK_ARRAY:
            node->oilname = new string(*node->children[0]->oilname 
                    + string("* ") + *node->children[1]->oilname);
            break;
        case TOK_INDEX:
            reg = register_alloc("a");
            fprintf(oilfile, INDENT "%s* %s = &%s[%s];\n",
                    get_result_type_name(node),
                    reg->c_str(),
                    node->children[0]->oilname->c_str(),
                    node->children[1]->oilname->c_str());

            node->oilname = new string(string("(*") 
                    + *reg + string(")")); 
            break;
        case '.':
            reg = register_alloc("a");
            fprintf(oilfile, INDENT "%s %s = &%s->%s;\n",
                    get_result_type_name(node),
                    reg->c_str(), node->children[0]->oilname->c_str(),
                    node->children[1]->oilname->c_str());

            node->oilname = new string(string("(*") + *reg +
                    string(")")); 
            break;
        case TOK_IDENT: case TOK_DECLID: case TOK_FIELD:
            node->oilname = mangle_name(node);
            break;
        case TOK_INT: case TOK_CHAR: case TOK_VOID:
            if(node->children.size() == 0)
                node->oilname = node->lexinfo;
            else
                node->oilname = new string(*node->lexinfo 
                        + " " + *node->children[0]->oilname);
            break;
        case TOK_BOOL:
            if(node->children.size() == 0)
                node->oilname = new string("char");
            else
                node->oilname = new string("char " 
                        + *node->children[0]->oilname);
            break;
        case TOK_STRING:
            if(node->children.size() == 0)
                node->oilname = new string("char*");
            else
                node->oilname = new string("char* " 
                        + *node->children[0]->oilname);
            break;
        case TOK_TYPEID:
            if(node->children.size() == 0)
                node->oilname = new string(string("struct s_") 
                        + *node->lexinfo + "*");
            else
                node->oilname = new string(string("struct s_") 
                        + *node->lexinfo + "* " 
                        + *node->children[0]->oilname);
            break;
        case TOK_NEW:
            reg = register_alloc("p");
            fprintf(oilfile, INDENT "struct s_%s* %s = xcalloc "
                    "(1, sizeof (struct s_%s));\n",
                    node->type_name->c_str(),
                    reg->c_str(),
                    node->type_name->c_str());
            node->oilname = reg;
            break;
        case TOK_NEWARRAY:
            reg = register_alloc("p");
            fprintf(oilfile, INDENT 
                    "%s* %s = xcalloc (%s, sizeof (%s));\n",
                    get_result_type_name(node->children[0]),
                    reg->c_str(),
                    node->children[1]->oilname->c_str(),
                    get_result_type_name(node->children[0]));
            node->oilname = reg;
            break;
        case TOK_NEWSTRING:
            reg = register_alloc("p");
            fprintf(oilfile, INDENT 
                    "char* %s = xcalloc (%s, sizeof (char));\n",
                    reg->c_str(), 
                    node->children[0]->oilname->c_str());
            node->oilname = reg;
            break;
        case TOK_NULL: case TOK_FALSE:
            node->oilname = new string("0");
            break;
        case TOK_TRUE:
            node->oilname = new string("1");
            break;
        case TOK_BLOCK: case TOK_ROOT:case TOK_STRINGCON:case ';':
            break;
        default:
            fprintf(stderr, "!!! unknown: %s\n", 
                    parser::get_tname(node->symbol));
            break;
    }
}


void emit_functions(astree *root)
{
    for(size_t child=0;child < root->children.size();child++) {
        astree *node = root->children[child];
        if(node->symbol == TOK_FUNCTION) {
            emit_recursive(node->children[0]);
            fprintf(oilfile, "%s(", 
                    node->children[0]->oilname->c_str());
            if(node->children[1]->children.size() == 0)
                fprintf(oilfile, "void");
            for(size_t param = 0;
                    param < node->children[1]->children.size();
                    param++) {

                if(!param) fprintf(oilfile, "\n");
                astree *parnode = node->children[1]->children[param];
                emit_recursive(parnode);
                fprintf(oilfile, INDENT);
                    fprintf(oilfile, "%s", parnode->oilname->c_str());
                if(param + 1 != node->children[1]->children.size())
                    fprintf(oilfile, ",\n");
            }
            fprintf(oilfile, ")\n");
            fprintf(oilfile, "{\n");
            emit_recursive(node->children[2]);
            fprintf(oilfile, "}\n");
        }
    }
}


void emit_strings()
{
    for(size_t s=0;s<globalstrings.size();s++)
        fprintf(oilfile, "char* s%ld = %s;\n", s+1,
                globalstrings[s]->c_str());
}


void emit_globals(astree *root)
{
    for(size_t child = 0;child<root->children.size();child++) {
        astree *node = root->children[child];
        if(node->symbol == TOK_VARDECL) {
            emit_recursive(node->children[0]);
            fprintf(oilfile, "%s;\n", 
                    node->children[0]->oilname->c_str());
        }
    }
}


void emit_structs(astree *root)
{
    for(size_t child = 0;child<root->children.size();child++) {
        astree *node = root->children[child];
        if(node->symbol == TOK_STRUCT) {
            fprintf(oilfile, "struct s_%s {\n", 
                    node->children[0]->lexinfo->c_str());
            for(size_t field = 1;field < node->children.size();
                    field++) {
                astree *finode = node->children[field];
                emit_recursive(finode);
                fprintf(oilfile, INDENT "%s;\n", 
                        finode->oilname->c_str());
            }
            fprintf(oilfile, "};\n");
        }
    }
}

int emit(astree *root, FILE *out)
{
    oilfile = out;
    fprintf(oilfile, "#define __OCLIB_C__\n");
    fprintf(oilfile, "#include \"oclib.oh\"\n");
    emit_structs(root);
    emit_strings();
    emit_globals(root);
    emit_functions(root);

    fprintf(oilfile, "void __ocmain (void)\n{\n");
    emit_recursive(root);
    fprintf(oilfile, "}\n");
    return 0;
}

