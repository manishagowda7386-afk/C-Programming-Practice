#include <stdio.h>
#include <string.h>
#include "../include/account.h"

Account accounts[MAX_ACCOUNTS];
int totalAccounts=0;

void createAccount()
{
    int i;

    if(totalAccounts>=MAX_ACCOUNTS)
    {
        printf("\nDatabase Full!\n");
        return;
    }

    printf("\n========== CREATE ACCOUNT ==========\n");

    printf("Account Number : ");
    scanf("%d",&accounts[totalAccounts].accountNumber);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==accounts[totalAccounts].accountNumber)
        {
            printf("\nAccount Number Already Exists!\n");
            return;
        }
    }

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
        printf("\n---------------------------------\n");
        printf("Account Number : %d\n",accounts[i].accountNumber);
        printf("Account Holder : %s\n",accounts[i].accountHolder);
        printf("Balance        : %.2f\n",accounts[i].balance);
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
            printf("Account Number : %d\n",accounts[i].accountNumber);
            printf("Account Holder : %s\n",accounts[i].accountHolder);
            printf("Balance        : %.2f\n",accounts[i].balance);
            return;
        }
    }

    printf("\nAccount Not Found.\n");
}

void searchAccountByName()
{
    char name[50];
    int i,found=0;

    printf("\nEnter Account Holder Name : ");
    scanf(" %[^\n]",name);

    for(i=0;i<totalAccounts;i++)
    {
        if(strcmp(accounts[i].accountHolder,name)==0)
        {
            printf("\n---------------------------------\n");
            printf("Account Number : %d\n",accounts[i].accountNumber);
            printf("Account Holder : %s\n",accounts[i].accountHolder);
            printf("Balance        : %.2f\n",accounts[i].balance);
            found=1;
        }
    }

    if(found==0)
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
                accounts[j]=accounts[j+1];

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
    float total=0,highest,lowest;

    if(totalAccounts==0)
    {
        printf("\nNo Accounts Available.\n");
        return;
    }

    highest=accounts[0].balance;
    lowest=accounts[0].balance;

    for(i=0;i<totalAccounts;i++)
    {
        total+=accounts[i].balance;

        if(accounts[i].balance>highest)
            highest=accounts[i].balance;

        if(accounts[i].balance<lowest)
            lowest=accounts[i].balance;
    }

    printf("\n========== BANK DASHBOARD ==========\n");
    printf("Total Accounts      : %d\n",totalAccounts);
    printf("Total Bank Balance  : %.2f\n",total);
    printf("Highest Balance     : %.2f\n",highest);
    printf("Lowest Balance      : %.2f\n",lowest);
}
