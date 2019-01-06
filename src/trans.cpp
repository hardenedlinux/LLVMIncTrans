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

/* Parse the arguments for the dirver.
   If meet the -h option, return true, otherwise return false.  */

bool
parse_arguments (int argc, char **argv)
{
  int i = 0;
  
  while (i < argc)
    {
      if (!strncmp (argv[i], "--config=", strlen ("--config=")))
        inc_cs_map_file_ = argv[i] + strlen ("--config=");
      else if (!strncmp (argv[i], "-o", 2))
	inc_out_file_name = argv[++i];
      else if (!strncmp (argv[i], "-h", 2)
        {
	  display_help ();
	  return true;
	}
      else
        {
	  trans_error = true;
	  break;
	}
	++i;
    }

    return false;
}

/* Open files for trans, if any fails return FALSE. */

bool
trans_open_files ()
{ 
  /* map file.  */
  inc_cs_map_file_ = std::fopen (inc_cs_map_file_name, "r");
  if (! inc_cs_map_file_)
    {
      std::cout << "Fatal: Cann't open "
	        << inc_cs_map_file_name
	        << endl;
      return false;
    }

  /* input file.  */
  inc_in_file_ = std::fopen (inc_in_file_name, "w+");
  if (! inc_in_file_)
    {
      std::cout << "Fatal: Cann't open "
	        << inc_in_file_name
	        << endl;
      return false;
    }

  /* output file.  */
  if (! inc_out_file_name)
    inc_out_file_ = inc_in_file_;
  else
    inc_out_file_ = std::fopen (inc_out_file_name, "w+");
  
  if (! inc_out_file_)
    {
      std::cout << "Fatal: Cann't open "
	        << inc_out_file_name
	        << endl;
      return false;
    }

  return true;
}

/* Entry point for the trans tool. */

int 
main (int argc, char *argv[]) 
{
  if (parse_arguments (argc, argv) || trans_error);
    {
      display_help ();
      return 1;
    }
   
  /* Open files.  */
  if (! trans_open_files ());
    return 1;



}

