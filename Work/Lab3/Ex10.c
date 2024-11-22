#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    double price;
} Item;

void display_menu();
void add_items_to_cart(Item *cart, int *cart_count, double *total);
void show_current_total(double total);
void checkout(Item *cart, int cart_count, double total);
void cancel_session(Item *cart, int *cart_count, double *total);

int main() {
    Item cart[MAX_ITEMS];  // Shopping cart
    int cart_count = 0;    // Number of items in the cart
    double total = 0.0;    // Current total

    while (1) {
        display_menu();
        char choice;
        printf("Please enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_items_to_cart(cart, &cart_count, &total);
                break;
            case '2':
                show_current_total(total);
                break;
            case '3':
                checkout(cart, cart_count, total);
                cart_count = 0;  // Reset the cart after checkout
                total = 0.0;     // Reset the total
                break;
            case '4':
                cancel_session(cart, &cart_count, &total);
                break;
            case 'q':
                printf("Are you sure you want to quit? (y/n): ");
                char quit_confirm;
                scanf(" %c", &quit_confirm);
                if (quit_confirm == 'y' || quit_confirm == 'Y') {
                    printf("Goodbye!\n");
                    return 0;
                }
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n---- Shopping Cart Menu ----\n");
    printf("1. Add items to shopping cart\n");
    printf("2. Show current total\n");
    printf("3. Check out\n");
    printf("4. Cancel session\n");
    printf("q. Quit\n");
}

void add_items_to_cart(Item *cart, int *cart_count, double *total) {
    Item items[] = {
        {"Apple", 1.99},
        {"Banana", 0.99},
        {"Carrot", 2.49},
        {"Doughnut", 1.50},
        {"Eggplant", 3.00}
    };
    int num_items = sizeof(items) / sizeof(items[0]);

    printf("\nSelect an item to add to your cart:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }

    int choice;
    printf("Enter item number (1-%d): ", num_items);
    scanf("%d", &choice);

    if (choice < 1 || choice > num_items) {
        printf("Invalid item number.\n");
        return;
    }

    int quantity;
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    cart[*cart_count] = items[choice - 1];
    (*cart_count)++;
    *total += items[choice - 1].price * quantity;

    printf("Added %d x %s to your cart. Current total: $%.2f\n", quantity, items[choice - 1].name, *total);
}

void show_current_total(double total) {
    printf("\nCurrent total: $%.2f\n", total);
}

void checkout(Item *cart, int cart_count, double total) {
    if (cart_count == 0) {
        printf("Your cart is empty. Please add items first.\n");
        return;
    }

    printf("\n--- Itemized Bill ---\n");
    for (int i = 0; i < cart_count; i++) {
        printf("%s - $%.2f\n", cart[i].name, cart[i].price);
    }
    printf("---------------------\n");
    printf("Total: $%.2f\n", total);

    printf("Thank you for shopping with us! Your cart is now reset.\n");
}

void cancel_session(Item *cart, int *cart_count, double *total) {
    if (*cart_count == 0) {
        printf("No items in the cart to cancel.\n");
        return;
    }

    printf("Are you sure you want to cancel the session and clear your cart? (y/n): ");
    char cancel_confirm;
    scanf(" %c", &cancel_confirm);

    if (cancel_confirm == 'y' || cancel_confirm == 'Y') {
        *cart_count = 0;
        *total = 0.0;
        printf("Session canceled. Your cart is now empty.\n");
    }
}
