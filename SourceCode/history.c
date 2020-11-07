#include"history.h"
void addHistory(char** history, char* lineInput, int count){
  int len = strlen(lineInput);
  history[count]=malloc(sizeof(char)*len);
  int i;
  for( i=0;i<len;i++)
    history[count][i]=lineInput[i];
 history[count][len] ='\0';
}

void printHistory(char** history, int history_count){
  if(history_count==0){
    printf("no history in command!");return;
  }
  int i;
  for( i=0;i<history_count;i++){
    printf("[%d]: %s",i,history[i]);
  }
}
