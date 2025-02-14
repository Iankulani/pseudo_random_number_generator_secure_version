#include <stdio.h>
#include <stdlib.h>

// Function to generate pseudo-random numbers using Linear Congruential Generator (LCG)
void generate_pseudo_random(int seed, int a, int c, int m, int length, const char* filename) {
    int current = seed;
    FILE *file = fopen(filename, "w");  // Open the file for writing

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(file, "Generated %d pseudo-random numbers:\n", length);

    for (int i = 0; i < length; ++i) {
        current = (a * current + c) % m;
        fprintf(file, "%d ", current);  // Save each random number to the file
    }

    fclose(file);  // Close the file
    printf("Random numbers have been saved to %s\n", filename);
}

int main() {
    int seed, a, c, m, length;
    char filename[256];

    printf("Welcome to the Pseudo-Random Number Generator Tool\n");

    // User input for PRNG parameters
    printf("Enter the seed value:");
    if (scanf("%d", &seed) != 1) {
        printf("Invalid input! Please enter a valid integer for the seed.\n");
        return 1; // Exit if invalid input
    }

    printf("Enter the multiplier (a):");
    if (scanf("%d", &a) != 1) {
        printf("Invalid input! Please enter a valid integer for the multiplier.\n");
        return 1; // Exit if invalid input
    }

    printf("Enter the increment (c):");
    if (scanf("%d", &c) != 1) {
        printf("Invalid input! Please enter a valid integer for the increment.\n");
        return 1; // Exit if invalid input
    }

    printf("Enter the modulus (m):");
    if (scanf("%d", &m) != 1) {
        printf("Invalid input! Please enter a valid integer for the modulus.\n");
        return 1; // Exit if invalid input
    }

    printf("Enter the number of pseudo-random numbers to generate:");
    if (scanf("%d", &length) != 1 || length <= 0) {
        printf("Invalid input! Please enter a valid positive integer for the number of numbers to generate.\n");
        return 1; // Exit if invalid input
    }

    // Ask the user for the filename to save the generated numbers
    printf("Enter the filename to save the generated numbers (default: random_numbers.txt):");
    getchar();  // Consume leftover newline character
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;  // Remove the newline character from input

    // If no filename is entered, use the default filename
    if (filename[0] == '\0') {
        snprintf(filename, sizeof(filename), "random_numbers.txt");
    }

    // Generate pseudo-random numbers and save them to the file
    generate_pseudo_random(seed, a, c, m, length, filename);

    return 0;
}
