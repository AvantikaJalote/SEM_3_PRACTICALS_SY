#include<iostream>
#include<tuple> //for using tuple and tie
using namespace std;

class External1; //forward declaration of class External1

class Internal1
{
    private:
    float Math;
    float OOP;
    float SE;
    float DS;

    public:
    Internal1(float,float,float,float); //constructor to initialise the variables
    tuple<float,float,float,float> operator+(External1 &); //operator overloading of "+". Along with this, it's also a friend function. Return type is tuple
};
    

Internal1::Internal1(float a,float b,float c,float d) //takes input for Internal1 class
{
    Math=a;  
    OOP=b;
    SE=c;
    DS=d;
}

class External1
{
    private:
    float Math;
    float OOP;
    float SE;
    float DS;

    public:
    External1(float,float,float,float); //constructor to initialise the variables
    friend tuple<float,float,float,float> Internal1::operator+(External1 &); //operator overloaded friend function
};

External1::External1(float a,float b,float c,float d) //takes input for External1 class
{
    Math=a;  
    OOP=b;
    SE=c;
    DS=d;
}


tuple<float,float,float,float> Internal1::operator+(External1 &marks) //operator overloaded friend function
{
    float T_Math=Math + marks.Math;
    float T_OOP=OOP + marks.OOP;
    float T_SE=SE + marks.SE;
    float T_DS=DS + marks.DS;

    return {T_Math,T_OOP,T_SE,T_DS}; //returning a tuple
}

void TotalMarks(float T_Math,float T_OOP,float T_SE,float T_DS) //displays total marks subject wise
{
    cout<<"\n\nTotal marks subjectwise:\n";
    cout<<"\nTotal marks for Math: "<<T_Math;
    cout<<"\nTotal marks for Object Oriented Programming(OOP): "<<T_OOP;
    cout<<"\nTotal marks for Software Engineering(SE): "<<T_SE;
    cout<<"\nTotal marks for Data Structure(DS): "<<T_DS<<endl;
}

int CheckResult(float T_Math,float T_OOP,float T_SE,float T_DS) //sees if a student has failed a subject
{
    int flag=0; //checks if student has passed or not

    if(T_Math<50)
    {
        cout<<"\nThe student has failed Math";
        flag=1;
    }
    if(T_OOP<50)
    {
        cout<<"\nThe student has failed Object Oriented Programming(OOP)";
        flag=1;
    }
    if(T_SE<50)
    {
        cout<<"\nThe student has failed Software Engineering(SE)";
        flag=1;
    }
    if (T_DS<50)
    {
        cout<<"\nThe student has failed Data Structures(DS)";
        flag=1;
    }
    if(flag==0)
    {
        cout<<"\nStudent has passed all subjects";
    }
    return flag;
}

int main()
{
    float Math,OOP,SE,DS;
    float T_Math,T_OOP,T_SE,T_DS;
    int flag =0;

    cout<<"\n\tEnter marks for ICA"<<endl;
    cout<<"\nAll marks are out of 50"<<endl;
    cout<<"\nMarks for Math: ";
    cin>>Math;
    cout<<"Marks for Object Oriented Programming(OOP): ";
    cin>>OOP;
    cout<<"Marks for Software Engineering(SE): ";
    cin>>SE;
    cout<<"Marks for Data Structure(DS): ";
    cin>>DS;
    Internal1 obj1(Math,OOP,SE,DS);

    cout<<"\n\tEnter marks for TEE"<<endl;
    cout<<"\nAll marks are out of 50"<<endl;
    cout<<"\nMarks for Math: ";
    cin>>Math;
    cout<<"Marks for Object Oriented Programming(OOP): ";
    cin>>OOP;
    cout<<"Marks for Software Engineering(SE): ";
    cin>>SE;
    cout<<"Marks for Data Structure(DS): ";
    cin>>DS;
    External1 obj2(Math,OOP,SE,DS);

    tie(T_Math,T_OOP,T_SE,T_DS)=obj1+obj2; //unpack tuple objects

    TotalMarks(T_Math,T_OOP,T_SE,T_DS); //displays total marks subject wise

    flag=CheckResult(T_Math,T_OOP,T_SE,T_DS); //sees if a student has failed a subject

    float total=T_Math+T_OOP+T_SE+T_DS;
    cout<<"\n\nTotal marks(out of 400): "<<total; //gives the total marks

    if(flag==0) //used to calculate the percentage
    {
        cout<<"\n\nPerecentage is: "<<total/4;
    }
    else
    {
        cout<<"\n\nPercentage is not applicable";
    }

    return 0;
}