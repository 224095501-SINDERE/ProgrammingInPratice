#include <stdio.h>
#include <string.h>

// Database allocation constraints matching curriculum criteria
#define MAX 5

// --- Global Parallel Storage Arrays for Supplier Data Management ---
char names[MAX][100];
char emails[MAX][100];
char phones[MAX][30];
char towns[MAX][50];
int count = 0; // Tracking active records

// --- Exact Specified Structural Prototypes ---
void displayMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);

int main() {
    int choice;
    float tempAmount, b, h, t, rev, exp, balance;

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu option selection type.\n");
            break;
        }
        getchar(); // Clear internal stdin stream buffer

        switch(choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                printf("Enter amount: ");
                scanf("%f", &tempAmount);
                printf("VAT: %.2f\n", calculateVAT(tempAmount));
                break;
            case 5:
                printf("Basic salary: "); scanf("%f", &b);
                printf("Housing allowance: "); scanf("%f", &h);
                printf("Transport allowance: "); scanf("%f", &t);
                printf("Gross salary: %.2f\n", calculateSalary(b, h, t));
                break;
            case 6:
                printf("Enter revenue: "); scanf("%f", &rev);
                printf("Enter expenses: "); scanf("%f", &exp);
                balance = calculateBudget(rev, exp);
                printf("Budget balance: %.2f\n", balance);
                if (balance > 0) printf("SURPLUS\n");
                else if (balance < 0) printf("DEFICIT\n");
                else printf("BALANCED\n");
                break;
            case 7:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice index. Try again.\n");
        }
    } while(choice != 7);

    return 0;
}

// Assignment Specified Menu Layout Function
void displayMenu() {
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
}

// Adds a new entry into the global structural database
void addSupplier() {
    if (count >= MAX) {
        printf("Database Error: Maximum supplier registry capacity achieved.\n");
        return;
    }

    printf("Enter supplier name: ");
    fgets(names[count], 100, stdin);
    names[count][strcspn(names[count], "\n")] = '\0'; // Strip internal newline

    printf("Enter email: ");
    fgets(emails[count], 100, stdin);
    emails[count][strcspn(emails[count], "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phones[count], 30, stdin);
    phones[count][strcspn(phones[count], "\n")] = '\0';

    printf("Enter town: ");
    fgets(towns[count], 50, stdin);
    towns[count][strcspn(towns[count], "\n")] = '\0';

    count++; // Advance index registry location counter
    printf("Supplier entry logged successfully.\n");
}

// Loops through and logs current information parameters to standard stream
void displaySupplier() {
    if (count == 0) {
        printf("No active suppliers are present inside the memory system.\n");
        return;
    }

    printf("\n--- SUPPLIER DETAILS ---\n");
    for(int i = 0; i < count; i++) {
        printf("Name : %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Phone: %s\n", phones[i]);
        printf("Town : %s\n", towns[i]);
        printf("------------------------\n");
    }
}

// Validates whether string array arguments contain matching terms
void searchSupplier() {
    char term[100];
    int matchingFlag = 0;

    if (count == 0) {
        printf("No data records available to search.\n");
        return;
    }

    printf("Enter supplier name to search: ");
    fgets(term, sizeof(term), stdin);
    term[strcspn(term, "\n")] = '\0';

    for(int i = 0; i < count; i++) {
        // Evaluate matching records using string comparisons
        if(strcmp(names[i], term) == 0) {
            printf("\nSupplier found matching query criteria:\n");
            printf("Name: %s | Town: %s | Email: %s\n", names[i], towns[i], emails[i]);
            matchingFlag = 1;
            break;
        }
    }
    if (!matchingFlag) printf("Supplier data record matches not found.\n");
}

// Assignment Financial Logic Math Layout Blocks
float calculateVAT(float amount) { return amount * 0.15f; }
float calculateSalary(float basic, float housing, float transport) { return basic + housing + transport; }
float calculateBudget(float revenue, float expenses) { return revenue - expenses; }
