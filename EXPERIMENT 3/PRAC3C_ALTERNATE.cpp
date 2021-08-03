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
    int choice; //select shape
    int cont; //takes choice if one wants to see main menu
    float length,height,radius;
    double vol;
    do
    {
        a:
        cout<<"\nMENU:";
        cout<<"\n1.Cube";
        cout<<"\n2.Sphere";
        cout<<"\n3.Cylinder";
        cout<<"\n4.Cone";
        cout<<"\nEnter choice:";
        cin>>choice;
        if(choice>4 || choice<1) //checks if menu choice entered is correct
        {
            cout<<"\nInvalid choice";
            goto a;
        }
        switch(choice)
        {
            case 1: //for cube
                    cout<<"\nEnter the length of side of the cube: ";
                    cin>>length;
                    vol=cube(length); 
                    cout<<"The volume of the cube is: "<<vol; 
                    break;
            case 2: //for radius
                    cout<<"\nEnter the radius for the sphere: ";
                    cin>>radius;
                    vol=sphere(radius); 
                    cout<<"The volume of the sphere is: "<<vol;
                    break;
            case 3: //for cylinder
                    cout<<"\nEnter radius for the cylinder: ";
                    cin>>radius;
                    cout<<"Enter height for the cylinder: ";
                    cin>>height;
                    vol=cylinder(radius,height); 
                    cout<<"The volume of the cylinder is: "<<vol;
                    break;
            case 4: //for cone
                    cout<<"\nEnter radius for the cone: ";
                    cin>>radius;
                    cout<<"Enter height for the cone: ";
                    cin>>height;
                    vol=cone(radius,height); 
                    cout<<"The volume of the cone is: "<<vol;
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


