#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char bill[15];
    int value;
    int quantity;
} bill;

bill thousand = {"Thousand", 1000, 2};
bill fiveHundred = {"Fivehundred", 500, 3};
bill hundred = {"Hundred", 100, 5};

int logIn() {}

int checkBalance(int balance) {
    printf("BALANCE: %d\n", balance);
}

int deposit(int balance) {
    int deposit;

    printf("Enter amount to deposit:\n");
    scanf("%d", &deposit);

    balance += deposit;

    return balance;
}

int legitWithdraw(int withdraw) {
    if (withdraw % 100 == 0) {
        return 1;
    } else {
        printf("Needs to be evenly divisible by 100\n");
    }
}

int billWithdraw(int balance, int withdraw) {
    int loopCount = 0;
    int initialWithdrawSum = withdraw;

    while (withdraw != 0) {
        if (legitWithdraw(withdraw) == 1) {
            if (withdraw >= thousand.value && thousand.quantity != 0) {
                thousand.quantity -= 1;
                withdraw -= thousand.value;
                balance -= thousand.value;

            } else if (withdraw >= fiveHundred.value && fiveHundred.quantity != 0) {
                fiveHundred.quantity -= 1;
                withdraw -= fiveHundred.value;
                balance -= fiveHundred.value;

            } else if (withdraw >= hundred.value && hundred.quantity != 0) {
                hundred.quantity -= 1;
                withdraw -= hundred.value;
                balance -= hundred.value;

            } else {
                break;
            }
        }
        loopCount++;
    }
    printf("\n\n\n:::LOOPCOUNT:::%d\n", loopCount);
    if (withdraw == 0) {
        printf("You withdrawed %d\n", initialWithdrawSum);

    } else {
        int moneyNotWithdrawn = initialWithdrawSum - withdraw;
        printf("Out of %d, %d was withdrawn\n", initialWithdrawSum, moneyNotWithdrawn);
    }

    balance -= withdraw;
    /*
    printf("THOUSAND LEFT: %d\n", thousand.quantity);
    printf("FIVEHUNDRED LEFT: %d\n", fiveHundred.quantity);
    printf("HUNDRED LEFT: %d\n", hundred.quantity);
    */
    printf(":::::::::::::::\n\n");

    return balance;
}

int billWithdrawSimulation() {
    system("clear");
    int withdrawals[7] = {1500, 700, 400, 1100, 1000, 700, 300};
    for (int i = 0; i < 7; i++) {
        billWithdraw(5700, withdrawals[i]);
    }
}

int withdraw(int balance) {
    int withdraw;
    printf("Enter amount to withdraw\n");
    scanf("%d", &withdraw);

    if (balance < withdraw) {
        printf("Insufficient funds\n");
    } else {
        balance = billWithdraw(balance, withdraw);
    }

    return balance;
};

int menu() {
    int balance = 10000;
    int loggedIn = 1;
    while (loggedIn == 1) {
        printf("##MENU##\n"
               "1. Check balance\n"
               "2. Deposit money\n"
               "3. Withdraw money\n"
               "4. Quit\n"
               "5. WITHDRAWAL SIMULATION\n"
               "########\n");

        int menuInput;
        scanf("%d", &menuInput);

        switch (menuInput) {
        case 1:
            checkBalance(balance);
            break;
        case 2:
            balance = deposit(balance);
            break;
        case 3:
            balance = withdraw(balance);
            break;
        case 4:
            return 0;
            break;
        case 5:
            billWithdrawSimulation();
            break;
        };
    }
}

int main() {

    int login = 1234;
    int loginInput;

    printf("Log in to the bank\n");
    scanf("%d", &loginInput);

    if (loginInput != login) {
        printf("Wrong password");

        return 0;
    } else {
        menu();
    }

    return 0;
};
