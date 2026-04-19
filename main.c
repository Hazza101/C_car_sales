
#define _CRT_SECURE_NO_WARNINGS
#define EXIT 'X'
#define BUY_CAR 'B'
#define VIEW_CARS 'A'
#define VIEW_SALES 'C'
#define MAX_CAR_ARRAY_SIZE 6

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* #include <stdlib.h>
#include "data.h"


#include "fileFunctions.h"
#include "sortFunction.h"
#include "genericFunctions.h"
*/


struct Car {
    char name[100];
    int quantity;
    int price;
};

void viewCars(const struct Car cars[], int size) {

    //sortCarArray();

    //clearScreen();
    printf("\n\n ____Available Models____\n\n");
    for (int i = 0; i < size; i++) {
        printf("We have %d %s's available at $%d. \n", cars[i].quantity, cars[i].name, cars[i].price);
    }

}

int chooseCar(const struct Car cars[], int size) {
   int invalidCarChosen = 1;

   while (invalidCarChosen) {

       printf("\nWhat car would you like to buy? \n\n");
       char userResponse[100];
       scanf("\n%[^\n]s", userResponse);

       if (strcmp(userResponse, "exit") == 0) {
           return -1;
       }

       for (int i = 0; i < size; i++)
       {

           int stringComparison;
           stringComparison = strcmp(userResponse, cars[i].name);

           if (stringComparison == 0)
           {
               return i;
           }
       }

       printf("Invalid Car Choice. Car Names are case sensitive.");
   }
   return -1;
}

int getCustomerName(char *name, size_t size) {
    int isValidName = 1;
    while (isValidName) {
        printf("Full Name: ");
        if (fgets(name, size, stdin) == NULL) {
            printf("Invalid input!\n");
            continue;
        }

        name[strcspn(name, "\n")] = '\0';

        if (name[0] == '\0') {
            printf("Please enter something!\n");
            continue;
        }
        if (strcmp(name, "exit") == 0) {
            return -1;
        }

        return 1;
    }

    return 0;
}

int buyCars(const struct Car cars[], int size) {

    int isExit;

    struct Car car;
    int isExit = chooseCar(cars, size, car);
    //printf("\n%d\n", carIndex);

    char customerName[100];
    isExit = getCustomerName(customerName, sizeof(customerName));
    if (isExit == -1) {
        return -1;
    }
    printf("%s\n", customerName);
    /*
    getchar();
    fgets(customerName, 100, stdin);
    customerName[strlen(customerName) - 1] = '\0';
    if (strcmp(customerName, "exit") == 0) {
        return 0;
    }


    int invalidNumOfCars = 1;
    int numOfCarsToBuy;
    while (invalidNumOfCars == 1)
    {

        printf("\nHow many would you like to buy?\n\n");
        numOfCarsToBuy = getValidatedWholeNumber();
        if (numOfCarsToBuy == 2000) {
            return 0;
        }

        if (numOfCarsToBuy > carArray[carIndex].carQuantity || numOfCarsToBuy <= 0)
        {

            printf("\nWe only have %d left.\n", carArray[carIndex].carQuantity);
        }
        else
        {
            invalidNumOfCars = 0;
        }
    }

    int age;
    char discountGiven;
    char membership;
    float discount = 1;

    printf("\nWhat is your age?\n\n");
    age = getValidatedWholeNumber();
    if (age == 2000) {
        return 0;
    }

    if (age <= 25 && age >= 18) {

        printf("\nCongratulations you qualify for a discount of 15%%.");
        discount = 0.85;
        discountGiven = 'Y';
        membership = '?';

    }

    else
    {
        printf("\nDo you hold a membership card with us? (Y/N)\n\n");
        scanf("\n%c", &membership);

        if (getchar() != '\n') {
            char exitString[10];
            scanf("%s", exitString);
            if (strcmp(exitString, "it") == 0) {
                return 0;
            }

        }

        if (membership == 'Y' || membership == 'y')
        {

            printf("\n\nCongratulations you qualify for a discount of 30%%.");
            discount = 0.7;
            discountGiven = 'Y';
            membership = 'Y';

        }

        else
        {

            printf("\n\nNo discount");
            membership = 'N';
            discountGiven = 'N';

        }
    }

    printf("\n\nThank you for buying a car.");

    float totalPrice = numOfCarsToBuy * carArray[carIndex].carPrice * discount;
    printf("\nTotal Price : £%d", (int)totalPrice);
    discount = (1 - discount) * 100;
    int salesIndex = getNumberOfSales();

    strcpy(customerArray[salesIndex].customerName, customerName);
    strcpy(customerArray[salesIndex].carName, carName);
    customerArray[salesIndex].discount = discount;
    customerArray[salesIndex].discountGiven = discountGiven;
    customerArray[salesIndex].numberOfCars = numOfCarsToBuy;
    customerArray[salesIndex].totalPrice = totalPrice;
    customerArray[salesIndex].age = age;
    customerArray[salesIndex].membership = membership;

    carArray[carIndex].carQuantity -= numOfCarsToBuy;
    invalidCarChosen = 0;*/
}
/*
void viewSales() {

    sortCustomerArray();
    int numOfSales = getNumberOfSales();
    clearScreen();
    printf("\n\n ____Sales History____\n\n");
    if (numOfSales == 0) {
        printf("\n\n There are currently no sales today. \n\n");
    }
    for (int i = 0; i < numOfSales; i++) {


        printf("Customer name: %s | Car purchased: %s | Quantity: %d | Total Price : %f \n Age : %d | Membership : %c | discountGiven : %c | discount : %d%% \n", customerArray[i].customerName, customerArray[i].carName, customerArray[i].numberOfCars, customerArray[i].totalPrice, customerArray[i].age, customerArray[i].membership, customerArray[i].discountGiven, (int)customerArray[i].discount);



    }


}
*/
void printMainMenu() {
    printf("\n\n______Main Menu________\n\n");
    printf("Type A to view car selection\n");
    printf("\nType B to buy a car\n");
    printf("\nType C to view sales\n");
    printf("\nType X to exit\n");
    printf("\nEnter: ");
}

char getResponse() {
    char response;
    scanf("\n%c", &response);
    response = toupper(response);
    if (getchar() != '\n') {
        response = 'z';
    }
    return response;

}
/*

    void returnToMainMenu() {

        //while (getchar() != '\n');
        printf("\n\nPlease press Enter to return to the main Menu:");
        getchar();
        clearScreen();
    }
 */

void printBanner() {
    printf("\n ______Welcome to BAINS AUTOS LTD______\n\n\n");
}

void mainMenu() {
    int exitProgram = 0;
    while (!exitProgram) {


        printMainMenu();
        char response = getResponse();

        switch (response) {

        case VIEW_CARS:
            printf("Viewing cars");
            //viewCars();
            //returnToMainMenu();
            break;

        case BUY_CAR:
            printf("Buying cars");
            //buyCars();
            //returnToMainMenu();
            break;

        case VIEW_SALES:
            printf("Viewing sales");
            //viewSales();
            //returnToMainMenu();
            break;

        case 'z':
            printf("Please enter only one character.");
            break;

        case EXIT:
            printf("Have a nice day. :)");
            exitProgram = 1;
            break;

        default:
            printf("\nPlease enter an appropriate response.");
            break;
        }


        //clearScreen();
    }

}

int main(void) {

    //ReadDataFromFile();
    //mainMenu();
    struct Car cars[MAX_CAR_ARRAY_SIZE] = {
        {"Audi A1", 10, 23000},
        {"Ford Fiesta", 6, 18000},
        {"Vauxhall Astra", 10, 21000},
        {"BMW", 10, 30000},
        {"Nissan Duke", 7, 22000},
        {"Volkswagen Golf", 5, 28000}
    };
    buyCars(cars, 6);
    //writeDataToFile();
    return 0;

}
