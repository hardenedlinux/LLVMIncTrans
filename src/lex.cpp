/* The lexer of trans tool.
   Code writed by David fuqiang Fan <feqin1023@gmail.com>.
   Used for transform the LLVM inc file for Capstone.  */

#include "trans.h"
#include "lex.h"
#include <cstdio>

/* Buffer for lex.  */
#define BUFFER_SIZE 4096
static char *buffer[BUFFER_SIZE];
//
struct buffer_ctrl_t
{
  char *cur_;
  char *limit_;
} buffer_ctrl;

//
static int lex_config_inited_flag;
static int lex_input_inited_flag;

/* Initialize the lex, if any error happend return 1.  */
int
lex_init (FILE *file, char *name)
{
  assert (lex_config_inited_flag == 0);
  lex_config_inited_flag = 1;

  // full buffer.
  size_t size = fread (buffer, 1, BUFFER_SIZE, file);
  if (ferror (file))
    {
      std::cout << Error: when read file: << name;
      return 1;
    }
  if (size < BUFFER_SIZE)
    assert (feof (file));

  buffer_ctrl.cur_ = buffer;
  buffer_limit = buffer + size;

  return 0;
}

/* Main interface of lex. return a token.  */
enum lex_type 
get_tok ()
{
  assert (trans_error == 0);
  assert (lex_inited_flag);

}


