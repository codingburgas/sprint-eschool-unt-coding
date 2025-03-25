#include "scores.h"
#include <iostream>
#include <fstream>

// Function to convert points to Bulgarian grade system
int getBulgarianGrade(int points) {
    if (points < 10) {
        return 2;
    }
    else if (points < 13) {
        return 3;
    }
    else if (points < 17) {
        return 4;
    }
    else if (points < 21) {
        return 5;
    }
    else {
        return 6;
    }
}
// Function to read scores from a file and store them in an array
void readScores(const string& filename, int scores[], int& count) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open " << filename << "!" << endl;
        return;
    }

    count = 0;
    while (file >> scores[count] && count < INT_MAX) {
        count++;
    }

    file.close();
}

// Function to find the top 3 highest scores from the array
void findTopScores(int scores[], int count, int topScores[]) {
    for (int i = 0; i < 3; i++) {
        topScores[i] = 0; // Initialize top scores to 0
    }

    // Update top scores in descending order
    for (int i = 0; i < count; i++) {
        if (scores[i] > topScores[0]) {
            topScores[2] = topScores[1];
            topScores[1] = topScores[0];
            topScores[0] = scores[i];
        }
        else if (scores[i] > topScores[1]) {
            topScores[2] = topScores[1];
            topScores[1] = scores[i];
        }
        else if (scores[i] > topScores[2]) {
            topScores[2] = scores[i];
        }
    }
}

// Function to display top scores for the Beginner Test
void displayTopScoresBeginner() {
    int scores[100], count;
    int topScores[3];
    readScores("BeginnerTestDB.txt", scores, count);
    findTopScores(scores, count, topScores);
    cout << "                                                                                                 [@]==============================================[@]" << endl;
    cout << "                                                                                                 ||       ._______________________________.        ||" << endl;
    cout << "                                                                                                 ||        Top 3 Scores for Beginner Test:         ||" << endl;
    cout << "                                                                                                 ||      .---------------------------------.       ||" << endl;
    for (int i = 0; i < 3; i++) {
        int grade = getBulgarianGrade(topScores[i]); // Convert score to Bulgarian grade
        cout << "                                                                                                 ||        " << i + 1 << ". " << topScores[i] << "  Points or a " << grade << " in Bulgaria" << "         ||" << endl;
    }
    cout << "                                                                                                 ||         ----------------------------           ||" << endl;
    cout << "                                                                                                 [@]==============================================[@]" << endl; 
    cout << endl;
}

// Function to display top scores for the Intermediate Test
void displayTopScoresIntermediate() {
    int scores[100], count;
    int topScores[3];
    readScores("intermediateTestDB.txt", scores, count);
    findTopScores(scores, count, topScores);
    cout << "                                                                                                 [@]==============================================[@]" << endl;
    cout << "                                                                                                 ||       ._______________________________.        ||" << endl;
    cout << "                                                                                                 ||      Top 3 Scores for Intermediate Test:       ||" << endl;
    cout << "                                                                                                 ||      .---------------------------------.       ||" << endl;
    for (int i = 0; i < 3; i++) {
        int grade = getBulgarianGrade(topScores[i]); // Convert score to Bulgarian grade
        cout << "                                                                                                 ||        " << i + 1 << ". " << topScores[i] << " Points or a " << grade << " in Bulgaria" << "          ||" << endl;
    }
    cout << "                                                                                                 ||         ----------------------------           ||" << endl;
    cout << "                                                                                                 [@]==============================================[@]" << endl;
    cout << endl;
}

// Function to display top scores for the Advanced Test
void displayTopScoresAdvanced() {
    int scores[100], count;
    int topScores[3];
    readScores("advancedTestDB.txt", scores, count);
    findTopScores(scores, count, topScores);
    cout << "                                                                                                 [@]==============================================[@]" << endl;
    cout << "                                                                                                 ||       ._______________________________.        ||" << endl;
    cout << "                                                                                                 ||        Top 3 Scores for Advanced Test:         ||" << endl;
    cout << "                                                                                                 ||      .---------------------------------.       ||" << endl;
    for (int i = 0; i < 3; i++) {
        int grade = getBulgarianGrade(topScores[i]); // Convert score to Bulgarian grade
        cout << "                                                                                                 ||        " << i + 1 << ". " << topScores[i] << " Points or a " << grade << " in Bulgaria" << "          ||" << endl;
    }
    cout << "                                                                                                 ||         ----------------------------           ||" << endl;
    cout << "                                                                                                 [@]==============================================[@]" << endl;
    cout << endl;
}

// Function to display top scores for all tests
void displayAllScores() {
    displayTopScoresBeginner();
    displayTopScoresIntermediate();
    displayTopScoresAdvanced();
}