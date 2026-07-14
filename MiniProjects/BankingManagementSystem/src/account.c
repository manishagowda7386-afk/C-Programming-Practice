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

    printf("Enter Account Number : ");
    scanf("%d",&accounts[totalAccounts].accountNumber);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==accounts[totalAccounts].accountNumber)
        {
            printf("\nAccount Number Already Exists!\n");
            return;
        }
    }

    printf("Enter Account Holder Name : ");
    scanf(" %[^\n]",accounts[totalAccounts].accountHolder);

    do
    {
        printf("Enter Initial Balance : ");
        scanf("%f",&accounts[totalAccounts].balance);

        if(accounts[totalAccounts].balance<0)
            printf("Balance cannot be negative!\n");

    }while(accounts[totalAccounts].balance<0);

    printf("\nAccount Type\n");
    printf("1. Savings\n");
    printf("2. Current\n");

    int choice;

    do
    {
        printf("Choose Account Type : ");
        scanf("%d",&choice);

        if(choice==1)
            strcpy(accounts[totalAccounts].accountType,"Savings");
        else if(choice==2)
            strcpy(accounts[totalAccounts].accountType,"Current");
        else
            printf("Invalid Choice!\n");

    }while(choice!=1 && choice!=2);

    do
    {
        printf("Create 4 Digit PIN : ");
        scanf("%d",&accounts[totalAccounts].pin);

        if(accounts[totalAccounts].pin<1000 || accounts[totalAccounts].pin>9999)
            printf("PIN must be exactly 4 digits!\n");

    }while(accounts[totalAccounts].pin<1000 || accounts[totalAccounts].pin>9999);

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
        printf("Account Type   : %s\n",accounts[i].accountType);
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
            printf("Account Type   : %s\n",accounts[i].accountType);
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
            printf("Account Type   : %s\n",accounts[i].accountType);
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

    printf("\n========== UPDATE ACCOUNT ==========\n");
    printf("Enter Account Number : ");
    scanf("%d",&number);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==number)
        {
            printf("Enter New Account Holder Name : ");
            scanf(" %[^\n]",accounts[i].accountHolder);

            printf("\nSelect Account Type\n");
            printf("1. Savings\n");
            printf("2. Current\n");

            int choice;

            do
            {
                printf("Choice : ");
                scanf("%d",&choice);

                if(choice==1)
                    strcpy(accounts[i].accountType,"Savings");
                else if(choice==2)
                    strcpy(accounts[i].accountType,"Current");
                else
                    printf("Invalid Choice!\n");

            }while(choice!=1 && choice!=2);

            printf("\nAccount Updated Successfully!\n");
            return;
        }
    }

    printf("\nAccount Not Found!\n");
}

void deleteAccount()
{
    int number,i,j;

    printf("\n========== DELETE ACCOUNT ==========\n");

    printf("Enter Account Number : ");
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

            printf("\nAccount Deleted Successfully!\n");
            return;
        }
    }

    printf("\nAccount Not Found!\n");
}

void changePin()
{
    int number;
    int oldPin;
    int newPin;
    int i;

    printf("\n========== CHANGE PIN ==========\n");

    printf("Enter Account Number : ");
    scanf("%d",&number);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==number)
        {
            printf("Enter Current PIN : ");
            scanf("%d",&oldPin);

            if(accounts[i].pin!=oldPin)
            {
                printf("\nIncorrect PIN!\n");
                return;
            }

            do
            {
                printf("Enter New 4 Digit PIN : ");
                scanf("%d",&newPin);

                if(newPin<1000 || newPin>9999)
                    printf("PIN must be exactly 4 digits!\n");

            }while(newPin<1000 || newPin>9999);

            accounts[i].pin=newPin;

            printf("\nPIN Changed Successfully!\n");
            return;
        }
    }

    printf("\nAccount Not Found!\n");
}



void bankDashboard()
{
    int i;
    float totalBalance=0;
    float highestBalance;
    float lowestBalance;
    float averageBalance;

    char highestHolder[50];
    char lowestHolder[50];

    if(totalAccounts==0)
    {
        printf("\nNo Accounts Available.\n");
        return;
    }

    highestBalance=accounts[0].balance;
    lowestBalance=accounts[0].balance;

    strcpy(highestHolder,accounts[0].accountHolder);
    strcpy(lowestHolder,accounts[0].accountHolder);

    for(i=0;i<totalAccounts;i++)
    {
        totalBalance+=accounts[i].balance;

        if(accounts[i].balance>highestBalance)
        {
            highestBalance=accounts[i].balance;
            strcpy(highestHolder,accounts[i].accountHolder);
        }

        if(accounts[i].balance<lowestBalance)
        {
            lowestBalance=accounts[i].balance;
            strcpy(lowestHolder,accounts[i].accountHolder);
        }
    }

    averageBalance=totalBalance/totalAccounts;

    printf("\n=====================================\n");
    printf("         BANK DASHBOARD\n");
    printf("=====================================\n");
    printf("Total Accounts      : %d\n",totalAccounts);
    printf("Total Balance       : %.2f\n",totalBalance);
    printf("Average Balance     : %.2f\n",averageBalance);
    printf("Highest Balance     : %.2f\n",highestBalance);
    printf("Highest Holder      : %s\n",highestHolder);
    printf("Lowest Balance      : %.2f\n",lowestBalance);
    printf("Lowest Holder       : %s\n",lowestHolder);
    printf("=====================================\n");
}
