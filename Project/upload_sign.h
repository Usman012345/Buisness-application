using namespace std;
void upload_sign(int a_count)
{
    string line;
    int y = 0;
    fstream data;
    data.open("signupindata.txt", ios::in);
    for (int x = 0; x < a_count; x++)
    {
        getline(data, line);
        y = 0;
        while (line[y] != ',')
        {
            username[x] = username[x] + line[y];
            y++;
        }
        y++;
        while (line[y] != ',')
        {
            password[x] = password[x] + line[y];
            y++;
        }
        y++;
        while (line[y] != '\0')
        {
            role[x] = role[x] + line[y];
            y++;
        }
    }
}