%{

#include <stdlib.h>
#include <stdbool.h>
#include "auxlib.h"
#include "lyutils.h"

#define YY_USER_ACTION  { lexer::advance (); }
#define IGNORE(THING)   { }

%}

%option 8bit
%option debug
%option nodefault
%option nounput
%option noyywrap
%option perf-report
%option verbose
%option warn


%{
// IDENT (identifiers) cannot start with a digit
// CHARCON STRINGCON
//         backslash, single quote, and newline
//         may not appear in a character or
//         string constants unless escaped
// INTCON
%}

LETTER            [A-Za-z_]
DIGIT             [0-9]
IDENT             ({LETTER}({LETTER}|{DIGIT})*)
BAD_IDENT         ({DIGIT}+({IDENT}+))
INTCON            ({DIGIT}+)
CHARCON           ('([^\\'\n]|\\[\\'"0nt])')
BAD_CHARCON       ('([^\\'\n]|\\[\\'"0nt]|\\[^\\'"0nt])?[']?[\n]?)
STRINGCON         (\"([^\\"\n]|\\[\\'"0nt])*\")
BAD_STRINGCON     (\"([^\\"\n]|\\[^\\'"0nt])*[\"]?[\n]?)
COMMENT           (\/\/.*)

%%

%{
// Reserved Words
%}
"char"          { return yylval_token (TOK_CHAR); }
"else"          { return yylval_token (TOK_ELSE); }
"if"            { return yylval_token (TOK_IF); }
"int"           { return yylval_token (TOK_INT); }
"bool"          { return yylval_token (TOK_INT); }
"char"          { return yylval_token (TOK_INT); }
"new"           { return yylval_token (TOK_NEW); }
"null"          { return yylval_token (TOK_NULL); }
"return"        { return yylval_token (TOK_RETURN); }
"string"        { return yylval_token (TOK_STRING); }
"struct"        { return yylval_token (TOK_STRUCT); }
"void"          { return yylval_token (TOK_VOID); }
"while"         { return yylval_token (TOK_WHILE); }

{STRINGCON}    { return yylval_token (TOK_STRINGCON); }
{CHARCON}      { return yylval_token (TOK_CHARCON); }
{INTCON}       { return yylval_token (TOK_INTCON); }
{IDENT}        { return yylval_token (TOK_IDENT); }


%{
// Special Symbols
%}
"#".*           { lexer::include(); }
[ \t]+          { IGNORE (white space) }
\n              { lexer::newline(); }

"="             { return yylval_token ('='); }
"+"             { return yylval_token ('+'); }
"-"             { return yylval_token ('-'); }
"*"             { return yylval_token ('*'); }
"/"             { return yylval_token ('/'); }
"("             { return yylval_token ('('); }
")"             { return yylval_token (')'); }
";"             { return yylval_token (';'); }
"[]"            { return yylval_token (TOK_ARRAY); }
"["             { return yylval_token ('['); }
"]"             { return yylval_token (']'); }
"{"             { return yylval_token ('{'); }
"}"             { return yylval_token ('}'); }
","             { return yylval_token (','); }
"."             { return yylval_token ('.'); }
"=="            { return yylval_token (TOK_EQ); }
"!="            { return yylval_token (TOK_NE); }
"<"             { return yylval_token ('<'); }
"<="            { return yylval_token (TOK_LE); }
">"             { return yylval_token ('>'); }
">="            { return yylval_token (TOK_GE); }
"%"             { return yylval_token ('%'); }
"!"             { return yylval_token ('!'); }

{BAD_IDENT}          { lexer::badtoken (yytext); }
{BAD_CHARCON}        { lexer::badchar (*yytext); }
{BAD_STRINGCON}      { lexer::badtoken (yytext); }
{COMMENT}            { IGNORE (comment); }
.                    { lexer::badchar (*yytext); }

%%
