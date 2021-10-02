#include<iostream>
using namespace std;

class BankAccount //main base class
{
    protected:
        string name;
        string address;
        int age;
        int acc_no;
        float balance;

    public:

        void OpenAccount() //to open user account
        {
            cout<<"Enter name: ";
            getline(cin,name);
            cout<<"Enter your address: ";
            getline(cin,address);
            cout<<"Enter age: ";
            cin>>age;
            cout<<"Enter Account number: ";
            cin>>acc_no;
            cout<<"Enter Intial Account balance: ";
            cin>>balance;
        };

        void Withdraw() //used to withdraw money
        {
            float amount;
            cout<<"\nEnter amount to withdrawn: ";
            cin>>amount;
            if(balance>=amount)
            {
                balance=balance-amount;
                cout<<"Amount is withdrawn. The current balance is: "<<balance;
            }
            else
            {
                cout<<"The amount cannot be withdrawn because of insufficient funds.";
            }
        };

        void Deposit() //used to deposit money in the account
        {
            int amount;
            cout<<"\n\nEnter the amount to be deposited: ";
            cin>>amount;
            balance=balance+amount;
            cout<<"Current balance is: "<<balance<<endl;
        };

        void Display()
        {
            cout<<"\nCustomer Name: "<<name;
            cout<<"\nCustomer Address: "<<address;
            cout<<"\nCustomer Age: "<<age;
            cout<<"\nSavings Account Number: "<<acc_no;
            cout<<"\nBalance: "<<balance;
        };
};

class LifeInsurance: virtual public BankAccount //inherets base class virtually so that its derived class will not have multiple copied of data members/functions
{
    protected:
    int lpolicy_no;
    float sum_assured;
    float lpremium;
    float term;

    public:

        void ReadLData() //read data for life insurance
        {
            cout<<"\nFor Life insurance";
            cout<<"\nEnter policy number: ";
            cin>>lpolicy_no;
            cout<<"Enter number of terms: ";
            cin>>term;
            cout<<"Enter the value for your insurance(in lacs): ";
            cin>>sum_assured;
        };

        void CalculateLifePremium() //to calculate the premium
        {
            if(age<=25)
            {
                lpremium=3000*sum_assured*term; //as it's 'x',000 per lac per term(year)
            }
            else if(age>=26 && age<=45)
            {
                lpremium=4000*sum_assured*term;
            }
            else if(age>=46 && age<=60)
            {
                lpremium=5000*sum_assured*term;
            }
            else
            {
                lpremium=0;
            }
        };

        void DeductLPremium() //final  balance after premium is deducted
        {
            balance=balance-lpremium;
        };

        void DisplayLifeInfo() //display life insurance details
        {
            cout<<"\nLife Insurance Policy No: "<<lpolicy_no;
            cout<<"\nSum assured: "<<sum_assured<<" lacs";
            cout<<"\nPremium to be paid: "<<lpremium;
            cout<<"\nBalance after the premium is paid: "<<balance;
            cout<<"\nTerm: "<<term<<endl;
        };
};

class CarInsurance:virtual public BankAccount //inherets base class virtually so that its derived class will not have multiple copied of data members/functions
{
    protected:
    int cpolicy_no;
    float car_details;
    float cpremium;
    float duration;

    public:

        void ReadCData() //read car insurance data
        {
            cout<<"\nFor Car insurance";
            cout<<"\nEnter policy number: ";
            cin>>cpolicy_no;
            cin.ignore();
            cout<<"Enter car details(age of car): ";
            cin>>car_details;
            cout<<"Enter duration: ";
            cin>>duration;
        };

        void CalculateCarPremium() //calculate preium for car
        {
            if(car_details<2)
            {
                cpremium=5000*8*duration; //calculates the premium for the years entered by user  //sum assurred is 8L
            }
            if(car_details>=2 && car_details<5)
            {
                cpremium=3000*8*duration;
            }
            else if (car_details>=5 && car_details<8)
            {
                cpremium=2000*8*duration;
            }
            else
            {
                cpremium=0;
            }
        };

        void DeductCPremium() //final balance of premium is paid
        {
            balance=balance-cpremium;
        };

        void DisplayCarInfo() //displays car insurance info
        {
            cout<<"\nCar Insurance Policy No: "<<cpolicy_no;
            cout<<"\nCar details: "<<car_details;
            cout<<"\nPremium to be paid: "<<cpremium;
            cout<<"\nBalance after the premium is paid: "<<balance;
            cout<<"\nDuration: "<<duration<<endl;
        };
};

class Claim:public LifeInsurance,public CarInsurance //inherets the two classes publicly
{
    public:

        float settle;
        float years;
        void settlement()
        {
            int choice;
            cout<<"\nClaim insurance for: ";
            cout<<"\n1.Life insurance";
            cout<<"\n2.Car insurance";
            cout<<"\nEnter your choice:";
            cin>>choice;
            switch(choice)
            {
                case 1: //for life insurance
                    cout<<"\nEnter the time when you need to close: ";
                    cin>>years;
                    if(years<6)
                    {
                        settle=0;
                    }
                    else if(years>5 && years<13)
                    {
                        settle=0.25*sum_assured*100000; //sum assured is in lacs
                    }
                    else if(years>12 && years<21)
                    {
                        settle=((0.50*sum_assured*100000)+(0.20*sum_assured*100000));
                    }
                    else
                    {
                        settle=2*sum_assured*100000;
                    }
                break;

                case 2: //for car insurance
                    cout<<"\nEnter the amount spent on repairing the car: ";
                    cin>>settle;
                break;
            }
        }

        void SettleDeposit()
        {
            balance=balance+settle;
        }

        void ClaimView()
        {
            cout<<endl;
            Display();
        }
};

int main()
{
    Claim c; //object of the derived class

    //calling the base class functions
    c.OpenAccount();
    c.Withdraw();
    c.Deposit();

    //we need to call all functions associated with life insurance
    c.ReadLData();
    c.CalculateLifePremium();
    c.DeductLPremium();
    c.DisplayLifeInfo();

    //calling all functions associated with car insurance
    c.ReadCData();
    c.CalculateCarPremium();
    c.DeductCPremium();
    c.DisplayCarInfo();

    //calling functions for insurance settlement
    c.settlement();
    c.SettleDeposit();
    c.ClaimView();
}