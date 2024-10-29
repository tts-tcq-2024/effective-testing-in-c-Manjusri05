#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAJOR_COLOR_COUNT 5
#define MINOR_COLOR_COUNT 5

const char* majorColor[MAJOR_COLOR_COUNT] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[MINOR_COLOR_COUNT] = {"Blue", "Orange", "Green", "Brown", "Slate"};

void printColorMap() {
    for (int i = 0; i < MAJOR_COLOR_COUNT; i++) {
        for (int j = 0; j < MINOR_COLOR_COUNT; j++) {
            printf("%d | %s | %s\n", i * MINOR_COLOR_COUNT + j, majorColor[i], minorColor[j]);
        }
    }
}

void testPrintColorMap() {
    // Expected output
    const char* expectedOutput[MAJOR_COLOR_COUNT * MINOR_COLOR_COUNT] = {
        "0 | White | Blue",
        "1 | White | Orange",
        "2 | White | Green",
        "3 | White | Brown",
        "4 | White | Slate",
        "5 | Red | Blue",
        "6 | Red | Orange",
        "7 | Red | Green",
        "8 | Red | Brown",
        "9 | Red | Slate",
        "10 | Black | Blue",
        "11 | Black | Orange",
        "12 | Black | Green",
        "13 | Black | Brown",
        "14 | Black | Slate",
        "15 | Yellow | Blue",
        "16 | Yellow | Orange",
        "17 | Yellow | Green",
        "18 | Yellow | Brown",
        "19 | Yellow | Slate",
        "20 | Violet | Blue",
        "21 | Violet | Orange",
        "22 | Violet | Green",
        "23 | Violet | Brown",
        "24 | Violet | Slate"
    };

    // Redirect stdout to capture printed output
    FILE *output = fopen("output.txt", "w");
    if (!output) {
        perror("Failed to open output file");
        return;
    }
    // Backup stdout
    FILE *original_stdout = stdout;
    stdout = output;

    // Call the function that prints the color map
    printColorMap();

    // Restore stdout
    stdout = original_stdout;
    fclose(output);

    // Read the output from the file
    FILE *input = fopen("output.txt", "r");
    if (!input) {
        perror("Failed to open output file");
        return;
    }

    char line[100];
    int index = 0;

    // Compare each line of the output with expected values
    while (fgets(line, sizeof(line), input) != NULL && index < MAJOR_COLOR_COUNT * MINOR_COLOR_COUNT) {
        // Remove the newline character for comparison
        line[strcspn(line, "\n")] = 0;  
        assert(strcmp(line, expectedOutput[index]) == 0);
        index++;
    }

    fclose(input);

    // Check if we printed the expected number of lines
    assert(index == MAJOR_COLOR_COUNT * MINOR_COLOR_COUNT);
}

int main() {
    testPrintColorMap(); // Run the test
    printf("All tests passed (maybe!)\n");
    return 0;
}
