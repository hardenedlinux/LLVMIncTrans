/* The driver of trans tool.
   Code writed by David fuqiang Fan <feqin1023@gmail.com>.
   Used for transform the LLVM inc file for Capstone.  */

#include "trans.h"

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
  //std::string temp (inc_in_file_name);
  //inc_in_file_name = std::rename(inc_in_file_name, (temp + "-old").c_str);
  inc_in_file_ = std::fopen (inc_in_file_name, "r");
  if (! inc_in_file_)
    {
      std::cout << "Fatal: Cann't open "
	        << inc_in_file_name
	        << endl;
      return false;
    }

  /* Contains the original LLVM inc file name. For every reason, 128 is a big
     enough number.  */
  char temp_name [128];
  /* output file.  */
  if (! inc_out_file_name)
    {
      char *pc = temp_name;
      unsigned len = strlen (inc_in_file_name);
      assert (len < 128 - 10 && "File name overflow !");
      std::strncpy (pc, inc_in_file_name, len);
      /* If the original inc file name is oldFileName.inc, We want the output
	 file name is oldFileNameTrans.inc.  */
      // This is strcpy, We need the terminal, and we konwn it is crystal.
      std::strcpy ( pc + len - 4/* strlen(".inc") */, "Trans.inc");
      inc_out_file_name = temp_name;
    }
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


/* Parse and record the configure map.
   If any error return false.  */

bool 
parse_config ()
{

}


/* Parse the input file make the transform and output the c file.
   If any error return false.  */
bool 
trans ()
{

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
  /* Read configure file.  */
  if (! parse_config ());
    return 1;
  /* Parse input file and generate output file.  */
  if (! trans ());
    return 1;

  return 0;
}

