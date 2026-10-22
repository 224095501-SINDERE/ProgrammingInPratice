#include <stdio.h>
#include <string.h>

int main() {
    char original[100];
    char backup[100];

    printf("Enter supplier name: ");
    fgets(original, sizeof(original), stdin);
    original[strcspn(original, "\n")] = '\0';

    // Duplicate string content from source into target array 
    strcpy(backup, original);

    // Verify replication accuracy
    printf("Original array contents: %s\n", original);
    printf("Backup array contents:   %s\n", backup);

    return 0;
}
