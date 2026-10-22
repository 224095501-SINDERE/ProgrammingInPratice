#include <stdio.h>
#include <string.h>

int main() {
    char name[50] = "ABC Office Supplies";
    char town[50] = "Windhoek";
    char sentence[150] = ""; // Initialize target placeholder blank

    // Concatenate strings logically to assemble a complete statement
    strcat(sentence, name);
    strcat(sentence, " operates in ");
    strcat(sentence, town);
    strcat(sentence, ".");

    // Deliver finalized compound sentence
    printf("%s\n", sentence);

    return 0;
}
