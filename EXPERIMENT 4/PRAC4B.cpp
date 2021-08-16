#include<iostream>
#include<string.h>
using namespace std;
int records=0; //global variable stores the number of records that hold the conditon of battavg>30 and bowling avg <25 true

class player
{
    private:
    char name[40];
    char region[20];
    float BattingAvg;
    float BowlingAvg;

    public:
    void ReadData(); //to input player data
    void GenerateList(char [10][40],player,float [10],float [10]); //to create all rounder player list
};


void player::ReadData()
{
    cout<<"\nEnter the name of the player: ";
    cin.ignore();
    cin.getline(name,40); //used to ignore or clear one or more characters from the input buffer. Otherwise getline refuses to behave normally- skips input for player name
    cout<<"Enter the name of the region: ";
    cin.ignore();
    cin.getline(region,40);
    cout<<"Enter the batting average: ";
    cin>>BattingAvg;
    cout<<"Enter the bowling average: ";
    cin>>BowlingAvg;
}

void player::GenerateList(char c[10][40], player p, float bat[10],float bowl[10])
{

    if(((p.BattingAvg>30) && (p.BowlingAvg<25)))
    {
        strcpy(c[records],p.name); //generates list for player name
        bat[records]=p.BattingAvg; //generates list for player batting scores
        bowl[records]=p.BowlingAvg; //generates list for player bowling scores
        records++;
    }
}

void SortBatList(char batavg[10][40],float bat[10]) //sorts all rounder player by batting average
{
    int i,j,temp1,size; 
    char temp2[40]; 
    size=records;
    for(i=0; i<size-1; i++) //bubble sort to sort the player names acc to batting average
    {
        for (j=0; j<size-i-1; j++)  
        {
            if (bat[j]>bat[j+1])
            {
                temp1=bat[j];
                strcpy(temp2,batavg[j]);
                bat[j]=bat[j+1];
                strcpy(batavg[j],batavg[j+1]);
                bat[j+1]=temp1;
                strcpy(batavg[j+1],temp2);
            }
        }
    }  
}

void SortBowlList(char bowlavg[10][40],float bowl[10]) //sorts all rounder player by bowling average
{
    int i,j,temp1,size; 
    char temp2[40]; //temporary store the player name
    size=records; //no of all rounder players
    for(i=0; i<size-1; i++) //bubble sort to sort the player names acc to batting average
    {
        for (j=0; j<size-i-1; j++)  
        {
            if (bowl[j]>bowl[j+1])
            {
                temp1=bowl[j];
                strcpy(temp2,bowlavg[j]);
                bowl[j]=bowl[j+1];
                strcpy(bowlavg[j],bowlavg[j+1]);
                bowl[j+1]=temp1;
                strcpy(bowlavg[j+1],temp2);
            }
        }
    }  
}

void Display(char avg[10][40],int n) //used to display
{
    for(int i=0; i<n; i++)
    {
        cout<<"Player "<<i+1<<": "<<avg[i]<<endl;
    }
}

int main()
{
    player play[10]; //allows for 10  player records
    int no; //stores the number of player
    char c[10][40],BattingAvg[10][40],BowlingAvg[10][40];//stores name of all rounder players,sorted acc to batting avg,orted accto batting avg resp
    float bat[10],bowl[10];

    cout<<"\nEnter the number of players(not more than 10): ";
    cin>>no;

    for(int i=0; i<no; i++)
    {
        cout<<endl;
        cout<<"Player "<<i+1<<":";
        play[i].ReadData();
        play[i].GenerateList(c,play[i],bat,bowl);
        strcpy(BattingAvg[i],c[i]); //creates list to sort players by batting avg
        strcpy(BowlingAvg[i],c[i]); //creates list to sort players by bowling avg
    }

    for(int j=0; j<records; j++) //to generate duplicate copies of list having the names of all rounder players
    {
        strcpy(BattingAvg[j],c[j]); //creates list to sort players by batting avg
        strcpy(BowlingAvg[j],c[j]); //creates list to sort players by bowling avg
    }
    cout<<endl;
    cout<<"The sorted batting average list is: "<<endl;
    SortBatList(BattingAvg,bat); //calls sort function for batting
    Display(BattingAvg,records);
    cout<<endl;

    cout<<"The sorted bowling average list is: "<<endl; //calls sort function for bowling
    SortBatList(BowlingAvg,bowl); //calls sort function for bowling
    Display(BowlingAvg,records);
    return 0;
}