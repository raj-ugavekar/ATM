//Project: ATM Project using OPPS in C++
#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <string.h>
using namespace std;

class atm                        // class ATM
{
private:                         // private member variables
    int account_No;
    string name;
    int PIN;
    float balance;
    string mobile_No;

public:                          // public member functions
    // set Data function setting into private variables
    void setData(int account_No_a, string name_a, int PIN_a, float balance_a, string mobile_No_a)
    {
        account_No = account_No_a;         //assigning formal arguments to private members
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }
    // getAccountNo returns user account no.
    int getAccountNo()
    {
        return account_No;
    }
    // getName returns user name.
    string getName()
    {
        return name;
    }
    // getPIN returns user pin
    int getPIN()
    {
        return PIN;
    }
    // returns bank balance
    float getBalance()
    {
        return balance;
    }
    //  returns mobile no.
    string getMobileNo()
    {
        return mobile_No;
    }
    // updating mobile no.
    void setMobile(string mob_prev, string mob_new)
    {
        try
        {
            if(mob_prev == mobile_No)  // checks old no.
            {
                mobile_No = mob_new;    // updates new
                cout<<"Successfully Updated Mobile No. ";
                _getch();  // holds screen
            }
            else
                throw(mobile_No);
        }
        catch(string mobile_No)
        {
            cout<<endl<<"  Incorrect !!!  Old  mobile  no.";
            _getch();
        }

    }
    // cash  withdraw function
    void  cashWithDraw(int amount_a)
    {
        try
        {
            if(amount_a > 0 && amount_a < balance)   // checks  entered amount validity
            {
                balance =  balance - amount_a;
                cout<<endl<<"Please Collect Your Cash";
                cout<<endl<<"Available Balance :"<<balance;
                _getch();
            }
            else
                throw(balance);
        }
        catch(float balance)
        {
            cout<<endl<<"Invalid Input or Insufficient Balance";
            _getch();
        }
    }
};

int main()
{
    int choice=0, enterPIN;
    int enterAccountNo;
   // system("cls");
    atm user1;
    user1.setData(1234567,"Raj",1111,50000.0f,"7066800685");
    do
    {
       // system("cls");
        cout<<endl<<"\t\t**********WELCOME TO ATM**********"<<endl;
        cout<<endl<<"Enter Your Account No :";
        cin>>enterAccountNo;
        cout<<endl<<"Enter PIN :";
        cin>>enterPIN;
        if((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int  amount = 0;
                string oldMobileNo, newMobileNo;
              //  system("cls");
                cout<<endl<<"\n\t\t**********WELCOME TO ATM**********"<<endl;
                cout<<endl<<"Select Options";
                cout<<endl<<"1. Check Balance";
                cout<<endl<<"2. Cash withdraw";
                cout<<endl<<"3. show User  Details";
                cout<<endl<<"4. Update Mobile no.";
                cout<<endl<<"5. Exit"<<endl;
                cin>>choice;

                switch(choice)
                {
                case 1:
                    cout<<endl<<"Your Bank Balance  is :"<<user1.getBalance();
                    _getch();
                    break;

                case 2:
                    cout<<endl<<"Enter the amount :";
                    cin>>amount;
                    user1.cashWithDraw(amount);
                    break;

                case 3:
                    cout<<endl<<"****User Details are :";
                    cout<<endl<<"-> Account no"<<user1.getAccountNo();
                    cout<<endl<<"-> Name "<<user1.getName();
                    cout<<endl<<"-> Balance"<<user1.getBalance();
                    cout<<endl<<"-> Mobile No."<<user1.getMobileNo();
                    _getch();
                    break;

                case 4:
                    cout<<endl<<"Enter Old Mobile No.";
                    cin>>oldMobileNo;
                    cout<<endl<<"Enter New Mobile No.";
                    cin>>newMobileNo;
                    user1.setMobile(oldMobileNo, newMobileNo);
                    break;

                case 5:
                    cout<<"\n\t\tTHANK YOU FOR VISITING\n";
                    exit(0);

                default:
                    cout<<endl<<"Enter Valid Data !!!";
                }
            }
            while(1);
        }
        else
        {
            cout<<endl<<"User Details are Invalid !!!";
            _getch();
        }
    }
    while(1);
    return 0;
}
