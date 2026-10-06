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

  #include "textfiles.h"
    /* This header is created during the build process, to contain the
       content of the ./textfiles/ folder as converted by `xxd -i`
       into character array, to be converted in this file to const string.*/


// =========== CONSTANTS =================================================== //
                                                                             //
  using CliArg = std::string;                                                //
  using CliVec = std::vector<CliArg>;                                        //
  using CliVIt = CliVec::iterator;                                           //
  using CliVIc = CliVec::const_iterator;                                     //
                                                                             //
  const std::string HELP_TEXT(                                               //
    reinterpret_cast<const char *>(textfiles_help_txt),                      //
    textfiles_help_txt_len);                                                 //
                                                                             //
  const std::string VERSION_TEXT(                                            //
    reinterpret_cast<const char *>(textfiles_version_txt),                   //
    textfiles_version_txt_len);                                              //
                                                                             //
// =========== DECLARATIONS ================================================ //
  void respNoArgsGiven();
  void respNoArgsGiven(std::string);
  void respNoArgsGiven(CliVIc theBranch);
  void respHelpMessage();
  void respGiveVersion();
  void respInvalidArgs(std::string theInvArg);
  void explorePath(std::vector<std::string>::iterator itr,
                   std::vector<std::string>::iterator end);

// =========== MAIN ======================================================== //
  int main(int argc, char *argv[]) {
    //-> Convert arguments to vector of strings and make iterator
      /* Input check: no arguments */
    if (argc == 1) {
      respNoArgsGiven();
      return 1;
    }
                                                                             //
    std::vector<std::string> args;                                           //
      /* First argument should have been "croll" and can be tossed now */    //
    for (int a = 1; a < argc; a++) {                                         //
      args.push_back(argv[a]);                                               //
    };                                                                       //
                                                                             //
    std::vector<std::string>::iterator i_args = args.begin();                //
                                                                             //
    //-> Read first argument to select branch                                //
      /* Set up to disregard extra arguments */                              //
    if (!(*i_args).compare("")) respNoArgsGiven(*(i_args));                  //
                                                                             //
    else if (!(*i_args).compare("-h")                                        //
          || !(*i_args).compare("--help")) {                                 //
      respHelpMessage();                                                     //
    }                                                                        //
                                                                             //
    else if (!(*i_args).compare("-v")                                        //
          || !(*i_args).compare("--version")) {                              //
      respGiveVersion();                                                     //
    }                                                                        //
                                                                             //
    else if (!(*i_args).compare("-e")                                        //
          || !(*i_args).compare("--explore")) {                              //
                                                                             //
        /* Check that more arguments exist */                                //
      if (i_args++ == args.end()) {
         respNoArgsGiven(*i_args);
         return 1;
      }
                                                                             //
                                                                             //
    } /* end -e branch */                                                    //
                                                                             //
    else respInvalidArgs(*i_args);
                                                                             //
                                                                             //
    return 0;                                                                //
  } /* --- end main() --- */                                                 //
                                                                             //
// =========== FUNCTIONS =================================================== //
// ----------- respNoArgsGiven() ------------------------------------------- //
  void respNoArgsGiven() { 
    std::cout << "croll " <<  " : no arguments given\n" << std::endl;
  }
  void respNoArgsGiven(std::string theBranch) {
    std::cout << 
      "croll " << theBranch << " : no arguments given\n" << 
      std::endl;
  }
  void respNoArgsGiven(CliVIc theBranch) {
    std::cout << 
      "croll " << *theBranch << " : no arguments given\n" << 
      std::endl;
  }

// ----------- respHelpMessage() ------------------------------------------- //
  void respHelpMessage() {                                                   //
    std::cout << HELP_TEXT;                                                  //
  }                                                                          //
                                                                             //
// ----------- respGiveVersion() ------------------------------------------- //
  void respGiveVersion() {                                                   //
    std::cout << VERSION_TEXT;                                               //
  }                                                                          //
                                                                             //
// ----------- respInvalidArgs() ------------------------------------------- //
  void respInvalidArgs(CliArg theInvArg) {                                   //
    std::cout << "croll: invalid argument " << theInvArg << "\n";            //
    respHelpMessage();                                                       //
  }                                                                          //
                                                                             //
// ----------- explorePath() ----------------------------------------------- //
  void explorePath(CliVIc itr, CliVIc end) {                                 //
    CliArg path = *itr;                                                   //
    /* Argument should be path to directory. Assumes so, and lets            //
       <filesystem> say otherwise. */                                        //
    while(itr < end) {                                                                         //
      path = *itr;                                                  //
      std::cout << path << "\n";                                               //
      for (const auto & entry : fs::directory_iterator(path)) {                //
        std::cout << entry.path() << "\n";                                     //
      }                                                                        //
      itr++;                                                                 //
    }                                                                        //
  }                                                                          //
                                                                             //
// ----------- revectorItr() ----------------------------------------------- //
//std::vector<std::string> revectorItr() (
//                         std::vector<std::string>::iterator itr) {
//  std::vector<std::string>T;                                               //
//}                                                                          //
                                                                             //
                                                                             //
//+++++++++++ EOF ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
