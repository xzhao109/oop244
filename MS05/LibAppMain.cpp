// Final Project Milestone 5
// LipApp Main
// Version 1.0
// Author    Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//                  August 5 2022
/////////////////////////////////////////////////////////////////

#include "LibApp.h"
#include "Date.h"
int main() {
   sdds::sdds_day = 10;
   sdds::sdds_mon = 8;
   sdds::sdds_year = 2022;
   sdds::sdds_test = true;
   sdds::LibApp theApp("LibRecs.txt");
   theApp.run();
   return 0;
}
