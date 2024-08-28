#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

void showMainMenu();
void startGuessingGame(int &previousAttempts, int &bestScore, int &totalGames, int &totalAttempts);
void displayPreviousScore(int previousAttempts, int bestScore, int totalGames);
void exitGame();
int getNumberRange();
int getUserGuess(int range);
void giveHint(int secretNumber, int attemptCount);

int main() {
    int userChoice;
    int previousAttempts = 0, bestScore = INT_MAX, totalGames = 0, totalAttempts = 0;

    while (true) {
        showMainMenu();
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                startGuessingGame(previousAttempts, bestScore, totalGames, totalAttempts);
                break;
            case 2:
                displayPreviousScore(previousAttempts, bestScore, totalGames);
                break;
            case 3:
                exitGame();
                return 0; 
            default:
                cout << "Oops! That’s not a valid choice. Please select a valid option." << endl;
        }
    }
}

void showMainMenu() {
    cout << "\n----------------------------------------------------------------------" << endl;
    cout << "----------------------- WELCOME TO THE GUESSING GAME -----------------------" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Please choose an option below:" << endl;
    cout << "1. Play the Game" << endl;
    cout << "2. View Previous Score" << endl;
    cout << "3. Exit" << endl;
    cout << "Your choice: ";
}

void startGuessingGame(int &previousAttempts, int &bestScore, int &totalGames, int &totalAttempts) {
    int range = getNumberRange();
    int secretNumber, userGuess, attemptCount = 0;

    srand(static_cast<unsigned int>(time(nullptr))); 
    secretNumber = rand() % range + 1;

    cout << "\n-------------------- GUESS THE NUMBER GAME --------------------" << endl;
    cout << "I've picked a number between 1 and " << range << ". Can you guess it?" << endl;

    do {
        userGuess = getUserGuess(range);
        attemptCount++;

        if (userGuess > secretNumber) {
            cout << "The number is smaller than your guess." << endl;
        } else if (userGuess < secretNumber) {
            cout << "The number is larger than your guess." << endl;
        } else {
            cout << "Congratulations! You've found the number in " << attemptCount << " attempt" << (attemptCount > 1 ? "s" : "") << "!" << endl;
            previousAttempts = attemptCount;
            if (attemptCount < bestScore) {
                bestScore = attemptCount;
                cout << "New best score!" << endl;
            }
            totalGames++;
            totalAttempts += attemptCount;
        }

        if (attemptCount % 5 == 0 && userGuess != secretNumber) {
            giveHint(secretNumber, attemptCount);
        }

    } while (userGuess != secretNumber);

    cout << "Do you want to play again? (y/n): ";
    char playAgain;
    cin >> playAgain;
    if (tolower(playAgain) == 'y') {
        startGuessingGame(previousAttempts, bestScore, totalGames, totalAttempts);
    }
}

void displayPreviousScore(int previousAttempts, int bestScore, int totalGames) {
    if (totalGames == 0) {
        cout << "\nYou haven’t played any games yet." << endl;
    } else {
        cout << "\nPrevious Game Attempts: " << previousAttempts << endl;
        cout << "Best Score: " << bestScore << " attempt" << (bestScore > 1 ? "s" : "") << endl;
        cout << "Total Games Played: " << totalGames << endl;
        cout << "Average Attempts per Game: " << static_cast<double>(previousAttempts) / totalGames << endl;
    }
}

void exitGame() {
    cout << "\nThank you for playing! Have a great day!" << endl;
}

int getNumberRange() {
    int range;
    cout << "Specify the maximum number for the range (must be positive): ";
    while (!(cin >> range) || range < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid range. Please enter a positive integer: ";
    }
    return range;
}

int getUserGuess(int range) {
    int guess;
    cout << "Enter your guess between 1 and " << range << ": ";
    while (!(cin >> guess) || guess < 1 || guess > range) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between 1 and " << range << ": ";
    }
    return guess;
}

void giveHint(int secretNumber, int attemptCount) {
    cout << "Hint: ";
    if (secretNumber % 2 == 0) {
        cout << "The number is even." << endl;
    } else {
        cout << "The number is odd." << endl;
    }
    if (attemptCount > 10) {
        cout << "Bonus hint: The number is ";
        if (secretNumber > attemptCount) {
            cout << "greater than " << attemptCount << "." << endl;
        } else {
            cout << "less than " << attemptCount << "." << endl;
        }
    }
}
