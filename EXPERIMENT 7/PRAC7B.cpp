#include<iostream>
#include<string.h>
using namespace std;

class doctor
{
    private:
    string name;
    string area;

    public:
    void input(); //takes input
    void operator<(doctor &); //operator overloading
    void display(); //displays the sorted list
};

void doctor::input()
{
    cout<<"\nEnter your name: ";
    getline(cin,name);
    cout<<"Enter your area: ";
    getline(cin,area);
}

void doctor::display()
{
    cout<<"Name of the Doctor is: "<<name;
    cout<<"\nArea: "<<area<<endl;
}

void doctor::operator<(doctor &doc)
{
    string temp1,temp2;
    if(area.compare(doc.area)<0) //returns value less than 0 if area is less than doc.area
    {
        //interchanging the area and name for the two instances passed
        temp1=doc.name;
        temp2=doc.area;
        doc.name=name;
        doc.area=area;
        name=temp1;
        area=temp2;
    }
}

int main()
{
    doctor doc[10];
    int n;
    cout<<"\nEnter the number of doctors(not more than 10): ";
    cin>>n;
    cin.ignore();

    for(int i=0; i<n; i++) //takes input
    {
        doc[i].input();
    }

    for(int i=0; i<n; i++) //bubblesort to sort the area list
    {
        for(int j=0; j<n-i-1; j++)
        {
            doc[j+1]<doc[j];
        }
    }

    cout<<endl;
    cout<<"The sorted list(by area):\n";

    for(int i=0; i<n; i++) //displays sorted output
    {
        doc[i].display();
    }

    return 0;

}