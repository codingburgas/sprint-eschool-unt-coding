#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "scores.h"
    using namespace std;

    void beginnerTest() {
        const int NUM_QUESTIONS = 50;
        const int NUM_SELECTED = 25;

        string questions[NUM_QUESTIONS] = {
            "Fill in the blank: I ______ a student.                                                        ||",
            "Which word is spelled correctly ?                                                             ||",
            "Which is correct grammar ?                                                                    ||",
            "Fill in the blank: They ______ a new car.                                                     ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct word to complete the sentence: ______ doing a great job.                   ||",
            "Fill in the blank: He ______ like pizza.                                                      ||",
            "Which is spelled correctly?                                                                   ||",
            "Identify the noun in the sentence: The cat sleeps on the mat.                                 ||",
            "Fill in the blank: She ______ to school every day.                                            ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct tense for breakfast this morning.                                          ||",
            "Fill in the blank: They ______ at the park yesterday.                                         ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct pronoun to complete the sentence: Sarah took ______ coat.                  ||",
            "Fill in the blank: I ______ very happy today.                                                 ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct form for the sentence: He ______ every morning.                            ||",
            "Fill in the blank: ______ a sunny day.                                                        ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct word to complete the sentence: I want ______ cookies.                      ||",
            "Fill in the blank: She ______ know the answer.                                                ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct preposition to complete the sentence: We will meet ______ the library.     ||",
            "Fill in the blank: He ______ finish his homework.                                             ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct usage in the phrase: Between you and ______.                               ||",
            "Fill in the blank: We ______ going to the movies tonight.                                     ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct word to complete the sentence: ______ car is red.                          ||",
            "Fill in the blank: I ______ a new computer.                                                   ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct verb form to complete the sentence: She ______ English fluently.           ||",
            "Fill in the blank: He ______ born in 2005.                                                    ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct word to complete the exclamation: I can't believe ______ leaving!          ||",
            "Fill in the blank: She ______ shopping every Saturday.                                        ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct article for the sentence: He is ______ honest man.                         ||",
            "Fill in the blank: They ______ want to go to the party.                                       ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct form for the sentence: She ______ two sisters.                             ||",
            "Fill in the blank: ______ house is on the corner.                                             ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct verb tense to complete the sentence: I ______ you tomorrow.                ||",
            "Fill in the blank: He ______ play basketball.                                                 ||",
            "Which is spelled correctly?                                                                   ||",
            "Choose the correct pronoun for the sentence: ______ are going on vacation.                    ||",
            "Fill in the blank: I ______ learning English grammar.                                         ||",
            "Which is spelled correctly?                                                                   ||"
        };

        string options[NUM_QUESTIONS] = {
            "                                                                    ||a) am                                                                                                     ||\n                                                                    ||b) are                                                                                                    ||\n                                                                    ||c) is                                                                                                     ||",
            "                                                                    ||a) definitely                                                                                             ||\n                                                                    ||b) definately                                                                                             ||\n                                                                    ||c) defenitely                                                                                             ||",
            "                                                                    ||a) I saw him yesterday                                                                                    ||\n                                                                    ||b) I seen him yesterday                                                                                   ||\n                                                                    ||c) I sawn him yesterday                                                                                   ||",
            "                                                                    ||a) has                                                                                                    ||\n                                                                    ||b) have                                                                                                   ||\n                                                                    ||c) had                                                                                                    ||",
            "                                                                    ||a) necessary                                                                                              ||\n                                                                    ||b) neccessary                                                                                             ||\n                                                                    ||c) necissery                                                                                              ||",
            "                                                                    ||a) You're                                                                                                 ||\n                                                                    ||b) Your                                                                                                   ||\n                                                                    ||c) You'r                                                                                                  ||",
            "                                                                    ||a) doesn't                                                                                                ||\n                                                                    ||b) don't                                                                                                  ||\n                                                                    ||c) dont                                                                                                   ||",
            "                                                                    ||a) tomorrow                                                                                               ||\n                                                                    ||b) tommorow                                                                                               ||\n                                                                    ||c) tommorrow                                                                                              ||",
            "                                                                    ||a) cat                                                                                                    ||\n                                                                    ||b) mat                                                                                                    ||\n                                                                    ||c) bed                                                                                                    ||",
            "                                                                    ||a) go                                                                                                     ||\n                                                                    ||b) goes                                                                                                   ||\n                                                                    ||c) had goes                                                                                               ||",
            "                                                                    ||a) beginning                                                                                              ||\n                                                                    ||b) begining                                                                                               ||\n                                                                    ||c) begginning                                                                                             ||",
            "                                                                    ||a) ate                                                                                                    ||\n                                                                    ||b) eat                                                                                                    ||\n                                                                    ||c) aten                                                                                                   ||",
            "                                                                    ||a) was                                                                                                    ||\n                                                                    ||b) were                                                                                                   ||\n                                                                    ||c) has                                                                                                    ||",
            "                                                                    ||a) believe                                                                                                ||\n                                                                    ||b) beleive                                                                                                ||\n                                                                    ||c) beleve                                                                                                 ||",
            "                                                                    ||a) her                                                                                                    ||\n                                                                    ||b) hers                                                                                                   ||\n                                                                    ||c) her's                                                                                                  ||",
            "                                                                    ||a) is                                                                                                     ||\n                                                                    ||b) am                                                                                                     ||\n                                                                    ||c) are                                                                                                    ||",
            "                                                                    ||a) friend                                                                                                 ||\n                                                                    ||b) freind                                                                                                 ||\n                                                                    ||c) frend                                                                                                  ||",
            "                                                                    ||a) run                                                                                                    ||\n                                                                    ||b) runs                                                                                                   ||\n                                                                    ||c) running                                                                                                ||",
            "                                                                    ||a) Its                                                                                                    ||\n                                                                    ||b) It's                                                                                                   ||\n                                                                    ||c) Its'                                                                                                   ||",
            "                                                                    ||a) separate                                                                                               ||\n                                                                    ||b) seperate                                                                                               ||\n                                                                    ||c) saperate                                                                                               ||",
            "                                                                    ||a) less                                                                                                   ||\n                                                                    ||b) fewer                                                                                                  ||\n                                                                    ||c) lower                                                                                                  ||",
            "                                                                    ||a) don't                                                                                                  ||\n                                                                    ||b) doesn't                                                                                                ||\n                                                                    ||c) doesnt                                                                                                 ||",
            "                                                                    ||a) accommodate                                                                                            ||\n                                                                    ||b) accomodate                                                                                             ||\n                                                                    ||c) accommadate                                                                                            ||",
            "                                                                    ||a) at                                                                                                     ||\n                                                                    ||b) in                                                                                                     ||\n                                                                    ||c) next                                                                                                   ||",
            "                                                                    ||a) did                                                                                                    ||\n                                                                    ||b) didn't                                                                                                 ||\n                                                                    ||c) didnt                                                                                                  ||",
            "                                                                    ||a) embarrass                                                                                              ||\n                                                                    ||b) embarass                                                                                               ||\n                                                                    ||c) emberrass                                                                                              ||",
            "                                                                    ||a) me                                                                                                     ||\n                                                                    ||b) I                                                                                                      ||\n                                                                    ||c) i                                                                                                      ||",
            "                                                                    ||a) is                                                                                                     ||\n                                                                    ||b) are                                                                                                    ||\n                                                                    ||c) am                                                                                                     ||",
            "                                                                    ||a) library                                                                                                ||\n                                                                    ||b) libary                                                                                                 ||\n                                                                    ||c) liebrary                                                                                               ||",
            "                                                                    ||a) There                                                                                                  ||\n                                                                    ||b) Their                                                                                                  ||\n                                                                    ||c) They're                                                                                                ||",
            "                                                                    ||a) has                                                                                                    ||\n                                                                    ||b) have                                                                                                   ||\n                                                                    ||c) had                                                                                                    ||",
            "                                                                    ||a) grammar                                                                                                ||\n                                                                    ||b) grammer                                                                                                ||\n                                                                    ||c) gramar                                                                                                 ||",
            "                                                                    ||a) speak                                                                                                  ||\n                                                                    ||b) speaks                                                                                                 ||\n                                                                    ||c) speek                                                                                                  ||",
            "                                                                    ||a) was                                                                                                    ||\n                                                                    ||b) were                                                                                                   ||\n                                                                    ||c) we're                                                                                                  ||",
            "                                                                    ||a) business                                                                                               ||\n                                                                    ||b) buisness                                                                                               ||\n                                                                    ||c) busyness                                                                                               ||",
            "                                                                    ||a) your                                                                                                   ||\n                                                                    ||b) you're                                                                                                 ||\n                                                                    ||c) your'e                                                                                                 ||",
            "                                                                    ||a) go                                                                                                     ||\n                                                                    ||b) goes                                                                                                   ||\n                                                                    ||c) gous                                                                                                   ||",
            "                                                                    ||a) calendar                                                                                               ||\n                                                                    ||b) calender                                                                                               ||\n                                                                    ||c) calander                                                                                               ||",
            "                                                                    ||a) an                                                                                                     ||\n                                                                    ||b) a                                                                                                      ||\n                                                                    ||c) um                                                                                                     ||",
            "                                                                    ||a) did                                                                                                    ||\n                                                                    ||b) didn't                                                                                                 ||\n                                                                    ||c) didnt                                                                                                  ||",
            "                                                                    ||a) privilege                                                                                              ||\n                                                                    ||b) priviledge                                                                                             ||\n                                                                    ||c) privelege                                                                                              ||",
            "                                                                    ||a) has                                                                                                    ||\n                                                                    ||b) have                                                                                                   ||\n                                                                    ||c) is                                                                                                     ||",
            "                                                                    ||a) Their                                                                                                  ||\n                                                                    ||b) There                                                                                                  ||\n                                                                    ||c) They're                                                                                                ||",
            "                                                                    ||a) opportunity                                                                                            ||\n                                                                    ||b) oppertunity                                                                                            ||\n                                                                    ||c) oppurtunity                                                                                            ||",
            "                                                                    ||a) will see                                                                                               ||\n                                                                    ||b) saw                                                                                                    ||\n                                                                    ||c) seen                                                                                                   ||",
            "                                                                    ||a) don't                                                                                                  ||\n                                                                    ||b) doesn't                                                                                                ||\n                                                                    ||c) doesnt                                                                                                 ||",
            "                                                                    ||a) guarantee                                                                                              ||\n                                                                    ||b) garantee                                                                                               ||\n                                                                    ||c) gaurantee                                                                                              ||",
            "                                                                    ||a) We                                                                                                     ||\n                                                                    ||b) Us                                                                                                     ||\n                                                                    ||c) I                                                                                                      ||",
            "                                                                    ||a) am                                                                                                     ||\n                                                                    ||b) is                                                                                                     ||\n                                                                    ||c) are                                                                                                    ||",
            "                                                                    ||a) vacuum                                                                                                 ||\n                                                                    ||b) vacume                                                                                                 ||\n                                                                    ||c) vacum                                                                                                  ||"
        };

        string answers[NUM_QUESTIONS] = {
            "am",
            "definitely",
            "I saw him yesterday",
            "have",
            "necessary",
            "You're",
            "doesn't",
            "tomorrow",
            "cat",
            "goes",
            "beginning",
            "ate",
            "were",
            "believe",
            "her",
            "am",
            "friend",
            "runs",
            "It's",
            "separate",
            "fewer",
            "doesn't",
            "accommodate",
            "at",
            "didn't",
            "embarrass",
            "me",
            "are",
            "library",
            "Their",
            "have",
            "grammar",
            "speaks",
            "was",
            "business",
            "you're",
            "goes",
            "calendar",
            "an",
            "didn't",
            "privilege",
            "has",
            "Their",
            "opportunity",
            "will see",
            "doesn't",
            "guarantee",
            "We",
            "am",
            "vacuum"
        };

        int indices[NUM_QUESTIONS];
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            indices[i] = i;
        }

        srand(int(time(0)));
        for (int i = NUM_QUESTIONS - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(indices[i], indices[j]);
        }

        int score = 0;
        string userInput;

        // Welcome screen
        cout << "                                                                                      [@]======================================================================[@]\n";
        cout << "                                                                                      ||               .___________________________________________.            ||\n";
        cout << "                                                                                      ||                   Welcome to the Beginner English Quiz!                ||\n";
        cout << "                                                                                      ||               .------------------------------------------.             ||\n";
        cout << "                                                                                      [==========================================================================]\n";
        cout << "                                                                                      ||               .___________________________________________.            ||\n";
        cout << "                                                                                      ||                       You will be given " << NUM_SELECTED << " questions.                  ||\n";
        cout << "                                                                                      ||       Type your answer and press Enter to move to the next question.   ||\n";
        cout << "                                                                                      ||               .------------------------------------------.             ||\n";
        cout << "                                                                                      [@]======================================================================[@]\n\n";

        // Display questions
        for (int i = 0; i < NUM_SELECTED; i++) {
            int qIndex = indices[i];

            // Display question with original formatting
            cout << "                                                                    ||Question ";
            if (i < 9) cout << " "; // Extra space for single-digit numbers
            cout << (i + 1) << ":";
            cout << questions[qIndex] << "\n";

            // Display options exactly as formatted
            cout << options[qIndex] << "\n";

            // Get answer
            cout << "                                                                    ||Your answer (enter the word and NOT a, b, c): ";
            getline(cin, userInput);

            // Check answer
            if (userInput == answers[qIndex]) {
                score++;
            }
            cout << endl;;

        }

        // Display results
        int grade = getBulgarianGrade(score);
        string formattedScore = (score < 10) ? " " + to_string(score) : to_string(score);
        string formattedGrade = (grade < 10) ? " " + to_string(grade) : to_string(grade);

        cout << "                                                                                      [@]======================================================================[@]\n";
        cout << "                                                                                      ||               .___________________________________________.            ||\n";
        cout << "                                                                                      ||            Quiz complete! Your final score is " << formattedScore << " out of " << NUM_SELECTED << " or " << formattedGrade << "." << "      ||\n";
        cout << "                                                                                      ||               .------------------------------------------.             ||\n";
        cout << "                                                                                      [@]======================================================================[@]\n";

        // Save score
        ofstream outFile("BeginnerTestDB.txt", ios::app);
        if (outFile.is_open()) {
            outFile << score << endl;
            outFile.close();
        }
    }