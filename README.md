#HW2 Shell Program
#### Evan Terry

[![Build Status](https://travis-ci.com/csc415-03-fall-2016/evanterry-hw2.svg?token=UmFuvyGeDwK5VzxyY1Uw&branch=master)](https://travis-ci.com/csc415-03-fall-2016/evanterry-hw2)

## Problem statement:

Implement a simple shell using the C language. Implementation details are mentioned in the individual TODOs inside shell.c. The shell has two main functionalities:

* Runs a program with specified arguments
* Mantains a list of commands in a history list.

A lot of template code has been provided, use it to obtain some programming hints.

## Expected input and outputs:
```
./hw2
shell>ls
file1 file2 file3
shell>
shell>
shell>
shell>ls /
Applications some-otherfolder-in-/ something-else
shell>pwd
/usr/omar/path-to-here
shell>exit

```
Explanation:
Once you start the shell, it will prompt 'shell>' to the user. when the user enters 'ls'. That program is executed by the shell using fork() and execvp(). Shell will ignore empty lines. 'exit' will exit the shell.

## Build instructions
Just open the folder/project via CLion.

## Files to work on
You are required to work on `README.md` and `shell.c`
You are allowed to add extra files if necessary. Please **DO NOT MODIFY** any other hw files. Modifying any other file will result in penalty to your grade.

## Tests and grading criteria
This program has no tests. You will have to make this program run without errors on Travis. Travis will be used to build your solution

## Plagiarism
Please do not copy-paste from the internet or from friends. The plagiarism detection system will flag it.

## Note
* There is **no partial credit** for code that does not compile
* The program would not compile at first because the program has errors
* It is required that you add your **name** and **travis ci badge** to your readme.
* Check the logs from Travis to make sure that your program is compiling.
* Make sure your last push is before the deadline. Your last push will be considered as your final submission.
* If you need to be considered for partial grade for any reason(failing tests on travis,etc). Then email the staff before the deadline. Late email requests may not be considered.
* Vagrant is entirely optional. Use it only if your development environment is giving you problems.
* Post questions on Piazza if you have any questions.
* Please contact the course staff if you run into issues. We are here to help you!