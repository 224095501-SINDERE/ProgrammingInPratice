#include <stdio.h>

int main() {

double revenue = 0.00;
double expenses = 0.00;
double balance = 0.00;

printf("MUNICIPAL BUDGET CALCULATOR\n");
printf("-------------\n");

//Ask user to enter total revenue
printf("Enter total revenue: ");
scanf("%lf", &revenue);

//Ask user to enter total expenses
printf("Enter total expenses: ");
scanf("%lf", &expenses);
balance = revenue - expenses;

//Calculate budget balance
balance = revenue - expenses;

printf("\nRevenue:%2f\n",revenue);
printf("Expenses:%2f\n",expenses);

if(balance > 0){
    printf("Expenses: %.2f\n",balance);
}
else if(balance < 0){
    printf("Deficit:%2f\n",-balance);
}else{
    printf("The budget is balanced.\n");
}

//display the results 
printf("Budget balance: %.2lf\n", balance);

return 0;
}