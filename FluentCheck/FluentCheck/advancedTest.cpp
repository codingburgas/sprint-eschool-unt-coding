#include <iostream>
#include <string>
#include <fstream>
#include "advancedTest.h"
#include "scores.h"
using namespace std;

void advancedTest() {
    const int NUM_QUESTIONS = 50; // Total questions available
    const int NUM_SELECTED = 25; // Half of the question will be chosen randomly for the test

    string advancedExercises[NUM_QUESTIONS] = {
      "Transform the sentence into the passive voice: 'The committee will announce the results tomorrow.'",
      "Rewrite the sentence using a third conditional structure: 'If he had studied, he would have passed the exam.'",
      "Rewrite the sentence in reported speech: 'She said, \"I will finish the project by tomorrow.\"'",
      "Combine the two sentences into one using a relative clause: 'The book was thrilling. It was written by a renowned author.'",
      "Transform the direct question into an indirect question: 'Where did you find that document?'",
      "Correct the parallel structure and rewrite the sentence: 'He enjoys reading, to swim, and biking.'",
      "Rewrite the sentence to eliminate redundancy: 'She made a free gift to him.'",
      "Transform the sentence to include a non-defining relative clause: 'Paris is a beautiful city. It is the capital of France.'",
      "Transform the active sentence into the passive voice: 'The chef prepared the meal with great care.'",
      "Rewrite the sentence to begin with a participial phrase: 'He entered the room, his eyes scanning the crowd.'",
      "Rewrite the sentence to use a third conditional: 'If she had known, she would have acted differently.'",
      "Convert the sentence from direct to indirect speech: 'He said, \"I am tired.\"'",
      "Combine two sentences into a compound-complex sentence: 'She read the book. She enjoyed it.'",
      "Rewrite the sentence to change it from a positive statement to a negative form: 'He has always been punctual.'",
      "Transform the sentence by incorporating an idiomatic expression: 'I was very surprised by the news.'",
      "Rewrite the sentence to express a hypothetical situation using the subjunctive mood: 'If I were you, I would reconsider the offer.'",
      "Rewrite the sentence by replacing the phrase 'in order to' with a more concise form: 'She studies hard in order to succeed.'",
      "Transform the sentence to remove a split infinitive: 'He decided to boldly go where no one had gone before.'",
      "Rewrite the sentence using inversion for emphasis: 'I have never seen such courage.'",
      "Transform the sentence into the past perfect tense: 'She arrives at the party and greets her friends.'",
      "Convert the sentence to a conditional form: 'She studies hard; consequently, she gets good grades.'",
      "Rewrite the sentence to correct tense inconsistency: 'He had finished his work, and then he is going home.'",
      "Transform the sentence by reordering words to avoid ending with a preposition: 'This is the topic I am interested in.'",
      "Rewrite the dialogue as a narrative sentence using indirect speech: '\"I am exhausted,\" he said.'",
      "Transform the sentence by removing redundancy: 'He entered the room and he entered it quickly.'",
      "Convert the direct command into a polite request: 'Close the door.'",
      "Rewrite the sentence to fix subject-verb agreement: 'The team of experts are arriving soon.'",
      "Transform the sentence into a compound sentence using a semicolon: 'I wanted to go but I was too tired.'",
      "Rewrite the exclamatory sentence into an interrogative one: 'What a wonderful performance!'",
      "Transform the statement into a rhetorical question: 'You must understand the consequences of your actions.'",
      "Rewrite the sentence using an appositive phrase: 'My brother is a skilled musician and performed at the concert.'",
      "Convert the sentence to use a gerund phrase: 'To travel is his passion.'",
      "Transform the sentence by replacing a common adjective with a more sophisticated one: 'The big house was impressive.'",
      "Rewrite the sentence to incorporate an advanced transition word: 'She was late and she missed the beginning of the presentation.'",
      "Transform the sentence to change a direct statement into a conditional clause: 'If it rains, we will cancel the picnic.'",
      "Rewrite the sentence using inversion for emphasis: 'I have never witnessed such beauty.'",
      "Transform the sentence by converting direct speech to reported speech: '\"I will come tomorrow,\" she said.'",
      "Rewrite the sentence to express regret in a more formal tone: 'I'm sorry for what I did.'",
      "Convert the question into a statement: 'Can you believe how fast time flies?'",
      "Transform the sentence to include a subordinating conjunction: 'I will call you. I finish work.'",
      "Rewrite the sentence by merging two independent clauses using a comma and a conjunction: 'He is talented, he is humble.'",
      "Transform the sentence by substituting a simple word with a more advanced synonym: 'She was very happy.'",
      "Rewrite the sentence to express surprise using an idiomatic expression: 'I was extremely surprised by the news.'",
      "Convert the direct question to an indirect question: 'What time does the train leave?'",
      "Transform the sentence by rewriting it to eliminate unnecessary words: 'He returned back to the office.'",
      "Rewrite the sentence to correct a dangling modifier: 'Walking down the street, the trees looked beautiful.'",
      "Transform the sentence by changing its voice: 'They built the house in 1920.'",
      "Rewrite the sentence to combine multiple ideas into one: 'He studied all night. He failed the exam.'",
      "Convert the sentence into a future conditional: 'If you study, you will pass the exam.'",
      "Transform the sentence by rephrasing it to use a subordinate clause: 'Because he was tired, he went to bed early.'"
    };

    string advancedAnswers[NUM_QUESTIONS] = {
        "The results will be announced by the committee tomorrow.",
        "Had he studied, he would have passed the exam.",
        "She said that she would finish the project by the next day.",
        "The book, which was written by a renowned author, was thrilling.",
        "Could you tell me where you found that document?",
        "He enjoys reading, swimming, and biking.",
        "She gave him a gift.",
        "Paris, which is the capital of France, is a beautiful city.",
        "The meal was prepared with great care by the chef.",
        "With his eyes scanning the crowd, he entered the room.",
        "Had she known, she would have acted differently.",
        "He said that he was tired.",
        "After reading the book, she enjoyed it.",
        "He has never been punctual.",
        "I was taken aback by the news.",
        "Were I you, I would reconsider the offer.",
        "She studies hard to succeed.",
        "He decided to go boldly where no one had gone before.",
        "Never have I seen such courage.",
        "She had arrived at the party and greeted her friends.",
        "If she studies hard, she gets good grades.",
        "He had finished his work, and then he went home.",
        "This is the topic in which I am interested.",
        "He said that he was exhausted.",
        "He entered the room quickly.",
        "Could you please close the door?",
        "The team of experts is arriving soon.",
        "I wanted to go; however, I was too tired.",
        "Wasn't that a wonderful performance?",
        "Do you not understand the consequences of your actions?",
        "My brother, a skilled musician, performed at the concert.",
        "Traveling is his passion.",
        "The enormous house was impressive.",
        "She was late; consequently, she missed the beginning of the presentation.",
        "Should it rain, we will cancel the picnic.",
        "Never have I witnessed such beauty.",
        "She said that she would come the next day.",
        "I deeply regret my actions.",
        "It is astonishing how fast time flies.",
        "I will call you after I finish work.",
        "He is talented, and he is humble.",
        "She was elated.",
        "I was flabbergasted by the news.",
        "Could you tell me what time the train leaves?",
        "He returned to the office.",
        "While walking down the street, I noticed that the trees looked beautiful.",
        "The house was built in 1920.",
        "Despite studying all night, he failed the exam.",
        "Should you study, you will pass the exam.",
        "He went to bed early because he was tired."
    };

    int indices[NUM_QUESTIONS]; // Array to store randomized question indices
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        indices[i] = i;
    }

    srand(static_cast<unsigned>(time(0))); // Random number generator

    // Shuffle question indices to randomize the test
    for (int i = NUM_QUESTIONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    int score = 0; // Variable to keep track of the user's score
    string userAnswer;

    cout << "Welcome to the Advanced English Quiz!\n";

    cout << "You will be given " << NUM_SELECTED << " questions.\n";
    cout << "Type your answer and press Enter to move to the next question.\n\n";

    // Ask questions
    for (int i = 0; i < NUM_SELECTED; i++) {
        int index = indices[i];
        cout << "Question " << (i + 1) << ": " << advancedExercises[index] << endl;
        cout << "Your answer: ";
        getline(cin, userAnswer);

        // Check if the answer is correct
        if (userAnswer == advancedAnswers[index]) {
            score++; // Increase the score bigger with one point
        }
        cout << endl;
    }

    int grade = getBulgarianGrade(score); // Get the Bulgarian grading equivalent for the final score

    cout << "Quiz complete! Your final score is " << score << " or " << grade << " out of" << NUM_SELECTED << "." << endl;

    // Open file in append mode to store user scores
    ofstream outFile("advancedTestDB.txt", ios::app);
    outFile << score << endl;
    outFile.close();
}
