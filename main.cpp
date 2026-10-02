/*_main.cpp___________________________________________________________________ 
|  MAIN                                                                       |
|  Entry point for croll                                                      |
|                                                                             |
|                                                                             |
|                                                                             |
|____________________________________________________________________________*/
// =========== HEADERS ===================================================== //
  #include <iostream>                                                        //
  #include <string>                                                          //
                                                                             //
  #include <filesystem>                                                      //
    namespace fs = std::filesystem;                                          //
    /* For perusing through directories */                                   //
                                                                             //
  #include "textfiles.h"                                                     //
    /* This header is created during the build process, to contain the       //
       content of the ./textfiles/ folder as converted by `xxd -i`           //
       into character array, to be converted in this file to const string.*/ //
                                                                             //
                                                                             //
// =========== CONSTANTS =================================================== //
  const std::string HELP_TEXT(                                               //
    reinterpret_cast<const char *>(textfiles_help_txt),                      //
    textfiles_help_txt_len);                                                 //
                                                                             //
  const std::string VERSION_TEXT(                                            //
    reinterpret_cast<const char *>(textfiles_version_txt),                   //
    textfiles_version_txt_len);                                              //
                                                                             //
// =========== DECLARATIONS ================================================ //
void respNoArgsGiven(std::string theBranch);                                 //
void respHelpMessage();                                                      //
void respGiveVersion();                                                      //
void respInvalidArgs(std::string theInvArg);                                 //
void explorePath(char* arg);                                                 //
                                                                             //
                                                                             //
// =========== MAIN ======================================================== //
  int main(int argc, char *argv[]) {                                         //
    std::string arg0 = argv[0];                                              //
    if (argc == 1) {                                                         //
      respNoArgsGiven(arg0);                                                 //
      return 1;                                                              //
    }                                                                        //
                                                                             //
    std::string arg1 = argv[1];                                              //
    //-> Read first argument and act                                         //
      /* Set up to disregard extra arguments */                              //
    if (!arg1.compare("")) respNoArgsGiven(arg0);                            //
                                                                             //
    else if (!arg1.compare("-h") || !arg1.compare("--help")) {               //
      respHelpMessage();                                                     //
    }                                                                        //
                                                                             //
    else if (!arg1.compare("-v") || !arg1.compare("--version")) {            //
      respGiveVersion();                                                     //
    }                                                                        //
                                                                             //
    else if (!arg1.compare("-e") || !arg1.compare("--explore")) {            //
                                                                             //
      if (argc == 2) {                                                       // 
         respNoArgsGiven(arg1);                                              //
         return 1;                                                           //
      }                                                                      //
                                                                             //
      std::string arg2 = argv[2];                                            //
      if (!arg2.compare("")) respNoArgsGiven(arg1);                          //
                                                                             //
      else explorePath(argv[2]);                                             //
                                                                             //
    } /* end -e branch */                                                    //
                                                                             //
    else respInvalidArgs(arg1);                                              //
                                                                             //
    return 0;                                                                //
  } /* --- end main() --- */                                                 //
                                                                             //
// =========== FUNCTIONS =================================================== //
// ----------- respNoArgsGiven() ------------------------------------------- //
  void respNoArgsGiven(std::string theBranch) {                              //
    std::cout << "croll " << theBranch << " : no arguments given\n";         //
  }                                                                          //
                                                                             //
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
  void respInvalidArgs(std::string theInvArg) {                              //
    std::cout << "croll: invalid argument " << theInvArg << "\n";            //
    respHelpMessage();                                                       //
  }                                                                          //
                                                                             //
// ----------- explorePath() ----------------------------------------------- //
  void explorePath(char* arg) {                                              //
    /* Argument should be path to directory. Assumes so, and lets            //
       <filesystem> say otherwise. */                                        //
    std::string path = arg;                                                  //
    std::cout << path << "\n";                                               //
    for (const auto & entry : fs::directory_iterator(path)) {                //
      std::cout << entry.path() << "\n";                                     //
    }                                                                        //
                                                                             //
  }                                                                          //
                                                                             //
                                                                             //
//+++++++++++ EOF ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
