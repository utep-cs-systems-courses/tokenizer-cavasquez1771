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

// error: if sentence ends with a space then an extra word is counted
int count_words(char *str) {
  int count = 0;

  while (*str != '\0') {
    str = word_start(str);
    if (non_space_char(*str))
      count++;
    str = word_terminator(str); 
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char *copy = (char*)malloc(sizeof(char)*len);
  for (int i = 0; i < len; i++) {
    *copy = *inStr;
    copy++;
    inStr++;
  }
  copy-=len;
  return copy;
}

int word_length(char *str) {
  return word_terminator(str) - word_start(str);
}

char **tokenize(char *str) {
  int num_words = count_words(str);
  char **tokens = malloc(num_words*sizeof(char *));
  char *p = str;  //for incrementing
  int len;
  char **start_address = tokens;
  printf("num words: %d", num_words);
  for (int i = 0; i < num_words; i++) {
    p = word_start(p);
    len = word_length(p);
    *tokens = copy_str(p, len);
    tokens++;
    p = word_terminator(p);
  }

  return start_address;
}

void print_tokens(char **tokens) {
  int i = 1;
  while (*tokens) {
    printf("Token %d is %s\n", i, *tokens);
    i++, tokens++;
  }
}


void free_tokens(char **tokens) {
  while (*tokens) {
    free(*tokens);
    tokens++;
  }
}


int menuOpt(char *str) {
  if (str[0] == 't')
    return 1;
  else if (str[0] == 'h')
    return 2;
  else if (str[0] == 'q')
    return 0;
  else
    return 4;
}







