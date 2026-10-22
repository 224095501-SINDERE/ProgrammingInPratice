#include <stdio.h>
#include <string.h>

// Global constants for array sizing
#define EMP_SIZE 5

// --- Function Prototypes ---
void displayMainMenu();
void handleEmployeeSalary();
void handleVAT();
void handleBudget();
void handleEmployeeSearch();
void handleSupplierManagement();

// Reusable calculation logic functions
float calculateSalary(float basic, float housing, float transport);
float calculateVAT(float amount);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

int main() {
    int choice;

    // Execution loop driven entirely by modular function routing
    do {
        displayMainMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid numeric choice input.\n");
            break;
        }
        getchar(); // Clear trailing newline from the buffer

        switch(choice) {
            case 1:
                handleEmployeeSalary();
                break;
            case 2:
                handleVAT();
                break;
            case 3:
                handleBudget();
                break;
            case 4:
                handleEmployeeSearch();
                break;
            case 5:
                handleSupplierManagement();
                break;
            case 6:
                printf("Exiting system. Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please pick an option from 1 to 6.\n");
        }
    } while(choice != 6);

    return 0;
}

// Visual layout rendering function
void displayMainMenu() {
    printf("\n============================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

// Interface handler wrapping salary computations
void handleEmployeeSalary() {
    float basic, housing, transport;
    printf("\n--- Calculate Salary Subsystem ---\n");
    printf("Enter basic salary: ");
    scanf("%f", &basic);
    printf("Enter housing allowance: ");
    scanf("%f", &housing);
    printf("Enter transport allowance: ");
    scanf("%f", &transport);

    float gross = calculateSalary(basic, housing, transport);
    printf("Total Gross Salary: %.2f\n", gross);
}

// Interface handler wrapping VAT computations
void handleVAT() {
    float amount;
    printf("\n--- Calculate VAT Subsystem ---\n");
    printf("Enter monetary amount: ");
    scanf("%f", &amount);

    float vat = calculateVAT(amount);
    printf("Calculated VAT (15%%): %.2f\n", vat);
}

// Interface handler wrapping budget calculations
void handleBudget() {
    float revenue, expenses;
    printf("\n--- Calculate Budget Subsystem ---\n");
    printf("Enter total municipality revenue: ");
    scanf("%f", &revenue);
    printf("Enter total operational expenses: ");
    scanf("%f", &expenses);

    float balance = calculateBudget(revenue, expenses);
    printf("Budget balance: %.2f\n", balance);
    if (balance > 0) printf("Financial Position: SURPLUS\n");
    else if (balance < 0) printf("Financial Position: DEFICIT\n");
    else printf("Financial Position: BALANCED\n");
}

// Interface handler wrapping linear employee searching routines
void handleEmployeeSearch() {
    int targetID;
    int data[EMP_SIZE] = {101, 102, 103, 104, 105};

    printf("\n--- Search Employee Subsystem ---\n");
    printf("Enter employee ID: ");
    scanf("%d", &targetID);

    int pos = searchEmployee(targetID, data, EMP_SIZE);
    if (pos != -1) {
        printf("Employee verified. Found at memory index position %d.\n", pos);
    } else {
        printf("Access Error: Employee ID not found inside database.\n");
    }
}

// Interface handler wrapping string manipulation tasks for suppliers
void handleSupplierManagement() {
    char sName[100];
    char sTown[50];
    char combined[160] = "";

    printf("\n--- Supplier Management Subsystem ---\n");
    printf("Enter supplier name: ");
    fgets(sName, sizeof(sName), stdin);
    sName[strcspn(sName, "\n")] = '\0'; // Remove newline character

    printf("Enter operating town: ");
    fgets(sTown, sizeof(sTown), stdin);
    sTown[strcspn(sTown, "\n")] = '\0';

    // Construct descriptive sentence string
    strcat(combined, sName);
    strcat(combined, " operates in ");
    strcat(combined, sTown);
    strcat(combined, ".");

    printf("Generated Profile Sentence:\n-> %s\n", combined);
}

// Core computational logic math wrappers
float calculateSalary(float basic, float housing, float transport) { return basic + housing + transport; }
float calculateVAT(float amount) { return amount * 0.15f; }
float calculateBudget(float revenue, float expenses) { return revenue - expenses; }
int searchEmployee(int id, int ids[], int size) {
    for(int i = 0; i < size; i++) {
        if(ids[i] == id) return i;
    }
    return -1;
}
