//	systemInfo.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 5/23/2020
//	Summary: This file will prints out all of the available colors for text in the CLI.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>
#include "../shell.h"
#include "../shell.c"

int main(int argv, char **argc)
{
    user *test=createUser("Thatboi","beans",1);
    fprintf(stdout,"arg1[1] is |%s|\n",argc[1]);
    if(strcmp(argc[1],"textpalette")==0)
    {
        int counter = 0;
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                printf("\033[38;5;%im", counter);
                printf(" %3i ", counter++);
            }

            printf("\n");
        }
        printf("\033[0m");
    }
    return 1;
}