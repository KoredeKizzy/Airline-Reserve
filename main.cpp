#include <iostream>
#include <cctype>
using namespace std;

int main()
{
   const int SEATS = 11;
   int plane[ SEATS ] = {};
   int people = 0;
   int economy = 6;
   int firstClass = 1;
   int choice;
   char response;

   // continue until plane is full
   while ( people < 10 )
   {
      cout << "\nPlease type 1 for \"firstClass\"\n"
         << "Please type 2 for \"economy\"\n";
      cin >> choice;

      // if user selects first class and seats available, assign seat
      if ( choice == 1 )
      {
         if ( !plane[ firstClass ] && firstClass <= 5 ) // seat available
         {
            cout << "Your seat assignment is " << firstClass
               << " in the first class section.\n";
            plane[ firstClass++ ];
            people++;
         } // end if
         else if ( firstClass > 5 && economy <= 10 ) // take economy seat
         {
            cout << "The firstClass section is full.\nWould you "
               << "like to sit in the economy section (Y or N)? ";
            cin >> response;

            // if economy is suitable, assign seat in economy section
            if ( response == 'Y' || response == 'y' )
            {
               cout << "Your seat assignment is " << economy
                  << " in the economy section.\n";
               plane[ economy++ ];
               people++;
            } // end if
            else // if economy seat not suitable, print next departure
               cout << "Next flight leaves in 3 hours.\n";
         } // end outer else
         else // if no economy seats either, print next departure
            cout << "Next flight leaves in 3 hours.\n";
      } // end outer if
      else // if user selects economy and seats available, assign seat
      {
         if ( !plane[ economy ] && economy <= 10 ) // seat available
         {
            cout << "Your seat assignment is " << economy
               << " in the economy section.\n";
            plane[ economy++ ];
            people++;
         } // end if
         else if ( firstClass <= 5 ) // first class seat available
         {
            cout << "The economy section is full.\nWould you like "
                 << "to sit in the firstClass section (Y or N)? ";
            cin >> response;

            if ( response == 'Y' || response == 'y' )
            {
               cout << "Your seat assignment is " << firstClass
                  << " in the first class section.\n";
               plane[ firstClass++ ];
               people++;
            } // end if
            else // if first class not suitable, print next departure
               cout << "Next flight leaves in 3 hours.\n";
         } // end outer else
         else // if no seats left, print next departure
            cout << "Next flight leaves in 3 hours.\n";
      } // end outer if
   } // end while

   cout << "All seats for this flight are sold." << endl;
} // end main
