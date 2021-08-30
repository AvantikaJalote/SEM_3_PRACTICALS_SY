#include<iostream>

using namespace std;

class Sales; //forward declaration of class Sales

class Employee
{
    private:
    string name;
    string Id;
    string department;
    float salary;

    public:
    friend class Sales; //This statement would make class Sales a friend class Employee i.e Sales can access the private and protected members of Employee. 
    void input(); //Take user detail
    void PrintDetails(); //Print the details
};

void Employee::input()
{
    cout<<"\nEnter Employee name: ";
    getline(cin,name);
    cout<<"\nEnter Employee Id: ";
    getline(cin,Id);
    cout<<"\nEnter Employee department: ";
    getline(cin,department);
    cout<<"\nEnter Employee salary: ";
    cin>>salary;
}

void Employee::PrintDetails()
{
    cout<<"\nEmployee details:"<<endl;
    cout<<"\nEmployee name: "<<name;
    cout<<"\nEmployee Id: "<<Id;
    cout<<"\nEmployee department: "<<department;
    cout<<"\nEmployee salary: "<<salary;
}

class Sales
{
    private:
    int sale;
    float incentive;

    public:
    void read(Employee &); //accesses data memeber of the Employee class
    void Display();
    void perform(); //New function added to assess employee performance
};

void Sales::read(Employee &emp)
{
    cout<<"\nEnter monthly sales: ";
    cin>>sale;
    if(sale>150)
    {
        incentive=(0.3*emp.salary);
    }
    else if((sale>=100) && (sale<=150))
    {
        incentive=(0.2*emp.salary);
    } 
    else if((sale>=50) && (sale<100))
    {
        incentive=(0.1*emp.salary);
    }
    else
    {
        incentive=0;
    }
}

void Sales::Display()
{
    cout<<"\nMonthly sales: "<<sale;
    cout<<"\nIncentives: "<<incentive;
}

void Sales::perform() //displays the Employee performance
{
   if(sale>150)
    {
        cout<<"\nYour monthly performance was Excellent";
    }
    else if((sale>100) && (sale<=150))
    {
        cout<<"\nYour monthly performance was Good";
    }
    else if((sale<=100) && (sale>=50))
    {
        cout<<"\nYour monthly performance was Satisfactory";
    }
    else
    {
        cout<<"\nYour monthly performance was Poor";
    }
}


int main()
{
    Employee emp;
    Sales sale;

    emp.input();
    sale.read(emp); //object of Employee class is passed to obj of sales class- friend class
    emp.PrintDetails(); //prints details of emp obj
    sale.Display();//prints details of sale obj
    sale.perform();

    return 0;
}