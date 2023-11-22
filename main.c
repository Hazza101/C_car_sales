
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "data.h"


#include "fileFunctions.h"
#include "sortFunction.h"
#include "genericFunctions.h"






int exitProgram = 0;


void mainMenuPrintStatements() {
    printf("\n\n______Main Menu________\n\n");
    printf("Type A to view car selection\n");
    printf("\nType B to buy a car\n");
    printf("\nType C to view sales\n");
    printf("\nType X to exit\n");
    printf("\nEnter:");
}



void mainMenu() {
    printf("\n ______Welcome to BAINS AUTOS LTD______\n\n\n");
    while (exitProgram == 0) {
        char response;


        mainMenuPrintStatements();


        scanf("\n%c", &response);
        response = toupper(response);
        if (getchar() != '\n') {
            response = 'z';
        }

        switch (response) {

        case VIEW_CARS:
            viewCars();
            returnToMainMenu();
            break;

        case BUY_CAR:
            buyCars();
            returnToMainMenu();
            break;

        case VIEW_SALES:
            viewSales();
            returnToMainMenu();
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

        /**
        if (response == EXIT) {
            printf("Have a nice day. :)");
            //setting not exit equal to 0 ends the while loop which is the main menu
            exitProgram = 1;
        }
        //Telling the user if they haven't chosen one of the acceptable options
        else if (response != 'A' && response != 'B' && response != 'C' && response != 'X') {
            printf("\nPlease enter an appropriate response.");

        }
        **/

        clearScreen();
    }

}






void viewCars() {
    sortCarArray();

    clearScreen();
    printf("\n\n ____Available Models____\n\n");
    for (int i = 0; i < MAX_CAR_ARRAY_SIZE; i++) {
        printf("We have %d %s's available at £%d. \n", carArray[i].carQuantity, carArray[i].carName, carArray[i].carPrice);
    }

}



int buyCars() {
    int invalidCarChosen = 1;
    char carName[100];
    int carIndex;
    clearScreen();
    while (invalidCarChosen == 1)
    {

        printf("\n\nPlease enter one of our car models\n\n");
        viewCars();

        printf("\n\nType exit to return to main menu\n\n");
        printf("\nWhat car would you like to buy? \n\n");
        char userResponse[100];
        scanf("\n%[^\n]s", userResponse);
        if (strcmp(userResponse, "exit") == 0) {
            return 0;
        }

        for (int i = 0; i < MAX_CAR_ARRAY_SIZE; i++)
        {

            int stringComparison;


            stringComparison = strcmp(userResponse, carArray[i].carName);

            if (stringComparison == 0)
            {


                strcpy(carName, carArray[i].carName);
                invalidCarChosen = 0;
                carIndex = i;


            }
        }
        if (invalidCarChosen == 1)
        {

            clearScreen();
            printf("Invalid Car Choice. Car Names are case sensitive.");


        }
    }


    char customerName[100];

    printf("\nWhat is your full name?\n\n");
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
    invalidCarChosen = 0;









}




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




















void main()
{

    ReadDataFromFile();
    mainMenu();
    writeDataToFile();

}