#include <stdio.h>
#include <string.h>
#include "../include/account.h"

Account accounts[MAX_ACCOUNTS];
int totalAccounts=0;

void createAccount()
{
    if(totalAccounts>=MAX_ACCOUNTS)
    {
        printf("\nDatabase Full!\n");
        return;
    }

    printf("\n========== CREATE ACCOUNT ==========\n");

    printf("Account Number : ");
    scanf("%d",&accounts[totalAccounts].accountNumber);

    printf("Account Holder : ");
    scanf(" %[^\n]",accounts[totalAccounts].accountHolder);

    printf("Initial Balance : ");
    scanf("%f",&accounts[totalAccounts].balance);

    printf("Create 4 Digit PIN : ");
    scanf("%d",&accounts[totalAccounts].pin);

    totalAccounts++;

    printf("\nAccount Created Successfully!\n");
}

void displayAllAccounts()
{
    int i;

    if(totalAccounts==0)
    {
        printf("\nNo Accounts Available.\n");
        return;
    }

    printf("\n========== ALL ACCOUNTS ==========\n");

    for(i=0;i<totalAccounts;i++)
    {
        printf("\nAccount %d\n",i+1);
        printf("-----------------------------\n");
        printf("Number  : %d\n",accounts[i].accountNumber);
        printf("Name    : %s\n",accounts[i].accountHolder);
        printf("Balance : %.2f\n",accounts[i].balance);
    }
}

void searchAccount()
{
    int number,i;

    printf("\nEnter Account Number : ");
    scanf("%d",&number);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==number)
        {
            printf("\nAccount Found\n");
            printf("Name : %s\n",accounts[i].accountHolder);
            printf("Balance : %.2f\n",accounts[i].balance);
            return;
        }
    }

    printf("\nAccount Not Found.\n");
}

void updateAccount()
{
    int number,i;

    printf("\nEnter Account Number : ");
    scanf("%d",&number);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==number)
        {
            printf("Enter New Name : ");
            scanf(" %[^\n]",accounts[i].accountHolder);

            printf("Enter New PIN : ");
            scanf("%d",&accounts[i].pin);

            printf("\nAccount Updated Successfully.\n");
            return;
        }
    }

    printf("\nAccount Not Found.\n");
}

void deleteAccount()
{
    int number,i,j;

    printf("\nEnter Account Number : ");
    scanf("%d",&number);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==number)
        {
            for(j=i;j<totalAccounts-1;j++)
            {
                accounts[j]=accounts[j+1];
            }

            totalAccounts--;

            printf("\nAccount Deleted Successfully.\n");
            return;
        }
    }

    printf("\nAccount Not Found.\n");
}

void bankDashboard()
{
    int i;
    float totalBalance=0;
    float highestBalance=0;
    float lowestBalance=0;

    if(totalAccounts==0)
    {
        printf("\nNo Accounts Available.\n");
        return;
    }

    highestBalance=accounts[0].balance;
    lowestBalance=accounts[0].balance;

    for(i=0;i<totalAccounts;i++)
    {
        totalBalance+=accounts[i].balance;

        if(accounts[i].balance>highestBalance)
            highestBalance=accounts[i].balance;

        if(accounts[i].balance<lowestBalance)
            lowestBalance=accounts[i].balance;
    }

    printf("\n====================================\n");
    printf("         BANK DASHBOARD\n");
    printf("====================================\n");
    printf("Total Accounts      : %d\n",totalAccounts);
    printf("Total Bank Balance  : %.2f\n",totalBalance);
    printf("Highest Balance     : %.2f\n",highestBalance);
    printf("Lowest Balance      : %.2f\n",lowestBalance);
    printf("====================================\n");
}
