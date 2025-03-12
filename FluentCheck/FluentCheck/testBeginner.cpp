#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void beginnerTest() {
    const int NUM_QUESTIONS = 50;
    const int NUM_SELECTED = 25;
    string questions[NUM_QUESTIONS] = {
        "Fill in the blank: I ______ a student.",
        "Which word is spelled correctly ? ",
        "Which is correct grammar ? ",
        "Fill in the blank: They ______ a new car.",
        "Which is spelled correctly?",
        "Choose the correct word to complete the sentence: ______ doing a great job.",
        "Fill in the blank: He ______ like pizza.",
        "Which is spelled correctly?",
        "Identify the noun in the sentence: The cat sleeps on the mat.",
        "Fill in the blank: She ______ to school every day.",
        "Which is spelled correctly?",
        "Choose the correct tense for breakfast this morning.",
        "Fill in the blank: They ______ at the park yesterday.",
        "Which is spelled correctly?",
        "Choose the correct pronoun to complete the sentence: Sarah took ______ coat.",
        "Fill in the blank: I ______ very happy today.",
        "Which is spelled correctly?",
        "Choose the correct form for the sentence: He ______ every morning.",
        "Fill in the blank: ______ a sunny day.",
        "Which is spelled correctly?",
        "Choose the correct word to complete the sentence: I want ______ cookies.",
        "Fill in the blank: She ______ know the answer.",
        "Which is spelled correctly?",
        "Choose the correct preposition to complete the sentence: We will meet ______ the library.",
        "Fill in the blank: He ______ finish his homework.",
        "Which is spelled correctly?",
        "Choose the correct usage in the phrase: Between you and ______.",
        "Fill in the blank: We ______ going to the movies tonight.",
        "Which is spelled correctly?",
        "Choose the correct word to complete the sentence: ______ car is red.",
        "Fill in the blank: I ______ a new computer.",
        "Which is spelled correctly?",
        "Choose the correct verb form to complete the sentence: She ______ English fluently.",
        "Fill in the blank: He ______ born in 2005.",
        "Which is spelled correctly?",
        "Choose the correct word to complete the exclamation: I can't believe ______ leaving!",
        "Fill in the blank: She ______ shopping every Saturday.",
        "Which is spelled correctly?",
        "Choose the correct article for the sentence: He is ______ honest man.",
        "Fill in the blank: They ______ want to go to the party.",
        "Which is spelled correctly?",
        "Choose the correct form for the sentence: She ______ two sisters.",
        "Fill in the blank: ______ house is on the corner.",
        "Which is spelled correctly?",
        "Choose the correct verb tense to complete the sentence: I ______ you tomorrow.",
        "Fill in the blank: He ______ play basketball.",
        "Which is spelled correctly?",
        "Choose the correct pronoun for the sentence: ______ are going on vacation.",
        "Fill in the blank: I ______ learning English grammar.",
        "Which is spelled correctly?"
    };
    string options[] = {
        "a) am \nb) are \nc) is", // 1
        "a) definitely \nb) definately \nc) defenitely", // 2
        "a) I saw him yesterday \nb) I seen him yesterday \nc) I sawn him yesterday", /// 3
        "a) has \nb) have \nc) had", // 4
        "a) necessary \nb) neccessary \nc) necissery", // 5
        "a) You're \nb) Your \nc) You'r", // 6
        "a) doesn't \nb) don't \nc) dont", // 7
        "a) tomorrow \nb) tommorow \nc) tommorrow", // 8
        "a) cat \nb) mat \nc) bed", // 9
        "a) go \nb) goes \nc) had goes", // 10
        "a) beginning \nb) begining \nc) begginning", //11
        "a) ate \nb) eat \nc) aten", // 12
        "a) was \nb) were \nc) has", //13
        "a) believe \nb) beleive \nc) beleve", //14 
        "a) her \nb) hers \nc) her's", //15 
        "a) is \nb) am \nc) are", //16 
        "a) friend \nb) freind \nc) frend", //17
        "a) run \nb) runs \nc) running", // 18
        "a) Its \nb) It's \nc) Its'", // 19
        "a) separate \nb) seperate \nc) saperate", // 20
        "a) less \nb) fewer \nc) lower", // 21
        "a) don't \nb) doesn't \nc) doesnt", // 22
        "a) accommodate \nb)accomodate \nc) accommadate", // 23
        "a) at \nb) in \nc) next", // 24
        "a) did \nb) didn't \nc) didnt", // 25
        "a) embarrass \nb) embarass \nc) emberrass", // 26
        "a) me \nb) I \nc) i", // 27
        "a) is \nb) are \nc) am", // 28
        "a) library \nb) libary \nc) liebrary", // 29
        "a) There \nb) Their \nc) They're", // 30
        "a) has \nb) have \nc) had", // 31
        "a) grammar \nb) grammer \nc) gramar", //32
        "a) speak \nb) speaks \nc) speek", // 33
        "a) was \nb) were \nc) we're", // 34
        "a) business \nb) buisness \nc) busyness", // 35
        "a) your \nb) you're \nc) your'e", // 36
        "a) go \nb) goes \nc) gous", //37
        "a) calendar \nb) calender \nc) calander", // 38
        "a) an \nb) a", //39
        "a) did \nb) didn't \nb) didnt", //40
        "a) privilege \nb) priviledge \nc) privelege", //41
        "a) has \nb) have \nc) is", //42
        "a) Their \nb) There \nc) They're", //43
        "a) opportunity \nb) oppertunity \nc) oppurtunity", // 44
        "a) will see \nb) saw \nc) seen", // 45
        "a) don't \nb) doesn't \nc) doesnt", // 46
        "a) guarantee \nb) garantee \nc) gaurantee", //47
        "a) We \nb) Us \nc) I", //48
        "a) am \nb) is \nc) are", // 49
        "a) vacuum \nb) vacume \nc) vacum"
    };
    string answers[] = {
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

    srand((int)time(0));

    for (int i = NUM_QUESTIONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    int score = 0;
    string userInput;

    cout << "Welcome to the English Quiz!\n";
    cout << "You will be given " << NUM_SELECTED << " questions.\n";
    cout << "Type your answer and press Enter to move to the next question.\n\n";

    for (int i = 0; i < NUM_SELECTED; i++) {
        int qIndex = indices[i];
        cout << "Question " << i + 1 << ":" << " " << questions[qIndex] << endl;
        cout << options[qIndex] << endl;
        cout << "Your answer (enter the word and NOT a, b, c): ";
        getline(cin, userInput);

        if (userInput == answers[qIndex]) {
            score++;
        }
        cout << "\n--------------------------\n\n";
    }

    cout << "Quiz complete! Your score: " << score << " out of " << NUM_SELECTED << endl;

    ofstream outFile("BeginnerTestDB.txt", ios::app);

    if (!outFile) {
        cerr << "Error opening BeginnerTestDB.txt for writing.\n";
    }

    outFile << score << endl;

    outFile.close();

}