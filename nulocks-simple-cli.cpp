#include "nulocks-core/Board.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
        cout << "Nulocks Simple CLI (C) 2014 by Phitherek_" << endl << endl;
        cout << "GAME RULES: Move the blocks on the board and match the numbers to get to " << pow(2, 11) << " block!" << endl << endl;
        Nulocks::Core::Board b;
        bool cont = true;
        bool afterwin = false;
        int** repr;
        repr = new int*[b.getSize()];
        for(int i = 0; i < b.getSize(); i++) {
                repr[i] = new int[b.getSize()];
        }
        while(cont) {
                cout << "Your score: " << b.getScore() << endl << endl;
                if(b.gameWon() && !afterwin) {
                        cout << "You won the game! Do you want to continue? (y/N)" << endl;
                        char o;
                        cin >> o;
                        if(o == 'y') {
                                afterwin = true;
                        } else {
                                cont = false;
                                break;
                        }
                } else if(b.gameLost()) {
                        cout << "You have lost the game :(" << endl;
                        cont = false;
                        break;
                }
                b.getRepresentation(&repr);
                for(int i = 0; i < b.getSize(); i++) {
                        if(i > 0) {
                                for(int j = 0; j < 4; j++) {
                                        cout << endl;
                                }
                        }
                        for(int j = 0; j < b.getSize(); j++) {
                                if(repr[i][j] > 0) {
                                        cout << repr[i][j] << "\t";
                                } else {
                                        cout << "#\t";
                                }
                        }
                }
                cout << endl;
                cout << endl << "(w, s, a, d) for move, (q) to quit: ";
                char c;
                cin >> c;
                if(c == 'q') {
                        cont = false;
                        break;
                } else if(c == 'w') {
                        b.moveUp();
                } else if(c == 's') {
                        b.moveDown();
                } else if(c == 'a') {
                        b.moveLeft();
                } else if(c == 'd') {
                        b.moveRight();
                }
                for(int i = 0; i < 20; i++) {
                        cout << endl;
                }
        }
        for(int i = 0; i < b.getSize(); i++) {
                delete[] repr[i];
        }
        delete[] repr;
        cout << "All done! Thanks for playing!" << endl;
        return EXIT_SUCCESS;
}
