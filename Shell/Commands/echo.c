//  echo.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will echo back the parameter given.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>

int main(int argv, char **argc)
{
    fprintf(stdout,"Echo ");
    for(int i=1;i<argv;i++)
    {
        fprintf(stdout,"%s",argc[i]);
        if(argv!=(i+1))
            fprintf(stdout," ");
    }
    fprintf(stdout," Echo\n");
    return 1;
}
