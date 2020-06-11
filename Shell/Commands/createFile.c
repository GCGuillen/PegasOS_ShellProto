//  createFIle.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will create a new file in the current directory so long as that file does not exist.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

struct stat sb;
char response[256];
FILE *fp;
int main(int argv, char **argc)
{
    fprintf(stdout,"Is the file you want to create? %s\n[y]es\n[n]o\n",argc[1]);
    fscanf(stdin,"%s",response);
    if(strcmp("y",response)==0)
    {
        if (stat(argc[1], &sb) == 0 && S_ISREG(sb.st_mode))
        {
            fprintf(stdout,"%s file already exists!\n",argc[1]);
        }
        else
        {
            fp = fopen(argc[1],"w");
            fclose(fp);
            fprintf(stdout,"File %s was created!\n",argc[1]);
        }
    }
    else if(strcmp("n",response)==0)
    {
        fprintf(stdout,"File %s was not created!\n",argc[1]);
    }
    return 1;
}