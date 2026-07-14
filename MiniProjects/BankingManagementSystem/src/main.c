#include <stdio.h>
#include "../include/menu.h"
#include "../include/account.h"
#include "../include/transaction.h"
#include "../include/file_manager.h"
#include "../include/transaction_history.h"

int main()
{
    int choice;

    loadAccounts();

    while(1)
    {
        displayMenu();

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                searchAccount();
                break;

            case 6:
                displayAllAccounts();
                break;

            case 7:
                updateAccount();
                break;

            case 8:
                deleteAccount();
                break;

            case 9:
                viewTransactionHistory();
                break;

            case 10:
                bankDashboard();
                break;

            case 11:
                saveAccounts();

                printf("\n=====================================\n");
                printf(" Accounts Saved Successfully.\n");
                printf(" Thank You For Using Our Bank.\n");
                printf("=====================================\n");

                return 0;

            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    }

    return 0;
}
