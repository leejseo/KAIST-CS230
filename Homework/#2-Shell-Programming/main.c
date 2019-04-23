/*
    DO NOT MODIFY THIS CODE 
*/

#include <stdio.h> 

#include "shell.h"

int main()
{   
    char command[100];  // maximum input char length = 100
    while(true){
        fgets(command, sizeof(command), stdin); // get command line
        shell(command);
    }
}
