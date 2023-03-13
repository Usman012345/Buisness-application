using namespace std;
string username[10], role[10], password[10];
string sign_in(int signup_count);
string sign_up(int signup_count)
{
    string user;
    cout << "Enter the username: ";
    cin >> user;
    bool flag = true;
    for (int c = 0; c < signup_count; c++)
    { 
        if ((username[c] == user))
        {
            flag = false;
            cout<<"Username already exists"<<endl;
            return "0";
        }
    }
    if (flag == true)
    {
        username[signup_count] = user;
    }
    cout << "Enter password: ";
    cin >> password[signup_count];
    cout << "Enter role: ";
    cin >> role[signup_count];
    // cout<<username[1]<<"  "<<password[1]<<"  "<<role[1]<<"  "<<signup_count; 
    signupindata(username, password, role,signup_count);
}
string sign_in(int signup_count)
{
    if (signup_count == 0)
    {
        cout << "You need to sign up first." << endl;
        system("pause");
        return "0";
    }
    bool exists = false;
    string user_name, pass_word, Role;
    cout << "Enter username: ";
    cin >> user_name;
    cout << "Enter password:";
    cin >> pass_word;
    int d = 0;
    for (; d < signup_count; d++)
    {
        if (user_name == username[d] && pass_word==password[d])
        {
            exists = true;
            break;
        }
        
    }
        if (exists == false)
        {
            cout << "Invalid input" << endl;
            system("pause");
            return "0";
        }

    return role[d];
}