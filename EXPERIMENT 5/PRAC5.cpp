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
    Employee(); //default constructor
    Employee(string, string, string, int); //Parameterised Constructor
    Employee(Employee &emp); //copy constructor
    Employee(string, string, string, int, int); //dynamic constructor
    void Display(); //Display the data
    ~Employee() //destructor
    {
        cout<<"\n\nDestructor is called";
        delete GrossSalary;
    }
};

Employee::Employee() //DEFAULT CONSTRUCTOR-initailises all class data members to 0 or null value
{
    cout<<"\n\nDEFAULT CONSTRUCTOR is called.";
    Name="No Name";
    Id="NULL";
    Department="NA";
    BasicSalary=0;
    DA=0;
    HRA=0;
    TA=0;
    GrossSalary=new float;
    *GrossSalary=0;
}

Employee::Employee(string name, string id, string dep,int salary) //PARAMETERISED CONSTRUCTOR
{
    cout<<"\n\nPARAMETERISED CONSTRUCTOR is called.";
    Name=name;
    Id=id;
    Department=dep;
    BasicSalary=salary;
    DA=0.5*BasicSalary;
    HRA=0.3*BasicSalary;
    TA=0.1*BasicSalary;
    GrossSalary=new float;
    *GrossSalary=BasicSalary+DA+HRA+TA;
}

Employee::Employee(Employee &emp) //COPY CONSTRUCTOR
{
    cout<<"\n\nCOPY CONSTRUCTOR is called";
    Name=emp.Name;
    Id=emp.Id;
    Department=emp.Department;
    BasicSalary=emp.BasicSalary;
    DA=emp.DA;
    HRA=emp.HRA;
    TA=emp.TA;
    GrossSalary=emp.GrossSalary;
};

Employee::Employee(string name, string id, string dep,int salary,int size) //DYNAMIC CONSTRUCTOR
{
    cout<<"\n\nDYNAMIC CONSTRUCTOR is called."; 
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
    Employee Emp1; //default constructor
    cout<<"\n\nDetails of Employee 1:";
    Emp1.Display();

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

    Employee Emp2(Name,Id,Department,BasicSalary); //calls constructor with parameters
    cout<<"\n\nDetails of Employee 2:";
    Emp2.Display();

    Employee Emp3=Emp2; //copy constructor
    cout<<"\n\nDetails of Employee 3:";
    Emp3.Display();

    Employee Emp4(Name,Id,Department,BasicSalary,5); //calls dynamic constructor
    cout<<"\n\nDetails of Employee 4:";
    Emp4.Display();

    return 0;
}
