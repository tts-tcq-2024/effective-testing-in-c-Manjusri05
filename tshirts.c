#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';

    // Handling invalid inputs (negative values)
    if (cms < 0) {
        return '\0'; // Indicate invalid input with a null character
    }

    if (cms < 38) {
        sizeName = 'S';
    } else if (cms >= 38 && cms <= 42) {
        sizeName = 'M';
    } else if (cms > 42) {
        sizeName = 'L';
    }
    
    return sizeName;
}

int main() {
    // These tests will pass
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');

    // Adding tests to check for edge cases
    assert(size(38) == 'M'); // Should return 'M'
    assert(size(42) == 'M'); // Should return 'M'
    assert(size(-1) == '\0'); // Should return null character for invalid input

    printf("All is well (maybe!)\n");
    return 0;
}
