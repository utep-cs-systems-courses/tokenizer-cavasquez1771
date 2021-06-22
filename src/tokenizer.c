#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c) {
  if ((c == ' ' || c == '\t') && c != '\0')
    return 1;
  else
    return 0; 
}

int non_space_char(char c) {
  if ((c != ' ' && c != '\t') && c != '\0')
    return 1;
  else
    return 0;
}

char *word_start (char *str) {
  while (space_char(*str)) //iterate to the next address until a non space char is found
    str++;
  return str;
}

char *word_terminator(char *word) {
  while (non_space_char(*word)) //interate to the next address until a space char is found
    word++;
  return word;
}

int count_words(char *str) {
  int count = 0;
  char *temp = str;
  temp = word_start(temp);

  while (*temp) { //while temp has a true value (non-zero)
    if (non_space_char(*temp))
      count++;
    temp = word_terminator(temp);
    temp = word_start(temp);
  }
  return count;
}

