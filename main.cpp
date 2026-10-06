/*_main.cpp___________________________________________________________________ 
|  MAIN                                                                       |
|  Entry point for croll                                                      |
|                                                                             |
|                                                                             |
|                                                                             |
|____________________________________________________________________________*/
// =========== HEADERS ===================================================== //
  #include <iostream>
  #include <string>
  #include <vector>

  #include <filesystem>
    namespace fs = std::filesystem;
    /* For perusing through directories */

  #include "Vargs/Vargs.hpp"
    /* Module For managing CL arguments */

  #include "textfiles.h"
    /* This header is created during the build process, to contain the
       content of the ./textfiles/ folder as converted by `xxd -i`
       into character array, to be converted in this file to const string.*/


// =========== CONSTANTS =================================================== //

  const std::string HELP_TEXT(
    reinterpret_cast<const char *>(textfiles_help_txt),
    textfiles_help_txt_len);

  const std::string VERSION_TEXT(
    reinterpret_cast<const char *>(textfiles_version_txt),
    textfiles_version_txt_len);

// =========== DECLARATIONS ================================================ //
  void callBranch(std::string head, Vargs tail);
  void respNoArgsGiven(std::string head);
  void respInvalidArg(std::string head);
  void printHelpMessage();
  void printVersion();

// =========== MAIN ======================================================== //
  int main(int argc, char *argv[]) {
    //-> Convert arguments to vector of strings and make iterator
      /* Input check: no arguments */
    if (argc == 1) {
      respNoArgsGiven("");
      return 1;
    }

    Vargs vargs(argc,argv);
    callBranch(vargs.fpop(),vargs);  


 
    return 0;
    
  } /* --- end main() --- */

// =========== FUNCTIONS =================================================== //
// ----------- respNoArgsGiven() ------------------------------------------- //
  void respNoArgsGiven(std::string head) { 
    std::cout << "croll " << head <<  " : no arguments given\n" << std::endl;
  }

// ----------- respInvalidArg() - ------------------------------------------ //
  void respInvalidArg(std::string head) { 
    std::cout << "croll " << head <<  " : invalid argument\n" << std::endl;
  }

// ----------- printHelpMessage() ------------------------------------------ //
  void printHelpMessage() {
    std::cout << HELP_TEXT;
  }

// ----------- printVersion() ---------------------------------------------- //
  void printVersion() {
    std::cout << VERSION_TEXT;
  }

// ----------- callBranch() ------------------------------------------------ //
  void callBranch(std::string head, Vargs tail) {
    if (head == "-h") {printHelpMessage(); return;}
    if (head == "-v") {printVersion(); return;}
    respInvalidArg(head); 
    return;
  }
//+++++++++++ EOF ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
