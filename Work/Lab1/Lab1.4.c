#include <stdio.h>

void butler(const char* name); // Change the prototype to accept a name

int main(void) {
    printf("I will summon the butler function.\n");

    // Call butler with a name
    butler("John");

    printf("Yes. Bring me some tea and writeable CD-ROMS.\n");

    return 0;
}

void butler(const char* name) { // Accept a name as a parameter
    printf("You rang, %s?\n", name); // Use %s to display the name
}
