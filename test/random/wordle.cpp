#include <iostream>
#include <cstring>
using namespace std;

/**
 * 0 OFF
 * 1 ON
 * 2 YELLOW
 * 3 GREEN
 */

int main(int argc, char** argv) {

    // Initialize wordle
    char wordle[6];
    strcpy(wordle, argv[1]);

    char guess[6];
    char color[27] = {1};

    char guess_num = 0;
    bool win = 0;

    while (guess_num < 6 & !win) {

        // Read in guess
        cin >> guess;

        // Assign colors
        for (int i = 0; i < 5; i++) {
            if (guess[i] == wordle[i]) {
                color[i] = 3; 
            } else {
                for (int j = i + 1; j < 5; j++) {
                    if (guess[i] == wordle[j]) {
                        color[i] = 2; break;
                    } else {
                        color[i] = 0;
                    }
                }
            }
            cout << +color[i] << " ";
        }

        // Check for win
        win = 1;
        for (int i = 0; i < 5; i++) {
            if (color[i] != 3) {
                win = 0;
            }
        }

        // Increment guess_num
        guess_num += 1;

        cout << "\n";
    }

    return 0;
}