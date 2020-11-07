#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
void addHistory(char** history, char* lineInput, int count);
void printHistory(char** history, int history_count);
