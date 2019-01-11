/* The lexer of trans tool.
   Code writed by David fuqiang Fan <feqin1023@gmail.com>.
   Used for transform the LLVM inc file for Capstone.  */

#include "trans.h"

/* Buffer for lex.  */
static char *buffer[4096];

static int lex_init ()


