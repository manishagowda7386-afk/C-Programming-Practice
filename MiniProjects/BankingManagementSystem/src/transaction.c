#include <stdio.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct
{
    int accountNumber;
    float balance;
} Account;

typedef struct
{
    int accountNumber;
    char type[30];
    float amount;
} Transaction;

extern Account accounts[];
extern int totalAccounts;

Transaction transactions[MAX_TRANSACTIONS];
int transactionCount = 0;


void addTransaction(int accNo, char type[], float amount)
{
    if(transactionCount < MAX_TRANSACTIONS)
    {
        transactions[transactionCount].accountNumber = accNo;

        strcpy(transactions[transactionCount].type, type);

        transactions[transactionCount].amount = amount;

        transactionCount++;
    }
}


int findAccount(int accNo)
{
    int i;

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber == accNo)
        {
            return i;
        }
    }

    return -1;
}

int verifyPin(int index)
{
    int pin;
    int enteredPin;

    printf("\nEnter PIN : ");
    scanf("%d",&enteredPin);

    pin = accounts[index].pin;

    if(pin == enteredPin)
    {
        return 1;
    }
    else
    {
        printf("\nIncorrect PIN!\n");
        return 0;
    }
}


void transferMoney()
{
    int fromAcc,toAcc;
    int fromIndex,toIndex;
    float amount;

    printf("\n========== MONEY TRANSFER ==========\n");

    printf("From Account Number : ");
    scanf("%d",&fromAcc);

    printf("To Account Number : ");
    scanf("%d",&toAcc);


    if(fromAcc == toAcc)
    {
        printf("\nCannot transfer to the same account!\n");
        return;
    }


    fromIndex = findAccount(fromAcc);

    if(fromIndex == -1)
    {
        printf("\nSource Account Not Found!\n");
        return;
    }


    if(!verifyPin(fromIndex))
    {
        return;
    }


    toIndex = findAccount(toAcc);

    if(toIndex == -1)
    {
        printf("\nDestination Account Not Found!\n");
        return;
    }

    printf("Amount : ");
    scanf("%f",&amount);


    if(amount <= 0)
    {
        printf("\nInvalid Amount!\n");
        return;
    }


    if(amount > accounts[fromIndex].balance)
    {
        printf("\nInsufficient Balance!\n");
        return;
    }


    accounts[fromIndex].balance -= amount;

    accounts[toIndex].balance += amount;


    addTransaction(fromAcc,"Transfer Sent",amount);

    addTransaction(toAcc,"Transfer Received",amount);


    printf("\nTransfer Successful!\n");

    printf("%.2f transferred successfully.\n",amount);
}
