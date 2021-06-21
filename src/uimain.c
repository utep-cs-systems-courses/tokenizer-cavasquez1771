#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main() {
  printf("Welcome!\n");
  char c[100];
  
  printf("\nPlease input a string:\n>");
  fgets(c,100,stdin);

  printf("the string is: %s\n",c);
}
