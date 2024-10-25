#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class ScoreStack 
{
    int* scores;
    int maxStackSize;
    int stackSize;
public:
    ScoreStack(int maxSize) : maxStackSize(maxSize), stackSize(0) {
        scores = new int[maxStackSize];
    }

    ~ScoreStack() {
        delete[] scores;
    }

    void push(int score) {
        if (stackSize < maxStackSize) {
            scores[stackSize++] = score;
        }
        else {
            cout << "Stack overflow: cannot add more scores." << endl;
        }
    }

    int pop() {
        if (stackSize > 0) {
            return scores[--stackSize];
        }
        else {
            cout << "Stack underflow: no scores to remove." << endl;
            return -1;
        }
    }

    void showScores() const {
        cout << "\n--- Score History ---" << endl;
        for (int i = 0; i < stackSize; i++) {
            cout << "Win " << (i + 1) << ": " << scores[i] << " points" << endl;
        }
        cout << "---------------------\n" << endl;
    }

    bool isEmpty() const {
        return stackSize == 0;
    }
};

class SlotMachine {
    int score;
    ScoreStack scoreStack;
public:
    SlotMachine() : score(0), scoreStack(10) {}

    char spinReel() {
        char symbols[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
        int randomIndex = rand() % 6;
        return symbols[randomIndex];
    }

    bool checkWin(char reel1, char reel2, char reel3) {
        return (reel1 == reel2 && reel2 == reel3);
    }

    void play() {
        char reel1, reel2, reel3;
        string input;

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
                scoreStack.push(10);
            }
            else {
                cout << "Try again!" << endl;
            }

            cout << "Your current score: " << score << " points" << endl;
            scoreStack.showScores();

            cout << "Press Enter to spin again or type 'exit' to quit." << endl;
            getline(cin, input);
            if (input == "exit" || input == "Exit") {
                break;
            }
        }
    } 
};

int main() {
    srand(time(0));
    SlotMachine game;
    game.play();
    return 0;
}