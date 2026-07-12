/*
 * Project: Electricity Bill Calculator
 * Language: C
 * Description:
 * Calculates the electricity bill based on slab rates.
 *
 * Author: Manisha TM
 */

#include <stdio.h>

int main() {
    int units;
    float bill = 0;

    printf("========== Electricity Bill Calculator ==========\n");

    printf("Enter electricity units consumed: ");
    scanf("%d", &units);

    if (units <= 100) {
        bill = units * 1.5;
    }
    else if (units <= 200) {
        bill = (100 * 1.5) + ((units - 100) * 2.5);
    }
    else if (units <= 300) {
        bill = (100 * 1.5) + (100 * 2.5) + ((units - 200) * 4.0);
    }
    else {
        bill = (100 * 1.5) + (100 * 2.5) + (100 * 4.0) + ((units - 300) * 6.0);
    }

    if (bill > 1000)
        bill += bill * 0.05;

    printf("\n----------- Bill Summary -----------\n");
    printf("Units Consumed : %d\n", units);
    printf("Total Bill     : ₹%.2f\n", bill);

    return 0;
}
