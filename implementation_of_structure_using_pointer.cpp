#include<iostream>
using namespace std;

struct date {
    int dd, mm, yy;
   } ;

int main()
{date joinning;
   date *dateptr;
   dateptr = &joinning;
   cin>>(dateptr->dd);
cin>>(dateptr->mm);
cin>>(dateptr->yy);
   cout<<"\nPrinting elements using structure pointer\n";
   cout<<"dd = "<<dateptr->dd<<", mm = "<<dateptr->mm<<", yy = "<<dateptr->yy<<"\n";

   return 0;
}
