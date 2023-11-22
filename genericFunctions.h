int getValidatedWholeNumber() {
    int validWholeNumber = 0;
    int userInput;
    do
    {


        int numOfCapturedValues = scanf("%d", &userInput);

        if (numOfCapturedValues == 0)
        {
            printf("\nPlease only enter whole numbers.\n\n");
            char string[10];
            scanf("%s", string);
            if (strcmp(string, "exit") == 0)
            {
                return 2000;
            }
        }
        else {

            validWholeNumber = 1;
        }


        while (getchar() != '\n');


    } while (validWholeNumber == 0);
    return userInput;
}

int getNumberOfSales() {
    int numOfSales = 0;
    for (int i = 0; i < MAX_SALES_SIZE; i++) {
        if (customerArray[i].totalPrice != 0) {
            numOfSales++;

        }
    }
    return numOfSales;
}

void clearScreen() {
    if (OS == "nt") {
        system("cls");
    }
    else if (OS == "posix") {
        system("clear");
    }
}


void returnToMainMenu() {

    //while (getchar() != '\n');
    printf("\n\nPlease press Enter to return to the main Menu:");
    getchar();
    clearScreen();
}
