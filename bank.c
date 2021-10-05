#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#define PIN 1234

double balance, toDeposit, toWithdraw;

double withdraw(double amount) {
    balance = balance - amount;
    return balance;
}

double deposit(double amount) {
    balance = balance + amount;
    return balance;
}

double checkBalance(double amount) {
    printf("BALANCE: %.2lf\n", amount);
}

int main(){
    int choice, pin, got=0;

    printf("============= WELCOME TO BANCO TIMAJO =============\n\nPlease enter PIN: \n>> ");
    scanf("%d",&pin);

    while(pin != PIN) {
        printf("INVALID PIN. Please enter again: \n>> ");
        scanf("%d", &pin);
    }

    printf("\nENTER INITIAL BALANCE \n>> P ");
    scanf("%lf", &balance);

    system("cls");

    printf("\nSELECT TRANSACTION\n");
    printf("\t1. Withdraw\n\t2. Deposit\n\t3. Check balance\n\t4. Exit \n>> ");
    scanf("%d",&choice);

    while (choice != 4){        

        system("cls");
        
        if(choice == 1){
            printf("AMOUNT TO WITHDRAW:\n>> P ");
            scanf("%lf", &toWithdraw);
            while(toWithdraw > balance){
                system("cls");
                printf("INSUFFICIENT BALANCE. Please enter amount less than or equivalent to your balance.\n>> Amount to withdraw: \n>> P ");
                scanf("%lf", &toWithdraw);
            }
            withdraw(toWithdraw);

            system("cls");
            printf("Processing your transaction.");
            printf("\nPlease get your cash. [Press 1]\n>> ");
            scanf("%d",&got);

            while (got != 1){
                system("cls");
                printf("Sorry, please get your cash. [Press 1]\n>> ");
                scanf("%d", &got);
            }            
            system("cls");
            
            printf("***********ACCOUNT STATUS***********\n\tBALANCE: P %.2lf\n", balance);
        }

        else if(choice == 2){
            printf("AMOUNT TO DEPOSIT\n>> P ");
            scanf("%lf", &toDeposit);
            deposit(toDeposit);
            printf("Processing your transaction.\n");
            system("cls");            
            printf("You have deposited an amount of P %.2lf in your account.\n\n", toDeposit);
            printf("***********ACCOUNT STATUS***********\n\tBALANCE: P %.2lf\n", balance);
        }

        else if(choice == 3){
            system("cls");
            checkBalance(balance);
        }
        else {
            system("cls");
            printf("\nInvalid Input. Please try again.\n"); 
        }        

        printf("\n============= Banking Made Easy at BANCO TIMAJO =============");
        printf("\n\n>> SELECT TRANSACTION\n");
        printf("\t1. Withdraw\n\t2. Deposit\n\t3. Check balance\n\t4. Exit \n>>");
        scanf("%d", &choice);
    }
    
    printf("\n============= Banking Made Easy at BANCO TIMAJO =============");
    printf("\nTHANK YOU FOR BANKING AT BANCO TIMAJO!!! WE ARE HAPPY TO SERVE YOU <3");
    
}