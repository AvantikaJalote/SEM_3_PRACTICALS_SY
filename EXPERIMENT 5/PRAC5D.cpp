//Demonstrates the concept of dynamic constructor
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
    float *GrossSalary;

    public:
    Employee(string, string, string, int, int); //dynamic constructor
    void Display(); //Display the data
    ~Employee() //destructor
    {
        cout<<"\n\nDestructor is called";
        delete GrossSalary;
    };
};

Employee::Employee(string name, string id, string dep,int salary,int size)
{
    cout<<"\nDynamic constructor is called.";
    Name=name;
    Id=id;
    Department=dep;
    BasicSalary=salary;
    DA=0.5*BasicSalary;
    HRA=0.3*BasicSalary;
    TA=0.1*BasicSalary;
    GrossSalary=new float(size); //dynamic allocation of memory
    *GrossSalary=BasicSalary+DA+HRA+TA;
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
    cout<<"\nGross salary is: "<<*GrossSalary;
}

int main()
{
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
    Employee emp(Name,Id,Department,BasicSalary,5); //calls dynamic constructor 
    emp.Display();

    return 0;
}