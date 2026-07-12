/*
 * Project: Library Management System
 * Language: C
 * Description:
 * Simulates a simple library system where a user can
 * issue, return, and view books.
 *
 * Author: Manisha TM
 */

#include <stdio.h>

int main() {

    int choice;
    int availableBooks = 100;

    while (1) {

        printf("\n========== LIBRARY MANAGEMENT ==========\n");
        printf("1. View Available Books\n");
        printf("2. Issue Book\n");
        printf("3. Return Book\n");
        printf("4. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\nAvailable Books: %d\n", availableBooks);
                break;

            case 2:

                if(availableBooks > 0) {
                    availableBooks--;
                    printf("\nBook Issued Successfully.\n");
                }
                else {
                    printf("\nNo Books Available.\n");
                }

                break;

            case 3:

                availableBooks++;
                printf("\nBook Returned Successfully.\n");

                break;

            case 4:

                printf("\nThank You for using Library Management System.\n");
                return 0;

            default:

                printf("\nInvalid Choice!\n");

        }

    }

    return 0;
}
