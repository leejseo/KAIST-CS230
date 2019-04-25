#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
/*
    Print all files and folders in the current working directory,
*/


void ls(){ 
    DIR *parent_dir;
    struct dirent *parent_dirent;
    const char *delim = "";
    parent_dir = opendir(".");
    if (!parent_dir) return;
    if (parent_dir != NULL){
        while ((parent_dirent = readdir(parent_dir))){
            if (!strcmp(parent_dirent->d_name, ".") || !strcmp(parent_dirent->d_name, "..")) continue;
            printf("%s%s", delim, parent_dirent->d_name);
            delim = " ";
        }
    }
    closedir(parent_dir);
    printf("\n");
}

/*
    Make a new directory called 'name'.
*/
void makedir(char* name){
    mkdir(name, 0770);
}


/*
    Remove a directory called 'name'.
*/
void removedir(char* name){
    rmdir(name);
}


/*
    Change current working directory to directory 'name'.
*/
void changedir(char* name){ 
    chdir(name);
}


char copied[300];

/*
    Get 'command' as an input,
    and execute proper functionalities according to command line.
*/

char *npt;
const char wsp[] = " \n\t";

void shell (char* command){
    memset(copied, 0, sizeof(copied));
    strcpy(copied, command);
    char* res;
    res = strtok_r(copied, wsp, &npt);
    if (strcmp(res, "ls") == 0){
        ls(); return;
    }
    
    if (strcmp(res, "mkdir") == 0){
        res = strtok_r(NULL, wsp, &npt);
        while (res != NULL){
            makedir(res);
            res = strtok_r(NULL, wsp, &npt);
        }
        return;
    }
    if (strcmp(res, "rmdir") == 0){
        res = strtok_r(NULL, wsp, &npt);
        while (res != NULL){
            removedir(res);
            res = strtok_r(NULL, wsp, &npt);
        }
        return;
    }
    if (strcmp(res, "cd") == 0){
        res = strtok_r(NULL, wsp, &npt);
        while (res != NULL){
            changedir(res);
            res = strtok_r(NULL, wsp, &npt);
        }
        return;
    }
}
