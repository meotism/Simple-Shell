#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int tokenString(char* lineInput, char** argv,char** argv_right);
int tokenWord(char* lineInput, char** argv);
int Len(char** argv);
int checkAnd(char* str);
int checkPipe(char** argv, char** argv_right, char* lineInput);
int checkRedirector(char* lineInput, char** argv);
