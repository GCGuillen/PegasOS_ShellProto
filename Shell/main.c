//	Main.c C File
//	Author: Giancarlo Guillen
//	Editor(s): Christopher Walen
//	Date Created: 5/23/2020
//	Summary: This file is the main C file that will handle the main loop of our CLI where it will take inputs
//           the user and execute the corresponding commands and then wait for next input. 
//	Last Edited By: Giancarlo Guillen (5/20/2020)

#include "shell.h"
#include "shell.c"

user registry[TOTAL_USERS],currentUser;
int numUsers, masterUser, debug, userColor, directoryColor, functionReturn, 
    menuColor1, menuColor2, menuColor3, menuColor4,power,foundFile;
char separator, commandInput[MAX_INPUT_LENGTH], 
    *parameter, nextCommand[MAX_INPUT_LENGTH], throwaway, fileLocation[MAX_INPUT_LENGTH];
struct dirent *de;
int main(void)
{
    power=0,foundFile=0;
    parameter=malloc(sizeof(char)*MAX_INPUT_LENGTH);
    createShellPrompt();    
    do
    {
        DIR *dr=opendir("./Commands/bin/");
        if(dr==NULL)
        {
            printf("Could not find current directory");
            return 0;
        }
        printUserLine();
        strcpy(nextCommand,getNextCommand());
        cypherCommand(nextCommand,commandInput);
        cypherParameter(nextCommand,parameter);
        while((de=readdir(dr)) != NULL)
        {
            if(strcmp(commandInput,de->d_name)==0)
            {
                strcpy(fileLocation,"./Commands/bin/");
                strcat(fileLocation,commandInput);
                strcat(fileLocation," ");
                strcat(fileLocation,parameter);
                system(fileLocation);
                foundFile=1;
            }
        }
        if(strcmp("power",commandInput)==0)
        {
            power=1;
        }
        if(foundFile==0)
        {
            fprintf(stdout,"Command inputted is not a known command. Enter 'help' for a list of commands\n");
        }
        foundFile=0;
       closedir(dr);
    } while (!power);
    free(parameter);
    return 0;
}