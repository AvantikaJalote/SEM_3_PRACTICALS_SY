#include<iostream>
#include<string.h>
using namespace std;

int flag=0; //used to check for invalid customer type

class consumer
{
    char Cname[50];
    long int Cnumber;
    char Ctype[15];
    long int CMR;
    long int LMR;
    char billmonth[10];
    long int amount;

    public:
    void ReadData();
    void CalculateBill(consumer &);
    void PrintBill(consumer);
};

void consumer::ReadData() //used to read user data
{
    cout<<"\nEnter name: ";
    cin.ignore();
    cin.getline(Cname,50);
    cout<<"Enter Consumer number: ";
    cin>>Cnumber;
    cout<<"Enter Consumer type(Commercial/Non-commercial): ";
    cin.ignore();
    cin.getline(Ctype,15);
    cout<<"Enter Current Meter Reading: ";
    cin>>CMR;
    cout<<"Enter Last Meter Reading: ";
    cin>>LMR;
    cout<<"Enter bill month: ";
    cin.ignore();
    cin.getline(billmonth,10);

}

void consumer::CalculateBill(consumer &c) //call by reference to modify the amount in the class object passed
{
    char type[]="Commercial";
    long int unit=(c.CMR-c.LMR);
    if((strcmpi(c.Ctype,type)==0)) //strcmpi compares two srings irrespective of lower/upper case letters
    {
        if(unit<=200)
        {
            c.amount=(5*unit);
        }
        else
        {
            int temp1=(unit-200); //stores the number of units consumed after the base units of 200
            c.amount=((5*200)+(10*temp1));
        }
    }
    else 
    {
        if(unit<=100)
        {
            c.amount=(3*unit);
        }
        else
        {
            int temp2=unit-100; //stores the number of units consumed after the base units of 100
            c.amount=((3*100)+(5*temp2));
        }
    }
}

void consumer::PrintBill(consumer c) //call by value as no data is to be modified
{
    cout<<"\nName: "<<c.Cname;
    cout<<"\nConsumer number: "<<c.Cnumber;
    cout<<"\nConsumer type: "<<c.Ctype;
    cout<<"\nCurrent Meter Reading: "<<c.CMR;
    cout<<"\nLast Meter Reading: "<<c.LMR;
    cout<<"\nBill month: "<<c.billmonth;
    cout<<"\nAmount to be paid: "<<c.amount;
}

int main()
{
    int cust;
    consumer cons[10]; //10 customer records

    cout<<"\nEnter the number of customers(not more than 10): ";
    cin>>cust;

    for(int i=0; i<cust; i++) //loop to take input and calculate the amount due
    {
        cout<<"\nEnter the details for consumer "<<i+1<<": ";
        cons[i].ReadData();
        cons[i].CalculateBill(cons[i]); //calculate their bill
    }

    for(int j=0; j<cust; j++) //loop to display all the consumer information
    {
        cout<<"\nCustomer "<<j+1<<": ";
        cons[j].PrintBill(cons[j]);
        cout<<endl;
    }
    return 0;
}