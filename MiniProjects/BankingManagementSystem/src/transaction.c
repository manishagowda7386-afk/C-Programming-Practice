void transferMoney()
{
    int fromAcc,toAcc;
    int i,j;
    float amount;

    printf("\n========== MONEY TRANSFER ==========\n");

    printf("From Account Number : ");
    scanf("%d",&fromAcc);

    printf("To Account Number : ");
    scanf("%d",&toAcc);

    if(fromAcc==toAcc)
    {
        printf("\nCannot transfer to the same account!\n");
        return;
    }

    for(i=0;i<totalAccounts;i++)
    {
        if(accounts[i].accountNumber==fromAcc)
        {
            if(!verifyPin(i))
                return;

            for(j=0;j<totalAccounts;j++)
            {
                if(accounts[j].accountNumber==toAcc)
                {
                    printf("Amount : ");
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
                    accounts[j].balance+=amount;

                    addTransaction(fromAcc,"Transfer Sent",amount);
                    addTransaction(toAcc,"Transfer Received",amount);

                    printf("\nTransfer Successful!\n");
                    printf("%.2f transferred successfully.\n",amount);

                    return;
                }
            }

            printf("\nDestination Account Not Found!\n");
            return;
        }
    }

    printf("\nSource Account Not Found!\n");
}
