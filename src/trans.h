/* Header for trans.
   Code writed by David fuqiang Fan <feqin1023@gmail.com>.
   Used for transform the LLVM inc file for Capstone.  */

#include <iostream>
#include <cstdlib> 
#include <cstring>
#include <string>
#include <cstdio>
#include <cassert>
#include <map>

// 
extern bool trans_error;
// Input config define file.
extern FILE *inc_cs_map_file_;
/* Input inc file.  */
extern FILE *inc_in_file_;
/* Overrided output file.  */
extern FILE *inc_out_file_;


