#include <stdio.h>

int main() {
    FILE *fs; // File pointer for source file
    FILE *ft; // File pointer for target file
    char ch;

    // Open input.txt in read mode ("r") and output.txt in write mode ("w")
    fs = fopen("input.txt", "r");
    ft = fopen("output.txt", "w");

    // Loop to read and write characters
    while (1) {
        ch = fgetc(fs); // Read character from source
        
        if (ch == EOF)
            break; // Exit loop when End Of File is reached
        else
            fputc(ch, ft); // Write character to target
    }

    fclose(fs); // Close source file
    fclose(ft); // Close target file
return 0;
}
