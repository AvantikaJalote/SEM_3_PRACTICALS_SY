//The concept identified is that of FRIEND FUNCTION (Global friend function)

#include<iostream>
using namespace std;

class TEE; //forward declaration of class TEE

class ICA
{
    private:
    float Math;
    float OOP;
    float SE;
    float DS;

    public:
    void Input_ICA();
    friend void Result(ICA, TEE); //global friend function- can access even the priv data emebers of ICA and TEE classes
};

void ICA::Input_ICA() //takes input for ICA class
{
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
}

class TEE
{
    private:
    float Math;
    float OOP;
    float SE;
    float DS;

    public:
    void Input_IEE();
    friend void Result(ICA, TEE); //global friend function- can access even the priv data mebers of ICA and TEE classes
};

void TEE::Input_IEE() //takes input for ICA class
{
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
}


void Result(ICA marks1, TEE marks2) //global friend function- can access even the priv data mebers of ICA and TEE classes
{
    float T_Math= marks1.Math + marks2.Math;
    float T_OOP= marks1.OOP + marks2.OOP;
    float T_SE= marks1.SE + marks2.SE;
    float T_DS= marks1.DS + marks2.DS;

    cout<<"\n\n\tRESULT:"<<endl;
    cout<<"\nICA and TEE marks(out of 50 each):";
    cout<<"\n\nMath:\nICA: "<<marks1.Math<<"\nTEE: "<<marks2.Math;
    cout<<"\n\nObject Oriented Programming(OOP):\nICA: "<<marks1.OOP<<"\nTEE: "<<marks2.OOP;
    cout<<"\n\nSoftware Engineering(SE):\nICA: "<<marks1.SE<<"\nTEE: "<<marks2.SE;
    cout<<"\n\nData Structure(DS):\nICA: "<<marks1.DS<<"\nTEE: "<<marks2.DS;
    cout<<"\n\nTotal marks:";
    cout<<"\nTotal marks for Math: "<<T_Math;
    cout<<"\nTotal marks for Object Oriented Programming(OOP): "<<T_OOP;
    cout<<"\nTotal marks for Software Engineering(SE): "<<T_SE;
    cout<<"\nTotal marks for Data Structure(DS): "<<T_DS;
}

int main()
{
    ICA obj1;
    TEE obj2;

    obj1.Input_ICA();
    obj2.Input_IEE();

    Result(obj1,obj2);
    
    return 0;
}
