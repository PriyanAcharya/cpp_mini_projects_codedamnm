#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string getChoice(int num) {
    switch(num) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Unknown";
    }
}

string determineWinner(int user, int comp) {
    if (user == comp) return "Draw";
    if ((user == 1 && comp == 3) ||
        (user == 2 && comp == 1) ||
        (user == 3 && comp == 2))
        return "You win";
    else
        return "I win";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int urchoice;
    int compChoice;

    cout << "Rock, Paper, Scissors Game!\n";
    cout << "Choose:\n1. Rock\n2. Paper\n3. Scissors\n";
    cout << "Enter your choice (1-3): ";
    cin >> urchoice;

    if (urchoice < 1 || urchoice > 3) {
        cout << "Invalid input. Please enter 1, 2, or 3.\n";
        return 1;
    }

    compChoice = rand() % 3 + 1;

    cout << "You chose: " << getChoice(urchoice) << endl;
    cout << "I chose: " << getChoice(compChoice) << endl;

    cout << "Result: " << determineWinner(urchoice, compChoice) << endl;

    return 0;
}
