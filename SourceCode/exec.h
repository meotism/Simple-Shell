#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int execArgsBuiltIn(char* lineInput,char** history,int historycount);
void execArgs(char** parsed, int background);
void execArgsPiped(char** parsed, char** parsedpipe, int background);
void execArgsRedirector(char** argv,int checkRedirector, int background);
void cmdChoice(int argc, char **argv);
