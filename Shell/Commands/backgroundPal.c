//  backgroundPal.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will display all the color variartions for the CLI backgorund color.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>
#include <string.h>
#include "../shell.h"
#include "../shell.c"

int main(int argv, char **argc)
{
    fprintf(stdout,"arg1[1] is |%s|\n",argc[1]);
    if(strcmp(argc[1],"backgroundpalette")==0)
    {
        fprintf(stdout,"This is the backgroundPalette bin\n");
        int counter = 0;
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                fprintf(stdout,"\033[48;5;%im", counter);
                fprintf(stdout," %3i ", counter++);
            }
            fprintf(stdout,"\n");
        }
        fprintf(stdout,"\033[0m\n");
    }
    return 1;
}