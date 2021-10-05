#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;

fstream file; //file object
// define a class to store student data
class student
{
    private:
    int admission_no;
    char name[50];
    char grade[10];

    public:
    void getData(); // get student data from user
    void displayData(); // display data
    void modify(); //for modifying the grade of a student
    int GetAddNo() //returs the admission_no of the student
    {
        return admission_no;
    };
};

void student::getData() 
{
    cout<<"\nEnter Admission Number: ";
    cin>>admission_no;
    cin.ignore(); // to ignore the newline char inserted when we press enter
    cout<<"Enter Name: ";
    cin.getline(name,50);
    cout<<"Enter Grade: ";
    cin>>grade;
}

void student::displayData() 
{
    cout<<"\nAdmission Number: "<<admission_no<<endl;
    cout<<"Student name: "<<name<<endl;
    cout<<"Student Grade: "<<grade<<endl;
}

void student::modify()
{
    char ch[10];
    cout<<"Enter New Grade: ";
    cin>>ch;
    strcpy(grade,ch);
}

int create_record() //to create the binary file and add some records to it
{
    student s;
    int students,i=0;
    cout<<"\nEnter of student records to be created(not more than 10): ";
    cin>>students;
    file.open("student.dat", ios::out|ios::binary); // open file for writing. If file exits, overwrites it and if the file doesn't exist, it creates a new one

    for(i=0; i<students; i++)
    {
        if(file)
        {
            s.getData();
            // write the object to a file
            file.write((char *)&s, sizeof(s));
        }
    }
    file.close(); // close the file as it was in write mode
    return students;
}

void add_record()
{
    ofstream f("student.dat",ios::app|ios::binary);
    int choice;
    student s;
    do
    {
        s.getData();
        f.write((char*)&s,sizeof(s));
        cout<<"\nDo you want to add more records?\n1.Yes\n2.No";
        cout<<"\nEnter choice: ";
        cin>>choice;
    } while(choice==1);
    
}
void display_record() //to display the contents of the binary file
{
    student temp;
    file.open("student.dat",ios::in|ios::binary); // open file for reading

    while(!file.eof())
    {
        file.read((char*)&temp,sizeof(temp));
        if(file)
        {
            temp.displayData();
        }
    }
    file.close(); // close the file
}

void modify_record()
{
    int pos,ano,flag = 0;
    student s;
    file.open("student.dat",ios::in|ios::binary|ios::out);
    cout<<"\nEnter the admission number of the student whose record needs to be modified: ";
    cin>>ano;
    while(!file.eof()) 
    {
        pos=file.tellg(); //returns the current “get” position of the pointer in the stream
        file.read((char*)&s,sizeof(s));
        if(file) 
        {
            if(s.GetAddNo()==ano) 
            {
                flag=1;
                s.modify(); //calls the function to modify the grade of the student
                file.seekg(pos); //moves the file pointer to the beginning position of the record being modified before writing back the modified record
                file.write((char*)&s, sizeof(s));
                break;
            }
        }
    }
    file.close();
  
    if(flag==1)
        cout<<"\nrecord modified \n";
    else
        cout<<"\nrecord not found \n";
}

void delete_record() //to delete a record in the binary file
{
    int ano,flag=0; //flag is to check if the recod is found or not
    student temp;
    ifstream f1("student.dat",ios::in|ios::binary); //opens file for reading and in binary mode
    ofstream f2("teeemp.dat",ios::out|ios::binary); //opens file for writing and in binary mode
    cout<<"\nEnter the admission number of the student whose record needs to be deleted: ";
    cin>>ano;
    while(!f1.eof())
    {
        f1.read((char*)&temp,sizeof(temp));
        if(f1) //checks the buffer record in the file
        {
            if(temp.GetAddNo()==ano)
            {
                flag=1;
                cout<<"\nDeleted record is: ";
                temp.displayData();
            }
            else
            {
                f2.write((char*)&temp,sizeof(temp));
            }      
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord not found.";
    }
    f1.close();
    f2.close();
    remove("student.dat");
    rename("teeemp.dat","student.dat");
}

void search_record() //to search for a record in the binary file
{
    student temp;
    file.open("student.dat",ios::in|ios::binary); //opens file for reading and in binary mode
    int rno;
    int found=0; //checks if the record is found or not
    cout<<"\nEnter admission Number to be searched: ";
    cin>>rno;

    while(!file.eof())
    {
        file.read((char*)&temp,sizeof(temp));
        if(file) //checks the buffer record in the file
        {
            if(temp.GetAddNo()==rno)
            {
                temp.displayData();
                found=1;
                break;
            }    
        }
    }
    if(found==0) 
    {
        cout<<"\nRecord is not found";
    }
    file.close();
}

int main()
{
    int choice,students;
    a: //label for main menu
    cout<<"\n\tMENU";
    cout<<"\n\n1.Create a file";
    cout<<"\n2.Add a record";
    cout<<"\n3.Delete a record";
    cout<<"\n4.Modify a record";
    cout<<"\n5.Search for a record";
    cout<<"\n6.Display all records";
    cout<<"\n\nEnter choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            students=create_record();
            break;
        case 2:
            add_record();
            break;
        case 3:
            delete_record();
            cout<<"\nFile after record deletion: ";
            display_record();
            cout<<endl;
            break;
        case 4:
            modify_record();
            cout<<"\nFile after record modification: ";
            display_record();
            cout<<endl;
            break;
        case 5:
            search_record();
            break;
        case 6:
            display_record();
            break;
    }
    cout<<"\nDo you want to see the main menu?\n1.Yes\n2.No";
    cout<<"\nEnter choice: ";
    cin>>choice;
    if(choice==1)
    {
        goto a;
    }
    return 0;
}