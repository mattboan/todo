#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>


// Check if the file exists
bool exists(const char * filename) {
    FILE * file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

int main() {
    // Get the current time
    time_t t = time(NULL);
    struct tm *timeinfo = localtime(&t);

    // Format the date as DDMMYY
    char date[30];
    strftime(date, sizeof(date), "/home/void/todo/%d%m%y", timeinfo);

    // Check if the file exits
    if (!exists(date)) {
        // Create a new file with the date as the filename
        FILE *file = fopen(date, "w");
        if (file == NULL) {
            printf("Failed to create the file.\n");
            return 1;
        }

        // Better string formated date DDth Month YYYYY
        const date_str[20];
        strftime(date_str, sizeof(date_str), "%dth %B %Y", timeinfo);

        // Write the date and ASCII art to the file
        fprintf(file, "%s\n\n", date_str);

        // Write the ASCII art
        fprintf(file, "██╗░░░██╗░█████╗░██╗██████╗░\n██║░░░██║██╔══██╗██║██╔══██╗\n╚██╗░██╔╝██║░░██║██║██║░░██║\n░╚████╔╝░██║░░██║██║██║░░██║\n░░╚██╔╝░░╚█████╔╝██║██████╔╝\n░░░╚═╝░░░░╚════╝░╚═╝╚═════╝░\n\n");

        // Close the file
        fclose(file);
    }

    // Open the file in NeoVim
    char command[100];
    snprintf(command, sizeof(command), "nvim %s", date);
    system(command);

    return 0;
}
