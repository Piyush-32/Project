#include <iostream>

using namespace std;

class ATM {
private:
    int Amount;
    int pin;

public:
    // Constructor to initialize Amount and pin
    ATM(int initialAmount, int initialPin) {
        Amount = initialAmount;
        pin = initialPin;
    }

    // Method to withdraw money
    void withdraw(int amt, int enteredPin) {
        cout << "Enter pin :" << " ";
        cin >> enteredPin;
        if (enteredPin == pin) {
            if (Amount >= amt) {
                cout << "Transaction successful" << endl;
                Amount -= amt;
                cout << "New Balance is " << Amount << endl;
            } else {
                cout << "Insufficient balance" << endl;
            }
        } else {
            cout << "Incorrect pin" << endl;
        }
    }

    // Method to deposit money
    void deposit(int amt) {
        Amount += amt;
        cout << "Deposited successfully" << endl;
        cout << "New Balance: " << Amount << endl;
    }

    // Method to change pin
    void pinChange(int newPin) {
        pin = newPin;
        cout << "Your pin has been changed successfully. Please use the new pin for further transactions." << endl;
    }

    // Method to check balance
    void checkBalance() {
        cout << "Your Balance: " << Amount << endl;
    }

    // Main ATM interface
    void start() {
        cout << "Welcome to ATM" << endl;
        int amt, n, newPin;
        char ch;
        do {
            cout << "Please insert your card" << endl;
            cout << "1: Withdraw\n2: Deposit\n3: Pin change\n4: Check balance" << endl;
            cout << "Enter your choice: ";
            cin >> n;
            cout << endl;
            switch (n) {
                case 1:
                    cout << "Enter amount to withdraw: ";
                    cin >> amt;
                    withdraw(amt, pin);
                    break;
                case 2:
                    cout << "Enter amount to deposit: ";
                    cin >> amt;
                    deposit(amt);
                    break;
                case 3:
                    cout << "Enter new pin: ";
                    cin >> newPin;
                    pinChange(newPin);
                    break;
                case 4:
                    checkBalance();
                    break;
                default:
                    cout << "Please choose a correct option" << endl;
            }
            cout << "Do you want to continue (y/n): ";
            cin >> ch;
            cout << endl;
        } while (ch == 'y' || ch == 'Y');
    }
};

int main() {
    // Initialize ATM object with initial amount and pin
    ATM atm(10000, 1234);
    // Start the ATM interface
    atm.start();
    return 0;
}
