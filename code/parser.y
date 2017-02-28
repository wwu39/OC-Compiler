%{

#include <assert.h>
#include <stdlib.h>
#include <string>
#include <cstring>

#include "astree.h"
#include "auxlib.h"
#include "lyutils.h"
#include "emit.h"
%}

%debug
%defines
%error-verbose
%token-table
%verbose

%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_FALSE TOK_TRUE TOK_NULL TOK_NEW
%token TOK_EQ TOK_NE TOK_LE TOK_GE TOK_ARRAY
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON

%token TOK_ROOT TOK_BLOCK TOK_PARAMLIST TOK_DECLID
%token TOK_FUNCTION TOK_TYPEID TOK_FIELD TOK_VARDECL TOK_IFELSE
%token TOK_RETURNVOID TOK_NEWSTRING TOK_NEWARRAY TOK_INDEX
%token TOK_PROTOTYPE TOK_CALL TOK_POS TOK_NEG

%right TOK_IF TOK_ELSE
%right '='
%left  TOK_EQ TOK_LE TOK_NE TOK_GE '>' '<'
%left  '+' '-'
%left  '*' '/' '%'
%right PREC_UPLUS PREC_UMINUS '!' TOK_ORD TOK_CHR
%left  PREC_INDEX PREC_FIELD PREC_CALL
%nonassoc TOK_NEW
%nonassoc PREC_PAREN

%start start

%%

start : program                     { yyparse_astree = $1; }
      ;

program : program statement         { $$ = $1->adopt($2); }
        | program function          { $$ = $1->adopt($2); }
        | program structdef         { $$ = $1->adopt($2); }
        | program error '}'         { $$ = $1; }
        | program error ';'         { $$ = $1; }
        |                           { $$ = new astree { TOK_ROOT, 
                                           {0,0,0}, "\0" }; }
        ;

statement : expr ';'                { $$ = $1; }
          | block                   { $$ = $1; }
          | vardecl
          | whileloop
          | ifelse
          | returnstate
          ;

returnstate : TOK_RETURN expr ';'                              
                { $$ = $1->adopt($2); }
            | TOK_RETURN ';'                                   
                { $1->symbol = TOK_RETURNVOID; $$ = $1; }
            ;

ifelse : TOK_IF '(' expr ')' statement                         
            { $$ = $1->adopt($3, $5);}
       | TOK_IF '(' expr ')' statement TOK_ELSE statement      
            { $$ = $1->adopt($3, $5); $1->adopt_sym($7, TOK_IFELSE);}
       ;

whileloop : TOK_WHILE '(' expr ')' statement                   
                { $$ = $1->adopt($3, $5); }
          ;

vardecl : identdecl '=' expr ';'                               
                { $2->symbol = TOK_VARDECL; $$ = $2->adopt($1, $3); }
        ;


block : blockcontents '}'                                      
            { $$ = $1; }
      | ';'                                                    
            { $$ = $1; }
      ;

blockcontents : blockcontents statement { $$ = $1->adopt($2); }
              | '{'                     
                    { $1->symbol = TOK_BLOCK; $$ = $1; }
              | '{' statement           
                    { $$ = $1->adopt_sym($2, TOK_BLOCK); }
              ;

expr : expr '+' expr                    { $$ = $2->adopt($1, $3); }
     | expr '-' expr                    { $$ = $2->adopt($1, $3); }
     | expr '*' expr                    { $$ = $2->adopt($1, $3); }
     | expr '/' expr                    { $$ = $2->adopt($1, $3); }
     | expr '%' expr                    { $$ = $2->adopt($1, $3); }
     | expr TOK_EQ expr                 { $$ = $2->adopt($1, $3); }
     | expr TOK_NE expr                 { $$ = $2->adopt($1, $3); }
     | expr TOK_LE expr                 { $$ = $2->adopt($1, $3); }
     | expr TOK_GE expr                 { $$ = $2->adopt($1, $3); }
     | expr '>' expr                    { $$ = $2->adopt($1, $3); }
     | expr '<' expr                    { $$ = $2->adopt($1, $3); }
     | expr '=' expr                    { $$ = $2->adopt($1, $3); }
     | '-' expr %prec PREC_UMINUS       
            { $1->symbol = TOK_NEG; $$ = $1->adopt($2); }
     | '+' expr %prec PREC_UPLUS        
            { $1->symbol = TOK_POS; $$ = $1->adopt($2); }
     | '!' expr                         { $$ = $1->adopt($2); }
     | '(' expr ')' %prec PREC_PAREN    { $$ = $2; }
     | constant                         { $$ = $1; }
     | variable                         { $$ = $1; }
     | allocator
     | call
     ;

call : TOK_IDENT '(' ')'                                
            { $2->symbol = TOK_CALL; $$ = $2->adopt($1); }
     | callargs ')' %prec PREC_CALL                     { $$ = $1; }
     ;

callargs : callargs ',' expr                            
                { $$ = $1->adopt($3); }
         | TOK_IDENT '(' expr                           
                { $2->symbol = TOK_CALL; $$ = $2->adopt($1, $3); }
         ;

allocator : TOK_NEW TOK_IDENT '(' ')'                   
                { $2->symbol = TOK_TYPEID; $$ = $1->adopt($2); }
          | TOK_NEW TOK_STRING '(' expr ')'             
                { $1->symbol = TOK_NEWSTRING; $$ = $1->adopt($4); }
          | TOK_NEW basetype '[' expr ']'               
                { $1->symbol = TOK_NEWARRAY; $$ = $1->adopt($2, $4); }
          ;

variable : TOK_IDENT
         | expr '[' expr ']' %prec PREC_INDEX       
                { $2->symbol = TOK_INDEX; $$ = $2->adopt($1, $3); }
         | expr '.' TOK_IDENT %prec PREC_FIELD      
                { $3->symbol = TOK_FIELD; $$ = $2->adopt($1, $3); }
         ;

constant : TOK_INTCON               { $$ = $1; }
         | TOK_STRINGCON            
                { $$ = $1; emitter_register_string($1); }
         | TOK_CHARCON              { $$ = $1; }
         | TOK_TRUE                 { $$ = $1; }
         | TOK_FALSE                { $$ = $1; }
         | TOK_NULL                 { $$ = $1; }
         ;

function : identdecl funcargs ')' block   
                { $$ = tree_function($1, $2, $4); }
         | identdecl '(' ')' block        
                { $2->symbol = TOK_PARAMLIST; 
                $$ = tree_function($1, $2, $4); }
         ;

funcargs : funcargs ',' identdecl         
                { $$ = $1->adopt($3); }
         | '(' identdecl                  
                { $1->symbol = TOK_PARAMLIST; 
                $$ = $2 ? $1->adopt($2) : $1; }
         ;

identdecl : basetype TOK_IDENT            
                { $2->symbol = TOK_DECLID; $$ = $1->adopt($2); }
          | basetype TOK_ARRAY TOK_IDENT  
                { $3->symbol = TOK_DECLID; $$ = $2->adopt($1, $3); }
          ;

basetype : TOK_VOID
         | TOK_BOOL    { $1->symbol = TOK_INT; $$ = $1; }
         | TOK_INT
         | TOK_CHAR    { $1->symbol = TOK_INT; $$ = $1; }
         | TOK_STRING
         | TOK_IDENT   { $1->symbol = TOK_TYPEID; $$ = $1; }
         ;

structdef : structcont '}'                { $$ = $1; }
          ;

structcont : structcont fielddecl ';'     
                { $$ = $1->adopt($2); }
           | TOK_STRUCT TOK_IDENT '{'     
                { $2->symbol = TOK_TYPEID; $$ = $1->adopt($2); }
           ;

fielddecl : basetype TOK_IDENT            
                { $2->symbol = TOK_FIELD; $$ = $1->adopt($2); }
          | basetype TOK_ARRAY TOK_IDENT  
                { $3->symbol = TOK_FIELD; $$ = $2->adopt($1, $3); }
          ;

%%

const char *parser::get_tname (int symbol) {
   const char *tname = yytname [YYTRANSLATE (symbol)];
   if (strstr (tname, "TOK_") == tname) tname += 4;
   return tname;
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

