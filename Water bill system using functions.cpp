#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
void getCustomerDetails(string &name, int &units);
double calculateBill(int units, double ratePerUnit);
double applyDiscount(double bill, int units, double &discountAmount);
void displayBill(string name, int units, double ratePerUnit, double billBeforeDiscount, double discountAmount, double finalAmount);

int main() {
    string customerName;
    int unitsConsumed;
    const double rate_per_unit = 5.0;
    double billBeforeDiscount = 0.0;
    double discountAmount = 0.0;
    double finalAmount = 0.0;

    getCustomerDetails(customerName, unitsConsumed);
    
    billBeforeDiscount = calculateBill(unitsConsumed, rate_per_unit );

    finalAmount = applyDiscount(billBeforeDiscount, unitsConsumed, discountAmount);
    
    displayBill(customerName, unitsConsumed, rate_per_unit, billBeforeDiscount, discountAmount, finalAmount);

    return 0;
}

// Function to prompt and get customer name and units consumed
void getCustomerDetails(string &name, int &units) {
    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter number of units consumed: ";
    cin >> units;
}

// Function to compute the water bill
double calculateBill(int units, double ratePerUnit) {
    return units * ratePerUnit;
}

// Function to apply a 10% discount if units exceed 100
double applyDiscount(double bill, int units, double &discountAmount) {
    if (units > 100) {
        discountAmount = bill * 0.10;
        return bill - discountAmount;
    } else {
        discountAmount = 0.0;
        return bill;
    }
}

// Fuaction to print the full bill breakdown
void displayBill(string name, int units, double ratePerUnit, double billBeforeDiscount, double discountAmount, double finalAmount) {

    cout << "\n========================================"<<endl;
    cout << "           WATER BILL STATEMENT          "<<endl;
    cout << "=========================================="<<endl;
    cout << "Customer Name        : " << name << endl;
    cout << "Units Consumed       : " << units <<endl;
    cout << "Rate Per Unit        : KSH " << ratePerUnit <<endl;
    cout << "-----------------------------------------"<<endl;
    cout << "Bill Before Discount : KSH " << billBeforeDiscount << endl;
    cout << "Discount (10%)       : KSH " << discountAmount << endl;
    cout << "========================================="<<endl;
    cout << "Final Amount Payable : KSH " << finalAmount << endl;
    cout << "============================================"<<endl;
}