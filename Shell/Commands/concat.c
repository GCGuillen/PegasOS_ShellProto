//  concat.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will concat two files into one main file.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

struct stat sb;
char response[256],buffer[256],location[20];
FILE *concatFile,*readFile;
int startIndex=0;
int main(int argv, char **argc)
{
    if (stat(argc[1], &sb) == 0 && S_ISREG(sb.st_mode))
    {
        if (stat(argc[2], &sb) == 0 && S_ISREG(sb.st_mode))
        {
            if ((concatFile = fopen(argc[1], "a")) == NULL)
            {
                fprintf(stderr, "Could not open %s in main()!\n", argc[1]);
                return 0;
            }
            if ((readFile = fopen(argc[2], "r")) == NULL)
            {
                fprintf(stderr, "Could not open %s in main()!\n", argc[2]);
                return 0;
            }
            while(fgets(buffer,sizeof(buffer),concatFile)!=NULL);
            while(fgets(buffer,sizeof(buffer),readFile)!=NULL)
            {
                fputs(buffer,concatFile);
            }
            fclose(concatFile);
            fclose(readFile);
        }
        else
        {
            fprintf(stdout,"The second file does not exist!\n");
        }
    }
    else
    {
        fprintf(stdout,"The first file does not exist!\n");
    }
    
    return 1;
}