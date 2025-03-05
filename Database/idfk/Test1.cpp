#include <iostream>
#include <fstream>
using namespace std;

void takeQuizAndSaveScore(const string& DB) {
    char answers[3];
    char correctAnswers[3] = { 'B', 'C', 'A' };
    int score = 0;

    cout << "Quiz: Choose A, B, C, or D.\n";

    cout << "1. What is 2 + 2?\nA) 3\nB) 4\nC) 5\nD) 6\n";
    cin >> answers[0];

    cout << "2. What is the capital of France?\nA) Berlin\nB) Madrid\nC) Paris\nD) Rome\n";
    cin >> answers[1];

    cout << "3. Which planet is known as the Red Planet?\nA) Mars\nB) Earth\nC) Venus\nD) Jupiter\n";
    cin >> answers[2];

    for (int i = 0; i < 3; i++) {
        answers[i] = toupper(answers[i]);
    }

    for (int i = 0; i < 3; i++) {
        if (answers[i] == correctAnswers[i]) {
            score++;
        }
    }

    cout << "Your score: " << score << "/3" << endl;

    ofstream file(DB, ios::app);
    file << score << endl;
    file.close();

    cout << "Your score has been saved to " << DB << endl;
}