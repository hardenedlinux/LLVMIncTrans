/* The header file for lex of trans tool.
   Code writed by David fuqiang Fan <feqin1023@gmail.com>.
   Used for transform the LLVM inc file for Capstone.  */

/* We take the LLVM internal datestruct name of llvm-tblgen generated inc file
   as keywords of LLVMIncTGrans, recongnize them and parse make substitute for
   the internal datestruct name of Capstone.  */


/* Define the   */
enum lex_type {
  NUMBER,        // value literal.
  ENUM,          // enum keywprd.
  CLASS,         // class keyword.

  SPACE = 32     // space of ASCII.
}
