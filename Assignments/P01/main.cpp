/*****************************************************************************
*
*  Author:           Cooper Wolf
*  Email:            ctwolf1014n@my.msutexas.edu
*  Label:            P01
*  Title:            Vector Class
*  Course:           CMPS 3013
*  Semester:         Spring 2024
*
*  Description:
*        This program implements a list linked based vector class. It's methods allow you to 
*        perform operations like push, pop, pushRear, popRear, pushAt, and popAt. This class 
*        is similar to a list link based queue with more methods. This project was done to 
*        further my knowledge of linked list and to get more comfortable using them.
*        
*  Usage:
*       - The program will ask for input and output files
*       - The input file needs to be of integers only
*
*  Files:
*       Source.cpp    : driver program
*       Vector.h      : header file with Vector defintion
*       Vector.cpp    : Vector implementation
*****************************************************************************/

#include <iostream>
#include <fstream>
#include "Vector.h"
using namespace std;

/**
 * Public    : openFile
 *
 * Description:
 *      This functions opens an output stream
 *
 * Params:
 *      [ofstream]  :   outfile
 *
 * Returns:
 *      void
 */
void openFile(ofstream& outfile);

/**
 * Public    : setFileName
 *
 * Description:
 *      This functions recives the name of the input file
 *
 * Params:
 *      [string]  :   input file name
 *
 * Returns:
 *      void
 */
void setFileName(string& infile_name);

/**
 * Public    : heading
 *
 * Description:
 *      This functions outputs the heading of the program
 *
 * Params:
 *      [ofstream]  :   outfile
 *
 * Returns:
 *      void
 */
void heading(ofstream& outfile);


int main()
{
    int x = 0;                      // variable to store popped values
    int A[] = { 11,25,33,47,51 };   // array to place into vector object
    string infile_name;             // string to store input file name
    Vector v1;                      // creating an empty vector object
    Vector v2(A, 5);                // copying array values into a vector
    Vector v3(v1);                  // copying v1 vector into v3
    ofstream outfile;               // creating output stream

    // calling functions to recieve
    // files/print heading
    setFileName(infile_name);
    openFile(outfile);
    heading(outfile);
    Vector v4(infile_name);         // creating vector of input data
    
    // pushing values into v1
    v1.pushFront(18);
    v1.pushFront(20);
    v1.pushFront(25);
    v1.pushRear(18);
    v1.pushRear(20);
    v1.pushRear(25);
    v1.print(outfile);

    cout << endl;
    outfile << endl;

    // printing v2
    v2.print(outfile);

    cout << endl;
    outfile << endl;

    // pushing values into v2
    v2.pushFront(9);
    v2.inOrderPush(27);
    v2.pushRear(63);
    v2.print(outfile);

    cout << endl;
    outfile << endl;

    // pushing v2 to the back of v1
    v1.pushRear(v2);
    v1.print(outfile);

    cout << endl;
    outfile << endl;

    // popping values from v1
    x = v1.popFront();
    x = v1.popFront();
    x = v1.popFront();
    v1.print(outfile);

    cout << endl << x << endl;
    outfile << endl << x << endl;

    //popping values from v1
    x = v1.popRear();
    x = v1.popRear();
    x = v1.popRear();
    v1.print(outfile);

    cout << endl << x << endl;
    outfile << endl << x << endl;

    // popping value from v2
    x = v2.popAt(3);
    v2.print(outfile);

    cout << endl << x << endl;
    outfile << endl << x << endl;

    // looking for number in v2
    x = v2.find(51);
    cout << x << endl;
    outfile << x << endl;

    // looking for number in v2
    x = v2.find(99);
    cout << x << endl;
    outfile << x << endl;

    v3.print(outfile);

    cout << endl;
    outfile << endl;

    // pushing v2 to the front of v3
    v3.pushFront(v2);
    v3.print(outfile);

    cout << endl;
    outfile << endl;

    // pushing v3 to the back from v4
    v4.pushRear(v3);
    v4.print(outfile);
}


// Prints heading
void heading(ofstream& outfile)
{
    outfile << "Cooper Wolf\n"
         << "February 5, 2024\n"
         << "Spring - 3013\n\n";
}

// Opens outfile
void openFile(ofstream& outfile)
{
    // characters to enter file name
    char outFileName[40];

    // opening user output file
    cout << "Enter the output file name: ";
    cin >> outFileName;
    outfile.open(outFileName);
}

// Gets input file name
void setFileName(string &infile_name)
{
    cout << "Enter input file name: ";
    cin >> infile_name;
}