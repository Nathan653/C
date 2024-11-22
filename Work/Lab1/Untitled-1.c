#include <stdio.h>

#define INITIAL_STOCK 1000 // Initial stock for each paper size
#define MAX_ORDER 1000     // Maximum order per paper size

int main(void) {
    // Initialize stock for each size
    int stockA3 = INITIAL_STOCK;
    int stockA4 = INITIAL_STOCK;
    int stockA5 = INITIAL_STOCK;

    // Variables to hold user orders
    int orderA3, orderA4, orderA5;

    // Prompt the user for their orders
    printf("Enter the number of packs to order:\n");
    
    // Get A3 order
    printf("A3 packs (max %d): ", MAX_ORDER);
    scanf("%d", &orderA3);
    
    // Validate A3 order
    if (orderA3 < 0 || orderA3 > MAX_ORDER) {
        printf("Invalid order quantity for A3. Order must be between 0 and %d.\n", MAX_ORDER);
        return 1; // Exit if the input is invalid
    }

    // Get A4 order
    printf("A4 packs (max %d): ", MAX_ORDER);
    scanf("%d", &orderA4);
    
    // Validate A4 order
    if (orderA4 < 0 || orderA4 > MAX_ORDER) {
        printf("Invalid order quantity for A4. Order must be between 0 and %d.\n", MAX_ORDER);
        return 1; // Exit if the input is invalid
    }

    // Get A5 order
    printf("A5 packs (max %d): ", MAX_ORDER);
    scanf("%d", &orderA5);
    
    // Validate A5 order
    if (orderA5 < 0 || orderA5 > MAX_ORDER) {
        printf("Invalid order quantity for A5. Order must be between 0 and %d.\n", MAX_ORDER);
        return 1; // Exit if the input is invalid
    }

    // Update stock amounts based on the orders
    stockA3 -= orderA3;
    stockA4 -= orderA4;
    stockA5 -= orderA5;

    // Display order details and updated stock
    printf("\nOrder Details:\n");
    printf("A3 packs ordered: %d\n", orderA3);
    printf("A4 packs ordered: %d\n", orderA4);
    printf("A5 packs ordered: %d\n", orderA5);

    printf("\nUpdated Stock Levels:\n");
    printf("A3 packs remaining: %d\n", stockA3);
    printf("A4 packs remaining: %d\n", stockA4);
    printf("A5 packs remaining: %d\n", stockA5);

    return 0;
}
