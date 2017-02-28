// $Id: main.cpp,v 1.1 2016-10-10 13:46:14-07 - - $
/* oc [@flags] [-Dstring] [-ly] program.oc
 */

#include <string>
using namespace std;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
//#include <iostream>

#include "string_set.h"
#include "auxlib.h"
#include "lyutils.h"
#include "symtable.h"
#include "emit.h"

extern FILE* yyin;
extern FILE* tok_file;
extern astree* yyparse_astree;
const string CPP = "/usr/bin/cpp";
extern int yy_flex_debug, yydebug;

bool is_oc(const char* path){
    size_t end = strlen(path);
    if (end < 3) return false;
    return path[end-1] == 'c'
        and path[end-2] == 'o'
        and path[end-3] == '.';
}

char* scan_opt(int argc, char** argv, string& dflag) {
    int opt = 0;
    yy_flex_debug = 0;
    yydebug = 0;
    while ((opt = getopt(argc, argv, "ly@:D:")) != -1) {
        switch (opt) {
            case 'l':
                yy_flex_debug = 1;
                break;
            case 'y':
                yydebug = 1;
                break;
            case '@':
                set_debugflags(optarg);
                break;
            case 'D':
                dflag = optarg;
                break;
            default:
                break;
        }
    }
    if(opt and yy_flex_debug and yydebug and !dflag.empty()) {
        // avoid unused warning atm
        
    }
    if (optind >= argc) {
        errprintf("Usage %s [@flags] [-Dstring] [-ly] program.oc\n",
                  exec::execname.c_str());
        exit(exec::exit_status);
    } else if (not is_oc(argv[optind])) {
        errprintf("Usage %s [@flags] [-Dstring] [-ly] program.oc\n",
                  exec::execname.c_str());
        exit(exec::exit_status);
    } else
        return argv[optind];
}

int main (int argc, char** argv) {
    string_set::set.max_load_factor(0.5);
    string dflag ="";
    exec::execname = argv[0];
    char* filename = scan_opt(argc, argv, dflag);
    // do what cppstrtok.cpp main does
    // cppstrtok.cpp main is deleted
    string command = CPP;
    if (not dflag.empty()){
        command += " -D";
        command += dflag;
    }
    command += " ";
    command += filename;
    yyin = popen (command.c_str(), "r");
    if (yyin == NULL) {
        // error handling using auxlib function
        syserrprintf(command.c_str());
        exit(exec::exit_status);
    } else {
        // cpplines(yyin, filename);
        
        string out = basename(filename);
        out = out.substr(0, out.size()-3);
        string str_out = out + ".str";
        string tok_out = out + ".tok";
        string ast_out = out + ".ast";
        string sym_out = out + ".sym";
        string oil_out = out + ".oil";
        
        // open output file
        tok_file = fopen(tok_out.c_str(), "w");
        FILE* ast_file = fopen(ast_out.c_str(), "w");
        FILE* sym_file = fopen(sym_out.c_str(), "w");
        FILE* oil_file = fopen(oil_out.c_str(), "w");
        // while (yylex() != YYEOF) {}
        int parse_status = yyparse();
        if (parse_status) {
            exec::exit_status = parse_status;
            exit(exec::exit_status);
        }
        int typecheck_status = typecheck(yyparse_astree, sym_file);
        yyparse_astree -> dump_tree(ast_file);
        if (typecheck_status) {
            exec::exit_status = typecheck_status;
            exit(exec::exit_status);
        }
        int emit_status = emit(yyparse_astree, oil_file);
        if (emit_status) {
            exec::exit_status = emit_status;
            exit(exec::exit_status);
        }
        fclose(tok_file);
        fclose(ast_file);
        fclose(sym_file);
        fclose(oil_file);
        
        // dump stringset
        FILE* str_file = fopen(str_out.c_str(), "w");
        // printf("open file %s\n", str_out.c_str());
        string_set::dump(str_file);
        fclose(str_file);
        
        if (pclose(yyin) != 0) exec::exit_status = EXIT_FAILURE;
        yylex_destroy();
    }
    
    return exec::exit_status;
}

