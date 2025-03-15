#include <iostream>
#include <fstream>
#include "testBeginner.h"
#include "options.h"
#include "scores.h"
using namespace std;

int main() {
    MainMenu();

    int scores[100], count;
    int topScores[3];

    readScores("BeginnerTestDB.txt", scores, count);
    findTopScores(scores, count, topScores);
    displayTopScores(topScores);

    return 0;
}
