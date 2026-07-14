#include <stdio.h>
#include "../include/account.h"
#include "../include/transaction.h"

void depositMoney()
{
    int accountNumber;
    float amount;
    int i;

    if(totalAccounts==0)
    {
        printf("\nNo Accounts Available!\n");
        return;
    }

    printf("\n========== DEPOSIT MONEY ==========\n");

    printf("Enter Account Number : ");
    scanf("%d",&accountNumber);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            printf("Enter Deposit Amount : ");
            scanf("%f",&amount);

            if(amount<=0)
            {
                printf("\nInvalid Amount!\n");
                return;
            }

            accounts[i].balance+=amount;

            printf("\n===================================\n");
            printf("Amount Deposited Successfully!\n");
            printf("Updated Balance : %.2f\n",accounts[i].balance);
            printf("===================================\n");

            return;
        }
    }

    printf("\nAccount Not Found!\n");
}

void withdrawMoney()
{
    int accountNumber;
    float amount;
    int i;

    if(totalAccounts==0)
    {
        printf("\nNo Accounts Available!\n");
        return;
    }

    printf("\n========== WITHDRAW MONEY ==========\n");

    printf("Enter Account Number : ");
    scanf("%d",&accountNumber);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            printf("Enter Withdrawal Amount : ");
            scanf("%f",&amount);

            if(amount<=0)
            {
                printf("\nInvalid Amount!\n");
                return;
            }

            if(amount>accounts[i].balance)
            {
                printf("\nInsufficient Balance!\n");
                return;
            }

            accounts[i].balance-=amount;

            printf("\n====================================\n");
            printf("Withdrawal Successful!\n");
            printf("Remaining Balance : %.2f\n",accounts[i].balance);
            printf("====================================\n");

            return;
        }
    }

    printf("\nAccount Not Found!\n");
}

void checkBalance()
{
    int accountNumber;
    int i;

    if(totalAccounts==0)
    {
        printf("\nNo Accounts Available!\n");
        return;
    }

    printf("\n========== CHECK BALANCE ==========\n");

    printf("Enter Account Number : ");
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

    printf("\nAccount Not Found!\n");
}
