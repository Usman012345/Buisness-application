#include<cstdlib>
using namespace std;
int a=0,b=0,c=0,d=0;
string line__,s_line__;
void store_a_b_c_d();
void read_a_b_c_d();
void discount_store(int discount_condition, int discountd);
void price(int prices[10],int medicine_count);
void Medicinedata(string medicine__[10], int quantity__[10], string expirary__[10],int medicine_count);
void signupindata(string username__[10], string password__[10], string role__[10],int signup_count);
void Employeedata(string epmloyee___name[10], float attendance_[10],int employee__count)
{
    fstream data;
    data.open("data.txt", ios::app);
        if(employee__count>0)
        {
    data<< "\n";
        }
    data << epmloyee___name[employee__count]<<',';
    data << attendance_[employee__count];
    data.close();
}
void Medicinedata(string medicine__[10], int quantity__[10], string expirary__[10],int medicine_count)
{
    cout<<medicine__[medicine_count]<<"  "<<quantity__[medicine_count]<<"  "<<expirary__[medicine_count]<<"  "<<medicine_count<<endl;
    Sleep(3000);
    fstream data;
    data.open("data1.txt", ios::app);
        if(medicine_count>0)
        {
    data<<"\n";
        }
    data << medicine__[medicine_count]<<",";
    data << quantity__[medicine_count]<<",";
    data << expirary__[medicine_count] ;
     cout<<medicine__[medicine_count]<<"  "<<quantity__[medicine_count]<<"  "<<expirary__[medicine_count]<<"  "<<medicine_count<<endl;
    Sleep(3000);
    data.close();
}
void price(int prices[10],int medicine_count)
{
    fstream data;
    data.open("prices.txt", ios::app);
    for(int x=0;x<=medicine_count;x++)
    {
    if(medicine_count>0)
{
    data<< "\n";
}
    data << prices[x];
    }
    data.close();
}
void discount_store(int discount_condition, int discountd)
{
    fstream data;
    data.open("discount.txt", ios::out);
    data << discount_condition <<",";
    data << discountd;
    data.close();
}
void signupindata(string username__[10], string password__[10], string role__[10],int signup_count)
{
    fstream data;
    data.open("signupindata.txt", ios::app);
    if(signup_count>0)
    {
        data<<"\n";
    }
        data << username__[d] << ",";
        data << password__[d] << ",";
        data << role__[d];
        d++;
    data.close();

}   
void store_a_b_c_d()
{
    fstream data;
    data.open("a_b_c_d.txt",ios::out);
    data<< a<<","<<b<<","<<c<<","<<d;
    data.close();
}
void read_a_b_c_d()
{
    int y=0;
    fstream data4;
    data4.open("a_b_c_d.txt",ios::in);
    getline(data4,line__);
    while(line__[y]!=',')
    {
        a=int(line__[y])-'0';
        y++;
    }
    y++;
    while(line__[y]!=',')
    {
        b=int(line__[y])-'0';
        y++;
    }
    y++;
    while(line__[y]!=',')
    {
        c=int(line__[y])-'0';
        y++;
    }
    y++;
    while(line__[y]!='\0')
    {
        d=int(line__[y])-'0';
        y++;
    }
    data4.close();
}
