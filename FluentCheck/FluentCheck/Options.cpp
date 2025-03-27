#include <iostream>
#include <cstdlib>
#include "testBeginner.h"
#include "options.h"
#include "intermediateTest.h"
#include "advancedTest.h"
#include "scores.h"
#include <conio.h>
#include <Windows.h>

using namespace std;

void setColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

void clearConsole() {
    system("cls");  // cls clears the screen
}

void MainMenu() {
    string mainChoiceStr;
    string testChoiceStr;
    int mainChoice;
    int testChoice;

    setColor(15);
    cout << "                                                             [@]=========================================================================================================================[@]" << endl;
    cout << "                                                             ||   /$$$$$$$$ /$$       /$$   /$$ /$$$$$$$$ /$$   /$$ /$$$$$$$$        /$$$$$$  /$$   /$$ /$$$$$$$$  /$$$$$$  /$$   /$$     ||" << endl;
    cout << "                                                             ||  | $$_____/| $$      | $$  | $$| $$_____/| $$$ | $$|__  $$__/       /$$__  $$| $$  | $$| $$_____/ /$$__  $$| $$  /$$/     ||" << endl;
    setColor(2);
    cout << "                                                             ||  | $$      | $$      | $$  | $$| $$      | $$$$| $$   | $$         | $$  \\__/| $$  | $$| $$      | $$  \\__/| $$ /$$/      ||" << endl;
    cout << "                                                             ||  | $$$$$   | $$      | $$  | $$| $$$$$   | $$ $$ $$   | $$         | $$      | $$$$$$$$| $$$$$   | $$      | $$$$$/       ||" << endl;
    cout << "                                                             ||  | $$__/   | $$      | $$  | $$| $$__/   | $$  $$$$   | $$         | $$      | $$__  $$| $$__/   | $$      | $$  $$       ||" << endl;
    cout << "                                                             ||  | $$      | $$      | $$  | $$| $$      | $$\\  $$$   | $$         | $$    $$| $$  | $$| $$      | $$    $$| $$\\  $$      ||" << endl;
    setColor(4);
    cout << "                                                             ||  | $$      | $$$$$$$$|  $$$$$$/| $$$$$$$$| $$ \\  $$   | $$         |  $$$$$$/| $$  | $$| $$$$$$$$|  $$$$$$/| $$ \\  $$     ||" << endl;
    cout << "                                                             ||  |__/      |________/ \\______/ |________/|__/  \\__/   |__/          \\______/ |__/  |__/|________/ \\______/ |__/  \\__/     ||" << endl;
    cout << "                                                             [@]=========================================================================================================================[@]" << endl;
    setColor(15);
    cout << "                                                              -By: UNT | CODING-" << endl;

    cout << endl; //just some blanc spaces 
    cout << endl; 
    cout << endl;

    setColor(15);
    cout << "                                                                                                 [@]=================================================[@]" << endl;
    cout << "                                                                                                 ||           .______________________________.        ||" << endl;
    cout << "                                                                                                 ||               -WELCOME TO fluentCheck-            ||" << endl;
    cout << "                                                                                                 ||           .------------------------------.        ||" << endl;
    setColor(2);
    cout << "                                                                                                 [=====================================================]" << endl;
    cout << "                                                                                                 ||                .___________________.              ||" << endl;
    cout << "                                                                                                 ||                  1. Start a Test                  ||" << endl;
    cout << "                                                                                                 ||                  2. View your scores              ||" << endl;
    cout << "                                                                                                 ||                  3. Quit                          ||" << endl;
    cout << "                                                                                                 ||                 .-----------------.               ||" << endl;
    setColor(4);
    cout << "                                                                                                 [=====================================================]" << endl;
    cout << "                                                                                                 ||          .________________________________.       ||" << endl;
    cout << "                                                                                                 ||            Please enter your choice (1-3)         ||" << endl;
    cout << "                                                                                                 ||          .--------------------------------.       ||" << endl;
    cout << "                                                                                                 [@]=================================================[@]" << endl;

    getline(cin, mainChoiceStr);
    mainChoice = stoi(mainChoiceStr);  //converts string to integer to avoid a bug where the test skips a question
    clearConsole();

    switch (mainChoice) {
    case 1:
        setColor(15);
        cout << "                                                                                              [@]===================================================[@]" << endl;
        cout << "                                                                                              ||         .__________________________________.        ||" << endl;
        cout << "                                                                                              ||                --- Start A Test ---                 ||" << endl;
        cout << "                                                                                              ||         .----------------------------------.        ||" << endl;
        cout << "                                                                                              [=======================================================]" << endl;
        cout << "                                                                                              ||         .__________________________________.        ||" << endl;
        cout << "                                                                                              ||               1. Start Beginner Test:               ||" << endl;
        cout << "                                                                                              ||              (Recommended A1-A2 level)              ||" << endl;
        cout << "                                                                                              ||         -----------------------------------         ||" << endl;
        cout << "                                                                                              ||     Beginner test for users with less experience    ||" << endl;
        cout << "                                                                                              ||       and knowledge of the language. Practices      ||" << endl;
        cout << "                                                                                              ||      spelling, tenses, correct word usage, and      ||" << endl;
        cout << "                                                                                              ||         more. Only multiple-choice questions.       ||" << endl;
        cout << "                                                                                              ||                                                     ||" << endl;
        setColor(2);
        cout << "                                                                                              ||            2. Start Intermediate Test:              ||" << endl;
        cout << "                                                                                              ||             (Recommended B1-B2 level)               ||" << endl;
        cout << "                                                                                              ||         ----------------------------------          ||" << endl;
        cout << "                                                                                              ||     Intermediate test for users with an average     ||" << endl;
        cout << "                                                                                              ||       English level. More questions, harder         ||" << endl;
        cout << "                                                                                              ||       exercises, spelling, tenses, sentence         ||" << endl;
        cout << "                                                                                              ||     forming, articles, and more. Mix of MCQs and    ||" << endl;
        cout << "                                                                                              ||                   open questions.                   ||" << endl;
        cout << "                                                                                              ||                                                     ||" << endl;
        setColor(4);
        cout << "                                                                                              ||               3. Start Advanced Test:               ||" << endl;
        cout << "                                                                                              ||              (Recommended C1-C2 level)              ||" << endl;
        cout << "                                                                                              ||          ----------------------------------         ||" << endl;
        cout << "                                                                                              ||      Advanced test for users with an advanced       ||" << endl;
        cout << "                                                                                              ||       English level. More questions covering        ||" << endl;
        cout << "                                                                                              ||     complex grammar, sentence construction, and     ||" << endl;
        cout << "                                                                                              ||     significant vocabulary. Only open questions.    ||" << endl;
        cout << "                                                                                              ||        .-----------------------------------.        ||" << endl;
        cout << "                                                                                              [=======================================================]" << endl;
        cout << "                                                                                              ||         .__________________________________.        ||" << endl;
        cout << "                                                                                              ||             Please choose an option (1-3)           ||" << endl;
        cout << "                                                                                              ||         .----------------------------------.        ||" << endl;
        cout << "                                                                                              [@]===================================================[@]" << endl;


        getline(cin, testChoiceStr);
        testChoice = stoi(testChoiceStr);

        // Run the selected test   
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
            advancedTest();
        }
        else {
            cout << "Invalid choice." << endl;
        }
        break;

    case 2:
        displayAllScores(); // Call function to display user scores
        break;

    case 3:
        cout << "Exiting program." << endl;
        break;

    default:
        cout << "\nInvalid choice. Please try again.\n" << endl;
        break;
    }
}
