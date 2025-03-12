#include <iostream>
#include <cstdlib>
#include "testBeginner.h"
#include "Options.h"
#include "intermediateTest.h"

using namespace std;

void clearConsole() {
    system("cls");  // cls clears the screen
}

void MainMenu() {
    string mainChoiceStr;
    string testChoiceStr;
    int mainChoice;
    int testChoice;

    cout << "Main Menu" << endl;
    cout << "1. Start Test" << endl;
    cout << "2. View Scores" << endl;
    cout << "3. Exit" << endl;
    cout << "(Enter 1 to start a test)" << endl;
    cout << "(Enter 2 to view the average score, and the top three highest scores achieved)" << endl;
    cout << "(Enter 3 to exit the program)" << endl;

    getline(cin, mainChoiceStr);
    mainChoice = stoi(mainChoiceStr);  //converts string to integer to avoid a bug where the test skips a question
    clearConsole();

    switch (mainChoice) {
    case 1:
        cout << "--- Start A Test ---" << endl;
        cout << "1. Start Beginner Test (Recommended A1-A2 level)" << endl;
        cout << "   Beginner test for users who have less experience and knowledge of the language.\n";
        cout << "   It practices spelling, tenses, correct word usage, and more.\n";
        cout << "   There are only multiple-choice questions.\n\n";

        cout << "2. Start Intermediate Test (Recommended B1-B2 level)" << endl;
        cout << "   Intermediate test for users who have an average English level.\n";
        cout << "   More questions, harder exercises, spelling, tenses, correct word usage, sentence forming, articles, and more.\n";
        cout << "   It is a mix between multiple-choice questions and open questions.\n\n";

        cout << "3. Start Advanced Test (Recommended C1-C2 level)" << endl;
        cout << "   Advanced test for users who have an advanced English level.\n";
        cout << "   Even more questions and advanced exercises covering complex grammar, refined sentence construction, and significant vocabulary.\n";
        cout << "   It has only open questions\n\n";

        getline(cin, testChoiceStr);
        testChoice = stoi(testChoiceStr);

        if (testChoice == 1) {
            clearConsole();
            beginnerTest();
        }
        else if (testChoice == 2) {
            clearConsole();
            intermediateTest();
        }
        else if (testChoice == 3) {
            clearConsole();
            // advancedTest();
        }
        else {
            cout << "Invalid choice." << endl;
        }
        break;

    case 2:
        cout << "\nScores: " << endl;
        //code for viewing scores for beginner, intermediate, advanced test goes here
        break;

    case 3:
        cout << "Exiting program." << endl;
        break;

    default:
        cout << "\nInvalid choice. Please try again.\n" << endl;
        break;
    }
}
