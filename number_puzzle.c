#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<unistd.h>
#include<string.h>


void create(int puzzle[4][4]);
void display(int puzzle[4][4]);
void shuffle(int puzzle[4][4]);
int checker(int puzzle[4][4]);
void movement_key(int puzzle[4][4]);
void welcome();
void result(int step);

int whiteSpace_i,whiteSpace_j;
void main()
{
    int puzzle[4][4];
    system("CLS");
    welcome();
    create(puzzle);
    printf("\n\n \t The   Resultant   Puzzle :");
    display(puzzle);
    sleep(2);
    system("CLS");

    shuffle(puzzle);
    printf("\n\t________________Solve   The   Puzzle__________________\n\n");
    display(puzzle);
    sleep(2);
    

    movement_key(puzzle);
    
}

void create(int puzzle[4][4])
{
    int i,j,numbers=1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            puzzle[i][j]=numbers++;
        }
    }
}

void shuffle(int puzzle[4][4])
{
    int level;
    printf("\n\n \t\t enter the level 1 or 2 or 3 : \n");
    scanf("%d",&level);
    if(level==1)
    {
        int level_1[4][4]={{2,3,4,16},{1,5,6,7},{10,11,12,8},{9,13,14,15}};
        memcpy (puzzle, level_1, sizeof(level_1));
        whiteSpace_i=0,whiteSpace_j=3;
    }
    else if(level==2)
    {
        int level_2[4][4]={{2,16,7,3},{1,5,11,4},{10,6,15,8},{9,13,14,12}};
        memcpy (puzzle, level_2, sizeof(level_2));
        whiteSpace_i=0,whiteSpace_j=1;
    }
    else
    {
        int level_3[4][4]={{5,1,2,3},{9,7,10,4},{13,16,6,8},{14,15,11,12}};
        memcpy (puzzle, level_3, sizeof(level_3));
        whiteSpace_i=2,whiteSpace_j=1;
    }
}

void movement_key(int puzzle[4][4])
{
    int i,j,step=0;
    char key;
    i=whiteSpace_i;
    j=whiteSpace_j;
    printf("\n\t Give keys to Play \t\n");
    while (1)
    {
        if( kbhit() )
        {
            
            key=getch();
            if(key==27)
                break;
            
            if( (key==80&&i+1>=4) || (key==75&&j-1<0) || (key==77&&j+1>=4) || (key==72&&i-1<0) )
            {
                Beep(600,400);
                printf("\n\n \t Please enter valid input \n");
                
            }
            else
            {
                switch (key)
                {
                    case 80:
                        i++;
                        break;
                    case 75:
                        j--;
                        break;
                    case 77:
                        j++;
                        break;
                    case 72:
                        i--;
                        break;
                }
                step++;
                puzzle[i][j]=(puzzle[i][j]+puzzle[whiteSpace_i][whiteSpace_j])-(puzzle[whiteSpace_i][whiteSpace_j]=puzzle[i][j]);
                whiteSpace_i=i;
                whiteSpace_j=j;
                system("CLS");
                display(puzzle);
            }
            
            if(whiteSpace_i==3&&whiteSpace_j==3)
            {
                if(checker(puzzle))
                {
                    result(step);
                    break;
                }
            }        

        }
    }
    
}

int checker(int puzzle[4][4])
{
    int i,j,count=1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(puzzle[i][j]!=count)
                return 0;
            count++;
        }
    }
    return 1;
}

void display(int puzzle[4][4])
{
    int i,j;
    
    for(i=0;i<4;i++)
    {
        printf("\n\n \t\t");
        for(j=0;j<4;j++)
        {
            if(puzzle[i][j]==4*4)
                printf("%c\t",219);
            else
                printf("%d\t",puzzle[i][j]);
        }
        printf("\n");
    }
    
    
}

void welcome()
{
    char welcome[]="\n\n \t\tWELCOME TO NUMBER REARRANGING PUZZLE\n",
    wait[]="\n\n \t\t LOADING";
    int i,j;
    for(i=0;welcome[i]!='\0';i++)
    {
        printf("%c",welcome[i]);
        if(welcome[i]==' ')
            sleep(2);
        
    }
    sleep(2);
    system("CLS");
    
    for(i=0;i<2;i++)
    {
        printf("\n\n \t\t Please Wait.!");
        printf("%s",wait);
        for(j=0;j<5;j++)
        {
            printf(".");
            sleep(1);
        }
        sleep(1);
        system("CLS");
    }
}

void result(int step)
{
    sleep(1);
    system("CLS");
    char result[]="\n\n\t\t ****TADA**** \n\t congrats the game has been finished \n";
    for(int i=0;result[i]!='\0';i++)
    {
        printf("%c",result[i]);
        if(result[i]==' ')
            sleep(2);
    }
    printf("\n Number Steps Taken To Solve The Puzzle : %d\n \t**play again**",step);
}