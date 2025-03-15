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

    // Process BeginnerTestDB
    readScores("BeginnerTestDB.txt", scores, count);
    findTopScores(scores, count, topScores);
    displayTopScoresBeginner(topScores);

    // Process IntermediateTestDB
    readScores("IntermediateTestDB.txt", scores, count);
    findTopScores(scores, count, topScores);
    displayTopScoresIntermediate(topScores);

    return 0;
}