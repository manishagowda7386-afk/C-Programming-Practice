#include <stdio.h>
#include "../include/account.h"
#include "../include/transaction.h"

void depositMoney()
{
    int accountNumber,i;
    float amount;

    printf("\nEnter Account Number : ");
    scanf("%d",&accountNumber);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            printf("Enter Amount : ");
            scanf("%f",&amount);

            accounts[i].balance+=amount;

            printf("\nAmount Deposited Successfully.\n");
            printf("Updated Balance : %.2f\n",accounts[i].balance);
            return;
        }
    }

    printf("\nAccount Not Found.\n");
}

void withdrawMoney()
{
    int accountNumber,i;
    float amount;

    printf("\nEnter Account Number : ");
    scanf("%d",&accountNumber);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            printf("Enter Amount : ");
            scanf("%f",&amount);

            if(amount>accounts[i].balance)
            {
                printf("\nInsufficient Balance.\n");
                return;
            }

            accounts[i].balance-=amount;

            printf("\nWithdrawal Successful.\n");
            printf("Remaining Balance : %.2f\n",accounts[i].balance);
            return;
        }
    }

    printf("\nAccount Not Found.\n");
}

void checkBalance()
{
    int accountNumber,i;

    printf("\nEnter Account Number : ");
    scanf("%d",&accountNumber);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            printf("\nAccount Holder : %s\n",accounts[i].accountHolder);
            printf("Current Balance : %.2f\n",accounts[i].balance);
            return;
        }
    }

    printf("\nAccount Not Found.\n");
}
