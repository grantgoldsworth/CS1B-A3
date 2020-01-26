/******************************************************************************
 * AUTHOR     : GRANT GOLDSWORTH
 * STUDENT ID : 1164709
 * A3         : GRADES
 * CLASS      : CS1B
 * SECTION    : MW  9:30A
 * DUE DATE   : 1/27/2020
 ******************************************************************************/

#include "functions.h"

/******************************************************************************
 * A3 - WEATHER
 *-----------------------------------------------------------------------------
 * This program will read in information from a file containing a True/False
 * test key, student IDs, and their answers. It will output the student answers
 * and their resulting scores.
 *-----------------------------------------------------------------------------
 * INPUT:
 *      Reads input from a file containing information in this format:
 *          <key>
 *          <studentID> <studentAnswers>
 *      Example:
 *          TTFTFTTTFTFTFFTTFTTF
 *          ABC54102 T FTFTFTTTFTTFTTF TF
 *          DEF56278 TTFTFTTTFTFTFFTTFTTF
 *
 * OUTPUT:
 * 		This program will output the student answers alongside the key, and then
 * 		the score for the student based on correct, incorrect, and unanswered
 * 		counts.
 *
 * 		Example:
 * 		    STUDENT ID: ABC54102
 *           KEY  STUDENT
 *           T    T       CORRECT
 *           T            NO ANSWER
 *           F    F       CORRECT
 *           T    T       CORRECT
 *           F    F       CORRECT
 *           T    T       CORRECT
 *           T    F       INCORRECT
 *           T    T       CORRECT
 *           F    T       INCORRECT
 *           T    T       CORRECT
 *           F    F       CORRECT
 *           T    T       CORRECT
 *           F    T       INCORRECT
 *           F    F       CORRECT
 *           T    T       CORRECT
 *           T    T       CORRECT
 *           F    F       CORRECT
 *           T            NO ANSWER
 *           T    T       CORRECT
 *           F    F       CORRECT
 *
 *           =====[ RESULTS ]=====
 *           STUDENT SCORE: 27 (67.50%)
 *           GRADE: D
 ******************************************************************************/

int main () {

    // clear the console screen for readability
    system("cls");

    const int ANS_AR_SIZE = 21;     // the total number of answers possible +1 (extra spot for '\0')
    const int ID_SIZE     = 9;      // the size of a student's ID

    char   answerKey[ANS_AR_SIZE];      // holds the answer key, can be T/F
    char   studentAnswer[ANS_AR_SIZE];  // holds student answers, can be T/F/<none>
    char   studentID[ID_SIZE];          // holds the student's ID
    int    studentScore;                // the resulting raw score for a student
    float  studentPercent;              // the percentage of student points to total possible raw points
    char   studentGrade;                // the letter grade for the student


    ifstream fin;
    fin.open("gradesInput.txt");

    fin.getline(answerKey, ANS_AR_SIZE);

    /***********************************************************************
     * While not at the end of input file, read in the ID, skip over the
     * whitespace between ID and answers, then read in the answers. Both
     * go into character arrays.
     *
     * Calculate the raw score, the percentage correct, and the letter
     * grade for the student.
     *
     * Output the answer key next to the student answer with marks for
     * each answer. Output the score, percent, and grade.
     ************************************************************************/
    while (!fin.eof()) {
        fin.get(studentID, ID_SIZE);

        // skip whitespace between ID and answers
        fin.ignore(3, ' ');

        fin.get(studentAnswer, ANS_AR_SIZE);
        fin.ignore(1000, '\n');

        // calculate score, percentage, and grade
        // (ANS_AR_SIZE - 1) * 2 is the total number of questions, multiplied by point value for each one
        studentScore   = calculatePoints(answerKey, studentAnswer);
        studentPercent = float(studentScore) / ((ANS_AR_SIZE - 1) * 2) * 100;
        studentGrade   = calculateLetterGrade(studentPercent);

        // Output the answer key next to student answers with marks
        cout << "STUDENT ID: " << studentID << endl;
        OutputAnswerResults(answerKey, studentAnswer);

        // Output the score, percent, and grade
        cout << setprecision(2) << fixed;
        cout << "\n=====[ RESULTS ]=====\n";
        cout << "STUDENT SCORE: " << studentScore << " (" << studentPercent << "%)\n";
        cout << "GRADE: " << studentGrade << endl << endl << endl;

    } // end while(!fin.eof)

    fin.close();
    system("pause");

    return 0;
}
