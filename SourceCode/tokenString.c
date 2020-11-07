#include"tokenString.h"

//-----ham tra ve so dong cua mang hai chieu
int Len(char** argv){
int i=0;
	do{
		if(argv[i]==NULL) return i;
		i++;
	}while(i<200);
return i;
}


//-------------------Ham phu tro cho ham Check



int tokenWord(char* lineInput, char** argv){
      int counter =0;
      char *token;
      char flags[]=" \n\t";
      token = strtok(lineInput, flags);
      //printf("%s",token);
      argv[counter]=token;
	
      while (token != NULL){		
       token = strtok(NULL, flags);
       counter++;
       argv[counter]=token;
      }
      return counter;
}

/*
Check position of first character 'c' in string 'str'
Return -1: 'c' out str
Return n>0: 'c' in str
*/
int  checkCharacterInString(char* str, char c){
  int len=strlen(str);
  int i;
  for( i=0;i<len;i++){
    if(str[i]==c){
      return i;
    }
  }
return  -1;
}

/*
Separate a string into 2 part by position
*/
void separateString(char* lineInput, char** argv, char** argv_right, int position){
  char* s1,*s2;
   int len = strlen(lineInput);
 
  
  s1 = malloc(sizeof(char)*position);
  s2 = malloc(sizeof(char)*(len-position));
  int i;
  for( i=0;i<position;i++){
    s1[i]=lineInput[i];
  }
  for(i=0;i<len-position-1;i++){
    s2[i]=lineInput[position+i+1];
  }
  //printf("\ns1: %s\ns2: %s", s1,s2);
  tokenWord(s1,argv);
  tokenWord(s2,argv_right);
}



//------------------------------------Check will write here

/*
Return 1: neu co pipe --> tach input ra 2 chuoi argv | argv_right
return 0: nen khong co pipe
*/
int checkPipe(char** argv, char** argv_right, char* lineInput){
  int pipe = checkCharacterInString(lineInput,'|');
  if(pipe !=-1){
      char*s1,*s2;
      separateString(lineInput,argv,argv_right, pipe); 
	return 1;
   }
return 0;
}


/*
Return 1: neu co '&' --> thay the & == " "
Return 0: neu khong co '&'
*/
int checkAnd(char* str){
int len = strlen(str);
int i;
int check=0;
	for(i=0;i<len;i++){
		if(str[i]=='&'){
		str[i]=' ';check = 1;
		}
	}
return check;
}

/*
return 0
return 1: > 
return 2: <
*/
int checkRedirector(char* lineInput, char** argv){
	int len = strlen(lineInput);
	int i;
	for(i=0;i<len;i++){
		if(lineInput[i]=='>'){
			lineInput[i]=' ';
			if(lineInput[i+1]=='>'){
				lineInput[i+1]=' ';
				tokenWord(lineInput, argv);
			 	return 3;}
			tokenWord(lineInput, argv);
			 return 1;
		}
		if(lineInput[i]=='<'){
			lineInput[i]=' ';
			tokenWord(lineInput, argv);
			 return 2;
		}
	}
	return 0;
}
























