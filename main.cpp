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
  #include "textfiles.h"                                                     //
//                                                                           //
// =========== CONSTANTS =================================================== //
  const std::string HELP_TEXT(                                               //
    reinterpret_cast<const char *>(textfiles_help_txt),                      //
    textfiles_help_txt_len);                                                 //
                                                                             //
  const std::string VERSION_TEXT(                                            //
    reinterpret_cast<const char *>(textfiles_version_txt),                   //
    textfiles_version_txt_len);                                              //
                                                                             //
                                                                             //
                                                                             //
                                                                             //
// =========== DECLARATIONS ================================================ //
void respNoArgsGiven();                                                      //
void respHelpMessage();                                                      //
void respGiveVersion();                                                      //
void respInvalidArgs(std::string theInvArg);                                 //
//                                                                           //
//                                                                           //
// =========== MAIN ======================================================== //
  int main(int argc, char *argv[]) {                                         //
    if (argc == 1) {                                                         //
      respNoArgsGiven();                                                     //
      return 1;                                                              //
    }                                                                        //
                                                                             //
    std::string arg1 = argv[1];                                              //
    //-> Read first argument and act                                         //
      /* Set up to disregard extra arguments */                              //
    if (!arg1.compare("")) respNoArgsGiven();                                //
                                                                             //
    else if (!arg1.compare("-h") || !arg1.compare("--help")) {               //
      respHelpMessage();                                                     //
    }                                                                        //
                                                                             //
    else if (!arg1.compare("-v") || !arg1.compare("--version")) {            //
      respGiveVersion();                                                     //
    }                                                                        //
                                                                             //
    else respInvalidArgs(arg1);                                              //
                                                                             //
    return 0;                                                                //
  } /* --- end main() --- */                                                 //
                                                                             //
// =========== FUNCTIONS =================================================== //
// ----------- respNoArgsGiven() ------------------------------------------- //
void respNoArgsGiven() {                                                     //
  std::cout << "croll: no arguments given\n";                                //
}                                                                            //
                                                                             //
// ----------- respHelpMessage() ------------------------------------------- //
void respHelpMessage() {                                                     //
  std::cout << HELP_TEXT;                                                    //
}                                                                            //
                                                                             //
// ----------- respGiveVersion() ------------------------------------------- //
void respGiveVersion() {                                                     //
  std::cout << VERSION_TEXT;                                                 //
}                                                                            //
                                                                             //
// ----------- respInvalidArgs() ------------------------------------------- //
void respInvalidArgs(std::string theInvArg) {                                //
  std::cout << "croll: invalid argument " << theInvArg << "\n";              //
  respHelpMessage();                                                         //
}                                                                            //
                                                                             //
                                                                             //
//+++++++++++ EOF ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
