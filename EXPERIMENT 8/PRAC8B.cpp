#include<iostream>
using namespace std;

class staff
{
    protected:
        int code;
        string name;

    public:
        void GetStaff()
        {
            cout<<"Enter staff code: ";
            cin>>code;
            cin.ignore();
            cout<<"Enter staff name: ";
            getline(cin,name);
        }

        void DisplayStaff()
        {
            cout<<"\nStaff name:"<<name;
            cout<<"\nStaff code: "<<code;
        }
};

class teacher:public staff //teacher class is the child class of staff
{
    private:
        string sub;
        string pub;

    public:
        void GetTeacher()
        {
            GetStaff();
            cout<<"Enter subject name: ";
            getline(cin,sub);
            cout<<"Enter name of publication: ";
            getline(cin,pub);
        }

        void DisplayTeacher()
        {
            DisplayStaff();
            cout<<"\nSubject name: "<<sub;
            cout<<"\nPublication: "<<pub;
        }
};

class officer:public staff //officer class is the child class of staff
{
    private:
        string grade;

    public:
        void GetOfficer()
        {
        GetStaff();
        cout<<"Enter Grade :";
        getline(cin,grade);
        }

        void DisplayOfficer()
        {
            DisplayStaff();
            cout<<"\nGrade is: "<<grade;
        }
};

class typist:public staff //typist class is the child class of staff
{
    private:
        float speed;

    public:
        void GetTypist()
        {
            GetStaff();
            cout<<"Enter typing speed(wpm): ";
            cin>>speed;
        }

        void DisplayTypist()
        {
            DisplayStaff();
            cout<<"\nTyping speed is: "<<speed;
        }
};


class casual:public typist //casual class is the child class of typist
{
    private:
        float dailywages=1000;//dailywages is pre defined

    public:
        void GetCasual()
        {
            GetTypist();
        }

        void DisplayCasual()
        {
            DisplayTypist();
            cout<<"\nDaily wages is: Rs."<<dailywages;
        }
};

class regular:public typist //regular class is the child class of typist
{
    private:
        float wage=200000; //monthly wage is also pre defined

    public:
        void GetRegular()
        {
            GetTypist();
        }

        void DisplayRegular()
        {
        DisplayTypist();
        cout<<"\nMonthly wage is: Rs. "<<wage;
        }
};

int main()
{
    //assuming that the database allows for only 5 records of each class
    teacher t[5];
    casual  c[5];
    officer o[5];
    regular r[5];
    int choice;
    int i,cont;
    int records1=0,records2=0,records3=0; //holds the intermediate teachers,officers and typists
    int count1=0,count2=0; //hold the final count for teachers,officers
    do
    {
        cout<<"\nEDUCATION INSTITUTION DATABASE\n\n";
        cout<<"MENU:\n";
        cout<<"\n1. Teachers";
        cout<<"\n2. Officer";
        cout<<"\n3. Typist";
        cout<<"\n4. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1: //for teacher
            {
                cout<<"Enter the number of teacher records to be created(not more than 5): ";
                cin>>records1;

                if(count1==0) //no records exist initially
                {
                    for(i=0;i<records1;i++)
                    {
                        cout<<endl;
                        t[i].GetTeacher();
                        count1++;
                    }
                } 
                else //some records exist
                {
                    int temp1=count1+records1;
                    for(i=count1;i<temp1;i++)
                    {
                        cout<<endl;
                        t[i].GetTeacher();
                        count1++;
                    }
                }

                for(i=0;i<count1;i++) //display
                {
                    cout<<endl;
                    cout<<"Teacher "<<i+1<<":";
                    t[i].DisplayTeacher();
                    cout<<endl;
                }
                break;
            }

            case 2:  
            {
                cout<<"Enter the number of officer records to be created(not more than 5): ";
                cin>>records2;

                if (count2==0)  //no records exist initially
                {
                    for(i=0;i<records2;i++)
                    {
                        cout<<endl;
                        o[i].GetOfficer();
                        count2++;
                    }
                }
                else //some records exist
                {
                    int temp2=count2+records2;
                    for(i=count2;i<temp2;i++)
                    {
                        cout<<endl;
                        o[i].GetOfficer();
                        count2++;
                    }
                }
                for(i=0;i<count2;i++) //display
                {
                    cout<<endl;
                    cout<<"Officer "<<i+1<<":";
                    o[i].DisplayOfficer();
                    cout<<endl;
                }
                break;
            }
            
            case 3:
            {
                //based on the assumption that once typist option is picked, it won't be picked again. No track for intermediate records are kept.
                int temp3;
                cout<<"1. Casual typist";
                cout<<"\n2. Regular typist";
                cout<<"\nEnter your choice: ";
                cin>>temp3;
                cout<<"\nEnter the number of records to be created(not more than 5): ";
                cin>>records3;

                if(temp3==1)
                {
                    for(i=0;i<records3;i++)
                    {
                        cout<<endl;
                        c[i].GetCasual();
                    }
                }
                else
                {
                    for(i=0;i<records3;i++)
                        {
                            cout<<endl;
                            r[i].GetRegular();
                        }
                }
                if (temp3==1) //checks constraint for display
                    {
                        for(i=0;i<records3;i++) //casual typist
                        {
                            cout<<endl;
                            c[i].DisplayCasual();
                            cout<<endl;
                        }
                    }
                    else
                    {
                        for(i=0;i<records3;i++) //regular typist
                        {
                            cout<<endl;
                            r[i].DisplayRegular();
                            cout<<endl;
                        }
                    }      
            break;
            }
            case 4:
                exit(0);
        }
        cout<<"\n\nDo you want to see the menu?";
        cout<<"\n1. Yes\n2. No";
        cout<<"\nEnter choice:";
        cin>>cont;
    }while(cont==1);

    return 0;
 }