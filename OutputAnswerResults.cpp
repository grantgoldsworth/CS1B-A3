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
 * FUNCTION - OutputAnswerResults
 * ____________________________________________________________________________
 * This function receives a 1-D array for an answer key, and another 1-D array
 * for a student's answers
 * ===> returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			key     - the array containing correct answers
 * 			answers - the student's answers, True / False / none
 *
 * POST-CONDITIONS
 *		This function will not modify the array arguments
 *		This function will output the answer key, next to student's answers,
 *          with marks
 ******************************************************************************/
void OutputAnswerResults(const char key[],    // the answer key array
                         const char student[] // the student answer array
                         ) {

    cout << left;
    cout << setw(5) << "KEY" << "STUDENT" << endl;

    for (int i = 0; i < strlen(key); i ++) {
        if (i < strlen(student)) {

            cout << setw(5) << key[i] << setw(8) << student[i];

            if (student[i] == key[i]) {
                cout << "CORRECT\n";
            }
            else if (student[i] == ' ') {
                cout << "NO ANSWER\n";
            }
            else {
                cout << "INCORRECT\n";
            }
        } // end if (i < strlen(student))
        else {

            cout << setw(5) << key[i] << setw(8) << " " << "NO ANSWER\n";
        }

    }
    cout << right;

    return;
}