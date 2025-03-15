#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "scores.h"
using namespace std;

bool requiresMultipleChoice(string question) {

    if (question.find("Which is spelled correctly") != string::npos) {
        return true;
    }
    if (question.find("Which sentence is correct") != string::npos) {
        return true;
    }
    if (question.find("Which is correct?") != string::npos) {
        return true;
    }
    // Additional exceptions for multiple choice:
    if (question.find("Choose the correct") != string::npos) {
        return true;
    }
    if (question.find("Identify the correct") != string::npos) {
        return true;
    }
    return false;
}

void intermediateTest() {
    const int NUM_QUESTIONS = 50;
    const int NUM_SELECTED = 25;
    string questions[NUM_QUESTIONS] = {
    "Fill in the blank: I can't believe you ______ the entire book in just two days.",
    "Choose the correct form: He insisted on ______ with the chores.",
    "Complete the sentence: If I had known you were coming, I ______ a bigger meal.",
    "Identify the correct phrase: \"They suggested me to call the office for more details.\"",
    "Fill in the blank: She's looking forward to ______ to Japan next month.",
    "Which is correct? \"Neither of the options ______ appealing.\"",
    "Rewrite in the passive: The manager will review your application next week.",
    "Choose the correct connector: I studied for hours; ______, I still didn't pass the exam.",
    "Fill in the blank: By this time tomorrow, we ______ the project.",
    "Which is correct? \"I'd rather you ______ this to anyone.\"",
    "Fill in the blank: He denied ______ the documents from the office.",
    "Reported speech: Convert \"She said, 'I will help you tomorrow.'\"",
    "Which sentence is correct regarding 'used to'?",
    "Fill in the blank: It's high time we ______ planning the event.",
    "Choose the correct option: I'm really tired; I'd rather ______ at home tonight.",
    "Fill in the blank: She apologized ______ late to the meeting.",
    "Which is correct? \"They suggested ______ to the museum.\"",
    "Fill in the blank: He found it difficult to cope ______ the pressure.",
    "Complete the conditional: If you ______ your work, you won't be able to leave early.",
    "Which is spelled correctly?",
    "Fill in the blank: They have a reputation ______ being very punctual.",
    "Choose the correct form: She prefers ______ novels rather than watching movies.",
    "Which sentence is correct? \"She is looking forward to ______ from you.\"",
    "Complete the sentence: I wish I ______ speak French fluently.",
    "Fill in the blank: Despite ______ all day, we decided to continue our trip.",
    "Which is correct? \"He ______ that we meet at noon.\"",
    "Fill in the blank: Hardly ______ when the concert began.",
    "Choose the correct word: I need to ______ more funds for the charity event.",
    "Complete the sentence: No sooner had he entered the room ______ everyone started clapping.",
    "Which sentence is correct?",
    "Fill in the blank: He objected ______ treated like a child.",
    "Which is correct? \"If she ______ the train, she would have arrived on time.\"",
    "Fill in the blank: They insisted ______ for dinner.",
    "Choose the correct phrase: I'd rather you ______ tonight.",
    "Complete the sentence: By the time you get this letter, I ______ for New York.",
    "Fill in the blank: He made me ______ outside for an hour.",
    "Which is correct? \"It's important that she ______ informed about the changes immediately.\"",
    "Rewrite in reported speech: \"They said, 'We can finish this by Friday.'\"",
    "Fill in the blank: I regret ______ her that secret; I should have kept it to myself.",
    "Choose the correct preposition: She's responsible ______ organizing the event.",
    "Fill in the blank: Had I known about the delay, I ______ home earlier.",
    "Which is correct? \"It's the first time I ______ sushi.\"",
    "Complete the sentence: I was supposed ______ you yesterday, but I forgot.",
    "Fill in the blank: I prefer coffee ______ tea in the mornings.",
    "Which sentence is correct?",
    "Fill in the blank: It's worth ______ the museum while you’re here.",
    "Choose the correct form: She can't help ______ at his jokes.",
    "Complete the sentence: He's not used to ______ on icy roads.",
    "Which is correct? \"They demanded that he ______ immediately.\"",
    "Fill in the blank: In case you ______ any help, give me a call."
    };

    string options[NUM_QUESTIONS] = {
        "a) finished \nb) finishing \nc) have finished", // 1
        "a) help \nb) helping \nc) to help", //2
        "a) would have prepared \nb) will prepare \nc) prepared", // 3
        "a) They suggested me to call \nb) They suggested that I call \nc) They suggested me that I call", // 4
        "a) travel \nb) traveling \nc) travels", // 5
        "a) sound \nb) sounds \nc) is sounding", // 6
        "a) Your application will be reviewed next week by the manager. \nb) Your application next week is reviewed by the manager. \nc) The manager will your application be reviewed next week.", // 7
        "a) therefore \nb) however \nc) in contrast", // 8
        "a) will complete \nb) will have completed \nc) are completing", // 9
        "a) didn't mention \nb) wouldn't mention \nc) don't mention", // 10
        "a) to steal \nb) stealing \nc) stolen", // 11
        "a) She said she will help me tomorrow. \nb) She said she would help me the following day. \nc) She said she will helps you tomorrow.", //12
        "a) I'm used to drive on the left. \nb) I'm used to driving on the left. \nc) I used driving on the left.)", //13
        "a) start \nb) started \nc) had started", // 14
        "a) stay \nb) staying \nc) to stay", // 15
        "a) for being \nb) to be \nc) about be", // 16
        "a) we go \nb) us to go \nc) we went", //17
        "a) with \nb) about \nc) on", //18
        "a) don't finish \nb) won't finish \nc) didn't finish", //19
        "a) receivable \nb) recieveable \nc) recievable", //20
        "a) of \nb) for \nc) about", //21
        "a) reading \nb) read \nc) to reading", //22
        "a) hear \nb) hearing \nc) hear from", //23
        "a) can \nb) could \nc) will", //24
        "a) it rains \nb) raining \nc) rained", //25
        "a) suggested \nb) suggested me \nc) suggested to me", // 26
        "a) we had arrived \nb) had we arrived \nc) arrived we", // 27
        "a) raise \nb) rise \nc) rouse", // 28
        "a) when \nb) than \nc) then", // 29
        "a) I should have went to bed earlier. \nb) I should have gone to bed earlier. \nc) I should have go to bed earlier.", // 30
        "a) to be \nb) to being \nc) being", // 31
        "a) hadn't missed \nb) didn't miss \nc) wouldn't miss", // 32
        "a) on paying \nb) to pay \nc) paying",  // 33
        "a) not come \nb) not to come \nc) not coming", // 34
        "a) will have left \nb) left \nc) will leave", //  35
        "a) wait \nb) to wait \nc) waiting",//  36
        "a) is \nb) be \nc) will be", // 37
        "a) They said they can finish it by Friday. \nb) They said they could finish it by Friday. \nc) They said they will finish it by Friday.", // 38
        "a) telling \nb) to tell \nc) told", // 39
        "a) for \nb) of \nc) about", // 40
        "a) would have left \nb) would leave \nc) had left", // 41
        "a) have eaten \nb) eat \nc) am eating", // 42
        "a) to call \nb) calling \nc) call", // 43
        "a) to \nb) than \nc) over", //. 44
        "a) If only I had more time, I would finish this. \nb) If only I would have more time, I would finish this. \nc) If only I will have more time, I would finish this.", // 45
        "a) visiting \nb) to visit \nc) visit", // 46
        "a) laugh \nb) laughing \nc) to laugh", // 47
        "a) drive \nb) driving \nc) to driving", // 48
        "a) apologize \nb) apologized \nc) would apologize", // 49
        "a) need \nb) will need \nc) needed" // 50
    };

    string answers[NUM_QUESTIONS] = {
        "finished",             // 1
        "helping",              // 2
        "would have prepared",  // 3
        "They suggested that I call",  // 4
        "traveling",            // 5
        "sounds",               // 6
        "Your application will be reviewed next week by the manager.", // 7
        "however",              // 8
        "will have completed",  // 9
        "didn't mention",       // 10
        "stealing",             // 11
        "She said she would help me the following day.", // 12
        "I'm used to driving on the left.", // 13
        "started",              // 14
        "stay",                 // 15
        "for being",            // 16
        "we go",                // 17
        "with",                 // 18
        "don’t finish",         // 19
        "receivable",           // 20
        "for",                  // 21
        "reading",              // 22
        "hearing",              // 23
        "could",                // 24
        "raining",              // 25
        "suggested",            // 26
        "had we arrived",       // 27
        "raise",                // 28
        "than",                 // 29
        "I should have gone to bed earlier.", // 30
        "to being",             // 31
        "hadn't missed",        // 32
        "on paying",            // 33
        "not come",             // 34
        "will have left",       // 35
        "wait",                 // 36
        "be",                   // 37
        "They said they could finish it by Friday.", // 38
        "telling",              // 39
        "for",                  // 40
        "would have left",      // 41
        "have eaten",           // 42
        "to call",              // 43
        "to",                   // 44
        "If only I had more time, I would finish this.", // 45
        "visiting",             // 46
        "laughing",             // 47
        "driving",              // 48
        "apologize",            // 49
        "need"                  // 50
    };
    int indices[NUM_QUESTIONS];
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        indices[i] = i;
    }
    for (int i = NUM_QUESTIONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    srand((unsigned)time(0));
    int score = 0;

    cout << "Welcome to the intermediate English Quiz!\n";
    cout << "You will be given " << NUM_SELECTED << " questions.\n";
    cout << "Type your answer and press Enter to move to the next question.\n\n";

    for (int i = 0; i < NUM_SELECTED; i++) { // currently 3 for debugging purposes, will become NUM_SELECTED for the full test
        int index = indices[i];
        int questionType = rand() % 2 + 1;
        if (requiresMultipleChoice(questions[index])) {
            questionType = 1;
        }

        cout << "\nQuestion " << (i + 1) << ": " << questions[index] << endl;

        string userAnswer;
        if (questionType == 1) {
            cout << options[index] << endl;
            cout << "Your answer (Type the correct word or sentence, do NOT type in a, b, c): ";
            getline(cin, userAnswer);
        }
        else {
            cout << "Please type your answer below: ";
            getline(cin, userAnswer);
        }

        if (userAnswer == answers[index]) {
            score++;
        }
    }

    int grade = getBulgarianGrade(score);

    cout << "Quiz complete! Your final score is " << score << " or " << grade << " out of" << NUM_SELECTED << "." << endl;

    ofstream outFile("IntermediateTestDB.txt", ios::app);
    outFile << score << endl;
    outFile.close();
}
