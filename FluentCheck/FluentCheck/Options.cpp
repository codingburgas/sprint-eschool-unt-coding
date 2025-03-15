#include <iostream>
#include <cstdlib>
#include "testBeginner.h"
#include "options.h"
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

    cout << "[@]=========================================================================================================================[@]" << endl;
    cout << "||   /$$$$$$$$ /$$       /$$   /$$ /$$$$$$$$ /$$   /$$ /$$$$$$$$        /$$$$$$  /$$   /$$ /$$$$$$$$  /$$$$$$  /$$   /$$     ||" << endl;
    cout << "||  | $$_____/| $$      | $$  | $$| $$_____/| $$$ | $$|__  $$__/       /$$__  $$| $$  | $$| $$_____/ /$$__  $$| $$  /$$/     ||" << endl;
    cout << "||  | $$      | $$      | $$  | $$| $$      | $$$$| $$   | $$         | $$  \\__/| $$  | $$| $$      | $$  \\__/| $$ /$$/      ||" << endl;
    cout << "||  | $$$$$   | $$      | $$  | $$| $$$$$   | $$ $$ $$   | $$         | $$      | $$$$$$$$| $$$$$   | $$      | $$$$$/       ||" << endl;
    cout << "||  | $$__/   | $$      | $$  | $$| $$__/   | $$  $$$$   | $$         | $$      | $$__  $$| $$__/   | $$      | $$  $$       ||" << endl;
    cout << "||  | $$      | $$      | $$  | $$| $$      | $$\\  $$$   | $$         | $$    $$| $$  | $$| $$      | $$    $$| $$\\  $$      ||" << endl;
    cout << "||  | $$      | $$$$$$$$|  $$$$$$/| $$$$$$$$| $$ \\  $$   | $$         |  $$$$$$/| $$  | $$| $$$$$$$$|  $$$$$$/| $$ \\  $$     ||" << endl;
    cout << "||  |__/      |________/ \\______/ |________/|__/  \\__/   |__/          \\______/ |__/  |__/|________/ \\______/ |__/  \\__/     ||" << endl;
    cout << "[@]=========================================================================================================================[@]" << endl;
    cout << "-By: UNT | CODING-" << endl;

    cout << endl; //just some blanc spaces 
    cout << endl; 
    cout << endl;

    cout << "[@]================================================[@]" << endl;
    cout << "|           .______________________________.        |" << endl;
    cout << "|                WELCOME TO fluentCheck             |" << endl;
    cout << "|           .------------------------------.        |" << endl;
    cout << "[===================================================]" << endl;
    cout << "|                .___________________.              |" << endl;
    cout << "|                  1. Start a Test                  |" << endl;
    cout << "|                  2. View your scores              |" << endl;
    cout << "|                  3. Quit                          |" << endl;
    cout << "|                 .-----------------.               |" << endl;
    cout << "[===================================================]" << endl;
    cout << "|          .________________________________.       |" << endl;
    cout << "|            Please enter your choice (1-3)         |" << endl;
    cout << "|          .--------------------------------.       |" << endl;
    cout << "[@]================================================[@]" << endl;

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
