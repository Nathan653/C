#include <stdio.h>
#include <string.h>
#include <ctype.h>

int process_text(FILE *file) {
    char word[100];
    int error_count = 0;
    int prev_char_was_space = 0;

    while (fscanf(file, "%s", word) != EOF) {
        int length = strlen(word);
        int has_error = 0;

        if (length > 10) {
            int has_hyphen = 0;
            for (int i = 0; i < length; i++) {
                if (word[i] == '-') {
                    has_hyphen = 1;
                    break;
                }
            }
            if (!has_hyphen) {
                printf("Warning: '%s' is longer than 10 characters and has no hyphen.\n", word);
                has_error = 1;
            }
        }

        for (int i = 1; i < length; i++) {
            if (isupper(word[i])) {
                printf("Warning: '%s' has an uppercase character beyond the first one.\n", word);
                has_error = 1;
                break;
            }
        }

        if (!isalpha(word[0])) {
            printf("Warning: '%s' starts with a non-alphabetic character.\n", word);
            has_error = 1;
        }

        for (int i = 1; i < length; i++) {
            if (ispunct(word[i]) && word[i - 1] == ' ') {
                printf("Warning: Punctuation in '%s' is preceded by a space.\n", word);
                has_error = 1;
                break;
            }
        }

        if (prev_char_was_space && word[0] == ' ') {
            printf("Warning: Repeated spaces detected.\n");
            has_error = 1;
        }

        if (has_error) {
            error_count++;
        }

        prev_char_was_space = (word[length - 1] == ' ');
    }

    return error_count;
}

int main() {
    const char *filename = "blah.txt"; 

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    int error_count = process_text(file);
    fclose(file);

    if (error_count == 0) {
        printf("No errors found\n");
    } else if (error_count == 1) {
        printf("1 error found\n");
    } else {
        printf("%d errors found\n", error_count);
    }

    return 0;
}
