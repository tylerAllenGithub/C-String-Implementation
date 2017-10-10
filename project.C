//Use a c-string not a string in this program.
#include "myStrCharFunc.h"
#include<fstream>
#include <iostream>
using namespace std;

//Set up
const int SIZE=26;// . size of the array
const int MAX=30;// . max length of a word. Assume no words can be longer than 30 characters.
typedef char cstr[MAX];// . Giving a new name .cstr. to a c-string with 30 slots.
struct type{
  int count;
  cstr longest;
  cstr shortest;
};

void  initializeArray( type ar[]);
void readFile(type ar[]);
void  printInfoOnOneLetter(type ar[]);
void printInfoOnAllLetters(type ar[]);
void processWord(cstr str, type ar[]);

int main()
{
  //Declare the array
  type array[SIZE];
  int choice;
  //menu
  initializeArray(array);
  readFile(array);
  do{
    cout<<"1. Show information on all the letters."<<endl;
    cout<<"2. Show information on one letter."<<endl;
    cout<<"3. Quit the program."<<endl;
    cout<<"Enter your choice here: ";
    cin>>choice;
    //display the menu
    switch(choice)
        {
        case 1:  printInfoOnAllLetters(array);
	  break;
        case 2: printInfoOnOneLetter(array);
	  break;
        case 3: cout<<"Thank you for using the system. Good bye."<<endl;
          break;        
        default: cout<<"Invalid choice. Please try again.";
        }

     }while(choice!=1&&choice!=2&&choice!=3);

    return 0;
  }
  void initializeArray(type ar[])
{
               for(int i=0;i<SIZE;i++)
	       {
		 ar[i].count=0;
		 myStrcpy(ar[i].longest, "");
		 myStrcpy(ar[i].shortest, "                             ");
		 } 
	     //initialize all the 3 fields in each slot of the array
	     //What do we initialize each field to?
}
  void readFile(type ar[])
	   {
	     //open the input file
	     cstr word;
	     ifstream fin;
	     fin.open("project2.dat");
	     //read one word at a time and send it to processWord()
	     fin >> word;
	     while(fin)
	       {
		 processWord(word, ar);
		 fin>> word;
	       }
	   }
  void processWord(cstr str, type ar[])
{
	    //increment the counter in the appropriate slot of the array
     int i=0;
    bool found = false;
  for(i = 0;i<SIZE && !found;i++)
    {
      if(str[0] == 'A'+i || str[0] == 'a'+i)
        {
          ar[i].count++;
          found = true;
        }
    }
  myToUpper(str[0]);
  if(myStrLen(str)>myStrLen(ar[i-1].longest))
    myStrcpy(ar[i-1].longest, str);
  
  if(myStrLen(str)<myStrLen(ar[i-1].shortest))
       	myStrcpy(ar[i-1].shortest, str);
      //check if the word is longest or shortest. If so, set it to the appropriate slot of the array.
	    //call myStrlen to check the length of the word
  //call myStrcpy to copy the word into the array
  }
  void  printInfoOnOneLetter(type ar[] )
  {
     char letter;
    cout<<"Which letter are you interested in?: ";
    cin>>letter;
    int slot=(int)(letter-65);
    cout<<endl;
     cout<<"Frequency: "<<ar[slot].count<<endl;
     if(ar[slot].count>0)
       {
        cout<<"Longest: "<<ar[slot].longest<<endl;
        cout<<"Shortest: "<<ar[slot].shortest<<endl;
        cout<<endl;
       }
}

      
  void printInfoOnAllLetters(type ar[])
{
  for(int i=0;i<SIZE; i++)
    {
      cout << (char)(65+i) << " " << ar[i].count << ": ";
      for(int k = 0;k<ar[i].count;k++)
	{
        cout << "*";
	}
      cout << " " << ar[i].longest << " - " <<ar[i].shortest<<endl;
    }  
}
