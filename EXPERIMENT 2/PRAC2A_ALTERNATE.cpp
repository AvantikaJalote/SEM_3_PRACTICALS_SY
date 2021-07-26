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
	add(short(1),short(2)); //calls function with short data type arguements

	add(100000,100000); //calls function with int data type arguements

	add(float(2.5),float(5.5)); //calls function with float data type arguements

	add(2.00005,2.00005); //calls function with double data type arguements

	add(0.33333333333333L,0.33333333333333L); //calls function with long double data type arguements

	add(123456L,123456L); //calls function with long int data type arguements
  
    return 0;
}