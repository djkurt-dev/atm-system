#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#include "atm.h"
#define PIN 1234



int main(){
    int choice, pin;
    char got;
    double balance, toDeposit, toWithdraw;

    printf("============= WELCOME TO BANCO TIMAJO =============\n\nPlease enter PIN: \n>> ");
    scanf("%d",&pin);

    while(pin != PIN) {
        printf("INVALID PIN. Please enter again: \n>> ");
        scanf("%d", &pin);
    }

    printf("\nENTER INITIAL BALANCE \n>> P ");
    scanf("%lf", &balance);

    system("cls");

    menu:
    printf("\nSELECT TRANSACTION\n");
    printf("\t1. Withdraw\n\t2. Deposit\n\t3. Check balance\n\t4. Exit \n>> ");
    scanf("%d",&choice);

    while (choice != 4){        

        system("cls");
        
        //withdraw
        if(choice == 1){
            printf("AMOUNT TO WITHDRAW:\n>> P ");
            scanf("%lf", &toWithdraw);
            while(toWithdraw > balance || toWithdraw == 0){
                system("cls");
                printf("INVALID VALUE. Amount should not exceed your balance, and not zero.\n>> Amount to withdraw: \n>> P ");
                scanf("%lf", &toWithdraw);
            }

            balance = withdraw(toWithdraw, balance);

            system("cls");
            printf("Processing your transaction.");
            printf("\nPlease get your cash. [Press 1]\n>> ");
            got = getch();

            system("cls");
            
            printf("***********ACCOUNT STATUS***********\n\tBALANCE: P %.2lf\n", balance);
        }
        //deposit
        else if(choice == 2){
            printf("AMOUNT TO DEPOSIT\n>> P ");
            scanf("%lf", &toDeposit);
            balance = deposit(toDeposit, balance);
            printf("Processing your transaction.\n");
            system("cls");            
            printf("You have deposited an amount of P %.2lf in your account.\n\n", toDeposit);
            printf("***********ACCOUNT STATUS***********\n\tBALANCE: P %.2lf\n", balance);
        }
        //check balance
        else if(choice == 3){
            system("cls");
            checkBalance(balance);
            
        }
        
        else {
            system("cls");
            printf("Invalid Input. Please try again.\n"); 
            goto menu;
        }        

        printf("\n============= Banking Made Easy at BANCO TIMAJO =============");
        printf("\n\n>> SELECT TRANSACTION\n");
        printf("\t1. Withdraw\n\t2. Deposit\n\t3. Check balance\n\t4. Exit \n>>");
        scanf("%d", &choice);
    }
    system("cls");
    printf("\n============= Banking Made Easy at BANCO TIMAJO =============");
    printf("\nTHANK YOU FOR BANKING AT BANCO TIMAJO!!! WE ARE HAPPY TO SERVE YOU <3");
}