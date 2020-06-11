//  copy.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 6/1/2020
//	Summary: This file will copy one file with it's contents to a different directory.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// This is in development. Still looking at how to accomplish this task.

struct stat sb;
char response[256];
int src_fd, dst_fd, n, err;
unsigned char buffer[4096];
int main(int argv, char **argc)
{
    fprintf(stdout,"This is the copy bin\n");
    fprintf(stdout,"Are you certain you want to copy %s into %s?\n[y]es\n[n]\n",argc[1],argc[2]);
    fscanf(stdin,"%s",response);
    if(strcmp("y",response)==0)
    {
        if (stat(argc[1], &sb) == 0 && S_ISREG(sb.st_mode))
        {
            fprintf(stdout,"File %s exists!\n",argc[1]);
            if (stat(argc[2], &sb) == 0 && S_ISDIR(sb.st_mode))
            {
                fprintf(stdout,"Directory %s exists!\n",argc[2]);
                src_fd = open(argc[1], O_RDONLY);
                dst_fd = open(argc[2], O_CREAT | O_WRONLY);
                while (1) {
                    err = read(src_fd, buffer, 4096);
                    if (err == -1) {
                        printf("Error reading file.\n");
                        exit(1);
                    }
                    n = err;
                    if (n == 0) break;
                    err = write(dst_fd, buffer, n);
                    if (err == -1) {
                        printf("Error writing to file.\n");
                        exit(1);
                    }
                }
                close(src_fd);
                close(dst_fd);
            }
            else
            {
                fprintf(stdout,"The directory does not exist!\n");
            }
        }
        else
        {
            fprintf(stdout,"File %s does not exist!\n",argc[1]);
        }
    }
    else if(strcmp("n",response)==0)
    {
        fprintf(stdout,"The file %s was not copied to the directory!\n",argc[1]);
    }
    return 1;
}