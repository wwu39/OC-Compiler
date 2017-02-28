// $Id: astree.h,v 1.10 2016-10-06 16:42:35-07 - - $

#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
using namespace std;

#include "auxlib.h"
#include "type.h"


struct symbol;

struct astree {

   // Fields.
   int symbol;               // token code
   location lloc;            // source location
   const string* lexinfo;    // pointer to lexical information
   vector<astree*> children; // children of this n-way node
   astree* parent;           // need to know the parent
   struct symbol* symentry;  // need struct keyword to clarify
   attr_bitset attributes;
   const string *type_name;
   const string *oilname;
   int blocknr;

   // Functions.
   astree (int symbol, const location&, const char* lexinfo, 
           astree* parent = nullptr);
   ~astree();
   astree* adopt (astree* child1, astree* child2 = nullptr,
                  astree* child3 = nullptr);
   astree* adopt_sym (astree* child, int symbol);
   void dump_node (FILE*);
   void dump_tree (FILE*, int depth = 0);
   static void dump (FILE* outfile, astree* tree);
   static void print (FILE* outfile, astree* tree, int depth = 0);
};

void destroy (astree* tree1, astree* tree2 = nullptr);
astree* tree_function(astree* ident, astree *arglist, astree* block);
void errllocprintf (const location&, const char* format, const char*);

#endif

