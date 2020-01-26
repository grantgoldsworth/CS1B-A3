/******************************************************************************
 * AUTHOR     : GRANT GOLDSWORTH
 * STUDENT ID : 1164709
 * A3         : GRADES
 * CLASS      : CS1B
 * SECTION    : MW  9:30A
 * DUE DATE   : 1/27/2020
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <windows.h>
using namespace std;

#ifndef CS1B_A3_FUNCTIONS_H
#define CS1B_A3_FUNCTIONS_H

int calculatePoints(const char [],   // the answer key array
                    const char []);  // the student answer array

char calculateLetterGrade(float); // the percentage score for the student, format ##.##

void OutputAnswerResults(const char [],  // the answer key array
                         const char []); // the student answer array

#endif //CS1B_A3_FUNCTIONS_H
