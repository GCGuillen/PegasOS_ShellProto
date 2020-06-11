#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#define DESTINATION_FOLDER "/mnt/c/users/guill/desktop/Root"
#define SOURCE_FOLDER "/mnt/c/users/guill/desktop/Root/dummy.txt" 

void printdir()
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    struct tm      *tm;

    char src_folder[1024];
    char dest_folder[1024];


    if((dp = opendir(SOURCE_FOLDER)) == NULL) {
         fprintf(stderr,"cannot open directory: %s\n", SOURCE_FOLDER);
         return;
    }
    chdir(SOURCE_FOLDER);
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);

        if(!S_ISDIR(statbuf.st_mode)) \
        {
             sprintf(src_folder,"%s%s", SOURCE_FOLDER,entry->d_name); 
             sprintf(dest_folder,"%s%s", DESTINATION_FOLDER,entry->d_name); 
             printf("%s----------------%s\n",entry->d_name,dest_folder);
             rename(src_folder, dest_folder);
        }
    }
    chdir("..");
    closedir(dp);
}

int main()
{
    while(1)
    {
        printdir();
     }
    //rename("aaa.txt", "/home/second/bbb.txt");
    printf("done.\n");
    exit(0);
}