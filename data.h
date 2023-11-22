#define VIEW_CARS 'A'
#define VIEW_SALES 'C'
#define BUY_CAR 'B'
#define EXIT 'X'
#define MAX_CAR_ARRAY_SIZE 6
#define MAX_SALES_SIZE 20
#ifdef _WIN32
#define OS "nt"
#elif __unix__
#define OS "posix"
#endif

void ReadDataFromFile();
void writeDataToFile();

void mainMenu();
void mainMenuPrintStatements();
void viewCars();
int buyCars();
void viewSales();

void SortCarArray();
void SortCustomerArray();

int getValidatedWholeNumber();
int getNumberOfSales();
void returnToMainMenu();
void clearScreen();

struct car {
    char carName[100];
    int carQuantity;
    int carPrice;
};


struct customer {
    char customerName[100];
    char carName[100];
    int numberOfCars;
    int age;
    char membership;
    char discountGiven;
    float discount;
    float totalPrice;
};


//creating an array to contain a list of different cars and their information same with customer
//but leaving it empty
struct car carArray[MAX_CAR_ARRAY_SIZE] = {
    {"Audi A1", 10, 23000},
    {"Ford Fiesta", 6, 18000},
    {"Vauxhall Astra", 10, 21000},
    {"BMW", 10, 30000},
    {"Nissan Duke", 7, 22000},
    {"Volkswagen Golf", 5, 28000}
};

struct customer customerArray[MAX_SALES_SIZE];
struct car tempCar;
struct customer tempCustomer;