The C Terminal Emulator is a lightweight, efficient program designed to replicate the functionality of a traditional terminal within a command-line interface. Developed using the C programming language, this emulator provides users with a seamless experience for executing commands, navigating directories, and interacting with the system.

AUTHORS:
Lillian Ngohuynh

NECESSARY FILES AND DOCUMENTATION:
main.c
The main .c file containing the code for a shell program. of a custom shell program with certain built-in commands such as exit, cd, and showpid. The shell provides a command-line interface for users to interact with the system. 

MakeFile
The makefile file allows for easy running and compilation of the main.c file. It is a script that generates executable programs, and includes all of the targets, dependencies, and rules required to run the main.c program.

README.txt
This file serves as an introductory document for this project. It contains important information regarding how to execute the program, what the program consists of, what users can expect of the program, the authors of the program, licensing agreements, and some additional information depending on the program's complexity. 

INSTRUCTIONS TO COMPILE main.c:
First, ensure the main.c file and the Makefile file are in the same directory. Then, in the terminal, type in make and hit enter. After such, the terminal should process the request and then go back to asking for input from you, the user. The program is now compiled. To run the file, see INSTRUCTIONS FOR RUNNING main.c.

INSTRUCTIONS FOR RUNNING main.c: 
Once the file is compiled, the terminal should be asking for input. Type in ./main and press enter. The program is now running. You should be provided with a command line interface, with the directories this file is in, listed and in red. You are prompted for commands and necessary arguments to run those commands. You can do a variety of commands, from cat and vi, to cd and pwd. You can also exit the program whenever by typing in the command, exit. 

CHALLENGES AND CONSTRAINTS:
It had been a while since I had coded in C, and thus it took a while getting used to the syntax and necessary functions to run the program. It was also difficult fully determining if your processes forked correctly, and attempting to show the pid of each process. I also took a while trying to get the execvp function to work.

SOURCES:
IBM: https://www.ibm.com/docs/en/zos/3.1.0
GNU: https://www.gnu.org/software/libc/manual/html_node/Concept-Index.html
CS 50 Stack Exchange: https://cs50.stackexchange.com
GeeksForGeeks: https://www.geeksforgeeks.org
StackOverFlow: https://stackoverflow.com
TutorialsPoint: https://www.tutorialspoint.com/index.htm
Professor Chowdhury's lecture_project_1_discussion.pptx
Professor Chowdhury's proj1-1.pdf

LICENSING:
MIT License

Copyright (c) [2023] [Lillian Ngohuynh]

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INC
