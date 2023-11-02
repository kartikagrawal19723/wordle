#include <stdio.h>
#include <Windows.h>
//For using Sleep in C
#include <stdlib.h>
#include <string.h>
int level,round;
char GUESS[6][6] = {
    {'-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-'}
};
int SOLUTION[6][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
};
void generateLevel(int level);
int GUESSCheck(char *GUESS);
int StartGame();
int  welcome();
void help();
int options();
void loading();
void nextslide(int a);
void gameSetUp();
//It will display the main matrix 
char* solDisp(int i);
//It will display the solution along the GUESS Matrix
void wordInput();
//Word input will ask for the entry in each matrix row and check for its validity
void paste(char* word);
//Paste function will edit the main matrix whenever a valid entry is passed
int check4(char GUESS[level]);
int check5(char GUESS[level]);
int check6(char GUESS[level]);
//Main Function
int main()
{
    //We now have the level
    level = StartGame()+3;
    gameSetUp();
    //Display the initial game set up
    for(int round=0;round<6;round++)
    {
        gameSetUp();
        wordInput();
        //Will take the word input and then check if it is a valid word
        //To qualify as a valid word, must be 'level'letters long
        //Must be in dictionary
    }
    return 0;
}

int StartGame()
{
    return(welcome());
}

int  welcome()
{
    printf("Welcome to GUESSle\n...Press Enter to Start...\nPress H for help.\n");
    char ch;//
    scanf("%c",&ch);
    //If no character is entered or any character other than h is entered, the code proceeds
    //If h or H is entered, the code first gives the instructions
    if(ch=='H'||ch=='h')
    {
        help();
        //This will redirect the user to the help menu
    }
    loading();
    return(options());
}

void help()
{
    system("cls");
    //All the help here
    printf("This is a guided tutorial");
    nextslide(3);
    printf("Welcome to GUESSle, a GUESS Guessing game.\n");
    printf("The original version was released in October, 2021 by Josh Wardle.\n");
    printf("This is a Remastered Version of the game in C.\n");
    nextslide(7);
    printf("The game begins with a 6 row matrix as given below:\n");
    generateLevel(5);
    nextslide(5);
    printf("Let us learn using an example");
    nextslide(2);
    printf("Let us say you have to guess the GUESS 'PLANT'");
    printf("\nYou won't be told what you are supposed to guess, it is just for the example");
    nextslide(7);
    printf("So you enter your first guess: STAND");
    nextslide(5);
    printf("The computer will return: ");
    printf("S :[ T :/ A :) N :) D :[");
    nextslide(10);
    printf("\nThis was because: \n");
    printf(":) means that the letter is in the right location\n");
    printf(":/ means that the letter exists in the GUESS but is not in the right location\n");
    printf(":[ means that the letter does not exist in the GUESS\n");
    nextslide(10);
    printf("So\nS :[ T :/ A :) N :) D :[ \nMeans that\n");
    printf("S and D are not in the original GUESS, i.e. PLANT\n");
    printf("T is in the wrong location and A and N are in the right location");
    nextslide(15);
    printf("This will fill one row.");
    printf("\nThe game will go on till either you find the correct GUESS or you use up your six attempts\n");
    printf("You will be revealed the answer when the game ends.");
    nextslide(9);
    printf("All the Best");
    printf("\n\n---\nEnter any key to continue\n");
    char ch;
    scanf("%d",&ch);
    system("cls");
}
void nextslide(int a)
{
    Sleep(a*1000);
    system("cls");
}
int options()
{
edef:
    system("cls");
    printf("There are 3 difficulty modes: \n");
    printf("Easy\t1\nMedium\t2\nHard\t3\n");
    int mode;
    printf("Enter Your Choice: ");
    char buffer[10];
    fgets(buffer, 10, stdin);
    mode = atoi(buffer);
    if(!(mode>0 && mode <4))
    {
        printf("Please enter 1, 2 or 3");
        Sleep(1100);
        goto edef;
    }
    return mode;
}

//Loading function to simulate a loading screen
void loading()
{
    for(int i=0;i<3;i++)
        //We print it with no dots, then erase, then with multiple
    {
        system("cls");
        //This command will clear the Command Line Interface
        printf("Loading");
        for(int j=0;j<=i;j++)
        {
            printf(".");
        }
        Sleep(300);
}
}

void generateLevel(int level)
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<level;j++)
            printf(" _ ");
        printf("\n");
    }
}

int GUESSCheck(char GUESS[level])
{
    //This code will invoke one of 3 different methods, depending on the level
    if(level==4)
        return(check4(GUESS));
    if(level==5)
        return(check5(GUESS));
    if(level==6)
        return(check6(GUESS));
}
void gameSetUp()
{
    system("cls");
    printf("Enter The GUESS: \n");
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<level;j++)
        {
            printf("%c %s ",GUESS[i][j],solDisp(SOLUTION[i][j]));
        }
        printf("\n");
    }
}
char* solDisp(int i)
{
    if(i==2)
        return(":/");
    else if(i==1)
        return(":)");
    else if(i==3)
        return(":[");
    else
        return("  ");
}
void wordInput()
{
    start:
    printf("Enter the word here: ");
    char buffer[100];
    gets(buffer);
    if(!(strcheck1(buffer)))
    {
        printf("Please enter a %d lettered word!",level);
        nextslide(3);
        gameSetUp();
        goto start;
        //The function calls itself as if to start over
    }
    if(!GUESSCheck(buffer))
    //To check if it is in the dictionary
    {
        printf("Please enter a valid word");
        nextslide(3);
        gameSetUp();
        goto start;
    }
    nextslide(1);
    char word[level];
    strcpy(word,buffer);
    paste(word);
    //The paste function will simply put it in the GUESS DDA
}
int strcheck1(char* wordishere)
{
    int len=0;
    while(*(wordishere+len)!='\0')
    {
        len++;
    }
    if(len==level)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void paste(char word[level])
{
    for(int i=0;i<level;i++)
    {
        GUESS[round][i]=*(word+i);
    }
    round++;
}
int check4(char wor[level])
{
    char data[5];
    FILE *file = fopen("C:/Users/itsar/OneDrive/Documents/GitHub/Wordle-in-C-1st-sem/letter4/wordle4letter.txt", "r");
    while(fgets(data, sizeof(data), file))
    {
        if(strcmp(data, wor)==0)
            return 1;
    }
    return 0;
}
int check5(char wor[level])
{
    char data[6];
    FILE *file = fopen("C:/Users/itsar/OneDrive/Documents/GitHub/Wordle-in-C-1st-sem/letter5/wordle5.txt", "r");
    while(fgets(data, sizeof(data), file))
    {
        if(strcmp(data, wor)==0)
            return 1;
    }
    return 0;
}
int check6(char wor[level])
{
    char data[7];
    FILE *file = fopen("C:/Users/itsar/OneDrive/Documents/GitHub/Wordle-in-C-1st-sem/letter6/wordle6letter.txt", "r");
    while(fgets(data, sizeof(data), file))
    {
        if(strcmp(data, wor)==0)
            return 1;
    }
    return 0;
}
/*
Submitted for MiniProject
OddSem 2023
Class of 2027
Batch -> B9
Branch -> BTech CSE
Members:
    Risha Gupta
    Devyani Sharma
    Arnav Sharma
    Anushka Tayal
*/