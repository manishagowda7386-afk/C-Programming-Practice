#ifndef ACCOUNT_H
#define ACCOUNT_H

#define MAX_ACCOUNTS 100

typedef struct
{
    int accountNumber;
    char accountHolder[50];
    float balance;
    int pin;
} Account;

extern Account accounts[MAX_ACCOUNTS];
extern int totalAccounts;

void createAccount();
void displayAllAccounts();
void searchAccount();
void updateAccount();
void deleteAccount();

/* Dashboard */
void bankDashboard();

#endif
