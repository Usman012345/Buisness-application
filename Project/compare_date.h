#include<cstdlib>
using namespace std;
int year_system;
int month_system;
int day_system;
bool compare_time(int year,int month,int day);
void current_time()
{
     time_t now = time(NULL);
   tm *ltm = localtime(&now);

   year_system=  1900 + ltm->tm_year ;
   month_system= 1 + ltm->tm_mon;
   day_system=ltm->tm_mday;
  }
  bool compare_time(int year,int month,int day)
  {
    current_time();
    if(year_system<year)
    {
        return false;
    }
    else if(year_system==year &&month_system<month)
    {
        return false;
    }
    else if(year_system==year &&month_system==month && (day_system<day))
    {
        return false;
    }
    else 
    {
        return true;
    }
  }