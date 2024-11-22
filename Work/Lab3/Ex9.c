#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_RANGE -100.0  
#define MAX_RANGE 100.0    

bool is_valid_number(double num) {
    return num >= MIN_RANGE && num <= MAX_RANGE;
}

void process_input(FILE *input_file, FILE *output_file) {
    double num;
    while (fscanf(input_file, "%lf", &num) == 1) {  
        if (is_valid_number(num)) {
            fprintf(output_file, "%lf\n", num); 
        } else {
            printf("Warning: %lf is out of range (%lf to %lf)\n", num, MIN_RANGE, MAX_RANGE);
        }
    }
}

int main() {
    const char *input_filename = "input.txt";   
    const char *output_filename = "output.txt";

    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }


    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file); 
        return EXIT_FAILURE;
    }

    process_input(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Processing complete. Valid numbers have been written to '%s'.\n", output_filename);
    
    return EXIT_SUCCESS;
}
