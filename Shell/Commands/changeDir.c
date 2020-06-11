//	changeDir.c C File
//	Author: Giancarlo Guillen
//	Editor(s): Christopher Walen
//	Date Created: 5/23/2020
//	Summary: This file is the main C file that handles the command cd in PegasOS.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

struct stat sb;
char response[256];
int main(int argv, char **argc)
{
    fprintf(stdout,"We made it to change  directory\n");
    if(stat(argc[1], &sb) == 0 && S_ISDIR(sb.st_mode))
    {
        // This is where we chnage the directory since it is found.
    }
    else
    {
        fprintf(stdout,"Directory %s does not exist!\n",argc[1]);
    }
    return 1;
}