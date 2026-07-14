#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/validation.h"

int isValidPin(int pin)
{
    if(pin>=1000 && pin<=9999)
        return 1;

    return 0;
}

int isValidAmount(float amount)
{
    if(amount>0)
        return 1;

    return 0;
}

int isValidAccountNumber(int accountNumber)
{
    if(accountNumber>0)
        return 1;

    return 0;
}

int isValidName(char name[])
{
    int i;

    if(strlen(name)==0)
        return 0;

    for(i=0;name[i]!='\0';i++)
    {
        if(!(isalpha(name[i]) || name[i]==' '))
            return 0;
    }

    return 1;
}
