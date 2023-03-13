#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>
#include "updatefiles.h"
#include "get_character.h"
#include "storedata.h"
#include "admin.h"
#include "signupin.h"
#include"upload_sign.h"
#include "employee.h"
#include "readfile.h"
#include"signup_count.h"
using namespace std;
main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int signup_count = 0;
    read_a_b_c_d();
    read_employee_count();
     read_medicine_count();
  signup_count=read_signup_count(signup_count);
  readfile(medicine_count,employee_count);
  upload_sign(signup_count);
    while (true)
    {
        system("cls");
           SetConsoleTextAttribute(hConsole, 12);
cout<<" ### ##   ###  ##    ##     ### ##  ##   ##     ##      ## ##  ##  ##             ### ##   ### ###   ## ##    ## ##   ### ##   ### ##"<<endl;   
cout<<" ##  ##   ##  ##     ##     ##  ##   ## ##      ##    ##   ##  ##  ##             ##  ##   ##  ##  ##   ##  ##   ##   ##  ##   ##  ##"<<endl;  
cout<<" ##  ##   ##  ##   ## ##    ##  ##  # ### #   ## ##   ##       ##  ##             ##  ##   ##      ##       ##   ##   ##  ##   ##  ##"<<endl;  
cout<<" ##  ##   ## ###   ##  ##   ## ##   ## # ##   ##  ##  ##        ## ##             ## ##    ## ##   ##       ##   ##   ## ##    ##  ##"<<endl;  
cout<<" ## ##    ##  ##   ## ###   ## ##   ##   ##   ## ###  ##         ##               ## ##    ##      ##       ##   ##   ## ##    ##  ##"<<endl;  
cout<<" ##       ##  ##   ##  ##   ##  ##  ##   ##   ##  ##  ##   ##    ##               ##  ##   ##  ##  ##   ##  ##   ##   ##  ##   ##  ##"<<endl;  
cout<<"####     ###  ##  ###  ##  #### ##  ##   ##  ###  ##   ## ##     ##              #### ##  ### ###   ## ##    ## ##   #### ##  ### ## "<<endl; 
   SetConsoleTextAttribute(hConsole, 15);
    jump:
        int option;
        cout <<"1.Sign up " << endl
             <<"2.sign in" << endl
             <<"0.exit" << endl;
        cin >> option;
        if (option == 1)
        {
            sign_up(signup_count);
            signup_count++;
            system("pause");
        }   
        else if (option == 2)
        {
            string Role = sign_in(signup_count);
            if (Role == "admin")
            {
                admin(hConsole);
            }
            if (Role == "employee")
            {
                employee_(hConsole);
            }
        }
        else if (option == 0)
        {
            signup_countstore(signup_count);
            store_a_b_c_d();
            return 0;
        }
        else if (option != 1 && option != 2 &&option!=0)
        {
            cout << "Wrong input!!!";
            system("pause");
            goto jump;
        }
    }
}