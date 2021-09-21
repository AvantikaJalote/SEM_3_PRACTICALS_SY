#include<iostream>
#include<math.h>
#include<bits/stdc++.h> //standard library to convert string to upper character
using namespace std;

class account
{
    protected:
        string cname;
        string accno;
        string type;
        float balance;

    public:

        void input(string atype) //takes input
        {
            cout<<"Enter Customer name: ";
            getline(cin,cname);
            cout<<"Enter Account Number: ";
            cin>>accno;
            type=atype;
            cout<<"Enter Account balance: ";
            cin>>balance;
        }

        void display() //displays
        {
            cout<<"\nCustomer Name: "<<cname;
            cout<<"\nAccount Number: "<<accno;
            cout<<"\nType: "<<type;
            cout<<"\nBalance: "<<balance;
        }

        void deposit() //helps to make deposit
        {
            int amount;
            cout<<"\n\nEnter the amount to be deposited: ";
            cin>>amount;
            balance=balance+amount;
            cout<<"Current balance is: "<<balance<<endl;
        }

        string return_acctype() //used to return acc type
        {
            return type;
        }

};

class sav_acct:public account
{
    float interest;

    public:

        float comp_int() //calculates compound interest
        {
            float time,rate;
            rate=7; //let the interest rate be 7%
            cout<<"\nCalculating compound interest.";
            cout<<"\nEnter the time(in years): ";
            cin>>time;
            interest=balance*(pow(1+rate/100,time))-balance; //assuming that the interest is compounded anually
            return interest;
        }

        void update_balance(float comp_int) //updates balance
        {
            balance=balance+comp_int;
            cout<<"\nThw updated balance after interest is: "<<balance<<endl;
        }

        void withdraw() //helps withdraw money in a savings acc
        {
            int amount;
            cout<<"\nEnter amount to withdrawn: ";
            cin>>amount;
            if(balance>=amount)
            {
                balance=balance-amount;
                cout<<"Amount is withdrawn. The current balance is: "<<balance<<endl;
            }
            else
            {
                cout<<"The amount cannot be withdrawn."<<endl;
            }
        }
};

class cur_acct:public account
{
    string cheque_book;
    int charge;

    public:
        void IssueChequeBook() //issues a cheque book
        {
            cout<<"\nDo you want a check book?(YES/NO):";
            cin>>cheque_book;
            transform(cheque_book.begin(), cheque_book.end(), cheque_book.begin(), ::toupper);//connvert cheque_book to upper string
            if(cheque_book=="YES")
            {
                cout<<"Check book is issued."<<endl;
            }
        }

        void min_balance() //checks for min balance
        {
            if(balance<=1000) //assuming that minimum balance of Rs.1000 is to be maintained
            {
                cout<<"\nPenality of RS.1000 is imposed."<<endl;
                charge=1000; //let the penalty imposed be Rs.1000
                balance=balance-charge;
            }
            else
            {
                cout<<"\nNo penality is imposed."<<endl;;
            }
        }

        void withdrawal() //helps withdraw money in a current acc
        {
            float amount;
            string choice;

            cout<<"\nEnter the amount to withdrawn: ";
            cin>>amount;
            if(balance>=amount)
            {
                float temp=balance-amount;
                if(temp>=1000) //checks the minimum balance condition
                {
                    balance=temp;
                    cout<<"\nAn amount of "<<amount<<" is withdrawn.";
                    cout<<"\nCurrent balance is: "<<balance<<endl;
                }
                else
                {
                    cout<<"\\nIf you withdraw "<<amount<<", your minimum balance will go below 1000 which will lead to a fine.";
                    cout<<"\nDo you still want to debit the amount?(YES/NO): ";
                    cin>>choice;
                    transform(choice.begin(), choice.end(), choice.begin(), ::toupper);//connvert choice to upper string
                    if(choice=="YES")
                    {
                        balance=temp-1000; //1000 is the fine
                        cout<<"\nAn amount of "<<amount<<" is withdrawn."<<endl;;
                        cout<<"\nCurrent balance is: "<<balance;
                        
                    }
                }
            }
            else
            {
                cout<<"\nThe amount cannot be withdrawn";
            }
        }
};

int main()
{
    sav_acct s[10];
    cur_acct c[10];
    int count1=0,count2=0; //keeps count of number of records created for saavings acc and current acc respectively
    string acc_type; //stores the account type
    int records; //no of accounts to be created

    cout<<"Enter the number of records to be created(max 10): ";
    cin>>records;

    for(int i=0; i<records; i++)
    {
        cout<<"\nEnter account type(Savings/Current): ";
        cin.ignore();
        getline(cin,acc_type);
        cout<<endl;
        transform(acc_type.begin(), acc_type.end(), acc_type.begin(), ::toupper);//connvert acc_type to upper string

        if(acc_type=="SAVINGS") //account type is savings and calls unctions associated with it
        {
            s[count1].input(acc_type);
            s[count1].display();
            s[count1].deposit();
            float comp_interest=s[count1].comp_int();
            cout<<"The compound interest is: "<<comp_interest<<endl;
            s[count1].update_balance(comp_interest);
            s[count1].withdraw();
            s[count1].display();
            cout<<endl;
            count1++;
        }
        else //account type is current and calls unctions associated with it
        {
            c[count2].input(acc_type);
            c[count2].display();
            c[count2].deposit();
            c[count2].IssueChequeBook();
            cout<<"\nChecking for minimum balance.";
            c[count2].min_balance();
            c[count2].withdrawal();
            c[count2].display();
            cout<<endl;
            count2++;
        }

    }
    
    return 0;
}
