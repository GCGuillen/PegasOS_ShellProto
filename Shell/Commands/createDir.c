//  createDir.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will create a new sub-directory in the current directory.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

int main(int argv, char **argc)
{
    struct stat sb;
    char response[256];
    if (stat(argc[1], &sb) == 0 && S_ISDIR(sb.st_mode))
    {
        fprintf(stdout,"The %s directory exists!\n",argc[1]);
    }
    else
    {
        fprintf(stdout,"Are you certain that you want to create %s directory!\n[y]es\n[n]o\n",argc[1]);
        fscanf(stdin,"%s",response);
        if(strcmp("y",response)==0)
        {
            mkdir(argc[1],0777);
            fprintf(stdout,"Success!\n");
        }
        else if(strcmp("n",response)==0)
        {
            fprintf(stdout,"%s directory was not created!\n",argc[1]);
        }
    }
}