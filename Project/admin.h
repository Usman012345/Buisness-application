#include "time.h"
using namespace std;
string mydate[5];
char const *A;//variables to compare dates
char const *B;//same
const int y = 10;//array indexes
const int z = 10;//array indexes
bool result;
int discount_c; //'y' shows the number of medicine and 'z' shows the number of employees
int option, quantity[y], prices[y], amount1, dis;
float attendance[z], discount;
 int employee_count = 0;
 int medicine_count = 0;
string mname, ename, medicine[y], employee[z], name, price_name;
string expirary[y];
void store_medicine_count();
void store_employee_count();
string read_employee_count();
void read_medicine_count();
int admin(HANDLE hConsole)
{
        int u = 0;
    while (true)
    {
        jump:
         system("cls");
         SetConsoleTextAttribute(hConsole, 12);
cout<<" ### ##   ###  ##    ##     ### ##  ##   ##     ##      ## ##  ##  ##             ### ##   ### ###   ## ##    ## ##   ### ##   ### ##"<<endl;   
cout<<" ##  ##   ##  ##     ##     ##  ##   ## ##      ##    ##   ##  ##  ##             ##  ##   ##  ##  ##   ##  ##   ##   ##  ##   ##  ##"<<endl;  
cout<<" ##  ##   ##  ##   ## ##    ##  ##  # ### #   ## ##   ##       ##  ##             ##  ##   ##      ##       ##   ##   ##  ##   ##  ##"<<endl;  
cout<<" ##  ##   ## ###   ##  ##   ## ##   ## # ##   ##  ##  ##        ## ##             ## ##    ## ##   ##       ##   ##   ## ##    ##  ##"<<endl;  
cout<<" ## ##    ##  ##   ## ###   ## ##   ##   ##   ## ###  ##         ##               ## ##    ##      ##       ##   ##   ## ##    ##  ##"<<endl;  
cout<<" ##       ##  ##   ##  ##   ##  ##  ##   ##   ##  ##  ##   ##    ##               ##  ##   ##  ##  ##   ##  ##   ##   ##  ##   ##  ##"<<endl;  
cout<<"####     ###  ##  ###  ##  #### ##  ##   ##  ###  ##   ## ##     ##              #### ##  ### ###   ## ##    ## ##   #### ##  ### ## "<<endl; 
   SetConsoleTextAttribute(hConsole, 2);
        cout << "Main menu<<Sign in/up<<Admin menu" << endl;
        cout << "1.Add employees.." << endl;
        cout << "2.Add medicine record.." << endl;
        cout << "3.Print medicine record.." << endl;
        cout << "4.Print employee record.." << endl;
        cout << "5.Check expiry dates.." << endl;
        cout << "6.Enter prices.." << endl;
        cout << "7.Order new medicine.." << endl;
        cout << "8.Add discout policy.." << endl;
        cout << "9.Remove medicine.." << endl;
        cout << "10.Remove employee.." << endl;
        cout<<"0.exit"<<endl;
        cin>>option;
        if (option == 1)
        {
            cout << "Main menu<<Sign in/up<<Admin menu<<Add employee " << endl;
            for (; employee_count < z;)
            {
                cout << "Enter employee name: " << endl;
                cin.ignore();
                getline(cin, employee[employee_count]);
                system("pause");
                break;
            }
            Employeedata(employee,attendance,employee_count);
            employee_count++;
          store_employee_count();
        }
        if (option == 2)
        {
            cout << "Main menu<<Sign in/up<<Admin menu<<Add medicine record " << endl;
            for (; medicine_count < y; )
            {
                cout << "Enter medicine: ";
                cin >> medicine[medicine_count];
                cout << "Enter quantity: ";
                cin >> quantity[medicine_count];
                cout << "Enter expirarys dates in dd/month/year: ";
                cin.ignore();
                getline(cin, expirary[medicine_count]);
                system("pause");
                break;
            }
             cout<<medicine[medicine_count]<<"  "<<quantity[medicine_count]<<"  "<<expirary[medicine_count]<<"  "<<medicine_count<<endl;
             Sleep(3000);
            Medicinedata(medicine,quantity,expirary,medicine_count);
            medicine_count++;
            store_medicine_count();
        }
        if (option == 3)
        {
            cout << "Main menu<<Sign in/up<<Admin menu<<Print medicine record " << endl;
            for (int r = 0; r <= medicine_count; r++)
            {
                if (medicine[r] != "-1")
                    cout << medicine[r] << "      " << quantity[r] <<"          "<<prices[r]<<"       "<<expirary[r] << endl;
            }
            system("pause");
        }
        if (option == 4)
        {
            cout << "Main menu<<Sign in/up<<Admin menu<<print employee record " << endl;
            for (int e = 0; e <= employee_count; e++)
            {
                if (employee[e] != "-1")
                {
                    cout << employee[e] << "     " << attendance[e] << endl;
                }
            }
            system("pause");
        }
        if (option == 5)
        {
            bool found=false;
            cout << "Main menu<<Sign in/up<<Admin menu<<Check expiry dates " << endl;
            for (int t = 0; t <= medicine_count; t++)
            {
                string expiry=expirary[t];
               bool expired=time2(expiry,medicine_count);
               if(expired==true)
               {
                cout<<medicine[t]<<"        "<<"expired"<<endl;
                medicine[t]="-1";
                prices[t]=-1;
                quantity[t]=-1;
                expirary[t]="-1";
                medicine_count--;
                store_medicine_count();
                updatamedicinedata(medicine,quantity,expirary,medicine_count);
                updatapricedata(prices,medicine_count);
                found=true;
               }
            }
            if(found==false)
             {
               cout<<"Nothing is expired."<<endl;
             }
            system("pause");
        }
        if (option == 6)
        { 
            cout << "Main menu<<Sign in/up<<Admin menu<<Enter prices " << endl;
            for (; u <=medicine_count ;)
            {
                cout << medicine[u] << "  Enter price: ";
                cin >> prices[u];
                u++;
            }
            price(prices,medicine_count);
            system("pause");
        }
        if (option == 7)
        {
            cout << "Main menu<<Sign in/up<<Admin menu<<Order new medicine " << endl;
            cout << "Enter medicine name: ";
            cin >> name;
            for (int i = 0; i < y; i++)
            {
                if (name != medicine[i])
                {
                    cout << "Register medicine first" << endl;
                    system("pause");
                    break;
                }
                else if (name == medicine[i])
                {
                    cout << "Enter quantity: ";
                    cin >> amount1;
                    quantity[i] = quantity[i] + amount1;
                    system("pause");
                    break;
                }
            }
            updatamedicinedata(medicine,quantity,expirary,medicine_count);
        }
        if (option == 8)
        {
            cout << "Main menu<<Sign in/up<<Admin menu<<Add dicount policy " << endl;
            cout<<"Enter discount condition: ";
            cin>>discount_c;
            cout << "Add discount..";
            cin >> dis;
            discount_store(discount_c,dis);
            system("pause");
        }
        if (option == 9)
        {
            bool exists_or_not=false;
            cout << "Main menu<<Sign in/up<<Admin menu<<Remove medicine " << endl;
            cout << "Enter medicine name: ";
            cin >> mname;
            for (int x = 0; x < y; x++)
            {
                if (mname == medicine[x])
                {
                    medicine[x] = "-1";
                    quantity[x] =-1;
                    prices[x] =-1;
                    expirary[x]=" ";
                    system("pause");
                    exists_or_not=true;
                    break;
                }
            }
                if(exists_or_not==false)
                {
                    cout<<"register medicine first:"<<endl;
                    system("pause");
                    break;
                }
            updatamedicinedata(medicine,quantity,expirary,medicine_count);
        }
        if (option == 10)
        {
            bool exists_or_not=false;
            cout << "Main menu<<Sign in/up<<Admin menu<<Remove employee " << endl;
            cout << "Enter the employee name: ";
            cin >> ename;
            for (int x = 0; x < z; x++)
            {
                if (ename == employee[x])
                {
                    employee[x] = "-1";
                    attendance[x]=-1;
                    system("pause");
                    exists_or_not=true;
                    break;
                }
            }
                if(exists_or_not==false)
                {
                    cout<<"register employee first:"<<endl;
                    system("pause");
                    break;
                }
            updateemployeedata(employee,attendance,employee_count);
        }
        if(option==0)
        {
            return 0;
        }
        else if(option!=1 &&option!=2 &&option!=3 &&option!=4 &&option!=5 &&option!=6 &&option!=7 &&option!=8 &&option!=9 &&option!=10 &&option!=0 )
        {
            cout<<"Wrong input!!!";
            system("pause");
            goto jump;
        }
    }
    }
    void store_medicine_count()
{
    fstream data;
    data.open("medicine_count.txt",ios::out);
    data<<medicine_count;
    data.close();
}
void store_employee_count()
{
        fstream data;
    data.open("employee_count.txt",ios::out);
    data<<employee_count;
    data.close();
}
    void read_medicine_count()
{
    int index__=0;
    string s__line,line_;
    fstream data;
    data.open("medicine_count.txt",ios::in);
    getline(data,line_);
    while(line_[index__]!='\0')
    {
        s__line=s__line+line_[index__];
        index__++;
    }
    medicine_count=stoi(s__line);
}
string read_employee_count()
{
    int index__=0;
    string s__line,line_;
    fstream data;
    data.open("employee_count.txt",ios::in);
    getline(data,line_);
    while(line_[index__]!='\0')
    {
        s__line=s__line+line_[index__];
        index__++;
    }
    cout<<s__line;
    employee_count=stoi(s__line);
}