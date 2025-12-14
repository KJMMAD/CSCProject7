#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const string fileNameStud = "C:\\Users\\cmmsk\\Downloads\\StudentAnswers.txt", fileNameExam = "C:\\Users\\cmmsk\\Downloads\\CorrectAnswers.txt";
const int totalQuestions = 20;

/*
* Func: getAnswers
* Purpose: Opens a file with student answers and verifies it opened successfully, after verification the program puts the data from the file into an array reference
* Parameters: 
* - int size: size of arrays
* - string fileNameStudentAns: name of file for student's test answers
* - char studAnswers[]: reference to the array for the students test answers
* - string fileNameExamAns: name of file for the exam answers
* - char examAnswers[]: reference to the array for the exam answers
* Return:
* - string array: student test answers in an array
* Preconditions:
* - None
* Postconditions:
* - Return an array with the student answers indexed
*/
int getAnswers(int size, string fileNameStudentAns, char studAnswers[], string fileNameExamAns, char examAnswers[]);

/*
* Func: gradeExam
* Purpose: Takes the answer key and student answer array to compare,
* compares the array and determines the number of missed questions and stores the incorrect question number in an array
* then in a parrallel 2D array the correct answer and student answer are stored at the same time
* Parameters:
* - char 
* Return:
* - int: Number of incorrect answers
* - array: Contains question numbers of incorrect answers
* - array: 2D array holding the correct answer and the students answer
* Precondition:
* - None
* Postcondition:
* - Returns an int, and modifies a 1D array and a 2D array
*/
int gradeExam(char studAnswers[], char examAnswers[], int questionNumber[], char questionAnswer[][totalQuestions]);

/*
* Func: writeReport
* Purpose: Writes the report for the students score, displays which questions the student got wrong with their answers and the correct answer,
* then displays their total score and if they passed.
* Parameters:
* - int incorrectTotal: integer of the number of incorrect answers
* - int array questionNumber: array containing the question number for the questions the student got wrong
* - char array questionAns: a 2D array containing the correct exam answer and the students wrong answer
* Return:
* - None
* Preconditions:
* - None
* Postconditions:
* - Writes the report of the students score, displaying the number of incorrect questions, the question number, the students answer with the correct answer,
* and finally the students score and if the student passed.
*/
void writeReport(int, int questionNumber[], char questionAns[][totalQuestions]);

int main()
{
    char studentAns[totalQuestions], examAns[totalQuestions], questionAns[2][totalQuestions];
    int questionNumber[totalQuestions];

    getAnswers(totalQuestions, fileNameStud, studentAns, fileNameExam, examAns);
    int incTotal = gradeExam(studentAns, examAns, questionNumber, questionAns);
    writeReport(incTotal, questionNumber, questionAns);
    return 0;
}

int getAnswers(int size, string fileNameStudentAns, char studAnswers[], string fileNameExamAns, char examAnswers[]) {
    ifstream inFileStudent(fileNameStudentAns);
    if (!inFileStudent) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    ifstream inFileExam(fileNameExamAns);
    if (!inFileExam) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int i = 0, j = 0;
    char answer;

    while (inFileStudent >> answer) {
        studAnswers[i] = answer;
        i++;
    }
    inFileStudent.close();

    while (inFileExam >> answer) {
        examAnswers[j] = answer;
        j++;
    }
    inFileExam.close();
}

int gradeExam(char studAnswers[], char  examAnswers[], int questionNumber[], char questionAns[][totalQuestions]) {
    int incorrectTotal = 0;
    int j = 0;
    for (int i = 0; i < totalQuestions; i++) {
        if (studAnswers[i] != examAnswers[i]) {
            questionNumber[j] = i;
            questionAns[0][j] = examAnswers[i];
            questionAns[1][j] = studAnswers[i];
            incorrectTotal++;
            j++;
        }
    }
    return incorrectTotal;
}

void writeReport(int incorrectTotal, int questionNumber[], char questionAns[][totalQuestions]) {
    double score = (static_cast<double>(totalQuestions) - incorrectTotal) / totalQuestions * 100;
    cout << "Exam report details" << endl;
    cout << "Number of questions missed: " << incorrectTotal << endl;
    cout << "Missed questions and correct answers:" << endl;
    cout << "Question" << "     " << "Correct Answer" << "      " << "Your Answer" << endl;
    for (int i = 0; i < incorrectTotal; i++) {
        cout << setw(4) << questionNumber[i] << setw(16) << questionAns[0][i] << setw(18) << questionAns[1][i] << endl;
    }
    cout << "Test score: " << fixed << setprecision(2)<< score << "%" << endl;
    if (score >= 70) {
        cout << "You passed the exam";
    }
    else {
        cout << "You didn't pass the exam";
    }
}