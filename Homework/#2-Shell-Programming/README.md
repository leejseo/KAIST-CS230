# Shell Programming

## Introduction

The purpose of this assignment is to become more familiar with the C language.
You will do this by writing a simple Linux shell program that supports directory creation and deletion.

## Logistics

You should solve the problem for this assignment individually.
Any clarifications and revisions to the assignment will be posted on the course web page (KLMS).

## Project Specification

Your shell program should have the following features

 * The command line typed by the user should consist of a command name and zero or more arguments, all seperated by one or more spaces.
 * Your shell program should supports following commands:
   * The ```ls``` command prints all files and folders in the current working directory.
   The printed files and folders should be seperated by exactly ‘one’ space and ended by line break character ```\n```.  
   ex) ```"directory1 dirctory2 file1 file2\n"```
   * The ```mkdir``` command creates directory.
   * The ```rmdir``` command deletes directory.
   * The ```cd``` command changes the current working directory to target directory.
   * The ```cd ..``` command changes the current working directory to upper directory.
 
 
## Output Example
```
ls
EliceUtils.cpp EliceUtils.h main.c shell.c shell.h main
mkdir dir1
ls
EliceUtils.cpp EliceUtils.h main.c shell.c shell.h main dir1
cd dir1
ls

mkdir dir2
ls
dir2
rmdir dir2
ls

cd ..
ls
EliceUtils.cpp EliceUtils.h main.c shell.c shell.h main dir1
```

## Evaluation

Your score will be computed out of a maximum 100 points with several test cases.
We will evaluate your score on elice evaluation system.
If you copy codes from internet or from other students, you will get 0 points.
