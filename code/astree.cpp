// $Id: astree.cpp,v 1.14 2016-08-18 15:05:42-07 - - $

#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "string_set.h"
#include "lyutils.h"
#include "symtable.h"
#include "type.h"

astree::astree (int symbol_, const location& lloc_, const char* info,
                astree* parent_) {
   symbol = symbol_;
   lloc = lloc_;
   lexinfo = string_set::intern (info);
   parent = parent_;
   symentry = nullptr;
   type_name = 0;
   oilname = 0;
   blocknr = 0;
   // vector defaults to empty -- no children
}

astree::~astree() {
   while (not children.empty()) {
      astree* child = children.back();
      children.pop_back();
      delete child;
   }
   if (yydebug) {
      fprintf (stderr, "Deleting astree (");
      astree::dump (stderr, this);
      fprintf (stderr, ")\n");
   }
}

astree* astree::adopt (astree* child1, astree* child2, astree* child3) {
   if (child1 != nullptr) {
      children.push_back (child1);
      child1->parent = this;
   }
   if (child2 != nullptr) {
      children.push_back (child2);
      child2->parent = this;
   }
   if (child3 != nullptr) {
      children.push_back (child3);
      child3->parent = this;
   }
   return this;
}

astree* astree::adopt_sym (astree* child, int symbol_) {
   symbol = symbol_;
   return adopt (child);
}


void astree::dump_node (FILE* outfile) {
   fprintf (outfile, "%s \"%s\" %zd.%zd.%zd {%d} %s",
            parser::get_tname (symbol),
            lexinfo->c_str(),
            lloc.filenr, lloc.linenr, lloc.offset, blocknr,
            __typeid_attrs_string(get_node_attributes(this),
                type_name).c_str());
   /*
   for (size_t child = 0; child < children.size(); ++child) {
      fprintf (outfile, " %p", children.at(child));
   }
   */
   if(symentry && symentry->definition != this)
       fprintf (outfile, " (%zd.%zd.%zd)", symentry->lloc.filenr,
              symentry->lloc.linenr, symentry->lloc.offset);
   
}

void astree::dump_tree (FILE* outfile, int depth) {
   // fprintf (outfile, "%*s", depth * 3, "");
   for (int i = 0; i < depth; ++i){
       fprintf(outfile, "|  ");
   }
   dump_node (outfile);
   fprintf (outfile, "\n");
   for (astree* child: children) child->dump_tree (outfile, depth + 1);
   fflush (NULL);
}

void astree::dump (FILE* outfile, astree* tree) {
   if (tree == nullptr) fprintf (outfile, "nullptr");
                   else tree->dump_node (outfile);
}

void astree::print (FILE* outfile, astree* tree, int depth) {
   fprintf (outfile, "; %*s", depth * 3, "");
   fprintf (outfile, "%s \"%s\" (%zd.%zd.%zd)\n",
            parser::get_tname (tree->symbol), tree->lexinfo->c_str(),
            tree->lloc.filenr, tree->lloc.linenr, tree->lloc.offset);
   for (astree* child: tree->children) {
      astree::print (outfile, child, depth + 1);
   }
}

void destroy (astree* tree1, astree* tree2) {
   if (tree1 != nullptr) delete tree1;
   if (tree2 != nullptr) delete tree2;
}

astree* tree_function(astree* ident, astree *arglist, astree* block) {
    bool prototype = block->symbol == ';';
    astree* function = new astree(prototype ? TOK_PROTOTYPE : 
            TOK_FUNCTION, ident->lloc, "\0");
    function->adopt(ident);
    function->adopt(arglist);
    if(!prototype)
        function->adopt(block);
    return function;
}

void errllocprintf (const location& lloc, const char* format,
                    const char* arg) {
   static char buffer[0x1000];
   assert (sizeof buffer > strlen (format) + strlen (arg));
   snprintf (buffer, sizeof buffer, format, arg);
   errprintf ("%s:%zd.%zd: %s", 
              lexer::filename (lloc.filenr), lloc.linenr, lloc.offset,
              buffer);
}
