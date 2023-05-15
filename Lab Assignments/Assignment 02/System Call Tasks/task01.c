//Mohammad Shafkat Hasan
//ID: 19101077
//System Call Tasks
//Task01

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Question:
Write a c program that will open a file given from the command line argument and then it will
ask the user to input strings which will be written to that file. It will continue to ask the user to
enter a string as long as the user enters “-1”. If the given file does not exist in the directory, then
your program will automatically create the file.
All code should be Unix compatible.
*/

// main function
int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[100], str[100];

    // Check if filename was provided as command line argument
    if (argc < 2) {
        printf("Please provide a filename as command line argument.\n");
        exit(1);
    }

    // Get filename from command line argument
    strcpy(filename, argv[1]);

    // Open file in write mode
    fp = fopen(filename, "w");

    // Check if file was opened successfully
    if (fp == NULL) {
        printf("Unable to open file %s.\n", filename);
        exit(1);
    }

    // Ask user to input strings
    printf("Enter a string to write to file (enter '-1' to quit):\n");
    scanf("%s", str);

    while (strcmp(str, "-1") != 0) {
        // Write string to file
        fprintf(fp, "%s\n", str);

        // Ask user for another string
        printf("Enter another string (enter '-1' to quit):\n");
        scanf("%s", str);
    }

    // Close file
    fclose(fp);

    printf("File %s has been written to.\n", filename);

    return 0;
}

/* Bash sample commands:
# Compile task01.c
gcc -o t01 task01.c

# Run sort.c with filename as command line arguments
./t01 filename
*/
