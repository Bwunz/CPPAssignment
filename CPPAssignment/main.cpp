#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;


void displayLogo();
void mainMenu();
void displayMovies();
void selectScreenType();
void selectTime();
void selectSeats();
void foodBeveragesMenu();
void showOrderDetails();
void showInvoice();
void showPurchaseHistory();
void exitProgram();


vector<string> movies = { "Zootopia 2", "Moana 2", "Snow White", "Avatar 3", "The Wild Robot" };
vector<string> screenTypes = { "2D", "Atmos", "3D" };
vector<string> showTimes = { "8:00 AM", "10:00 AM", "12:00 PM", "2:00 PM", "4:00 PM", "6:00 PM", "8:00 PM", "10:00 PM" };
vector<string> foodMenu = { "Popcorn - $5.00", "Potato Chips - $4.00", "100 Plus - $3.00", "Cola - $3.00", "Combo - $10.00" };

string selectedMovie, selectedScreenType, selectedTime;
int numAdults, numKids, numStudents, numSeniors, numOKU;
double totalPrice = 0.0;
vector<string> purchaseHistory;

int main() {
    displayLogo();
    mainMenu();
    return 0;
}

void displayLogo() {
    cout << "==============================" << endl;
    cout << "        Cincai CINEMA        " << endl;
    cout << "==============================" << endl << endl;
}

void mainMenu() {
    int choice;
    do {
        cout << "\nMain Menu:" << endl;
        cout << "1. Movies" << endl;
        cout << "2. Purchase History" << endl;
        cout << "3. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;
        switch (choice) {
        case 1:
            displayMovies();
            break;
        case 2:
            showPurchaseHistory();
            break;
        case 3:
            exitProgram();
            break;
        default:
            cout << "\nInvalid option, please try again." << endl;
        }
    } while (choice != 3);
}

void displayMovies() {
    cout << "\nMovies List:" << endl;
    for (int i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i] << endl;
    }
    int movieChoice;
    cout << "Select a movie: ";
    cin >> movieChoice;
    if (movieChoice > 0 && movieChoice <= movies.size()) {
        selectedMovie = movies[movieChoice - 1];
        selectScreenType();
    }
    else {
        cout << "Invalid selection." << endl;
    }
}

void selectScreenType() {
    cout << "\nScreen Types:" << endl;
    for (int i = 0; i < screenTypes.size(); i++) {
        cout << i + 1 << ". " << screenTypes[i] << endl;
    }
    int screenChoice;
    cout << "Select a screen type: ";
    cin >> screenChoice;
    if (screenChoice > 0 && screenChoice <= screenTypes.size()) {
        selectedScreenType = screenTypes[screenChoice - 1];
        selectTime();
    }
    else {
        cout << "Invalid selection." << endl;
    }
}

void selectTime() {
    cout << "\nAvailable Times:" << endl;
    for (int i = 0; i < showTimes.size(); i++) {
        cout << i + 1 << ". " << showTimes[i] << endl;
    }
    int timeChoice;
    cout << "Select a time: ";
    cin >> timeChoice;
    if (timeChoice > 0 && timeChoice <= showTimes.size()) {
        selectedTime = showTimes[timeChoice - 1];
        selectSeats();
    }
    else {
        cout << "Invalid selection." << endl;
    }
}

void selectSeats() {
    cout << "\nEnter number of Adults: ";
    cin >> numAdults;
    cout << "Enter number of Kids: ";
    cin >> numKids;
    cout << "Enter number of Students: ";
    cin >> numStudents;
    cout << "Enter number of Senior Citizens: ";
    cin >> numSeniors;
    cout << "Enter number of OKU: ";
    cin >> numOKU;

    double adultPrice = numAdults * 15.0;
    double kidPrice = numKids * 15.0 * 0.9;
    double studentPrice = numStudents * 15.0 * 0.9;
    double seniorPrice = numSeniors * 15.0 * 0.8;
    double okuPrice = numOKU * 15.0 * 0.7;

    totalPrice = adultPrice + kidPrice + studentPrice + seniorPrice + okuPrice;

    foodBeveragesMenu();
}

void foodBeveragesMenu() {
    char choice;
    cout << "\nDo you want food/beverages? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Food/Beverages Menu:" << endl;
        for (int i = 0; i < foodMenu.size(); i++) {
            cout << i + 1 << ". " << foodMenu[i] << endl;
        }
        cout << "Select an option (or 0 to skip): ";
        int foodChoice;
        cin >> foodChoice;
        switch (foodChoice) {
        case 1:
            totalPrice += 5.0;
            break;
        case 2:
            totalPrice += 4.0;
            break;
        case 3:
            totalPrice += 3.0;
            break;
        case 4:
            totalPrice += 3.0;
            break;
        case 5:
            totalPrice += 10.0;
            break;
        case 0:
            break;
        default:
            cout << "Invalid selection." << endl;
        }
    }

    showOrderDetails();
}

void showOrderDetails() {
    double tax = totalPrice * 0.06;
    totalPrice += tax;

    cout << "\nOrder Summary:" << endl;
    cout << "Movie: " << selectedMovie << endl;
    cout << "Screen Type: " << selectedScreenType << endl;
    cout << "Time: " << selectedTime << endl;
    cout << "Seats: " << (numAdults + numKids + numStudents + numSeniors + numOKU) << endl;
    cout << "Total Price: $" << fixed << setprecision(2) << totalPrice << " (including tax)" << endl;

    char confirm;
    cout << "Confirm order? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        char paymentMethod;
        cout << "Payment Method (A - Card, B - Cash, C - E-Wallet): ";
        cin >> paymentMethod;
        showInvoice();
    }
}

void showInvoice() {
    cout << "\n==============================" << endl;
    cout << "            INVOICE            " << endl;
    cout << "==============================" << endl;
    cout << "Movie: " << selectedMovie << endl;
    cout << "Screen Type: " << selectedScreenType << endl;
    cout << "Time: " << selectedTime << endl;
    cout << "Seats: " << (numAdults + numKids + numStudents + numSeniors + numOKU) << endl;
    cout << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
    cout << "Hall: " << rand() % 10 + 1 << endl;
    cout << "==============================" << endl;

    purchaseHistory.push_back("Movie: " + selectedMovie + ", Total Price: $" + to_string(totalPrice));
}

void showPurchaseHistory() {
    cout << "\nPurchase History:" << endl;
    for (const auto& record : purchaseHistory) {
        cout << record << endl;
    }
}

void exitProgram() {
    cout << "Exiting the program..." << endl;
}
