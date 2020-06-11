//  clear.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will clear the CLI of the previous inputed arguements and outputted content.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>

int main()
{
    fprintf(stdout,"This is the clear bin\n");
    printf("\e[1;1H\e[2J"); 
    return 1;
}