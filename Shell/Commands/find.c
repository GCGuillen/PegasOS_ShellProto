//  find.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will find the file given as a parameter and report where the file is located.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

struct stat sb;
char response[256];
int main(int argv, char ** argc)
{
    fprintf(stdout,"This is the find bin\n");
    
    return 1;
}