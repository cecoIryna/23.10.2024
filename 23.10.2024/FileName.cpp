#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

char spinReel() {
    char symbols[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    int randomIndex = rand() % 6;
    return symbols[randomIndex];
}

bool checkWin(char reel1, char reel2, char reel3) {
    return (reel1 == reel2 && reel2 == reel3); 
}

int main() {
    srand(time(0));

    char reel1, reel2, reel3;
    string input;
    int score = 0; 

    cout << "Welcome to the Slot Machine! Press Enter to spin the reels..." << endl;
    getline(cin, input);

    while (true) {
        reel1 = spinReel();
        reel2 = spinReel();
        reel3 = spinReel();

        cout << "Reels: " << reel1 << " " << reel2 << " " << reel3 << endl;

        if (checkWin(reel1, reel2, reel3)) {
            cout << "Congratulations! You've won!" << endl;
            score += 10;
        }
        else {
            cout << "Try again!" << endl;
        }

        cout << "Your current score: " << score << " points" << endl;
        cout << endl;

        cout << "Press Enter to spin again or type 'exit' to quit." << endl;
        getline(cin, input);
        if (input == "exit" || input == "Exit") {
            break;
        }
    }

    return 0;
}