//  currentDir.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will display the current working directory.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main(int argv, char **argc)
{
    char currentWorkingDirectory[256];
    if (getcwd(currentWorkingDirectory, sizeof(currentWorkingDirectory)) != NULL)
    {
        printf("Current working dir: %s\n", currentWorkingDirectory);
    } 
    else 
    {
       perror("error");
       return 1;
    }
    return 1;
}