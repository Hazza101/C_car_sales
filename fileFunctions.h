void ReadDataFromFile() {

    FILE* salesFile;


    salesFile = fopen("sales_data.txt", "r");


    if (salesFile != NULL) {
        int salesIndex = 0;
        int fileStream;
        while (fileStream != EOF) {
            fileStream = fscanf(
                salesFile, "%[^,],%[^,], %d %d %c %c %f %f",
                customerArray[salesIndex].customerName, customerArray[salesIndex].carName,
                &customerArray[salesIndex].numberOfCars, &customerArray[salesIndex].age,
                &customerArray[salesIndex].membership, &customerArray[salesIndex].discountGiven,
                &customerArray[salesIndex].discount, &customerArray[salesIndex].totalPrice
            );






            salesIndex++;
        }
        fclose(salesFile);
    }
    else {
        printf("No file exists");

    }
}


void writeDataToFile() {
    FILE* salesFile;
    salesFile = fopen("sales_data.txt", "w");
    if (salesFile != NULL) {
        int fileStream;
        int numOfSales = getNumberOfSales();
        int salesIndex = 0;
        clearScreen();

        while (salesIndex < numOfSales) {

            fileStream = fprintf(
                salesFile, "%s,%s, %d %d %c %c %f %f\n",
                customerArray[salesIndex].customerName, customerArray[salesIndex].carName,
                customerArray[salesIndex].numberOfCars, customerArray[salesIndex].age,
                customerArray[salesIndex].membership, customerArray[salesIndex].discountGiven,
                customerArray[salesIndex].discount, customerArray[salesIndex].totalPrice
            );
            salesIndex++;

        }
        fclose(salesFile);
    }
    else {
        printf("No file exists.");
    }


}

