#include <stdio.h>

double withdraw(double amount, double balance) {
    balance = balance - amount;
    return balance;
}

double deposit(double amount, double balance) {
    balance = balance + amount;
    return balance;
}

double checkBalance(double amount) {
    printf("BALANCE: %.2lf\n", amount);
}