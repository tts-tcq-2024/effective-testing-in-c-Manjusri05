#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

// Modify the stub to simulate a failure
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Simulate failure if the temperature exceeds a threshold, e.g., 100°C
    if (celcius > 100) {
        return 500; // Simulate a non-ok response
    }
    return 200; // Simulate a successful alert
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Increment failure count correctly when there is a non-ok response
        alertFailureCount += 1; // This should increment for non-ok responses
    }
}

int main() {
    alertInCelcius(400.5); // This should trigger a failure
    alertInCelcius(303.6); // This should trigger a failure too

    // Check if the failure count is as expected (should be 2 for this case)
    assert(alertFailureCount == 2); // This assertion will fail if the count is incorrect

    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
