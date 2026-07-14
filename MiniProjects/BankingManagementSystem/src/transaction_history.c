#include <stdio.h>
#include <time.h>
#include "../include/transaction_history.h"

void addTransaction(int accountNumber, char type[], float amount)
{
    FILE *fp;

    fp = fopen("../data/transactions.txt","a");

    if(fp==NULL)
    {
        printf("\nUnable to save transaction history.\n");
        return;
    }

    time_t now;
    time(&now);

    fprintf(fp,
    "Account: %d | Type: %s | Amount: %.2f | Date: %s",
    accountNumber,
    type,
    amount,
    ctime(&now));

    fclose(fp);
}


void viewTransactionHistory()
{
    FILE *fp;
    char ch;

    fp=fopen("../data/transactions.txt","r");

    if(fp==NULL)
    {
        printf("\nNo Transaction History Found.\n");
        return;
    }


    printf("\n========== TRANSACTION HISTORY ==========\n");

    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }

    fclose(fp);
}
