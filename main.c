#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"
#include "stack.h"

int main(int argc, char **argv){
  
  int i,j;
  Stack s;
  s.top = NULL;
  s.size = 0;
  /*NodePtr top= NULL;
  for( i = 1 ; i<argc ; i++)
  {
    pushs(&s,atoi(argv[i]));
  }
  while(s.top){
    printf("   %d",pops(&s));
  }*/
  /*push(&top,5);
  pop(&top);
  push(&top,5);
  push(&top,5);*/

 printf("Checking the parentheses in argv arguments\n");
  for(i=1;i<argc;i++)
  {
    int N = 0;
     for(j=0;j<strlen(argv[i]);j++)
     {
       switch(argv[i][j])
       {
         case '{' : push_stack(&s , argv[i][j]);
                    break;
         case '[' : push_stack(&s , argv[i][j]);
                    break;
         case '}' : if(pop_stack(&s) != '{') N = 1;
                    break;
         case ']' : if(pop_stack(&s) != '[') N = 1;
                    break;
       }
       if(N == 1) break;
       /* Use stack to help with the parentheses*/
     }
     if (N == 1)
     {
       printf("argv %d : Incorrect\n",i);
     }
     else
     {
       printf("argv %d : Correct\n",i);
     }
  }
//*/



   return 0;
}
