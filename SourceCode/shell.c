#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include"history.h"
#include"tokenString.h"
#include"exec.h"

	/* Colors */
#define ANSI_COLOR_CYAN_BOLD  "\033[1m\033[36m"  
#define ANSI_COLOR_YELLOW_BOLD   "\033[1m\033[33m"
#define ANSI_COLOR_BIRGHT_BLUE "\033[1m\033[34m"
#define ANSI_COLOR_BRIGHT_RED "\033[1m\033[31m"
#define ANSI_COLOR_RESET  "\033[0m"

void shellEnvir(){  
	printf("\n--------Chao mung den voi MYSHELL---------\nThanh Vien Nhom: \n1: Nguyen Phu Bao Tien\n2: Tran Van Tu\n3: Tran Ngoc Tuan\nGo 'help' neu ban muon giup do\n");

}

	// Prints the prompt.  appears whenever the shell is ready to recieve input
void prompt(){	
		/* Printing */
	printf(ANSI_COLOR_CYAN_BOLD "%s@osh" ANSI_COLOR_RESET, getenv("USER"));  // Prints the name of the shell
	printf(":"); 
	printf("$ ");
}


int main(){
  int i;
  char** argv;
  char** history;	
  char** argv_right;
  argv = malloc(sizeof(char)*200);
  argv_right = malloc(sizeof(char)*100);   
  history = malloc(sizeof(char)*1000);
  int history_count=0;
  int background=0;
    
  int counter = 0; // argument counter: ls -af: 2 cd ..: 2 
  char lineInput[100];


  system("clear");  // Use System clear to give the shell a clean look on startup
  shellEnvir();
    while(1){	
      counter = 0;
      prompt(); 	
      fgets(lineInput, 100 ,stdin);
      //printf("Lineinput: %s",lineInput);

	//printf("\nAdded history");
	
	int checkBuiltIn = execArgsBuiltIn(lineInput, history, history_count);
	if(checkBuiltIn==0){continue;}
	//printf("\nLineInput: %s",lineInput);
	addHistory(history, lineInput, history_count);
	if(checkBuiltIn==2){history_count++;continue;}
	history_count++;
	checkBuiltIn = execArgsBuiltIn(lineInput, history, history_count);
	if(checkBuiltIn==2||checkBuiltIn==0)continue;

	//printf("\nHistory: %s", history[history_count-1]);
      
	//---------------Pipe 

	int cp = checkPipe(argv, argv_right, lineInput);
	
      	if(cp == 1){
		/*int len = Len(argv);
		for(i=0;i<len;i++){
			printf("\nargvs: %s",argv[i]);	
		}
		 len = Len(argv_right);
		for(i=0;i<len;i++){
			printf("\nArgv_right:%s",argv_right[i]);	
		}*/
		//background = checkAndPipe(argv, argv_right):
		execArgsPiped(argv, argv_right, background);
		continue;
	}
	
	//---------------Redirector
	int background = checkAnd(lineInput);
	int cr = checkRedirector(lineInput, argv);
	if(cr!=0){
		//printf("thanh cong\t %d \n",cr);
		execArgsRedirector(argv, cr, background);continue;
         }

	
	//---------------Simple command
	//printf("\nLineInput: %s",lineInput);
	tokenWord(lineInput, argv);
	execArgs(argv, background);
    }



  free(argv);
  free(argv_right);
  //Free history
  for(i=0;i<history_count;i++){
    free(history[i]);} 
  free(history); 
}

