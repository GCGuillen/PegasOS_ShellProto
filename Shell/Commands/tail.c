//	tail.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 5/23/2020
//	Summary: This file will display the ending n lines of the given file.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

struct stat sb;
char response[256],buff[256];
int linesRead=1,linesToBeRead=5,tailCount=0;
int main(int argv, char **argc)
{
    //fprintf(stdout,"%d\n",argv);
    if(argv>2)
        linesToBeRead=atoi(argc[2]);
    if (stat(argc[1], &sb) == 0 && S_ISREG(sb.st_mode))
    {
        FILE *openFile;
        //fprintf(stdout,"File |%d| exists!\n",atoi(argc[2]));
        openFile=fopen(argc[1],"r");
        while(fgets(buff, 256, openFile)!=NULL)
        {
            //fgets(buff, 256, openFile);
            //printf("%s", buff );
            linesRead++;
        }
        linesRead--;
        fclose(openFile);
        linesToBeRead=linesRead-linesToBeRead;
        openFile=fopen(argc[1],"r");
        while(tailCount<linesToBeRead)
        {
            fgets(buff, 256, openFile);
            tailCount++;
        }
        while(fgets(buff, 256, openFile)!=NULL)
        {
            fprintf(stdout,"%s", buff );
            //linesRead++;
        }
        fprintf(stdout,"\n");
        fclose(openFile);
    }
    return 1;
}