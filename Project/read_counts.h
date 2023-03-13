#include<fstream>
#include<iostream>
#include<cstdlib>
using namespace std;
void read_employee_count();
void read_medicine_count()
{
    int index_;
    string line,s_line;
    fstream data;
    data.open("medicine_count.txt",ios::in);
    getline(data,line);
    while(line[index_]!='/0')
    {
        s_line=s_line+line[index_];
        index_++;
    }
    medicine_count=stoi(s_line);
}
void read_employee_count()
{
    int index_;
    string line,s_line;
    fstream data;
    data.open("employee_count.txt",ios::in);
    getline(data,line);
    while(line[index_]!='/0')
    {
        s_line=s_line+line[index_];
        index_++;
    }
    employee_count=stoi(s_line);
}