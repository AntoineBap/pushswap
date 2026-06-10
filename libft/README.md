# Common-Core---Libft-b94e3700-0cf7-41a2-8ab8-555e3bb7ae4b
his activity has been created as part of the 42 curriculum by schoisi

Description :

Working in C can quickly become challenging without access to the powerful functions provided by the standard library. This project is designed to bridge that gap by guiding you through the reimplementation of essential standard functions from scratch.

The goal is not only to recreate these utilities, but to deeply understand how they work internally and how to use them efficiently in real-world scenarios. By building your own library, you strengthen your grasp of memory management, data manipulation, and core programming concepts in C.

This custom library will serve as a solid foundation for future projects, allowing you to write cleaner, more efficient code while relying on functions you fully understand and control.

Instructions :

go to the files of this project and on your terminal tap : "make", for the compilation.

Resources :

- Some tutorials on YouTube about linked lists.
- AI was used to explain the functions we had to recreate and to review my mistakes, if there were any.

detailed description :

The libft project consists of creating a custom C library regrouping a set of reusable functions that replicate and extend standard C library behavior. This library is intended to be used as a foundation for future projects throughout the 42 curriculum.

The library is organized into three main parts:

1. Libc Functions Reimplementation

The first part focuses on reimplementing standard C library functions. Each function reproduces the behavior of its original counterpart, following the same prototypes and specifications, with the ft_ prefix.

This includes:

Character type checks
String manipulation functions
Memory handling functions
Basic conversion functions

The objective is to understand how these low-level functions work internally without relying on the original implementations.

2. Additional Functions

The second part introduces utility functions that are not part of the standard library or provide extended behavior.

These functions handle:

Advanced string manipulation (substring, join, trim, split)
Data conversion (integer to string)
Functional iteration on strings
Output to file descriptors

This section improves usability and provides tools frequently needed in C projects.

3. Linked List Functions

The third part implements a singly linked list using the t_list structure:

---------------------------------------------

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;

---------------------------------------------

Functions are provided to:

Create and initialize nodes
Add elements to the front or back of a list
Access and iterate through elements
Delete nodes or entire lists
Apply functions to list content

This part introduces dynamic data structures and reinforces memory management concepts.

Technical Constraints
No use of global variables
No memory leaks
No unexpected crashes (segfault, etc.)
Compilation with -Wall -Wextra -Werror
Static library generated with ar (libft.a)
Makefile with required rules (all, clean, fclean, re)
Purpose

This library provides a solid base for understanding C programming fundamentals and will be reused in future 42 projects.
