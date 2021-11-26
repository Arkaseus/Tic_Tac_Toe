#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char checkr(char s[]);
void board(char s[]);

void main()
{ char s[10]={'1','2','3','4','5','6','7','8','9'};
  char p1,p2,result,temp='y';
   int p_input;
  
    while(temp=='y')
 {
   printf("\t\t! TIC TAC TOE !");  
   board(s);
   
   printf("\nPlayer 1 choose 'x' or 'o' ");
   scanf("%c",&p1);
   p2=(p1=='x')?'o':'x';
 
     while(1)  
   {  again1:
      printf("Player 1 turn: ");
      scanf("%d",&p_input);
       if(s[p_input-1]==p1||s[p_input-1]==p2)
         { printf("place already assigned...try again");
         goto again1; }
      temp=p1;
      s[p_input-1]=p1;
      system("cls");
      board(s);
      result=checkr(s);
      if(result=='w'||result=='d')
       break;
       again2:
      printf("Player 2 turn: ");
      scanf("%d",&p_input);
        if(s[p_input-1]==p1||s[p_input-1]==p2)
         {printf("place already assigned...try again\n");
         goto again2;}
      temp=p2;
      s[p_input-1]=p2;
      system("cls");
      board(s);
      result=checkr(s);
      if(result=='w'||result=='d')
       break;
   }  

   if(result=='w')
   {  if(temp==p1)
       printf("\nPlayer 1 is Winner !\n");
       else
       printf("\nPlayer 2 is Winner !\n");
    }
    else if(result=='d')
    printf("\n Game tie... '-' \n");   
  
  printf("\nPress 'Y' to play again :");
  fflush(stdin);
  scanf("%c",&temp);
 }
  getch();
}

//function for board interface
 void board (char s[]) 
  { printf("\n\n");
    printf("\t\t %c | %c | %c\n",s[0],s[1],s[2]);
    printf("\t\t===|===|===\n");
    printf("\t\t %c | %c | %c \n",s[3],s[4],s[5]);
    printf("\t\t===|===|===\n");
    printf("\t\t %c | %c | %c \n",s[6],s[7],s[8]);
   }

 //function for checking result
   char checkr(char s[])
  { 
     if(s[0]==s[1]&&s[1]==s[2])
     return 'w';
    else if(s[3]==s[4]&&s[4]==s[5])
     return 'w';
     else if(s[6]==s[7]&&s[7]==s[8])
     return 'w';
     else if(s[0]==s[3]&&s[3]==s[6])
     return 'w';
     else if(s[1]==s[4]&&s[4]==s[7])
     return 'w';
     else if(s[2]==s[5]&&s[5]==s[8])
     return 'w';
     else if(s[0]==s[4]&&s[4]==s[8])
     return 'w';
     else if(s[2]==s[4]&&s[4]==s[6])
     return 'w';
     else if(s[0]!='1'&&s[1]!='2'&&s[2]!='3'&&s[3]!='4'&&s[4]!='5'&&s[5]!='6'&&s[6]!='7'&&s[7]!='8'&&s[8]!='9')
      return 'd';
      return 0;

   }


