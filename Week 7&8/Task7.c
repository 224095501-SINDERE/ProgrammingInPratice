#include <stdio.h>
#include <string.h>

#define SIZE 5

int main() {
    // Parallel data storage configurations
    char names[SIZE][100];
    char emails[SIZE][100];
    char phones[SIZE][30];
    char towns[SIZE][50];
    char query[100];
    int count = 0;

    // Population stage loop
    for (int i = 0; i < SIZE; i++) {
        printf("\n--- Entry %d of %d ---\n", i + 1, SIZE);
        printf("Enter name: ");
        fgets(names[i], 100, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
        
        printf("Enter email: ");
        fgets(emails[i], 100, stdin);
        emails[i][strcspn(emails[i], "\n")] = '\0';

        printf("Enter phone: ");
        fgets(phones[i], 30, stdin);
        phones[i][strcspn(phones[i], "\n")] = '\0';

        printf("Enter town: ");
        fgets(towns[i], 50, stdin);
        towns[i][strcspn(towns[i], "\n")] = '\0';
    }

    // Processing search request 
    printf("\nEnter supplier name to search: ");
    fgets(query, 100, stdin);
    query[strcspn(query, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(names[i], query) == 0) {
            printf("\nSupplier found!\nName: %s\nEmail: %s\nPhone: %s\nTown: %s\n", 
                   names[i], emails[i], phones[i], towns[i]);
            found = 1;
            break;
        }
    }
    if (!found) printf("Supplier not found.\n");

    return 0;
}
