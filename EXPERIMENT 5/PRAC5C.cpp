//Demonstrates the concept of Copy constructor
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
    Employee(Employee &emp); //copy constructor
    
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

Employee::Employee(Employee &emp) //copy constructor
{
    cout<<"\n\nCopy constructor is called";
    Name=emp.Name;
    Id=emp.Id;
    Department=emp.Department;
    BasicSalary=emp.BasicSalary;
    DA=emp.DA;
    HRA=emp.HRA;
    TA=emp.TA;
    GrossSalary=emp.GrossSalary;
};

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
    Employee emp1; //calls default constructor

    emp1.Read(); //calls read() to take employee information
    cout<<"\nDetails of Employee 1:";
    emp1.Display(); 

    Employee emp2=emp1; //copy constructor is called
    cout<<"\n\nDetails of Employee 2:";
    emp2.Display(); 

    return 0;
}