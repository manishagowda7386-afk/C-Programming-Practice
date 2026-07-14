#include <stdio.h>
#include "../include/account.h"
#include "../include/report.h"

void exportAccountReport()
{
    FILE *fp;
    int i;

    fp = fopen("../data/report.txt","w");

    if(fp==NULL)
    {
        printf("\nUnable to generate report.\n");
        return;
    }

    fprintf(fp,"=============================================\n");
    fprintf(fp,"      BANK ACCOUNT REPORT\n");
    fprintf(fp,"=============================================\n\n");

    fprintf(fp,"Total Accounts : %d\n\n",totalAccounts);

    for(i=0;i<totalAccounts;i++)
    {
        fprintf(fp,"---------------------------------------\n");
        fprintf(fp,"Account Number : %d\n",accounts[i].accountNumber);
        fprintf(fp,"Account Holder : %s\n",accounts[i].accountHolder);
        fprintf(fp,"Balance        : %.2f\n",accounts[i].balance);
    }

    fprintf(fp,"\n=============================================\n");

    fclose(fp);

    printf("\nReport exported successfully!\n");
    printf("Location : data/report.txt\n");
}
