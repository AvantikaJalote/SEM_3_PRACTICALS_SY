#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int records; //creating a global variable to store the number of records wanted
int stored=0; //counts the number of records created/stored

struct library
{
    char name[100];
    char author[100];
    float price;
    int copies;
    void display();

}lib[1000]; //structure definition

void input() //Defined to take the book records from the user and to store them when no records exist
{ 
    for(int i=0; i<records; i++)
    {
        stored+=1;
        cout<<"\nEnter details for book "<<i+1<<":";
        cout<<"\nEnter book name:"; 
        cin.ignore(); //used to ignore or clear one or more characters from the input buffer. Otherwise getline refuses to behave normally- skips input for book name
        cin.getline(lib[i].name,50);
        cout<<"Enter Author name:";
        cin.getline(lib[i].author,50);
        cout<<"Enter Price of book:";
        cin>>lib[i].price;
        cout<<"Enter number of copies:";
        cin>>lib[i].copies;
        cout<<endl;
    }
}

void input(int start) //Defined to take the book records from the user and to store them when we have some intial records
{
    int temp=start+records;
    for(int i=start; i<temp; i++)
    {
        stored+=1;
        cout<<"\nEnter details for book "<<i+1<<":";
        cout<<"\nEnter book name:"; 
        cin.ignore();
        cin.getline(lib[i].name,50);
        cout<<"Enter Author name:";
        cin.getline(lib[i].author,50);
        cout<<"Enter Price of book:";
        cin>>lib[i].price;
        cout<<"Enter number of copies:";
        cin>>lib[i].copies;
        cout<<endl;
    }
}

void display() //used to display the book details
{
    if(records==0)
    {
        cout<<"\nNo books available";
    }
    else
    {
        for(int j=0; j<stored; j++)
        {
            cout<<"\n\nBook: "<<j+1;
            cout<<"\nBook name: "<<lib[j].name;
            cout<<"\nAuthor name: "<<lib[j].author;
            cout<<"\nPrice of the book: "<<lib[j].price;
            cout<<"\nNumber of copies available: "<<lib[j].copies;
        }
    }
}

void SearchBookName() //used to search book name and return its name aand number of copies available
{
    int found=0;
    int i=0;
    char bookname[100];
    cout<<"\nEnter the name of the book which needs to be found:";
    cin.ignore();
    cin.getline(bookname, 100);
    while(i<1000)
    {
        if(strcmpi(lib[i].name,bookname)==0)
        {
        cout<<"\nThe book is available and number of copies available is: "<<lib[i].copies;
        found=1;
        break;
        }
        i++;
    }
    if(found==0)
    {
        cout<<"\nThe book "<<bookname<<" was not found.";
    }
 
}

void SearchByAuthor() //used to display all the books of a specific author along with number of copies available for it
{
    int i=0;
    int flag=0;
    char authorname[100];
    cout<<"\nEnter the name of the author whose books needs to be found:";
    cin.ignore();
    cin.getline(authorname, 100);
    while(i<1000)
    {
    if(strcmpi(lib[i].author,authorname)==0)
        {
        cout<<"\n\nBook "<<i+1<<" name: "<<lib[i].name;
        cout<<"\nNumber of copies available: "<<lib[i].copies;
        flag=1;
        break;
        }
        i++;
    }
    if(flag==0)
    {
        cout<<"\nThe author "<<authorname<<" was not found.";
    }
}

void SortByName() //used to sort the books in alphabetical order by their name
{
    library temp;
    for(int j=0; j<stored; j++)
    {
        for(int k=0; k<stored-j-1; k++)
        {
            if(strcmpi(lib[k].name,lib[k+1].name)>0)
            {
                temp=lib[k];
                lib[k]=lib[k+1];
                lib[k+1]=temp;
            }
        }
    }
    
}

int main()
{
    int cont=1; //var to check if user wants to see the main menu again
    int choice; //takes user choice for menu driving
    do
    {
        b: //label to display menu again if the choice entered by the user is invalid
        cout<<"\nMenu:";
        cout<<"\n1. Enter book details";
        cout<<"\n2. Display books available";
        cout<<"\n3. Search for availability of a specific book";
        cout<<"\n4. Search for an author and his books";
        cout<<"\n5. Sort book list by name";
        cout<<"\n\nEnter your choice:";
        cin>>choice; 
        if(choice>6 || choice<1) //checks if menu choice entered is correct
        {
            cout<<"\nInvalid choice";
            goto b;
        }
        switch(choice)
        {
            case 1:
                    a: //label to check if the records wanted are within limits of number of arrays created to store them
                    cout<<"\nEnter the number of records you want to create(not more than 1000):";
                    cin>>records;
                    if(records>1000 || records<=0)
                    {
                        cout<<"This is not possible.";
                        goto a;
                    }
                    else
                    {
                        if(stored==0) //checks if initial records exist
                        {
                            input(); //calls the input function to take input
                        }
                        else
                        {
                            input(stored); //intial records exist- calls the other input function
                        }
                    }
                    break;

            case 2:
                    display();
                    break;

            case 3:
                    SearchBookName();
                    break;

            case 4:
                    SearchByAuthor();
                    break;

            case 5:
                    SortByName();
                    display();
                    break;
    }
    cout<<"\n\nDo you want to see the menu?";
    cout<<"\n1. Yes\n2. No";
    cout<<"\nEnter choice:";
    cin>>cont;
    }while(cont==1);
    return 0;

}

