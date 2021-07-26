#include<iostream>
#include<math.h>
using namespace std;

double volume(float length) //calculates volume for cube
{
    double vol=pow(length,3);
    return vol;
}

double volume(double pi, float radius) //calculates volume for sphere
{
    double vol=(4*pi*(pow(radius,3)))/3;
    return vol;
}

double volume(float radius,float height) //calculates volume for cylinder
{
    double vol=3.14*height*(pow(radius,2));
    return vol;
}

double volume(double pi, float radius, float height) //calculates volume for cone
{
    double vol=(pi*height*(pow(radius,2)))/3;
    return vol;
}

int main()
{
    float length,height,radius;
    double vol,vol1,vol2,vol3,vol4,pi;

    cout<<"\nEnter the parameters for a Cube:"; //CUBE
    cout<<"\nEnter the length of side of the cube: ";
    cin>>length;
    vol1=volume(length); //takes one arguement with float data type
    cout<<"The volume of the cube is: "<<vol1; 

    cout<<"\n\nEnter the parameters for a Sphere:"; //SPHERE
    cout<<"\nEnter the radius for the sphere: ";
    cin>>radius;
    cout<<"Enter the value for pi: ";
    cin>>pi;
    vol2=volume(pi,radius); //takes two arguements with double and float data type resp
    cout<<"The volume of the sphere is: "<<vol2;

    cout<<"\n\nEnter the parameters for a Cylinder:"; //CYLINDER
    cout<<"\nEnter radius for the cylinder: ";
    cin>>radius;
    cout<<"Enter height for the cylinder: ";
    cin>>height;
    vol3=volume(radius,height); //takes two arguements with float data type 
    cout<<"The volume of the cylinder is: "<<vol3;

    cout<<"\n\nEnter the parameters for a Cone:"; //CONE
    cout<<"\nEnter radius for the cone: ";
    cin>>radius;
    cout<<"Enter height for the cone: ";
    cin>>height;
    cout<<"Enter the value for pi: ";
    cin>>pi;
    vol4=volume(pi,radius,height); //takes three arguements with double, float and float data type resp
    cout<<"The volume of the cone is: "<<vol4;

    vol=vol1+vol2+vol3+vol4; //calculates the total volume
    cout<<"\n\nThe total volume of all shapes is: "<<vol; //displays the total volume

    return 0;
}


