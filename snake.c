
//kbhit(),rand()
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int width=40, height=40,GameOver;
int x,y,fruitX,fruitY,Score,flag;
int tailX[100],tailY[100];
int CountTail=0;
void setup()
{
    GameOver=0;
    x=width/2;
    y=height/2;
    label1:
    fruitX=rand()%20;
    if(fruitX==0)
        goto label1;
    label2:
    fruitY=rand()%20;
    if(fruitY==0)
            goto label2;
}
void draw()
{
    int i,j,k;
    system("cls");
    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
      {
        if(i==0||i==height-1||j==0||j==width-1)
         {
          printf("*");
         }

         else
         {
             if(i==x && j==y)
                printf("0");
             else if(i==fruitX&&j==fruitY)
                printf("F");
             else
              {
                  int ch=0;
                  for(k=0;k<CountTail;k++)
                  {
                      if(i==tailX[k] && j==tailY[k])
                      {
                          printf("o");
                          ch=1;
                      }
                  }
                  if(ch==0)
                  printf(" ");
              }
         }
      }

      printf("\n");

    }
    printf("Score= %d",Score);
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
            flag=1;
            break;
        case 's':
            flag=2;
            break;
        case 'w':
            flag=3;
            break;
        case 'd':
            flag=4;
            break;
        case 'x':
            GameOver=1;
            break;

        }
    }
}
void MakeLogic()
{
    int i;
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(i=1;i<CountTail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }

    switch(flag)
    {
        case 1:
            y--;
            break;
        case 2:
            x++;
            break;
        case 3:
            x--;
            break;
        case 4:
            y++;
            break;
        default:
            break;
    }
  if(x<0||x>width||y<0||y>height)
    GameOver=1;
    for(i=0;i<CountTail;i++)
    {
        if(x==tailX[i] && y==tailY[i])
            GameOver=1;
    }
    if(x==fruitX && y==fruitY)
    {
       label3:
    fruitX=rand()%20;
    if(fruitX==0)
        goto label3;
    label4:
    fruitY=rand()%20;
    if(fruitY==0)
        goto label4;
        Score=Score+5;
        CountTail++;
    }
}

int main()
{
    label6:
    setup();
    int m, n,c;
    while(!GameOver)
    {
        draw();
        input();
        MakeLogic();

      for(m=0;m<6000;m++)
         for(n=0;n<6000;n++){

         }
    }
   printf("\n Press Y to continue again:");
   scanf("%c",&c);
   if(c=='y'||c=='Y')
    goto label6;
  return 0;
}
