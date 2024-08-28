#include <iostream>
#include <cmath>

using namespace std;

void displayMenu() {
    cout << "\n---------------------- SIMPLE CALCULATOR ----------------------\n";
    cout << "Choose an operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division - Quotient (/)" << endl;
    cout << "5. Division - Remainder (%)" << endl;
    cout << "6. Power (^)" << endl;
    cout << "0. Exit" << endl;
    cout << "----------------------------------------------------------------" << endl;
}

int getOperation() {
    int operation;
    cout << "Select an operation (0-6): ";
    while(!(cin >> operation) || operation < 0 || operation > 6) {
        cout << "Invalid input. Please enter a number between 0 and 6: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return operation;
}

void performOperation(int a, int b, int operation) {
    cout << "\nResult: ";
    switch (operation) {
        case 1:
            cout << a << " + " << b << " = " << (a + b) << endl;
            break;
        case 2:
            cout << a << " - " << b << " = " << (a - b) << endl;
            break;
        case 3:
            cout << a << " * " << b << " = " << (a * b) << endl;
            break;
        case 4:
            if (b != 0)
                cout << a << " / " << b << " = " << (a / b) << endl;
            else
                cout << "Error: Division by zero!" << endl;
            break;
        case 5:
            if (b != 0)
                cout << a << " % " << b << " = " << (a % b) << endl;
            else
                cout << "Error: Division by zero!" << endl;
            break;
        case 6:
            cout << a << " ^ " << b << " = " << pow(a, b) << endl;
            break;
    }
    cout << "----------------------------------------------------------------\n";
}

int main() {
    cout << "\n---------------------- WELCOME TO MY SIMPLE CALCULATOR ----------------------\n" << endl;

    int firstNumber, secondNumber;
    int operation;
    bool continueCalculator = true;

    while (continueCalculator) {
        cout << "Enter the first number: ";
        while(!(cin >> firstNumber)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter the second number: ";
        while(!(cin >> secondNumber)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        do {
            displayMenu();
            operation = getOperation();

            if (operation == 0) {
                continueCalculator = false;
                break;
            }

            performOperation(firstNumber, secondNumber, operation);

            cout << "Would you like to:" << endl;
            cout << "1. Continue with the same numbers" << endl;
            cout << "2. Enter new numbers" << endl;
            cout << "0. Exit" << endl;
            cout << "Choose an option (0/1/2): ";
            while(!(cin >> operation) || (operation != 0 && operation != 1 && operation != 2)) {
                cout << "Invalid input. Please enter 0, 1, or 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (operation == 2) {
                break;
            } else if (operation == 0) {
                continueCalculator = false;
            }

        } while(operation == 1);
    }

    cout << "\nThank you for using this calculator.\n";
    return 0;
}
