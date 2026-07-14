#include <stdio.h>
#include "../include/account.h"
#include "../include/statement.h"

void generateStatement()
{
    int accountNumber;
    int i;

    printf("\n=====================================\n");
    printf("       ACCOUNT STATEMENT\n");
    printf("=====================================\n");

    printf("Enter Account Number : ");
    scanf("%d",&accountNumber);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            printf("\n-------------------------------------\n");
            printf("Account Number : %d\n",accounts[i].accountNumber);
            printf("Account Holder : %s\n",accounts[i].accountHolder);
            printf("Account Type   : %s\n",accounts[i].accountType);
            printf("Current Balance: %.2f\n",accounts[i].balance);
            printf("-------------------------------------\n");
            printf("Thank you for banking with us.\n");
            printf("-------------------------------------\n");
            return;
        }
    }

    printf("\nAccount Not Found!\n");
}
