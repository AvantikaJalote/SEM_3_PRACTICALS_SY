#include<iostream>
using namespace std;

int main()
{
    int *inch=new int; //dynamic allocation of inches variable
    float *yards=new float; //dynamic allocation of yards variable
    int *feet=new int; //dynamic allocation of yards variable
    int *inches=new int; //dynamic allocation of yards variable

    cout<<"\nEnter the value in inches: ";
    cin>>*inch; //stores user input in inches

    *yards=float(*inch)/36;
    cout<<"\nThe value in yards is: "<<*yards<<" yards"<<endl;

    *feet=int(*inch/12);
    *inches=*inch%12;
    cout<<"\nThe value in feet and inches is: "<<*feet<<"ft "<<*inches<<"in";

    delete inch; //deleteing the dynamiclly alloted variable inch
    delete inches; //deleteing the dynamiclly alloted variable inches
    delete feet; //deleteing the dynamiclly alloted variable feet
    delete yards; //deleteing the dynamiclly alloted variable yards
    return 0;
}