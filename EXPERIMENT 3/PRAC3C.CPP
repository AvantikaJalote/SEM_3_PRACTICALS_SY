#include<iostream>
#include<math.h>
#define pi 3.14
using namespace std;

inline double cube(float length) //calculates volume for cube //inline function
{
    double vol=pow(length,3);
    return vol;
}

inline double sphere(float radius) //calculates volume for sphere //inline function
{
    double vol=(4*pi*(pow(radius,3)))/3;
    return vol;
}

inline double cylinder(float radius,float height) //calculates volume for cylinder //inline function
{
    double vol=pi*height*(pow(radius,2));
    return vol;
}

inline double cone(float radius, float height) //calculates volume for cone //inline function
{
    double vol=(pi*height*(pow(radius,2)))/3;
    return vol;
}

int main()
{
    float length,height,radius;
    double vol,vol1,vol2,vol3,vol4;

    //calculates volume of cube
    cout<<"\nEnter the parameters for a Cube:"; 
    cout<<"\nEnter the length of side of the cube: ";
    cin>>length;
    vol1=cube(length); 
    cout<<"The volume of the cube is: "<<vol1<<endl; 

    //calculates volume of sphere
    cout<<"\nEnter the parameters for a Sphere:"; 
    cout<<"\nEnter the radius for the sphere: ";
    cin>>radius;
    vol2=sphere(radius); 
    cout<<"The volume of the sphere is: "<<vol2<<endl;

    //calculates volume of cylinder
    cout<<"\nEnter the parameters for a Cylinder:"; 
    cout<<"\nEnter radius for the cylinder: ";
    cin>>radius;
    cout<<"Enter height for the cylinder: ";
    cin>>height;
    vol3=cylinder(radius,height); 
    cout<<"The volume of the cylinder is: "<<vol3<<endl;

    //calculates volume of cone
    cout<<"\nEnter the parameters for a Cone:";
    cout<<"\nEnter radius for the cone: ";
    cin>>radius;
    cout<<"Enter height for the cone: ";
    cin>>height;
    vol4=cone(radius,height); 
    cout<<"The volume of the cone is: "<<vol4<<endl;

    //total volume
    vol=vol1+vol2+vol3+vol4;
    cout<<"\nThe total volume is: "<<vol;

    return 0;
}