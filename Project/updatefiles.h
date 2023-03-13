using namespace std;
void updateemployeedata(string array[10],float array1[10],int employee_count)
{
    fstream data;
    data.open("data.txt", ios::out);
    for(int x=0;x<=employee_count;x++){
        if(array[x]!="-1")
        {
            if(x>0)
            {
            data << "\n";
            }
        data << array[x]<<",";
        data<<array1[x];
    }
    }
    data.close();
}
void updatamedicinedata(string array1[10],int array2[10],string array3[10],int medicine_count)
{
    fstream data;
    data.open("data1.txt", ios::out);
    for(int x=0;x<=medicine_count;x++)
    {
        if(array1[x]!="-1")
        {
            if(x>0)
            {
                data<<'\n';
            }
        data << array1[x]<<",";
         data<<array2[x]<<",";
        data<<array3[x];
    }
    }
    data.close();
}
void updatapricedata(int prices_[10],int medicine_count)
{
    fstream data;
    data.open("prices.txt",ios::out);
    for (int x=0;x<=medicine_count;x++)
    {
        if(x>0)
        {
            data<<'\n';
        }
    data<<prices_[x];   
    }
    data.close();
}