#include <iostream>
#include <fstream>
using namespace std;

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
* - string array cAnsw: array containing the correct answers for the test
* - string array sAnsw: array containing the students answers for the test
* Return:
* - int: Number of incorrect answers
* - array: Contains question numbers of incorrect answers
* - array: Contains students incorrect answers
* - array: Contains corresponding correct answer for students incorrect answer
* Precondition:
* - None
* Postcondition:
* - Returns an int, and three arrays
*/
int gradeExam(string, string);

/*
* Func: writeReport
* Purpose: Writes the report for the students score, displays which questions the student got wrong with their answers and the correct answer,
* then displays their total score and if they passed.
* Parameters:
* - int incAnswers: integer of the number of incorrect answers
* - string array questionNum: array containing the question number for the questions the student got wrong
* - string array studentAnsw: array containing the students incorrect answers
* - string array correctAns: array containing the correct test answer for the questions the student got wrong
* Return:
* - None
* Preconditions:
* - None
* Postconditions:
* - Writes the report of the students score, displaying the number of incorrect questions, the question number, the students answer with the correct answer,
* and finally the students score and if they passed.
*/
void writeReport(int, string, string, string);

const string fileNameStud = "C:\\Users\\cmmsk\\Downloads\\StudentAnswers.txt", fileNameExam = "C:\\Users\\cmmsk\\Downloads\\CorrectAnswers.txt";
const int totalQuestions = 20;

int main()
{
    char studentAns[totalQuestions], examAns[totalQuestions];
    getAnswers(totalQuestions, fileNameStud, studentAns, fileNameExam, examAns);
    for (int i = 0; i < totalQuestions; i++) {
        cout << studentAns[i] << " " << examAns[i] << endl;
    }
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
