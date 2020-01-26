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
 * FUNCTION - calculatePoints
 * ____________________________________________________________________________
 * This function receives a 1-D array for an answer key, and another 1-D array
 * for a student's answers
 * ===> returns the total points earned by the student
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			key     - the array containing correct answers
 * 			answers - the student's answers, True / False / none
 *
 * POST-CONDITIONS
 *		This function will not modify the array arguments
 *		This function will return a number representing the total points earned
 ******************************************************************************/

int calculatePoints(const char key[],     // the answer key array
                    const char answers[]  // the student answer array
                    ) {

    const int CORRECT_POINTS   = 2;     // point value rewarded for correct answer
    const int INCORRECT_POINTS = -1;    // point value rewarded for incorrect answer
    const int NO_ANS_POINTS    = 0;     // point value rewarded for no answer

    int totalPoints;    // total points the student has accumulated

    totalPoints = 0;

    /***********************************************************************
     * For each answer possible in the key, check it against the student's
     * answer and tally points accordingly.
     *
     * If the student has left 1 or more of the last questions unanswered,
     * they will be tallied as no answer points - only possible if the inner
     * if statement fails.
     ************************************************************************/

    for (int i = 0; i < strlen(key); i ++) {
        // check if loop is within student-answered questions
        if (i < strlen(answers)) {

            // correct answer
            if (answers[i] == key[i]) {
                totalPoints += CORRECT_POINTS;
            }

            // no answer
            else if (answers[i] == ' ') {
                totalPoints += NO_ANS_POINTS;
            }

            // incorrect answer
            else {
                totalPoints += INCORRECT_POINTS;
            }
        } // end if (i < strlen(answers))

        // condition where student 'did not finish' or left trailing questions unanswered - tally no answer
        else {
            totalPoints += NO_ANS_POINTS;
        }
    } // end for (int i = 0; i < strlen(key); i ++)

    return totalPoints;
}