#include "file.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

const int MAX_SIZE = 200;

/*
    Create file 
    Be careful when you set permission about your file.
*/
int create_file(char* filename) {
    int _file = open(filename, O_RDWR|O_CREAT, 0644);
    close(_file);
    return 0;
}

/*
    Read 'size' bytes in file and print it.
    If there is no such file, print ("error occured\n").
*/

void read_file(char* filename, int size) {
    int _file = open(filename, O_RDONLY);
    if (_file < 0){
        printf("error occured\n");
        return;
    }
    char buf[MAX_SIZE];
    memset(buf, 0, sizeof(buf));
    read(_file, buf, size);
    printf("%d ", size);
    printf("%s", buf);
    printf("\n");
    close(_file);
}

/*
	Open file and write char array tmp to your file.
*/
void write_file(char* filename, char* tmp) {
    int _file = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0644);
    int size = strlen(tmp);
    write(_file, tmp, size);
    close(_file);
}

/* 
    Copy the contents of source file to the dest file back and forth as much as n bytes.For example, suppose "1234abcd\n" is the content of the source file. Then "1a2b3c4d\n" will be the content of the dest file. You sholud use lseek() function.
    If there is no dest file, create it by using "create_file" funtion
*/
void weird_copy_file(char* source, char* dest, int n) {
    int _file = open(source, O_RDONLY);
    char buf[MAX_SIZE];
    memset(buf, 0, sizeof(buf));
    for (int i=0; i<n; i++){
        lseek(_file, i, SEEK_SET);
        read(_file, buf+(2*i), 1);
        lseek(_file, n-1, SEEK_CUR);
        read(_file, buf+(2*i+1), 1);
    }
    close(_file);
    write_file(dest, buf);
}

/*
    Get 'command' as an input,
    and execute proper functionalities according to command line.
*/

const char* wsp = " \n\t";
char *npt;

void file(char* command) {
    char copied[MAX_SIZE];
    strcpy(copied, command);
    char *res;
    res = strtok_r(copied, wsp, &npt);
    if (strcmp(res, "create") == 0){
        char* name = strtok_r(NULL, wsp, &npt);
        create_file(name);
        return;
    }
    if (strcmp(res, "read") == 0){
        char *name = strtok_r(NULL, wsp, &npt);
        char *l = strtok_r(NULL, wsp, &npt);
        int len = 0;
        int n = strlen(l);
        for (int i=0; i<n; i++){
            len *= 10;
            len += (int)(l[i] - '0');
        }
        read_file(name, len);
        return;
    }
    if (strcmp(res, "write") == 0){
        char *name = strtok_r(NULL, wsp, &npt);
        char *to_write = strtok_r(NULL, wsp, &npt);
        write_file(name, to_write);
        return;
    }
    if (strcmp(res, "copy") == 0){
        char *name1 = strtok_r(NULL, wsp, &npt);
        char *name2 = strtok_r(NULL, wsp, &npt);
        char *l = strtok_r(NULL, wsp, &npt);
        int len = 0;
        int n = strlen(l);
        for (int i=0; i<n; i++){
            len *= 10;
            len += (int)(l[i] - '0');
        }
        weird_copy_file(name1, name2, len);
        return;
    }
}
