#include <iostream>
#include <cstdlib>
#include "testBeginner.h"
#include "Options.h"

using namespace std;

void clearConsole() {
	system("cls");
}

// Unfinished main menu (requires lots of polishing)
void MainMenu() {
	int mainChoice = 0;
	int testChoice = 0;
	bool exitProgram = false;

	while (!exitProgram) {
		cout << "====== Main Menu ======" << endl;
		cout << "1. Start Test" << endl;
		cout << "2. View Scores" << endl;
		cout << "3. Exit" << endl;
		cin >> mainChoice;
		switch (mainChoice) {
		case 1:
			cout << "\n --- Start Test ---" << endl;
			cout << "1. Start Beginner Test" << endl;
			cout << "2. Start Intermediate Test" << endl;
			cin >> testChoice;
			if (testChoice == 1) {
				clearConsole();
				beginnerTest();
			}
			else if (testChoice == 2) {
				clearConsole();
				//intermediateTest();
			}
			else {
				cout << "Invalid choice." << endl;
			}
			break;

		case 2:
			cout << "\nScores: " << endl;

			// Code for test scores

			break;

		case 3:
			cout << "Exiting program.";
			exitProgram = true;
			break;
		default:
			cout << "\nInvalid choice. Please try again.\n" << endl;
			break;
		}
	}
}
