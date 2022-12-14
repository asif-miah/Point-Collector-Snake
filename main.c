#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#define BORDER 42
#define SIZE 25
#define COIN 'P'

void mkshape();
void displayshape();
char board[SIZE][SIZE];

int main()
{
   //char house[SIZE][SIZE];
   mkshape();
   int col = 0, row =0, died = 0, uprow = 0,downrow = 1, leftcol = 0, rightcol = 0 , rndm = 5 ,point = 0;

   while(1)
    {
        if(kbhit())
        {
            switch(getch())
            {
            case 'w':
                uprow = -1;
                downrow = 0;
               rightcol = 0;
                leftcol = 0;
                break;
            case 's':
                downrow = 1;
                uprow = 0;
               leftcol = 0;
               rightcol = 0;
                break;
            case 'a':
                leftcol = -1;
                 uprow = 0;
               downrow =0;
               rightcol = 0;
                break;
              case 'd':
                rightcol = 1;
                 uprow = 0;
              downrow = 0;
               leftcol = 0;
                break;
            }

        }
           if(uprow )
          {
              row--;

          }
        if(downrow)
          {
               row++;

          }
          if(leftcol == -1)
          {
               col--;

          }
           if(rightcol == 1)
          {
               col++;

          }


            if(board[2+row][3+col] == BORDER)
                 died ++;
                  if( board[2+row][3+col] == COIN)
           {

               point++ ;
                board[rndm + 3+ row ][ rndm - 4 + col] = COIN;

               if( row % 2 == 0)
                rndm = -3;
               else rndm =   2;
               if(col % 2 == 0)
                rndm = -3;
               else rndm =  2;

           }
           board[2+row][3+col] = 36;
           displayshape(point);
           if(died != 0)
                 break;






           board[2+row][3+col] = ' ';




    }
printf("\t Game is over \t\n");

printf("\tYour point is %d\t\n", point);
    return 0;
}

void mkshape()
{
    for(int i = 0; i < SIZE; i++)
    {

        for(int j = 0; j< SIZE ; j++)
        {

            if(i == 0 || i == (SIZE -1))

             board[i][j] = BORDER;

             else if(i != 0 && i != (SIZE -1))
             {
                 if( j == 0 || j == (SIZE -1))
                    board[i][j] = BORDER;


             else
                board[i][j] = ' ';
             }
             if(j == 5 && i == 7)
                 board[i][j] = COIN;
        }
    }
}
void displayshape(int  point)
{
    system("cls");
    printf("\n\npoint  %d  \t Coder: Asif\n\n", point);
    for(int i = 0; i<SIZE ; i++)
    {

        for(int j = 0; j< SIZE; j++)
            printf("%c", board[i][j]);

            printf("\n");

    }
    Sleep(240);
}
