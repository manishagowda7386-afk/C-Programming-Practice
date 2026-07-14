#include <stdio.h>
#include <string.h>
#include "../include/account.h"
#include "../include/transaction.h"
#include "../include/transaction_history.h"

int verifyPin(int index)
{
    int pin;

    printf("Enter 4-Digit PIN : ");
    scanf("%d",&pin);

    if(accounts[index].pin==pin)
        return 1;

    printf("\nIncorrect PIN!\n");
    return 0;
}

void depositMoney()
{
    int accountNumber,i;
    float amount;

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
            if(!verifyPin(i))
                return;

            printf("Enter Deposit Amount : ");
            scanf("%f",&amount);

            if(amount<=0)
            {
                printf("\nInvalid Amount!\n");
                return;
            }

            accounts[i].balance+=amount;

            addTransaction(accountNumber,"Deposit",amount);

            printf("\nDeposit Successful!\n");
            printf("Updated Balance : %.2f\n",accounts[i].balance);

            return;
        }
    }

    printf("\nAccount Not Found!\n");
}

void withdrawMoney()
{
    int accountNumber,i;
    float amount;

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
            if(!verifyPin(i))
                return;

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

            addTransaction(accountNumber,"Withdrawal",amount);

            printf("\nWithdrawal Successful!\n");
            printf("Remaining Balance : %.2f\n",accounts[i].balance);

            return;
        }
    }

    printf("\nAccount Not Found!\n");
}

void checkBalance()
{
    int accountNumber,i;

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
            if(!verifyPin(i))
                return;

            printf("\nAccount Holder : %s\n",accounts[i].accountHolder);
            printf("Current Balance : %.2f\n",accounts[i].balance);

            return;
        }
    }

    printf("\nAccount Not Found!\n");
}

void viewTransactionHistory()
{
}
