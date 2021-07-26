#include<iostream>
using namespace std;

void add(short num1, short num2) //adds two arguements with short data type
{
    short sum=num1+num2;
    cout<<"\nThe addition of the two numbers with short datatype is: "<<sum;
}

void add(int num1, int num2) //adds two arguements with int data type
{
    int sum=num1+num2;
    cout<<"\nThe addition of the two numbers with int datatype is: "<<sum;
}

void add(float num1, float num2) //adds two arguements with float data type
{
    float sum=num1+num2;
    cout<<"\nThe addition of the two numbers with float datatype is: "<<sum;
}

void add(double num1, double num2) //adds two arguements double short data type
{
    double sum=num1+num2;
    cout<<"\nThe addition of the two numbers with double datatype is: "<<sum;
}

void add(long double num1, long double num2) //adds two arguements with long double data type
{
    long double sum=num1+num2;
    cout<<"\nThe addition of the two numbers with long double datatype is: "<<sum;
}

void add(long int num1, long int num2) //adds two arguements with long int data type
{
    long int sum=num1+num2;
    cout<<"\nThe addition of the two numbers with long int datatype is: "<<sum;
}

int main()
{
    int choice; //saves the user choice
    int cont; //takes choice if one wants to see main menu
    do
    {
        a:
        cout<<"\nMENU:";
        cout<<"\n1.Short";
        cout<<"\n2.Integer";
        cout<<"\n3.Float";
        cout<<"\n4.Double";
        cout<<"\n5.Long double";
        cout<<"\n6.Long integer";
        cout<<"\nEnter choice:";
        cin>>choice;
        if(choice>6 || choice<1) //checks if menu choice entered is correct
        {
            cout<<"\nInvalid choice";
            goto a;
        }
        switch(choice)
        {
            case 1:
                    short a,b;
                    cout<<"\nEnter value 1: ";
                    cin>>a;
                    cout<<"Enter value 2: ";
                    cin>>b;
                    add(a,b); //calls function with short data type arguements
                    break;
            case 2:
                    int c,d;
                    cout<<"\nEnter int 1: ";
                    cin>>c;
                    cout<<"Enter int 2: ";
                    cin>>d;
                    add(c,d); //calls function with int data type arguements
                    break;
            case 3:
                    float e,f;
                    cout<<"\nEnter float 1: ";
                    cin>>e;
                    cout<<"Enter float 2: ";
                    cin>>f;
                    add(e,f); //calls function with float data type arguements
                    break;
            case 4:
                    double g,h;
                    cout<<"\nEnter value 1: ";
                    cin>>g;
                    cout<<"Enter value 2: ";
                    cin>>h;
                    add(g,h); //calls function with double data type arguements
                    break;
            case 5:
                    long double i,j;
                    cout<<"\nEnter value 1: ";
                    cin>>i;
                    cout<<"Enter value 2: ";
                    cin>>j;
                    add(i,j); //calls function with long double data type arguements
                    break;
            case 6:
                    long int k,l;
                    cout<<"\nEnter long integer 1: ";
                    cin>>k;
                    cout<<"Enter long integer 2: ";
                    cin>>l;
                    add(k,l); //calls function with long int data type arguements
                    break;
            default:
                    cout<<"\nInvalid input";
                    break;
        }
    cout<<"\n\nDo you want to see the menu?";
    cout<<"\n1. Yes\n2. No";
    cout<<"\nEnter choice:";
    cin>>cont;
    }while(cont==1);
    
    return 0;
}