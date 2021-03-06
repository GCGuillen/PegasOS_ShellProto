//	Shell.cpp C++ File
//	Author: Giancarlo Guillen
//	Editor(s): Christopher Walen
//	Date Created: 5/23/2020
//	Summary: This file is the shell C file that will handle funcitons used in the main.c file. 
//	Last Edited By: Christopher Walen (7/5/2020)

#include "shell.hpp"

char buffer[MAX_INPUT_LENGTH], argument[MAX_INPUT_LENGTH];
char userName[MAX_INPUT_LENGTH] = "GCGuillen";
char separator = '@';
// Default User will be 0
int currentUserIndex = 1;
//strcpy(userName,"GCGuillen");

// This simply creates the initial CLI screen.
void createShellPrompt()
{
   clearScreen();
}

// Clears the screen to setup the shell.
void clearScreen()
{
    for (int x = 0; x < CLEAR_SIZE; x++)
    {
        std::cout << "\n";
        //fprintf(stdout,"\n");
    }
}

// This Function will read in the input from the user.
char* getNextCommand()
{
    fgets(buffer, MAX_INPUT_LENGTH, stdin);
    fflush(stdin);
    return buffer;
}

// This Function will display where in the system the user is in.
void printUserLine(user *temp)
{
    char directory[MAX_DIRECTORY_LENGTH], commandLine[MAX_DIRECTORY_LENGTH];
    if (getcwd(directory, sizeof(directory)) != NULL)
    {
        //fprintf(stdout,"%s@%s$ ",temp->userName,directory);
        std :: cout << "\033[38;5;"<< temp->userColor << "m";
        std :: cout << temp->userName;
        std :: cout << "\033[0m";
        std :: cout << separator;
        std :: cout << "\033[38;5;" << temp->directoryColor << "m";
        std :: cout << directory << ": ";
        std :: cout << "\033[0m";
        /*fprintf(stdout,"\033[38;5;%im", temp->userColor);
        fprintf(stdout,"%s", temp->userName);
        fprintf(stdout,"\033[0m");
        fprintf(stdout,"%c", separator);
        fprintf(stdout,"\033[38;5;%im", temp->directoryColor);
        fprintf(stdout,"%s: ", directory);
        fprintf(stdout,"\033[0m");*/
    } 
    else 
    {
       perror("getcwd() error");
    }
}

// This Function will cypher out the command from the input read in.
char* cypherCommand(char input[], char command[])
{
    char temp[MAX_INPUT_LENGTH];
    int stringLength = strlen(input);

    for (int x = 0; x < stringLength; x++)
    {
        temp[x] = tolower(input[x]);

        if (input[x] == '\n')
        {
			temp[x] = '\0';
            break;
        }
        else if (input[x] == ' ')
        {
            temp[x] = '\0';
            break;
        }
    }

    strcpy(command,temp);
    return command;
}

// This Function will cypher out the parameters given from the input read in.
char* cypherParameter(char inputCommand[], char inputParameter[])
{
    char temp[MAX_INPUT_LENGTH];
    int stringLength = strlen(inputCommand), index;

    // Grab the command
    for (int x = 0; x < stringLength; x++)
    {
        if (inputCommand[x] == ' ')
        {
            index = x + 1;
            break;
        }
    }

    // Grab the parameters following the command
    for (int i = index, paramIndex = 0; i < stringLength; i++, paramIndex++)
    {
        temp[paramIndex] = inputCommand[i];

        if (inputCommand[i] == '\n')
        {
            temp[paramIndex] = '\0';
            break;
        }
    }

    strcpy(inputParameter, temp);
    //fprintf(stdout,"Insanity check: %s\n",inputParameter);
    return inputParameter;
}

int sendOff(char parameter[], char path[], char commandInput[], user *temp)
{
    char fileLocation[256];
    int returnValue;

    strcpy(fileLocation, path);
    strcat(fileLocation, commandInput);
    strcat(fileLocation, " ");
    strcat(fileLocation, parameter);

    //fprintf(stdout,"Insanity check: |%s|\n", fileLocation);
    if (strcmp(commandInput, "textpalette") == 0)
    {
        system(fileLocation);

        if (strcmp(parameter, commandInput) != 0)
            temp->userColor = atoi(parameter);

        return 1;
    }
    else if (strcmp(commandInput, "backgroundpalette") == 0)
    {
        system(fileLocation);

        if (strcmp(parameter, commandInput) != 0)
            temp->directoryColor = atoi(parameter);
        
        return 1;
    }
    else if (strcmp(commandInput, "hello") == 0)
    {
        strcat(fileLocation, " ");
        strcat(fileLocation, temp->userName);
        system(fileLocation);
        return 1;
    }
    else if (strcmp(commandInput, "login") == 0)
    {
        system(fileLocation);
        return 1;
    }
    else
    {
        system(fileLocation);
        return 1;
    }
}

user *createUser(char *name, char *pass, int currentUserIndex)
{
    user *temp = new user;
    temp->userColor = 15;
    temp->directoryColor = 15;
    strcpy(temp->userName, name);
    strcpy(temp->password, pass);
    return temp;
}