#include <stdio.h>
#include <string.h>

int main() {
    char name[100] = "";
    char searchName[100];
    int choice;

    do {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline element

        switch(choice) {
            case 1:
                printf("Enter supplier name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                break;
            case 2:
                if (strlen(name) == 0) printf("No supplier recorded.\n");
                else printf("Supplier Name: %s\n", name);
                break;
            case 3:
                printf("Enter supplier name to search: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0';
                if (strcmp(name, searchName) == 0) printf("Supplier found.\n");
                else printf("Supplier not found.\n");
                break;
            case 4:
                printf("Supplier name length: %zu\n", strlen(name));
                break;
            case 5:
                printf("Exiting application.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
