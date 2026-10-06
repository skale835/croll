/*_test_croll.cpp____________________________________________________
|  Test program for croll                                            |
|                                                                    |
|  Copyright (c) 2026 Sameer Kale [skale835@proton.me]               |
|  SPDX-License-Identifier: GPL-3.0-or-later                         |
|                                                                    |
|___________________________________________________________________*/
// =========== HEADERS ============================================ //

  #include <iostream>
  #include <cstdlib>
    /* system() */
  #include <sys/wait.h>
    /* see man system() */
  #include <cstdio>
    /* FILE stuff */

  #include "testUtils/testutils.h"
    /* Test utilities, namespace test */
// =========== MAIN ============================================== //
  int main() {
    test::printTitle("croll Test");
    int wstat;
    int ret;
    char buff[128];
// ---------- Test empty & invalid ------------------------------- //
    test::printHeading("Test empty and invalid arguments");

    wstat = system("./croll");
    if (WIFEXITED(wstat)) ret = WEXITSTATUS(wstat);
    test::printResult("./croll no args return 1",
                      ret==1);

    wstat = system("./croll -invalid");
    if (WIFEXITED(wstat)) ret = WEXITSTATUS(wstat);
    test::printResult("./croll invalid args return 1",
                      ret==1);
   
// ---------- Test -v -------------------------------------------- //
    test::printHeading("Test -v: Print version");            
    wstat = system("./croll -v");      
    if (WIFEXITED(wstat)) ret = WEXITSTATUS(wstat);
    test::printResult("return 0",
                      ret==0);       
   
// ---------- Test -v -------------------------------------------- //
    FILE *pipe = popen("./croll -h", "r");
    if (pipe == nullptr) {test::printNote("popen failed!"); return 1;}
    fgets(buff, 128, pipe);

    test::printHeading("Test -h: Help message");
    test::printNote(buff);
    ret = pclose(pipe);
    if (WIFEXITED(wstat)) ret = WEXITSTATUS(wstat);
    test::printResult("return 0",
                      ret==0);       
   
// ---------- End test ------------------------------------------- //
    test::printHeading("TEST END");
    return 0;
  }

//+++++++++++ EOF +++++++++++++++++++++++++++++++++++++++++++++++++ //
