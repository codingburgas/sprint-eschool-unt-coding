#ifndef SCORES_H
#define SCORES_H

#include <string>

using namespace std;

void readScores(const string& filename, int scores[], int& count);
void findTopScores(int scores[], int count, int topScores[]);
void displayTopScoresBeginner();
void displayTopScoresIntermediate();
void displayTopScoresAdvanced();
void displayAllScores();
int getBulgarianGrade(int points);

#endif