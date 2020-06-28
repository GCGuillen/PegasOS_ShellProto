//  copy.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will copy one file with it's contents to a different directory.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

struct stat sb;
char response[256],buffer[256],location[20];
FILE *currentFile,*newFile;
int startIndex=0;
int main(int argv, char **argc)
{
    if (stat(argc[1], &sb) == 0 && S_ISREG(sb.st_mode))
    {
        if (stat(argc[2], &sb) == 0 && S_ISDIR(sb.st_mode))
        {
            for(int i=0; i<strlen(argc[1]); i++)
            {
                if(argc[1][i]=='/')
                    startIndex=i+1;
            }
            for(int i=startIndex,j=0;i<strlen(argc[1]);i++,j++)
            {
                location[j]=argc[1][i];
                if(i==strlen(argc[1]))
                    location[j++]='\0';
            }
            strcat(argc[2],location);
            currentFile=fopen(argc[1],"r");
            newFile=fopen(argc[2],"w");
            while(fgets(buffer,sizeof(buffer),currentFile)!=NULL)
            {
                fputs(buffer,newFile);
            }
            fclose(currentFile);
            fclose(newFile);
            fprintf(stdout,"The %s file has been successfully copied over!\n",location);
            //remove(argc[1]);
        }
        else
        {
            fprintf(stdout,"The directory you which to copy to does not exist\n");
        }
        
    }
    else
    {
        fprintf(stdout,"The file you are trying to copy does not exist\n");
    }
    
    return 1;
}