//Demonstrates the concept of default constructor
#include<iostream>
using namespace std;

class Employee
{
    string Name;
    string Id;
    string Department;
    float BasicSalary;
    float DA;
    float HRA;
    float TA;
    float GrossSalary;

    public:
    Employee(); //default constructor i.e accepts no parameters
    void Read(); //used to take employee information from the user
    void Display(); //Display the data
    ~Employee() //destructor
    {
        cout<<"\n\nDestructor is called";
    };
};

Employee::Employee() 
{
    cout<<"\nDefault constructor is called.";
    Name="NA";
    Id="NULL";
    Department="NA";
    BasicSalary=0;
    DA=0;
    HRA=0;
    TA=0;
    GrossSalary=0;
}

void Employee::Read()
{
    cout<<"\n\nEnter name: ";
    getline(cin,Name);
    cout<<"Enter Id: ";
    getline(cin,Id);
    cout<<"Enter your department: ";
    getline(cin,Department);
    cout<<"Enter Base salary: ";
    cin>>BasicSalary;
    DA=0.5*BasicSalary;
    HRA=0.3*BasicSalary;
    TA=0.1*BasicSalary;
    GrossSalary=BasicSalary+DA+HRA+TA;
}

void Employee::Display()
{
    cout<<"\n\nEmployee details are: "<<endl;
    cout<<"\nEmployee name: "<<Name;
    cout<<"\nEmployee ID: "<<Id;
    cout<<"\nEmployee department: "<<Department;
    cout<<"\nBase salary: "<<BasicSalary;
    cout<<"\nDearness allowance is: "<<DA;
    cout<<"\nHouse rent allowance is: "<<HRA;
    cout<<"\nTotal allowance is: "<<TA;
    cout<<"\nGross salary is: "<<GrossSalary;
}

int main()
{
    Employee emp; //calls default constructor

    emp.Display(); //this display will help us to see the default values of data memebers of class Employee assigned by the constructor

    emp.Read(); //calls read() to take employee information
    emp.Display(); //helps to see the data stored in data members of Employee after user input

    return 0;
}