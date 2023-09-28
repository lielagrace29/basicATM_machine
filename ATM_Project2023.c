// ATM_Project2023.c : This file contains the 'main' function. Program execution begins and ends there.
// ITT-310 Liela Pressley 8/30- 9/2/2023- Alpha
// 9/8- Beta Goals: Invalid Number/error message, go back to main menu after each function is complete (boolean), exit function
// Final Project Goals: Aesthetics and add pin to log in
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//calling functions
void loginValid(int pin);
void mainMenu();
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);
void menuExit();
void errorMessage();
void menuRepeat();

//set pin variable for login 
int pin;
//set balance variable to 20000 as default for user
float balance = 20000.00;
//boolean if again == true for user to go back to main menu after process is complete
bool again = true;
//declare choose as integer
int choose;

//main functions
int main()
{
    printf("Welcome to GCU ATM................. Provided by LP Bank Services\n");

    loginValid(pin);
    //declare option variable as integer for user to select
    int option;
   
    //while loop to present mainmenu
    while (again== true) {
       
        // Welcome Message to User
        printf("Type in the Number for the Transaction You wish to Perform: \n");

        //call main menu function
        mainMenu();

        //user input for their option selection
        scanf_s("%d",  &option);

        if (option == 1) {
            checkBalance(balance);
            menuRepeat();
            
        }
        else if (option == 2) {
            balance = depositMoney(balance);
            menuRepeat();
        }
        else if (option == 3) {
            balance = withdrawMoney(balance);
            menuRepeat();
         
        }
        else if (option == 4) {
            menuExit();
            return 0;
        }
        else {
            errorMessage();
          
        }

           
    }
   return 0;
}

//FUNCTIONALITY FOR EACH OPTIONS

void mainMenu(int pin) {
    //MAIN MENU PRESENTATION FUNCTIONALITY
    printf(" 1------- Check My Balance\n ");
    printf(" 2------- Make a Deposit\n ");
    printf(" 3------- Withdraw from My Account\n ");
    printf(" 4------- Exit and Print Reciept\n ");
}  

//CHECK YOUR BALANCE FUNCTIONALITY
void checkBalance(float balance) {
    printf("You selected to See Your Current Balance \n");
    printf("Your Available Balance is:  $%.2f\n\n", balance);
}

//DEPOSIT INTO ACCOUTN FUNCTIONALITY
float depositMoney(float balance) {
    float deposit; //intializing deposit variable for user input
    printf("You chose to Deposit Money \n");
    printf("Your Available Balance is:  $%.2f\n\n", balance);
    printf("Enter the amount you wish to deposit:   ");
    scanf_s("%f", &deposit); //user input into deposit variable

    //add deposit to balance
    balance += deposit;

    //new balance
    printf("\n Your New Balance is       $%.2f\n\n", balance);
    return balance; //allows for updated balance to be made available for other functions
}
float withdrawMoney(float balance) {
    float withdraw;
    bool back = true;
    printf("You chose to Withdraw Money from Your Account \n");
    printf("Your Available Balance is:  $%.2f\n\n", balance);
  
    while (back) {
        printf("Enter the amount you wish to withdraw:  \n");
        scanf_s("%f", &withdraw); //user input for withdraw
   
        //use a if statement for if balance is >= withdraw amount allow it to be subtracted if less then don't allow for withdraw to occur.
        if (withdraw < balance) {
            back = false;
            balance -= withdraw;
            printf("You are withdrawing:  $%.2f\n ", withdraw);
            printf("Your New Available Balance is:  $%.2f\n\n", balance);
        }
        else {
            //if balance is < withdraw print don't have enough, present balance then exit
            printf("I'm sorry- you do not have enough money in your account to make this withdraw. \n");
            printf("Your Current balance is:  $%.2f\n\n", balance);
        }
    
    }
    return balance; //keeps balance updated globally
    
}
 
//login in validation function
void loginValid() {
    bool validation = true;
    int counter = 0;
    //while validation is true and counter is less than 3 ask for pin 3x if user enters wrong.
    while (validation && counter <= 3) {
        printf("---------------------------------------\n");
        printf("Please enter your pin: ____\n");
        scanf_s("%d", &pin);

        if (pin == 1234) {
            validation = false;
            again = true;
           
        }
        else if (counter == 3) {
            printf("For your account's safety we will end your transaction, see you soon. \n");
            printf("---------------------------------------\n");
            again = false;
        }
        else {
            printf("Sorry, that pin is invalid please try again.\n");
           // validation = true;
            again = false;
            counter += 1;   
        }

    }
}
//exit menu function
void menuExit() {
    printf("Take your reciept! Thank you for choosing LP Banking \n");
    printf("Your Current Balance is: $%.2f\n", balance);
}

//error message funciton
void errorMessage() {
    printf(" You have selected an invalid number. \n");
}

// perform another transaction function
void menuRepeat() {
    printf("........................\n");
    printf("Would you like to perform another transaction: \n");
    printf("1.... Yes \n");
    printf("2.... No \n");
    //user input for choose variable to restart main menu
    scanf_s("%d", &choose);

    if (choose == 2) {
        again = false;
        menuExit();
    }
    else if (choose == 1) {
        again = true;
    }
    else {
        errorMessage();
        printf("For your account's safety we will end your transaction and print your reciept, see you soon. \n");
        again = false;
        menuExit();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
