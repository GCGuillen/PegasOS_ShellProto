//  hello.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will simply greet the User to PegasOS.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>

int main(int argv, char **argc)
{
    //printf("check |%s|",argc[2]);
    fprintf(stdout,"Hello there, %s! Welcome to PegasOS!\n",argc[2]);
    return 1;
}