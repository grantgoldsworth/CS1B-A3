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
 * FUNCTION - calculateLetterGrade
 * ____________________________________________________________________________
 * This function receives a float representing the student's percentage score,
 * in the format ##.## percent
 * ===> returns grade
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			percent - the percentage score earned by the student
 *
 * POST-CONDITIONS
 *		This function will not modify the percentage argument
 *		This function will return a character representing student's Grade
 ******************************************************************************/

char calculateLetterGrade(float percent // the percentage score for the student, format ##.##
                         ) {

    char letterGrade;   // the letter grade for the student based on percentage earned

    if (percent <= 59.99) {
        letterGrade = 'F';
    }
    else if (percent <= 69.99) {
        letterGrade = 'D';
    }
    else if (percent <= 79.99) {
        letterGrade = 'C';
    }
    else if (percent <= 89.99) {
        letterGrade = 'B';
    }
    else {
        letterGrade = 'A';
    }

    return letterGrade;
}