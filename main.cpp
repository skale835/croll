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
//                                                                           //
// =========== CONSTANTS =================================================== //
//                                                                           //
//                                                                           //
// =========== DECLARATIONS ================================================ //
void respNoArgsGiven();                                                      //
void respHelpMessage();                                                      //
void respGiveVersion();                                                      //
void respInvalidArgs(std::string theInvArg);                                 //
//                                                                           //
//                                                                           //
// =========== MAIN ======================================================== //
  int main(int argc, char *argv[]) {                                         //
    std::string arg1 = argv[1];                                              //
    //-> Read first argument and act                                         //
      /* Set up to disregard extra arguments */                              //
                                                                             //
    if (!argc) respNoArgsGiven();                                            //
                                                                             //
    else if (!arg1.compare("-h") || !arg1.compare("--help")) {       //
      respHelpMessage();                                                     //
    }                                                                        //
                                                                             //
    else if (!arg1.compare("-v") || !arg1.compare("--version")) {    //
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
  std::cout << "croll: help \n";                                             //
}                                                                            //
                                                                             //
// ----------- respGiveVersion() ------------------------------------------- //
void respGiveVersion() {                                                     //
  std::cout << "croll: version 0.1.\n";                                      //
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
