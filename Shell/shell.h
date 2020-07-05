//	Shell.h Header File
//	Author: Giancarlo Guillen
//	Editor(s): Christopher Walen
//	Date Created: 5/20/2020
//	Summary: This file is the main header file for the Shell for PegsasOs. Having the varibles
//           structs, enums, and functions be used for main.c which handles the CLI.
//	Last Edited By: Giancarlo Guillen (5/24/2020)


#ifndef SHELL_H
	#define SHELL_H

	#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include <unistd.h>
    #include <dirent.h>

	// This is how you do booleans in standard C
	#ifndef bool
		#define bool _Bool
		#define true 1
		#define false 0
	#endif

    #define MAX_INPUT_LENGTH 256
    #define MAX_DIRECTORY_LENGTH 1024

    #define CLEAR_SIZE 128
    #define DEBUG_DEFAULT 0
    #define TOTAL_USERS 10

	typedef struct user
    {
        char userName[MAX_INPUT_LENGTH];
        char password[MAX_INPUT_LENGTH];
        int userColor;
        int directoryColor;
    } user;

	typedef enum command
    {
        CD,CLEAR, TEXTPALETTE, BACKGROUNDPALETTE, USERCOLOR, DIRECTORYCOLOR, HEAD,
        MENUCOLOR, MENUCOLOR1, MENUCOLOR2, MENUCOLOR3, MENUCOLOR4, FIND,
        DEBUG, USERNAME, LOGIN, USER, CREATEFILE, CURRENTDIR, DELETEFILE, ECHO, MOVE, COPY, TAIL,

        HELP, EXIT,
        NUM_COMMANDS
    } command;

    
    void createShellPrompt();
    char* getNextCommand();
    const char* commandString(int index); 
    char* cypherCommand(char inputCommand[], char nextCommand[]);
    char* cypherParameter(char inputCommand[], char inputParameter[]);
    void clearScreen();
    void printUserLine();
#endif