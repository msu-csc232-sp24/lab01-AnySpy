/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2024
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 0.2023.07.27
 * @date    07/27/2023
 *
 * @copyright Copyright (c) 2023 James R. Daehn
 */

#ifndef MSU_CSC232_H_
#define MSU_CSC232_H_

#define FALSE 0
#define TRUE 1

#define FINISHED_PART_1 TRUE
#define FINISHED_PART_2 TRUE
#define FINISHED_PART_3 TRUE

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "expanded_templates.h"

/** Common iostream objects */
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/** Common iomanip objects */
using std::left;
using std::right;
using std::setprecision;
using std::setw;

const int ROSTER_SIZE {5};

const int NUM_COURSES {3};

double grades[ROSTER_SIZE];

double gradeBook[NUM_COURSES][ROSTER_SIZE];


double maxGrade(int numElements, double arr[]);

// This was a little confusing because, in the lab-01 readme, it says that we should be able to use numColumns as the second parameter in arr (if our compiler is c99 compatible, which may be the issue). This doesn't work here so the TA told me to use ROSTER_SIZE as the second parameter.
int indexOfMaxGrade(int numRows, int numColumns, double arr[][ROSTER_SIZE]);

// Returns a double of the maximum grade given an int of the number of elements in the array, and an array with the data type of double.
double maxGrade(int numElements, double arr[])
{
    // A temporary variable of type double so we can use this as our return value.
    double max = 0;

    // Iterates through the provided array and sets the maximum to the current value if that is larger than the current "max".
    for(int i = 0; i < numElements; i++)
    {
        if(arr[i] > max) max = arr[i];
    }

    // Returns the maximum value.
    return max;
}

// Returns the index of the maximum grade of type int when provided the number of rows and columns of type int and a two-dimensional array of type double.
int indexOfMaxGrade(int numRows, int numColumns, double arr[][ROSTER_SIZE])
{
    // Two temporary ints. One is the current maximum value and the second is the index of that value.
    int index = 0;
    int max = 0;

    // A nested for loop that iterates through the rows and columns of the array.
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numColumns; j++)
        {
            // If the value of the value stored in the current position of the array is greater than the maximum value, we change "max" to be the array's value and index to be the index of the value.
            if(arr[i][j] > max)
            {
                max = arr[i][j];
                index = i;
            }
        }
    }

    // We then return index.
    return index;
}

// With seed 2126634923, all tests passed.

#endif // MSU_CSC232_H_
