#ifndef SCORES_H
#define SCORES_H

#include <string>

using namespace std;

void readScores(const string& filename, int scores[], int& count);
void findTopScores(int scores[], int count, int topScores[]);
void displayTopScoresBeginner(int topScores[]);
void displayTopScoresIntermediate(int topScores[]);

#endif