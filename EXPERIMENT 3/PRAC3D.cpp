#include<iostream>
using namespace std;

void INPUT(char div='A', string prg="B.Tech") //Default arguements
{
    int rollno[3]; //stores 3 roll numbers (int type)
    string name[3]; //stores 3 names (string type)
    string divison[3]; //stores 3 division names (string type)
    string program[3]; //stores 3 program names (string type)

    cout<<"\nEnter the details of the students"<<endl;
    for(int i=0; i<3; i++) //for 3 records
    {
        cout<<"\nEnter details of student "<<i+1<<" :";
        cout<<"\nEnter Roll Number: ";
        cin>>rollno[i];
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin,name[i]);
        divison[i]=div;
        program[i]=prg;
    }
    cout<<"\n\nEntered data is:"<<endl;
    for(int j=0; j<3; j++)
    {
        cout<<"\nDetails of student "<<j+1<<" :";
        cout<<"\nRoll Number: "<<rollno[j];
        cout<<"\nName: "<<name[j];
        cout<<"\nDivision: "<<divison[j];
        cout<<"\nProgram: "<<program[j]<<endl;
    }
}

int main()
{
    cout<<"\nMETHOD 1:";
    INPUT(); //calls the INPUT function //default arguements are taken

    cout<<"\nMETHOD 2:";
    INPUT('B'); //'A' gets overwritten and the other arguement is the default arguement

    cout<<"\nMETHOD 3:";
    char div;
    string prgm;
    cout<<"\nEnter the division for the students: ";
    cin>>div;
    cout<<"Enter the program for the students: ";
    cin.ignore();
    getline(cin,prgm);
    INPUT(div,prgm); //default arguements get overwritten
    return 0;
}