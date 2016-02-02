# Assignment 1
Comp Org assignment 1

DUE DATE: 8 a.m., Tuesday, February 2nd.

## Assignment Description
For this INDIVIDUAL assignment (no groups allowed) you will write a 2-D Matrix
Swap and Multiplication System on a Linux computer. The purpose of this
program is to give you experience with C programming with special emphasis on
pointers and memory allocation. A second objective is to give you experience
in working with the Unix/Linux operating system from the shell/command line
prospective.

For a tutorial on basic matrix multiplication (if you've forgotten), please
goto the following:

[http://en.wikipedia.org/wiki/Matrix_multiplication](http://en.wikipedia.org/wiki/Matrix_multiplication)

Here you will read into memory an `NxN` array/matrix of doubles, compute the
swap of that matrix and then compute the multiplication of the original
matrix. An example matrix will be provided for you.

The swap matrix operation is implemented as follows: the *i*th column is
exchanged/swapped with the contents of the *i+2* column. So, column 0 is
swapped with column 2 and column 1 is swapped with column 3 and so on until
all columns are swapped upto column *N-1* for an `NxN` matrix.

The detail specifications are as follows:

* Use your favorite Linux editor (nano, vi or emacs) to view the "mm.c" file. Nano is easiest to learn while emacs has much more power.
* You must WRITE the functions given in the template.
* Each routine indicates what needs to be done in comments.
* You cannot under any circumstances modify the main function or
  the function prototypes of any of the other routines. You have to use
  the template that is given to you.

## Grading Criteria

* Correctness: 85\%
  - allocates and frees memory correctly.
  - Computes matrix swap correctly.
  - Computes matrix multiplication correctly.
  - Checks for return values on all functions.
* Documentation/Comments: 15\% (i.e., liberal use of comments so we can understand your program).
