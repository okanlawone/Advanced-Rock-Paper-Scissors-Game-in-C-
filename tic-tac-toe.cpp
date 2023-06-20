#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Choice { ROCK, PAPER, SCISSORS, LAVA, WATER };

Choice getUserChoice() {
    int choice;
    cout << "Enter your choice:\n";
    cout << "0 - Rock\n";
    cout << "1 - Paper\n";
    cout << "2 - Scissors\n";
    cout << "3 - Lava\n";
    cout << "4 - Water\n";
    cout << "Your choice: ";
    cin >> choice;
    return static_cast<Choice>(choice);
}

Choice getComputerChoice() {
    srand(time(0));
    int choice = rand() % 5;
    return static_cast<Choice>(choice);
}

void determineWinner(Choice userChoice, Choice computerChoice) {
    cout << "Your choice: ";
    switch (userChoice) {
        case ROCK:
            cout << "Rock" << endl;
            break;
        case PAPER:
            cout << "Paper" << endl;
            break;
        case SCISSORS:
            cout << "Scissors" << endl;
            break;
        case LAVA:
            cout << "Lava" << endl;
            break;
        case WATER:
            cout << "Water" << endl;
            break;
    }

    cout << "Computer's choice: ";
    switch (computerChoice) {
        case ROCK:
            cout << "Rock" << endl;
            break;
        case PAPER:
            cout << "Paper" << endl;
            break;
        case SCISSORS:
            cout << "Scissors" << endl;
            break;
        case LAVA:
            cout << "Lava" << endl;
            break;
        case WATER:
            cout << "Water" << endl;
            break;
    }

    cout << "-------------------\n";
    cout << "Rules:\n";
    cout << "Rock beats Scissors and Lava.\n";
    cout << "Paper beats Rock and Water.\n";
    cout << "Scissors beats Paper.\n";
    cout << "Lava beats Scissors and Paper.\n";
    cout << "Water beats Rock and Lava.\n";
    cout << "-------------------\n";

    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == ROCK && (computerChoice == SCISSORS || computerChoice == LAVA)) ||
               (userChoice == PAPER && (computerChoice == ROCK || computerChoice == WATER)) ||
               (userChoice == SCISSORS && computerChoice == PAPER) ||
               (userChoice == LAVA && (computerChoice == SCISSORS || computerChoice == PAPER)) ||
               (userChoice == WATER && (computerChoice == ROCK || computerChoice == LAVA))) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    cout << "*** Rock-Paper-Scissors Game ***" << endl;

    while (true) {
        cout << "-------------------\n";
        cout << "Menu:\n";
        cout << "Enter 'p' to play the game.\n";
        cout << "Enter 'r' to view the rules.\n";
        cout << "Enter 'q' to quit the game.\n";
        cout << "Your choice: ";

        char menuChoice;
        cin >> menuChoice;

        if (menuChoice == 'p' || menuChoice == 'P') {
            Choice userChoice = getUserChoice();
            Choice computerChoice = getComputerChoice();
            determineWinner(userChoice, computerChoice);
        } else if (menuChoice == 'r' || menuChoice == 'R') {
            cout << "-------------------\n";
            cout << "Rules:\n";
            cout << "Rock beats Scissors and Lava.\n";
            cout << "Paper beats Rock and Water.\n";
            cout << "Scissors beats Paper.\n";
            cout << "Lava beats Scissors and Paper.\n";
            cout << "Water beats Rock and Lava.\n";
            cout << "-------------------\n";
        } else if (menuChoice == 'q' || menuChoice == 'Q') {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;
    }

    return 0;
}
