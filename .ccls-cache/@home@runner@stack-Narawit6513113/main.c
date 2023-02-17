#include "node.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  int i, j;
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
  for (i = 1; i < argc; i++) {
    int N = 0; // N=1->Miss match N=2->toomanyopen N=3->toomanyclose
    for (j = 0; j < strlen(argv[i]); j++) {
      switch (argv[i][j]) {
      case '{':
        // push_stack(&s, argv[i][j]);
        // break;
      case '[':
        push_stack(&s, argv[i][j]);
        break;
      case '}':
        if (s.size == 0)
          N = 2;
        else if (pop_stack(&s) != '{')
          N = 1;
        break;

      case ']':
        if (s.size == 0)
          N = 2;
        else if (pop_stack(&s) != '[')
          N = 1;
        break;
      }
      if (N == 1 || N == 2)
        break;
      /* Use stack to help with the parentheses*/
    }
    if (s.size > 0) {
      printf("argv %d : Incorrect : too many open\n", i);
      pop_all(&s);
    } else if (N == 1) {
      printf("argv %d : Incorrect : mismatch\n", i);
    } else if (N == 0) {
      printf("argv %d : Correct\n", i);
    } else if (N == 2) {
      printf("argv %d : Incorrect : too many close\n", i);
    }
  }
  return 0;
}
