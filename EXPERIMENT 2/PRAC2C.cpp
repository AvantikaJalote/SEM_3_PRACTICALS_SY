#include<iostream>
using namespace std;

float MinMarks(float *arr,float size) //funcion to find minimum marks
{
    float min=101; //total marks is 100, so min set to 100+1=101
    for(float i=0; i<size; i++)
    {
        if(*arr<min) //accesses the data value stored in arr; * (dereference operator) operator accesses the data stored in address of arr
        {
            min=*arr; //assigns the value to min
        }
        arr++; //this will take us to address of the next element in arr array i.e increment the address by 1 unit(here it is float data type)
    }
    return min;
}

float MaxMarks(float *arr, float size) //function to find maximum marks
{
    float max=-1; //since marks can't be negative, the max is set to -1 i.e people will score more than -1
    for(float i=0; i<size; i++)
    {
        if(*arr>max) //accesses the data value stored in arr
        {
            max=*arr; //assigns the value to max
        }
        arr++; //this will take us to address of the next element in arr array i.e increment the address by 1 unit(here it is float data type)
    }
    return max;
}

int main()
{
    float marks[50]; //array to store the marks
    int size; // to store the number of enteries needed 
    cout<<"\nEnter the number of students(not more than 50): ";
    cin>>size;
    cout<<"\nEnter the marks(not more than 100): "<<endl;
    for(int k=0; k<size; k++) //inputs the data in the array
    {
        cout<<"\nEnter marks of student "<<k+1<<": ";
        cin>>marks[k];
    }
    float minimum=MinMarks(marks,size); //passes the address of marks[0] along with the number of student records created
    cout<<"\n\nMinimum marks is: "<<minimum;
    float maximum=MaxMarks(marks,size); ////passes the address of marks[0] along with the number of student records created 
    cout<<"\n\nMaximum marks is: "<<maximum;
    return 0;
}