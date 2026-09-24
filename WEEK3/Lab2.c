#include <stdio.h>

int main() {

    char studentName[50];
    double test1 = 0.00;
    double test2 = 0.00;
    double assignment = 0.00;
    double total = 0.00;

    //ask user to input student name
    printf("Enter student name: ");
    scanf("%d", &studentName);

    //ask user to input test1 mask
    printf("Enter test 1 mark: ");
    scanf("%lf", &test1);

    //ask user to input test 2 mark
    printf("Enter test 2 mark: ");
    scanf("%lf", &test2);

    //ask user to input assignment mark
    printf("Enter Assignment mark: ");
    scanf("%lf", &assignment);

    //calculate total mark
    total = test1 + test2 + assignment;

    //display the results
    printf("\nStudent Name: %d\n", studentName);
    printf("Total Mark: %.2lf\n", total);

    //determine the results
    if (total >= 75) {
        printf("Distinction");
    }
    else if (total >= 60) {
        printf("Credit");
    }
    else if (total >= 50) {
        printf("Pass");
    }
    else {
        printf("Fail");
    }
    
    return 0;
}
