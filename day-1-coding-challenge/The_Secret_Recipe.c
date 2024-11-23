#include <stdio.h>

int main() {
    char inged[20][20];
    float quantity[20];
    int num = 0;

    // Input loop for ingredients
    for (int i = 0; i < 20; i++) {
        printf("Enter your Ingredient (or type 'y' to stop): ");
        scanf("%s", inged[i]);

        // Break the loop if the user inputs 'y'
        if (inged[i][0] == 'y') {
            break;
        }

        num++;
    }

    printf("\nTotal ingredients entered: %d\n", num);

    // Input quantities for each ingredient
    for (int j = 0; j < num; j++) {
        printf("Enter the quantity of %s: ", inged[j]);
        scanf("%f", &quantity[j]);
    }

    // Check quantities and collect invalid ones
    int invalid_indices[20];
    int invalid_count = 0;
printf("______________________________________________________________________________________\n");
    for (int i = 0; i < num; i++) {
        if (quantity[i] < 100 || quantity[i] > 1000) {
            printf("%s (%f) is out of the allowed range (100g to 1000g).\n", inged[i], quantity[i]);
            invalid_indices[invalid_count] = i;
            invalid_count++;
        }
    }
printf("____________________________________________________________________________\n");
    // Output the results
    if (invalid_count > 0) {
        printf("\nThe following ingredients need adjustment:\n");
        for (int j = 0; j < invalid_count; j++) {
            printf("- %s: %f\n", inged[invalid_indices[j]], quantity[invalid_indices[j]]);
        }
    } else {
        printf("\nAll ingredient quantities are within the allowed range!\n");
    }

    return 0;
}
