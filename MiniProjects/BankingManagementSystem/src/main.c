#include <stdio.h>
#include "../include/menu.h"
#include "../include/account.h"
#include "../include/transaction.h"
#include "../include/file_manager.h"
#include "../include/transaction_history.h"
#include "../include/report.h"
#include "../include/interest.h"

void welcomeScreen()
{
    printf("\n");
    printf("=============================================================\n");
    printf("            BANKING MANAGEMENT SYSTEM v1.0\n");
    printf("=============================================================\n");
    printf(" Features Available\n");
    printf("-------------------------------------------------------------\n");
    printf(" * Create Account\n");
    printf(" * Deposit / Withdraw Money\n");
    printf(" * Transfer Money\n");
    printf(" * Search Accounts\n");
    printf(" * Transaction History\n");
    printf(" * Interest Calculator\n");
    printf(" * Export Account Report\n");
    printf(" * Secure PIN Authentication\n");
    printf("=============================================================\n\n");
}

int main()
{
    int choice;

    loadAccounts();

    welcomeScreen();

    while(1)
    {
        displayMenu();

        printf("\nEnter your choice : ");
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
                searchAccountByName();
                break;

            case 7:
                displayAllAccounts();
                break;

            case 8:
                updateAccount();
                break;

            case 9:
                deleteAccount();
                break;

            case 10:
                viewTransactionHistory();
                break;

            case 11:
                bankDashboard();
                break;

            case 12:
                changePin();
                break;

            case 13:
                exportAccountReport();
                break;

            case 14:
                calculateInterest();
                break;

            case 15:
                transferMoney();
                break;

            case 16:
                saveAccounts();

                printf("\n=============================================================\n");
                printf("   Thank you for using Banking Management System v1.0\n");
                printf("=============================================================\n");

                return 0;

            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    }

    return 0;
}
