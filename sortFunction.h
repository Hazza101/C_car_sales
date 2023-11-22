void sortCustomerArray() {
    int notSorted = 1;
    while (notSorted == 1) {

        notSorted = 0;
        int numOfSales = getNumberOfSales();
        for (int i = 0; i < numOfSales; i++) {
            int consecutiveSalesIndex = i + 1;



            if (customerArray[i].totalPrice < customerArray[consecutiveSalesIndex].totalPrice) {
                notSorted = 1;

                tempCustomer = customerArray[i];
                customerArray[i] = customerArray[consecutiveSalesIndex];
                customerArray[consecutiveSalesIndex] = tempCustomer;




            }

        }
    }



}

void sortCarArray() {
    int notSorted = 1;
    while (notSorted == 1) {

        notSorted = 0;
        for (int i = 0; i < MAX_CAR_ARRAY_SIZE; i++) {
            int consecutiveSalesIndex = i + 1;



            if (carArray[i].carQuantity < carArray[consecutiveSalesIndex].carQuantity) {

                notSorted = 1;

                tempCar = carArray[i];
                carArray[i] = carArray[consecutiveSalesIndex];
                carArray[consecutiveSalesIndex] = tempCar;



            }

        }
    }



}

