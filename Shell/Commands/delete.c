//  delete.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will delete a file in the current working directory.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

struct stat sb;
char response[256];
int main(int argv, char **argc)
{
    fprintf(stdout,"Is the file you want to delete? %s\n[y]es\n[n]o\n",argc[1]);
    fscanf(stdin,"%s",response);
    if(strcmp("y",response)==0)
    {
        fprintf(stdout,"File %s was deleted!\n",argc[1]);
        if (stat(argc[1], &sb) == 0 && S_ISREG(sb.st_mode))
        {
            remove(argc[1]);
        }
        else
        {
            fprintf(stdout,"File %s does not exist!\n",argc[1]);
        }
    }
    else if(strcmp("n",response)==0)
    {
        fprintf(stdout,"File %s was not deleted!\n",argc[1]);
    }
    return 1;
}