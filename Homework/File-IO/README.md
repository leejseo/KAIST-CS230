# File I/O

## Introduction

The objective of this assignment is to understand basic File I/O on the system level.
You should use only "```create()```, ```open()```, ```close()```, ```write()```, ```read()```, ```lseek()```".
Please read Chapter 10 “System level I/O” of “Computer Systems: A Programmer’s Perspective” before doing this assignment.

## Specification

The command line typed by the user should consist of a command name and zero or more arguments, all seperated by one or more spaces.

You should complete four function.

* ```create_file(char* filename)```
  * create file named filename. Be careful about the permission of your file.
* ```write_file(char* filename, char* tmp)```
  * Write the contents of the tmp array to a file named filename.
  * Suppose the size of the tmp is less then 10 bytes.
  * If there is no such file, create new file.
  * If there already exist such file, erase the original contents and overwrite it.
* ```read_file(char* filename, int size)```
  * Read a function that reads a file of a given size and print it.
  * If there is no such file, print “error occured\n”.
* ```weird_copy_file(char* source, char* dest, int n)```
  * This function copy the source file with weird manner. It copy back and forth as much as n byte in iterative way.
  * See the example below to understand this function.
  * ex) n = 4, source file : “1234abcd” then contents of dest file will be “1a2b3c4d”.
  * ex) n = 2, source file : “12AB” then contents of dest file will be “1A2B”.
  * ex) n = 1, source file : “12” then contents of dest file will be “12”.
  * **notice** : the goal of this function is to understand how ```lseek()``` works. You can solve it in a different way, but you have to use ```lseek()```.
  
You can’t see your file when you creating your file.
If you want to check your files in your console, use another function you did in your last assignment.

## Output example

```
create foo.txt
write foo.txt hello
read foo.txt 5
5 hello
read foo.txt 3
3 hel
read test.txt 1
error occured
create test.txt
write foo.txt 1234abcd
copy foo.txt test.txt 4
read test.txt 8
8 1a2b3c4d
```

## Evaluation

Your score will be computed out of a maximum 100 points with several test cases.
We will evaluate your score on elice evaluation system.
If you copy codes from internet or from other students, you will get 0 points.
