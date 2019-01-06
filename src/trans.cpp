/* The driver of trans tool.
   Code writed by David fuqiang Fan <feqin1023@gmail.com>.
   Used for transform the LLVM inc file for Capstone.  */

#include <iostream>
#include <cstdlib> 
#include <cstring>
#include <map>

using std::strncmp;
using std::strlen;

/* Whether we meet a error. */
bool trans_error;

/* Contains the map from LLVM inc to Capstone internal declarations.
   This file is default in the directory same as this driver. */
char *inc_cs_map_file_name = "trans.config"
FILE *inc_cs_map_file_;

/* Input inc file.  */
char *inc_in_file_name;
FILE *inc_in_file_;

/* Overrided output file.  */
char *inc_out_file_name;
FILE *inc_out_file_;

/* Print the help infos.  */

void
display_help ()
{
  std::cout << "Usage : trans [options] file...0\n"
	    << "  --config=<file>    Override the default map config file.\n"
	    << "  -o <file>          Place the output into file.\n"
	    << "  -h                 Print this infos.\n";
  
  return;
}

/* Parse the arguments for the dirver.  */
voild
parse_arguments (int argc, char **argv)
{
  int i = 0;
  
  while (i < argc)
    {
      if (!strncmp (argv[i], "--config=", strlen ("--config=")))
        inc_cs_map_file_ = argv[i] + strlen ("--config=");
      if (!strncmp (argv[i], "-o", 2))
	
  
    }
}


/* Entry point for the trans tool. */

int 
main (int argc, char *argv[]) 
{
  parse_arguments (argc, argv);
  if (trans_error)
    {
      display_help ();
      return 1;
    }

  



}

