//Demonstrates the concept of constructor overloading
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
    Employee(string, string, string, int);
    void Display(); //Display the data
    ~Employee() //destructor
    {
        cout<<"\n\nDestructor is called";
    };
};

Employee::Employee() 
{
    cout<<"\nConstructor 1 is called.";
    Name="NA";
    Id="NULL";
    Department="NA";
    BasicSalary=0;
    DA=0;
    HRA=0;
    TA=0;
    GrossSalary=0;
}

Employee::Employee(string name, string id, string dep,int salary)
{
    cout<<"\nConstructor 2 is called.";
    Name=name;
    Id=id;
    Department=dep;
    BasicSalary=salary;
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
    Employee emp1; //calls default constructor
    emp1.Display();

    string Name,Id,Department;
    int BasicSalary;
    cout<<"\n\nEnter name: ";
    getline(cin,Name);
    cout<<"Enter Id: ";
    getline(cin,Id);
    cout<<"Enter your department: ";
    getline(cin,Department);
    cout<<"Enter Base salary: ";
    cin>>BasicSalary;
    Employee emp2(Name,Id,Department,BasicSalary); //calls constructor with parameters
    emp2.Display();

    return 0;
}