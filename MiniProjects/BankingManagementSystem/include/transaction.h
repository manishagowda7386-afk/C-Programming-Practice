#ifndef TRANSACTION_H
#define TRANSACTION_H

/* PIN Verification */
int verifyPin(int index);

/* Transaction Operations */
void depositMoney();
void withdrawMoney();
void checkBalance();

/* Transaction History */
void viewTransactionHistory();

#endif
