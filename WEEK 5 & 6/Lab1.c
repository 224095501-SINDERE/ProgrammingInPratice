#include <stdio.h>
int main(){
    //declaring variables
    //1.Ask for Salary from emppoyee
    //2.Initialize highest and lowest with the first valid entry
    //3.Declaring average
    //4.Declaring total
    //5.Declaring highest
    //6.Declaring lowest
float salary;
float total = 0;
float highest;
float lowest;
float average;
for (int i = 1; i <= 50; i++) {
printf("Enetr salary for employee %d: ", i);
scanf("%f", &salary);

total = total + salary;

//Initialize highest and lowest with the very first employee's salary
if (i == 1) {
highest = salary;
lowest = salary;
} else{
    //Check for new highest or lowest
if (salary > highest) {
highest = salary;

}
if (salary < lowest) {
lowest = salary;
}
}
}

average = total / 50;

printf("\n--- Salary Report ---\n");
printf("Average salary: %.2f\n", average);
printf("Highest salary: %.2f\n", highest);
printf("Lowest salary: %.2f\n", lowest);

return 0;
}