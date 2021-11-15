#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int deposit(int balance){
    int deposit = 2500;
    balance = balance - deposit;
    return balance;

};

/*LOGGED IN*/
int main(){
    static int balance = 5000;
    balance = deposit(balance);
    printf("%d", balance);
};