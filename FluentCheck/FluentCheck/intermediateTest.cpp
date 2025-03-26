#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "scores.h"
using namespace std;

// Function to determine if a question requires multiple-choice options 
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
// Function to conduct an intermediate-level English test
void intermediateTest() {
    const int NUM_QUESTIONS = 50;
    const int NUM_SELECTED = 25;
    string questions[NUM_QUESTIONS] = {
        "Fill in the blank: I can't believe you ______ the entire book in just two days.                ||",
        "Choose the correct form: He insisted on ______ with the chores.                                   ||",
        "Complete the sentence: If I had known you were coming, I ______ a bigger meal.                  ||",
        "Identify the correct phrase: \"They suggested me to call the office for more details.\"           ||",
        "Fill in the blank: She's looking forward to ______ to Japan next month.                         ||",
        "Which is correct? \"Neither of the options ______ appealing.\"                                   ||",
        "Rewrite in the passive: The manager will review your application next week.                       ||",
        "Choose the correct connector: I studied for hours, ______, I still didn't pass the exam.       ||",
        "Fill in the blank: By this time tomorrow, we ______ the project.                               ||",
        "Which is correct? \"I'd rather you ______ this to anyone.\"                                      ||",
        "Fill in the blank: He denied ______ the documents from the office.                                ||",
        "Reported speech: Convert \"She said, 'I will help you tomorrow.'\"                                ||",
        "Which sentence is correct regarding 'used to'?                                                 ||",
        "Fill in the blank: It's high time we ______ planning the event.                                ||",
        "Choose the correct option: I'm really tired, I'd rather ______ at home tonight.                ||",
        "Fill in the blank: She apologized ______ late to the meeting.                                  ||",
        "Which is correct? \"They suggested ______ to the museum.\"                                        ||",
        "Fill in the blank: He found it difficult to cope ______ the pressure.                             ||",
        "Complete the conditional : If you ______ your work, you won't be able to leave early.             ||",
        "Which is spelled correctly?                                                                       ||",
        "Fill in the blank: They have a reputation ______ being very punctual.                           ||",
        "Choose the correct form: She prefers ______ novels rather than watching movies.                   ||",
        "Which sentence is correct ? \"She is looking forward to ______ from you.\"                        ||",
        "Complete the sentence: I wish I ______ speak French fluently.                                   ||",
        "Fill in the blank: Despite ______ all day, we decided to continue our trip.                    ||",
        "Which is correct? \"He ______ that we meet at noon.\"                                             ||",
        "Fill in the blank: Hardly ______ when the concert began.                                          ||",
        "Choose the correct word : I need to ______ more funds for the charity event.                      ||",
        "Complete the sentence: No sooner had he entered the room ______ everyone started clapping.        ||",
        "Which sentence is correct?                                                                     ||",
        "Fill in the blank : He objected ______ treated like a child.                                   ||",
        "Which is correct? \"If she ______ the train, she would have arrived on time.\"                    ||",
        "Fill in the blank: They insisted ______ for dinner.                                               ||",
        "Choose the correct phrase: I'd rather you ______ tonight.                                         ||",
        "Complete the sentence: By the time you get this letter, I ______ for New York.                  ||",
        "Fill in the blank: He made me ______ outside for an hour.                                      ||",
        "Which is correct? \"It's important that she ______ informed about the changes immediately.\"      ||",
        "Rewrite in reported speech: \"They said, 'We can finish this by Friday.'\"                        ||",
        "Fill in the blank: I regret ______ her that secret, I should have kept it to myself.              ||",
        "Choose the correct preposition: She's responsible ______ organizing the event.                    ||",
        "Fill in the blank: Had I known about the delay, I ______ home earlier.                            ||",
        "Which is correct? \"It's the first time I ______ sushi.\"                                         ||",
        "Complete the sentence: I was supposed ______ you yesterday, but I forgot.                      ||",
        "Fill in the blank: I prefer coffee ______ tea in the mornings.                                    ||",
        "Which sentence is correct?                                                                     ||",
        "Fill in the blank: It's worth ______ the museum while you're here.                             ||",
        "Choose the correct form: She can't help ______ at his jokes.                                      ||",
        "Complete the sentence: He's not used to ______ on icy roads.                                      ||",
        "Which is correct? \"They demanded that he ______ immediately.\"                                   ||",
        "Fill in the blank: In case you ______ any help, give me a call.                                ||"
    };

    string options[NUM_QUESTIONS] = {
        "                                                                    ||a) finished                                                                                                 ||\n                                                                    ||b) finishing                                                                                                ||\n                                                                    ||c) have finished                                                                                            ||",
        "                                                                    ||a) help                                                                                                     ||\n                                                                    ||b) helping                                                                                                  ||\n                                                                    ||c) to help                                                                                                  ||",
        "                                                                    ||a) would have prepared                                                                                      ||\n                                                                    ||b) will prepare                                                                                             ||\n                                                                    ||c) prepared                                                                                                 ||",
        "                                                                    ||a) They suggested me to call                                                                                ||\n                                                                    ||b) They suggested that I call                                                                               ||\n                                                                    ||c) They suggested me that I call                                                                            ||",
        "                                                                    ||a) travel                                                                                                   ||\n                                                                    ||b) traveling                                                                                                ||\n                                                                    ||c) travels                                                                                                  ||",
        "                                                                    ||a) sound                                                                                                    ||\n                                                                    ||b) sounds                                                                                                   ||\n                                                                    ||c) is sounding                                                                                              ||",
        "                                                                    ||a) Your application will be reviewed next week by the manager.                                              ||\n                                                                    ||b) Your application next week is reviewed by the manager.                                                   ||\n                                                                    ||c) The manager will your application be reviewed next week.                                                 ||",
        "                                                                    ||a) therefore                                                                                                ||\n                                                                    ||b) however                                                                                                  ||\n                                                                    ||c) in contrast                                                                                              ||",
        "                                                                    ||a) will complete                                                                                            ||\n                                                                    ||b) will have completed                                                                                      ||\n                                                                    ||c) are completing                                                                                           ||",
        "                                                                    ||a) didn't mention                                                                                           ||\n                                                                    ||b) wouldn't mention                                                                                         ||\n                                                                    ||c) don't mention                                                                                            ||",
        "                                                                    ||a) to steal                                                                                                 ||\n                                                                    ||b) stealing                                                                                                 ||\n                                                                    ||c) stolen                                                                                                   ||",
        "                                                                    ||a) She said she will help me tomorrow.                                                                      ||\n                                                                    ||b) She said she would help me the following day.                                                            ||\n                                                                    ||c) She said she will helps you tomorrow.                                                                    ||",
        "                                                                    ||a) I'm used to drive on the left.                                                                           ||\n                                                                    ||b) I'm used to driving on the left.                                                                         ||\n                                                                    ||c) I used driving on the left.                                                                              ||",
        "                                                                    ||a) start                                                                                                    ||\n                                                                    ||b) started                                                                                                  ||\n                                                                    ||c) had started                                                                                              ||",
        "                                                                    ||a) stay                                                                                                     ||\n                                                                    ||b) staying                                                                                                  ||\n                                                                    ||c) to stay                                                                                                  ||",
        "                                                                    ||a) for being                                                                                                ||\n                                                                    ||b) to be                                                                                                    ||\n                                                                    ||c) about be                                                                                                 ||",
        "                                                                    ||a) we go                                                                                                    ||\n                                                                    ||b) us to go                                                                                                 ||\n                                                                    ||c) we went                                                                                                  ||",
        "                                                                    ||a) with                                                                                                     ||\n                                                                    ||b) about                                                                                                    ||\n                                                                    ||c) on                                                                                                       ||",
        "                                                                    ||a) don't finish                                                                                             ||\n                                                                    ||b) won't finish                                                                                             ||\n                                                                    ||c) didn't finish                                                                                            ||",
        "                                                                    ||a) receivable                                                                                               ||\n                                                                    ||b) recieveable                                                                                              ||\n                                                                    ||c) recievable                                                                                               ||",
        "                                                                    ||a) of                                                                                                       ||\n                                                                    ||b) for                                                                                                      ||\n                                                                    ||c) about                                                                                                    ||",
        "                                                                    ||a) reading                                                                                                  ||\n                                                                    ||b) read                                                                                                     ||\n                                                                    ||c) to reading                                                                                               ||",
        "                                                                    ||a) hear                                                                                                     ||\n                                                                    ||b) hearing                                                                                                  ||\n                                                                    ||c) hear from                                                                                                ||",
        "                                                                    ||a) can                                                                                                      ||\n                                                                    ||b) could                                                                                                    ||\n                                                                    ||c) will                                                                                                     ||",
        "                                                                    ||a) it rains                                                                                                 ||\n                                                                    ||b) raining                                                                                                  ||\n                                                                    ||c) rained                                                                                                   ||",
        "                                                                    ||a) suggested                                                                                                ||\n                                                                    ||b) suggested me                                                                                             ||\n                                                                    ||c) suggested to me                                                                                          ||",
        "                                                                    ||a) we had arrived                                                                                           ||\n                                                                    ||b) had we arrived                                                                                           ||\n                                                                    ||c) arrived we                                                                                               ||",
        "                                                                    ||a) raise                                                                                                    ||\n                                                                    ||b) rise                                                                                                     ||\n                                                                    ||c) rouse                                                                                                    ||",
        "                                                                    ||a) when                                                                                                     ||\n                                                                    ||b) than                                                                                                     ||\n                                                                    ||c) then                                                                                                     ||",
        "                                                                    ||a) I should have went to bed earlier.                                                                       ||\n                                                                    ||b) I should have gone to bed earlier.                                                                       ||\n                                                                    ||c) I should have go to bed earlier.                                                                         ||",
        "                                                                    ||a) to be                                                                                                    ||\n                                                                    ||b) to being                                                                                                 ||\n                                                                    ||c) being                                                                                                    ||",
        "                                                                    ||a) hadn't missed                                                                                            ||\n                                                                    ||b) didn't miss                                                                                              ||\n                                                                    ||c) wouldn't miss                                                                                            ||",
        "                                                                    ||a) on paying                                                                                                ||\n                                                                    ||b) to pay                                                                                                   ||\n                                                                    ||c) paying                                                                                                   ||",
        "                                                                    ||a) not come                                                                                                 ||\n                                                                    ||b) not to come                                                                                              ||\n                                                                    ||c) not coming                                                                                               ||",
        "                                                                    ||a) will have left                                                                                           ||\n                                                                    ||b) left                                                                                                     ||\n                                                                    ||c) will leave                                                                                               ||",
        "                                                                    ||a) wait                                                                                                     ||\n                                                                    ||b) to wait                                                                                                  ||\n                                                                    ||c) waiting                                                                                                  ||",
        "                                                                    ||a) is                                                                                                       ||\n                                                                    ||b) be                                                                                                       ||\n                                                                    ||c) will be                                                                                                  ||",
        "                                                                    ||a) They said they can finish it by Friday.                                                                  ||\n                                                                    ||b) They said they could finish it by Friday.                                                                ||\n                                                                    ||c) They said they will finish it by Friday.                                                                 ||",
        "                                                                    ||a) telling                                                                                                  ||\n                                                                    ||b) to tell                                                                                                  ||\n                                                                    ||c) told                                                                                                     ||",
        "                                                                    ||a) for                                                                                                      ||\n                                                                    ||b) of                                                                                                       ||\n                                                                    ||c) about                                                                                                    ||",
        "                                                                    ||a) would have left                                                                                          ||\n                                                                    ||b) would leave                                                                                              ||\n                                                                    ||c) had left                                                                                                 ||",
        "                                                                    ||a) have eaten                                                                                               ||\n                                                                    ||b) eat                                                                                                      ||\n                                                                    ||c) am eating                                                                                                ||",
        "                                                                    ||a) to call                                                                                                  ||\n                                                                    ||b) calling                                                                                                  ||\n                                                                    ||c) call                                                                                                     ||",
        "                                                                    ||a) to                                                                                                       ||\n                                                                    ||b) than                                                                                                     ||\n                                                                    ||c) over                                                                                                     ||",
        "                                                                    ||a) If only I had more time, I would finish this.                                                            ||\n                                                                    ||b) If only I would have more time, I would finish this.                                                     ||\n                                                                    ||c) If only I will have more time, I would finish this.                                                      ||",
        "                                                                    ||a) visiting                                                                                                 ||\n                                                                    ||b) to visit                                                                                                 ||\n                                                                    ||c) visit                                                                                                    ||",
        "                                                                    ||a) laugh                                                                                                    ||\n                                                                    ||b) laughing                                                                                                 ||\n                                                                    ||c) to laugh                                                                                                 ||",
        "                                                                    ||a) drive                                                                                                    ||\n                                                                    ||b) driving                                                                                                  ||\n                                                                    ||c) to driving                                                                                               ||",
        "                                                                    ||a) apologize                                                                                                ||\n                                                                    ||b) apologized                                                                                               ||\n                                                                    ||c) would apologize                                                                                          ||",
        "                                                                    ||a) need                                                                                                     ||\n                                                                    ||b) will need                                                                                                ||\n                                                                    ||c) needed                                                                                                   ||"
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
    int indices[NUM_QUESTIONS]; // Array to store randomized question indices
    // Initialize indices array
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        indices[i] = i;
    }
    // Shuffle question indices to randomize the test
    for (int i = NUM_QUESTIONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    srand(int(time(0)));
    int score = 0;

    cout << "                                                                                      [@]======================================================================[@]\n";
    cout << "                                                                                      ||               .___________________________________________.            ||\n";
    cout << "                                                                                      ||                 Welcome to the Intermediate English Quiz!              ||\n";
    cout << "                                                                                      ||               .------------------------------------------.             ||\n";
    cout << "                                                                                      [==========================================================================]\n";
    cout << "                                                                                      ||               .___________________________________________.            ||\n";
    cout << "                                                                                      ||                       You will be given " << NUM_SELECTED << " questions.                  ||\n";
    cout << "                                                                                      ||       Type your answer and press Enter to move to the next question.   ||\n";
    cout << "                                                                                      ||               .------------------------------------------.             ||\n";
    cout << "                                                                                      [@]======================================================================[@]\n";

    cout << endl; //just some spacing between the Q&A and the welcoming sign
    cout << endl;

    for (int i = 0; i < NUM_SELECTED; i++) { // Loop through selected questions
        int index = indices[i];
        int questionType = rand() % 2 + 1;
        if (requiresMultipleChoice(questions[index])) {
            questionType = 1;
        }

        cout << "                                                                    ||Question " << (i + 1) << ": " << questions[index] << endl;

        string userAnswer;
        if (questionType == 1) {
            cout << options[index] << endl;
            cout << "                                                                    ||Your answer (Type the correct word or sentence, do NOT type in a, b, c): ";
            getline(cin, userAnswer);
        }
        else {
            cout << "                                                                    ||Please type your answer below: ";
            getline(cin, userAnswer);
        }
        // Check if the user's answer is correct
        if (userAnswer == answers[index]) {
            score++; // Increase the score bigger with one point
        }
        cout << endl;
    }
     
    int grade = getBulgarianGrade(score); // Get the Bulgarian grading equivalent for the final score

    string formattedScore = (score < 10) ? " " + to_string(score) : to_string(score);
    string formattedGrade = (grade < 10) ? " " + to_string(grade) : to_string(grade);

    cout << endl; //just some spacing between the Q&A and the score sign
    cout << endl;

    cout << "                                                                                      [@]======================================================================[@]\n";
    cout << "                                                                                      ||               .___________________________________________.            ||\n";
    cout << "                                                                                      ||            Quiz complete! Your final score is " << formattedScore << " out of " << NUM_SELECTED << " or " << formattedGrade << "." << "      ||\n";
    cout << "                                                                                      ||               .------------------------------------------.             ||\n";
    cout << "                                                                                      [@]======================================================================[@]\n";



    // Open file in append mode to store user scores
    ofstream outFile("IntermediateTestDB.txt", ios::app);
    outFile << score << endl;
    outFile.close();
}
