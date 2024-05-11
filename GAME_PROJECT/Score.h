#ifndef SCORE__H
#define SCORE__H

#include "graphics.h"
#include "defs.h"
#include <fstream>
#include <cstdlib>

using namespace std;
    bool isHighScoreFileEmpty()
    {
        ifstream file("Highscore.txt");
        return file.peek() == ifstream::traits_type::eof();
    }

    int readHighScore()
    {
        int highScore;
        ifstream file("Highscore.txt");
        if (file.good()) {
            file >> highScore;
        }else{
            highScore = 0;
        }
        return highScore;
    }

    void updateHighScore(int newHighScore)
    {
        ofstream file("Highscore.txt");
        if (file.good()){
            file.clear();
            file << newHighScore;
        }else{
            cout << "Error updating high score!" << endl;
            exit(EXIT_FAILURE);
        }
    }
#endif // SCORE__H
