#include <stdio.h>

#include "../include/menu.h"
#include "../include/account.h"
#include "../include/transaction.h"
#include "../include/file_manager.h"
#include "../include/transaction_history.h"
#include "../include/report.h"
#include "../include/interest.h"
#include "../include/statement.h"


void welcomeScreen()
{
    printf("\n");
    printf("=============================================================\n");
    printf("            BANKING MANAGEMENT SYSTEM v1.0\n");
    printf("=============================================================\n");
    printf("Features Available\n");
    printf("-------------------------------------------------------------\n");
    printf("* Create Account\n");
    printf("* Deposit / Withdraw Money\n");
    printf("* Transfer Money\n");
    printf("* Search Accounts\n");
    printf("* Transaction History\n");
    printf("* Interest Calculator\n");
    printf("* Account Statement\n");
    printf("* Export Account Report\n");
    printf("* Secure PIN Authentication\n");
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
                transferMoney();
                break;

            case 11:
                showTransactionHistory();
                break;

            case 12:
                calculateInterest();
                break;

            case 13:
                generateStatement();
                break;

            case 14:
                generateReport();
                break;

            case 15:
                saveAccounts();

                printf("\n=====================================\n");
                printf(" Thank you for using our Banking System!\n");
                printf("=====================================\n");

                return 0;

            default:
                printf("\nInvalid Choice! Please try again.\n");
        }

        saveAccounts();

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}
