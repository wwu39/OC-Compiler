#include <vector>

#include "type.h"
#include "astree.h"
#include "lyutils.h"
#include "symtable.h"
using namespace std;

extern int semantic_errors;
size_t next_block = 1;
vector<size_t> block_num_stack;
vector<symbol_table*> symbol_stack;

symbol_table *typeid_table = new symbol_table();

int scope_get_current_depth()
{
    return symbol_stack.size() - 1;
}

symbol_table *scope_get_global_table()
{
    return symbol_stack[SCOPE_GLOBAL];
}

symbol_table *scope_get_current_table()
{
    return symbol_stack.back();
}

void enter_block()
{
    symbol_stack.push_back(NULL);
    block_num_stack.push_back(next_block);
    ++next_block;
}

void leave_block()
{
    symbol_stack.pop_back();
    block_num_stack.pop_back();
}

size_t get_current_block()
{
    return block_num_stack.back();
}

symbol_table *scope_get_top_table()
{
    if(symbol_stack.back() == NULL) {
        symbol_stack.back() = new symbol_table();
    }
    return symbol_stack.back();
}

symbol *create_symbol_in_table(symbol_table *table, astree *node)
{
    symbol *sym = new symbol();
    sym->lloc.filenr = node->lloc.filenr;
    sym->lloc.linenr = node->lloc.linenr;
    sym->lloc.offset = node->lloc.offset;
    sym->definition = node;
    node->symentry = sym;
    if(table) {
        symbol_entry entry(node->lexinfo, sym);
        table->insert(entry);
    }
    return sym;
}

struct symbol *find_symbol_in_table(symbol_table *table,
        const string *ident)
{
    if(table == NULL || ident == NULL)
        return NULL;
    auto entry = table->find(ident);
    if(entry == table->end())
        return NULL;
    return &*entry->second;
}

struct symbol *find_symbol(const string *ident)
{
    for (size_t i = symbol_stack.size(); i-- > 0;)
    {
        symbol_table *table = symbol_stack[i];
        if(table == NULL) {
            continue;
        }
        auto entry = table->find(ident);
        if(entry == table->end()) {
            continue;
        }
        return &*entry->second;
    }
    return NULL;
}

int typeid_table_field_select(astree *node)
{
    symbol *sym = find_symbol_in_table(typeid_table,
            node->children[0]->type_name);
    if(!sym) {
        fprintf(stderr,
                "%zd.%zd.%zd: typeid '%s' is undefined\n",
                node->lloc.filenr, node->lloc.linenr, node->lloc.offset,
                node->children[0]->type_name ?
                    node->children[0]->type_name->c_str()
                    : "???");
        semantic_errors++;
        return 1;
    }
    symbol *field = find_symbol_in_table(sym->fields,
            node->children[1]->lexinfo);
    if(!field) {
        fprintf(stderr,
                "%zd.%zd.%zd: typeid '%s' does not"
                " have a field '%s'\n",
                node->lloc.filenr, node->lloc.linenr, node->lloc.offset,
                node->children[0]->type_name->c_str(),
                node->children[1]->lexinfo->c_str());
        semantic_errors++;
        return 1;
    }
    node->symentry = field;
    node->type_name = field->type_name;
    node->children[1]->symentry = field;
    node->children[1]->type_name = field->type_name;
    return 0;
}

static void __print_symbol(symbol *sym, astree *decl, attr_bitset attr)
{
    fprintf(symfile, "%*s%s (%zd.%zd.%zd)", (int)print_depth * 3, "",
            decl->lexinfo->c_str(), decl->lloc.filenr,
            decl->lloc.linenr, decl->lloc.offset);

    if(attr.test(ATTR_field)) {
        fprintf(symfile, " field {%s} ", current_structure->c_str());
    } else {
        fprintf(symfile, " {%ld} ", sym->block_nr);
    }
    fprintf(symfile, "%s\n", type_attrs_string(sym).c_str());
}

symbol *symbolize_declaration(symbol_table *table, astree *node,
        attr_bitset initial_attr)
{
    attr_bitset attr = initial_attr;
    if(!node_generate_attributes(node, attr)) {
        semantic_errors++;
        return 0;
    }
    astree *decl;
    const string *typenm;
    if(node->symbol == TOK_ARRAY) {
        decl = node->children[1];
        typenm = node->children[0]->lexinfo;
    } else {
        decl = node->children[0];
        typenm = node->lexinfo;
    }
    symbol *prev_sym;
    if((prev_sym = find_symbol_in_table(table, decl->lexinfo))) {
        if(initial_attr.test(ATTR_function) && !prev_sym->fnblock) {
            __print_symbol(prev_sym, decl, attr);
            return prev_sym; 
        } else {
            fprintf(stderr,
                    "%zd.%zd.%zd: duplicate declaration of"
                    " identifier '%s'. Previous"
                    " declaration at %zd.%zd.%zd\n",
                    node->lloc.filenr, node->lloc.linenr, 
                    node->lloc.offset, decl->lexinfo->c_str(), 
                    prev_sym->lloc.filenr,
                    prev_sym->lloc.linenr, prev_sym->lloc.offset);
            semantic_errors++;
            return 0;
        }
    }
    struct symbol *sym = create_symbol_in_table(table, decl);
    if(!attr.test(ATTR_function) && !attr.test(ATTR_field))
        attr.set(ATTR_lval);
    sym->type_name = NULL;
    if(attr.test(ATTR_struct)) {
        sym->type_name = typenm;
        decl->type_name = typenm;
    }
    sym->attributes = attr;
    sym->block_nr = get_current_block();
    decl->blocknr = get_current_block();
    node->blocknr = get_current_block();
    __print_symbol(sym, decl, attr);
    return sym;
}

