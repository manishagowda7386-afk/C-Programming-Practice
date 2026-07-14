#include <stdio.h>
#include "../include/account.h"
#include "../include/file_manager.h"

void saveAccounts()
{
    FILE *fp;

    fp = fopen("../data/accounts.dat", "wb");

    if(fp == NULL)
    {
        printf("\nError: Unable to save account data.\n");
        return;
    }

    fwrite(&totalAccounts, sizeof(int), 1, fp);
    fwrite(accounts, sizeof(Account), totalAccounts, fp);

    fclose(fp);
}

void loadAccounts()
{
    FILE *fp;

    fp = fopen("../data/accounts.dat", "rb");

    if(fp == NULL)
    {
        totalAccounts = 0;
        return;
    }

    fread(&totalAccounts, sizeof(int), 1, fp);
    fread(accounts, sizeof(Account), totalAccounts, fp);

    fclose(fp);
}
