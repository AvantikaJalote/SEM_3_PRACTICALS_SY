#include<iostream>
using namespace std;

float Average(int arr[],int students) //calculates the average and returns it to main
{
    float average=0,sum=0;
    for(int j=0; j<students; j++)
    {
        sum=sum+arr[j];
    }
    average=float(sum/students); //calculates the average
    return average; //returns average
}

int main()
{
    int students; //no of students there in the class

    cout<<"\nEnter the number of students: ";
    cin>>students;

    int *marks=new int[students]; //dynamic allocation of memory for marks array variable

    for(int i=0; i<students; i++)
    {
        cout<<"\nEnter the marks of student "<<i+1<<": "; //stores marks
        cin>>marks[i];
    }
    
    float avg=Average(marks,students);
    cout<<"\nThe average marks are: "<<avg; //average is printed in main

    delete[] marks; //deallocation of memory alloted to marks
}