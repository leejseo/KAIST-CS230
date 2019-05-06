#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>


int create_file(char*);
void read_file(char*, int);
void write_file(char* , char* );
void weird_copy_file(char*source, char*dest, int n);
void file(char*command);
