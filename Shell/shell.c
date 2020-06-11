//	Shell.c C File
//	Author: Giancarlo Guillen
//	Editor(s): Christopher Walen
//	Date Created: 5/23/2020
//	Summary: This file is the shell C file that will handle funcitons used in the main.c file. 
//	Last Edited By: Giancarlo Guillen (5/20/2020)
#include "shell.h"

char buffer[MAX_INPUT_LENGTH], argument[MAX_INPUT_LENGTH];
char userName[256]="GCGuillen";
//strcpy(userName,"GCGuillen");

// This simply creates the initial CLI screen.
void createShellPrompt()
{
   clearScreen();
}
// Clears the screen to setup the shell.
void clearScreen()
{
    for(int x=0;x< CLEAR_SIZE ; x++)
    {
        fprintf(stdout,"\n");
    }
}
// This Function will read in the input from the user.
char* getNextCommand()
{
    fgets(buffer,MAX_INPUT_LENGTH,stdin);
    fflush(stdin);
    return buffer;
}
// This Function will display where in the system the user is in.
void printUserLine()
{
    char directory[MAX_DIRECTORY_LENGTH], commandLine[MAX_DIRECTORY_LENGTH];
    if (getcwd(directory, sizeof(directory)) != NULL)
    {
       fprintf(stdout,"%s~%s$ ",userName,directory);
    } 
    else 
    {
       perror("getcwd() error");
    }
}
// This Function will cypher out the command from the input read in.
char* cypherCommand(char inputCommand[],char nextCommand[])
{
    char temp[MAX_INPUT_LENGTH];
    int stringLength=strlen(inputCommand);
    for(int x=0;x<stringLength;x++)
    {
        temp[x]=tolower(inputCommand[x]);
        if(inputCommand[x] == '\n')
        {
			temp[x] = '\0';
            break;
        }
        else if(inputCommand[x]==' ')
        {
            temp[x] = '\0';
            break;
        }
    }
    strcpy(nextCommand,temp);
    return nextCommand;
}
// This Function will cypher out the parameters given from the input read in.
char* cypherParameter(char inputCommand[], char inputParameter[])
{
    char temp[MAX_INPUT_LENGTH];
    int stringLength=strlen(inputCommand),index;
    for(int x=0; x<stringLength;x++)
    {
        if(inputCommand[x]==' ')
        {
            index=x+1;
            break;
        }
    }
    for(int i=index,paramIndex=0;i<stringLength;i++,paramIndex++)
    {
        temp[paramIndex]=tolower(inputCommand[i]);
        if(inputCommand[i]=='\n')
        {
            temp[paramIndex]='\0';
            break;
        }
    }
    strcpy(inputParameter,temp);
    //fprintf(stdout,"Insanity check: %s\n",inputParameter);
    return inputParameter;
}