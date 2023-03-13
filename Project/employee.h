using namespace std;
int employee_(HANDLE hConsole)
{
    string name_of_medicine;
    while(true)
    {
        top:
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
  SetConsoleTextAttribute(hConsole, 1);
    int option,quantity_,no,price_;
    string name_att,medicine_;
    cout<<"Main menu<<sign in/up<<employee menu<<Prepare bill"<<endl;
    cout<<"1.Mark attendance.."<<endl;
    cout<<"2.Prepare bill.."<<endl;
    cout<<"3.Check medinine record.."<<endl;
    cout<<"4.Request new medicine.."<<endl;
    cout<<"5.Edit prices"<<endl;
    cout<<"0.exit"<<endl;
    cin>>option;
    if(option==1)
    {
        bool exists_or_not=false;
        cout << "Main menu<<Sign in/up<<employee menu<<Mark attendance " << endl;
        cout<<"Enter name: ";
        cin>>name_att;
        for(int x=0;x<employee_count;x++)
        {
            if(name_att==employee[x])
            {
                attendance[x]++;
                exists_or_not=true;
                updateemployeedata(employee,attendance,employee_count);
                break;
            }
        }
            if(exists_or_not==false) 
            {
                cout<<"Register employee first"<<endl;
                break;
            }
        system("pause");
    }
    if(option==2)
    {
        bool exists_or_not=false;
        go:
        hop:
        int payable_amount=0;
        cout << "Main menu<<Sign in/up<<employee menu<<prepare bill " << endl;
        cout<<"Enter number of medicine: ";
        cin>>no;
        if(no>(medicine_count+1))
        {
            cout<<"only" <<medicine_count+1<<"medicine are avaliable";
            system("pause");
            goto top;
        }
        for(int x=0;x<no;x++)
        {
            exists_or_not=false;
            cout<<"Enter the name of medicine: ";
        cin>>medicine_;
        cout<<"quantity: ";
        cin>>quantity_;
        for(int h=0;h<=medicine_count; h++)
        {
        if(medicine_==medicine[h])
        {
            if(quantity_>quantity[h])
            {
                cout<<"quantity too low";
                system("pause");
                goto go;
            }
            price_=prices[h]*quantity_;
            quantity[h]=quantity[h]-quantity_;
            updatamedicinedata(medicine,quantity,expirary,medicine_count);
               payable_amount=payable_amount+price_;
               exists_or_not=true;
               h++;
        break;
        }
        }
        if(exists_or_not==false) 
        {
        cout<<"Invalid input";
        system("pause");
        goto hop;

        }
        }
        if(payable_amount>=discount_c)
        {
            float discount__;
               discount__ = (dis)*payable_amount/100;
            cout<<"Original amount: "<<payable_amount<<endl ;
            payable_amount=payable_amount-discount__;
        }   
    cout<<"Payable amount: "<<payable_amount<<endl;
    system("pause");
    }
    if(option==3)
    {
        cout << "Main menu<<Sign in/up<<employee menu<<medicine record " << endl;
        for(int x=0;x<=medicine_count;x++)
        {
            if(medicine[x]!="-1")
            cout<<medicine[x] <<"     "<<quantity[x]<<"          "<<prices[x]<<"         "<<expirary[x]<<endl;           
        }
        system("pause");
    }
    if(option==4)
    {
        cout << "Main menu<<Sign in/up<<employee menu<<request medicine " << endl;
        bool if_it_exists=false;
        cout<<"Enter name of medicine..";
        cin>>name_of_medicine;
        for(int j=0;j<=medicine_count;j++)
        {
            if(name_of_medicine==medicine[j])
            {
                cout<<"Medicine already exists"<<endl;
                system("pause");
                if_it_exists=true;
                break;
            }
        }
        if(if_it_exists==false && medicine_count<10)
        {
            medicine[medicine_count+1]=name_of_medicine;
        }
        else 
        cout<<"Medicine already exists or the store is full";
    }
     if (option == 5)
        {
            int new_price=0;
            cout << "Main menu<<Sign in/up<<employee menu<<Edit prices " << endl;
            cout << "Enter medicine name: ";
            cin >> price_name;
            bool check_x=false;
            for (int x = 0; x <= medicine_count; x++)
            {
                if (price_name == medicine[x])
                {
                    cout << "Enter new price: ";
                    cin >> new_price;
                    prices[x]=new_price;
                    check_x=true;
                    system("pause");
                    break;

                }
            }
                if(check_x==false)
                { 
                cout<<"Register medicine first:"<<endl;
                system("pause");
                }
            updatapricedata(prices,medicine_count);
        }
    if(option==0)
    {
        return 0;
    }
    else if(option!=1 && option!=2 && option!=3 &&option!=4 &&option!=5 && option!=0)
    {
        cout<<"Wrong input!!!";
        system("pause");
        goto jump;
    }
}
}