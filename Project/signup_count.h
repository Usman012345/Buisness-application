using namespace std;
int read_signup_count(int singup_count);
void signup_countstore(int singup_count)
{
    fstream data;
    data.open("signup_count.txt", ios::out);
    data << singup_count<<" ";
    data.close();
}
int read_signup_count(int singup_count)
{
    int y = 0;
    string line, s__line="";
    fstream data;
    data.open("signup_count.txt", ios::in);
    getline(data,line);
    while (line[y] != ' ')
    {
        s__line=s__line+line[y];
        y++;
    }
    singup_count=stoi(s__line);
    data.close();
    return singup_count;
}