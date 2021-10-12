#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <direct.h>

int recordWithdraw(double amount, double balance){
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    double initial = balance + amount;

    FILE *withdraw = fopen("withdraw_record.txt", "a");
    fprintf(withdraw, "\n%d-%d-%d,%d:%d,%.2lf,%.2lf,%.2lf",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900,tm.tm_hour,tm.tm_min, amount,balance, initial);
}

int recordDeposit(double amount, double balance){
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    double initial = balance - amount;

    FILE *withdraw = fopen("deposit_record.txt", "a");
    fprintf(withdraw, "\n%d-%d-%d,%d:%d,%.2lf,%.2lf,%.2lf",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900,tm.tm_hour,tm.tm_min, amount,balance,initial);
}

double withdraw(double amountToWithdraw, double balance) {
    balance = balance - amountToWithdraw;
    recordWithdraw(amountToWithdraw,balance);
    return balance;
}

double deposit(double amountToDeposit, double balance) {
    balance = balance + amountToDeposit;
    recordDeposit(amountToDeposit,balance);
    return balance;
}

double checkBalance(double amount) {
    printf("BALANCE: %.2lf\n", amount);
}