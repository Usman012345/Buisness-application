#include <cstdlib>
#include<string>
using namespace std;
 string line, s_line="";
  int index_ = 0;
void readfile(int medicine_count,int employee_count)
{
    index_=0;
    fstream data;
    data.open("data.txt", ios::in);
    for (int x = 0; x <= employee_count; x++)
    {
        getline(data, line);
        index_ = 0;
        while (line[index_] != ',')
        {
            employee[x] = employee[x] + line[index_];
            index_++;
        }
        index_++;
        s_line="";
        while (line[index_] != '\0')
        {
            s_line = s_line + line[index_];
            index_++;
       }
        attendance[x] = stoi(s_line);
        index_++;
    }
    data.close();
    s_line="";
    index_ = 0;
    fstream data1;
    data1.open("data1.txt", ios::in);
    for (int x = 0; x <= medicine_count; x++)
    {
        s_line="";
        getline(data1, line);
        index_= 0;
        while (line[index_] != ',')
        {
            medicine[x] = medicine[x] + line[index_];
            index_++;
      }
        index_++;
        while (line[index_]!= ',')
      {
            s_line = s_line + line[index_];
         
            index_++;
        }
        quantity[x] = stoi(s_line);
        index_++;
        while (line[index_] != '\0')
        {
            expirary[x] = expirary[x] + line[index_];
            index_++;
        }
        index_++;
    }
    data1.close();
       s_line="";
       line="";
    index_= 0;
    fstream data2;
    data2.open("prices.txt", ios::in);
    for (int o = 0; o <= medicine_count; o++)
    {
        s_line="";
        index_= 0;
        getline(data2,line);
        //  cout<<line<<endl;
        //  system("pause");
        while (line[index_] != '\0')
        {
            s_line = s_line + line[index_];
            index_++;
       }
    //    cout<<s_line<<endl;
    //    system("pause");
        prices[o] = stoi(s_line);
       // cout<<"runned"<<endl;
       // system("pause");
    }
    data2.close();
         s_line="";
         line="";
    index_= 0;
    fstream data3;
    data3.open("discount.txt", ios::in);
    getline(data3, line);
    s_line="";
    while(line[index_] != ',')
  {
        s_line = s_line + line[index_];
        index_++;
    }
    discount_c = stoi(s_line);
    s_line="";
    index_++;
    while (line[index_] != '\0')
    {
        s_line = s_line + line[index_];
        index_++;
    }
    dis = stoi(s_line);
    data3.close();
    s_line="";
}
