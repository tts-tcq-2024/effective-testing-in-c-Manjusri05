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
        // Intentionally introduce a bug by not incrementing the count for one case
        if (celcius < 200) {
            // This condition will prevent counting for the first call
            alertFailureCount += 0; // No increment
        } else {
            alertFailureCount += 1; // This will increment for other c
