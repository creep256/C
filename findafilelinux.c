#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
int main()
{
    char *file_name="index.html";
    DIR *dir;
    dir=opendir(".");
    struct dirent *entry;
    char *found_file_name=NULL;
    while((entry=readdir(dir))!=NULL){
        if(strcmp(entry->d_name,file_name)==0){
            found_file_name=entry->d_name;
            printf("Found : %s",found_file_name);
            break;
        }
    }
    closedir(dir);
    
}