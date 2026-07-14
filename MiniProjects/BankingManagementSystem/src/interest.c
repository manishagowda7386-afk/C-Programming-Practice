#include <stdio.h>
#include <string.h>
#include "../include/account.h"
#include "../include/interest.h"

void calculateInterest()
{
    int accountNumber;
    int years;
    int i;

    float rate;
    float interest;
    float finalAmount;

    if(totalAccounts==0)
    {
        printf("\nNo Accounts Available.\n");
        return;
    }

    printf("\n========== INTEREST CALCULATOR ==========\n");

    printf("Enter Account Number : ");
    scanf("%d",&accountNumber);

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            printf("Enter Number of Years : ");
            scanf("%d",&years);

            if(years<=0)
            {
                printf("\nInvalid Number of Years!\n");
                return;
            }

            if(strcmp(accounts[i].accountType,"Savings")==0)
                rate=6.5;
            else
                rate=4.0;

            interest=(accounts[i].balance*rate*years)/100;
            finalAmount=accounts[i].balance+interest;

            printf("\n========== INTEREST DETAILS ==========\n");
            printf("Account Holder : %s\n",accounts[i].accountHolder);
            printf("Account Type   : %s\n",accounts[i].accountType);
            printf("Current Balance: %.2f\n",accounts[i].balance);
            printf("Interest Rate  : %.2f%%\n",rate);
            printf("Interest Earned: %.2f\n",interest);
            printf("Final Balance  : %.2f\n",finalAmount);

            return;
        }
    }

    printf("\nAccount Not Found!\n");
}
