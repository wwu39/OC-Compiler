#ifndef __EMIT_H
#define __EMIT_H
#include <cstdio>
#include "astree.h"

int emit(astree *root, FILE *out);
void emitter_register_string(astree *node);
#endif

