#include<cstdlib>
#include "compare_date.h"
using namespace std;
int index=0;
 bool time2(string expiry,int medicine_count)
 {
   index=0;
   string digit="";
   int year=0,month=0,day=0;
            while(expiry[index]!='/')
            {
               digit=digit+expiry[index];
      index++;
            }
            day=stoi(digit);
            index++;
            digit="";
         while(expiry[index]!='/')
         {
            digit=digit+expiry[index];
         index++;
      }
      month=stoi(digit);
      index++;
      digit="";
         while(expiry[index]!='\0')
         {
              digit=digit+(expiry[index]);
         index++;
         }
      year=stoi(digit);
   bool expired= compare_time(year,month,day);
   return expired;  
   }