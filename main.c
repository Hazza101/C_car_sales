
#define _CRT_SECURE_NO_WARNINGS
#define EXIT 'X'
#define BUY_CAR 'B'
#define VIEW_CARS 'A'
#define VIEW_SALES 'C'
#define MAX_CAR_ARRAY_SIZE 6

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <stdlib.h>
/*
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

struct Sale {
    char car[100];
    char name[100];
    int quantity;
    int price;
    char discountGiven;
    char membership;
    float discountPercent;
};

void viewCars(const struct Car cars[], int size) {

    //sortCarArray();

    //clearScreen();
    printf("\n\n ____Available Models____\n\n");
    for (int i = 0; i < size; i++) {
        printf("We have %d %s's available at $%d. \n", cars[i].quantity, cars[i].name, cars[i].price);
    }

}

int chooseCar(struct Car cars[], int size, struct Car **car) {
   int invalidCarChosen = 1;

   while (invalidCarChosen) {

       printf("What car would you like to buy?: ");
       char userResponse[100];
       scanf("\n%[^\n]s", userResponse);
       getchar();
       if (strcmp(userResponse, "exit") == 0) {
           return -1;
       }

       for (int i = 0; i < size; i++)
       {

           int stringComparison;
           stringComparison = strcmp(userResponse, cars[i].name);

           if (stringComparison == 0)
           {
               *car = &cars[i];
               return 1;
           }
       }

       printf("Invalid Car Choice. Car Names are case sensitive.\n");
   }
   return -1;
}

int getValidNumberOfCars(const struct Car *car, int* numberOfCars) {

    int invalidNumOfCars = 1;
    char input[100];
    while (invalidNumOfCars)
    {

        printf("Quantity: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            return -1;
        }
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "exit") == 0) {
            return -1;
        }

        char* endptr;
        long val = strtol(input, &endptr, 10);

        if (*endptr != '\0') {
            printf("Please enter a valid number!\n");
            continue;
        }
        *numberOfCars = (int) val;

        if (*numberOfCars > car->quantity || *numberOfCars <= 0)
        {

            printf("We only have %d left.\n", car->quantity);
        }
        else
        {
            return 1;
        }
    }
    return 1;
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

int getYoungAdultDiscount(char* discountGiven, float* discount) {
    int age;
    char input[100];
    int hasEnteredAge = 1;
    while ( hasEnteredAge ) {

        printf("Age: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            return -1;
        }

        input[strcspn(input, "\n")] = '\0';

        if ( strcmp(input, "exit") == 0 ) {
            return -1;
        }

        char* endptr;
        double val = strtol(input, &endptr, 10);

        if (*endptr != '\0') {
            printf("Please enter a valid number!\n");
            continue;
        }

        age = (int) val;


        if (age <= 25 && age >= 18) {

            printf("Congratulations you qualify for a discount of 15%%.\n");
            *discount = 0.85;
            *discountGiven = 'Y';

        } else {
            printf("No discount given.!\n");
            *discount = 1;
            *discountGiven = 'N';
        }

        return 1;
    }


    return -1;
}

int getMembershipDiscount(char* discountGiven, float* discount, char* membership) {
    int invalidAnswer = 1;
    char input[10];
    while (invalidAnswer) {
       printf("Membership?(Y/N): ");
       if (fgets(input, sizeof(input), stdin) == NULL) {
           return -1;
       }

       input[strcspn(input, "\n")] = '\0';

       if ( strcmp(input, "exit") == 0 ) {
           return -1;
       }

       if ( strlen(input) > 1) {
           printf("Invalid input\n");
           continue;
       }

       if ( strcmp(input, "Y") == 0 ) {

           printf("Congratulations you qualify for a discount of 30%%.\n");
           *discount = 0.7;
           *discountGiven = 'Y';
           *membership = 'Y';
           return 1;

       } else if ( strcmp(input, "N") == 0 ) {

           printf("No discount\n");
           *membership = 'N';
           *discountGiven = 'N';
           *discount = 1;
           return 0;
       } else {
           printf("Invalid input\n");
       }


    }
    return -1;
}

int buyCars(struct Car cars[], int size, struct Sale* sale) {

    int isExit;

    struct Car *car;
    isExit = chooseCar(cars, size, &car);
    if (isExit == -1) {
        return -1;
    }

    char customerName[100];
    isExit = getCustomerName(customerName, sizeof(customerName));
    if (isExit == -1) {
        return -1;
    }


    int numberOfCars;
    isExit = getValidNumberOfCars(car, &numberOfCars);
    if (isExit == -1) {
        return -1;
    }


    char discountGiven;
    char membership = '?';
    float discount = 1;
    isExit = getYoungAdultDiscount(&discountGiven, &discount);
    if (isExit == -1) {
        return -1;
    }
    if (discountGiven != 'Y') {

        isExit = getMembershipDiscount(&discountGiven, &discount, &membership);
        if (isExit == -1) {
            return -1;
        }

    }

    printf("Thank you for buying a car.\n");
    printf("Car: %s\nName: %s\nQuantity: %d\nMembership: %c\nDiscount given: %c\nDiscount percent: %f\nPrice: %d\n", car->name, customerName, numberOfCars, membership, discountGiven, 1-discount, car->price);
    car->quantity -= numberOfCars;
    strcpy(sale->car, car->name);
    strcpy(sale->name, customerName);
    sale->quantity = numberOfCars;
    sale->membership = membership;
    sale->discountGiven = discountGiven;
    sale->discountPercent = 1 - discount;
    sale->price = car->price;
    return 1;

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

int readCarData(struct Car cars[], int size, char filename[]) {
    printf("%s\n", filename);
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Something went wrong.");
        return -1;
    }
    int i = 0;
    while ( fscanf(fp, "%99[^,],%d,%d\n", cars[i].name, &cars[i].quantity, &cars[i].price) == 3 ) {
        i++;
    }
    return 1;
}

int main(void) {

    //mainMenu();
    struct Car cars[MAX_CAR_ARRAY_SIZE];
    readCarData(cars, MAX_CAR_ARRAY_SIZE, "product_data.txt");

    viewCars(cars, 6);
    //struct Sale sale;
    //buyCars(cars, 6, &sale);
    //printf("%s\n", sale.car);
    // viewCars(cars, 6);
    //writeDataToFile();
    return 0;

}
