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
    friend void operator<(doctor &,doctor &); //operator overloading using global friend function
    void display(); //will display the sorted list
};

void doctor::input()
{
    cout<<"\nEnter your name: ";
    getline(cin,name);
    cout<<"\nEnter your area: ";
    getline(cin,area);
}

void doctor::display()
{
    cout<<"Name of the Doctor is: "<<name;
    cout<<"\nArea: "<<area<<endl;
}

void operator<(doctor &doc1, doctor &doc2) //operator overloaded function-sorts the list by area
{
    string temp1,temp2;
    if(doc1.area.compare(doc2.area)<0) //returns value less than 0 if doc1.area is less than doc2.area
    { 
        //interchanging the area and name for the two instances passed
        temp1=doc1.area;
        temp2=doc1.name;
        doc1.area=doc2.area;
        doc1.name=doc2.name;
        doc2.area=temp1;
        doc2.name=temp2;
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

    for(int i=0; i<n; i++) //bubble sort to sort the area list
    {
        for(int j=0; j<n-i-1; j++)
        {
            operator<(doc[j+1],doc[j]);
        }
    }

    cout<<endl;

    for(int i=0; i<n; i++) //displays output
    {
        doc[i].display();
    }

    return 0;

}