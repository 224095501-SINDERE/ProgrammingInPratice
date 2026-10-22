#include <stdio.h>
#include <string.h>

int main() {
    // Declare character arrays to store text details
    char name[100];
    char email[100];
    char phone[30];
    char town[50];

    // Request inputs from user via fgets to preserve string whitespace
    printf("Enter supplier name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);

    // Display formatted results back to the screen
    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s", name);
    printf("Email: %s", email);
    printf("Phone: %s", phone);
    printf("Town : %s", town);

    return 0;
}
