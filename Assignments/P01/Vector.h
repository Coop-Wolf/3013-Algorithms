/*
 * Vector
 *
 * Description:
 *      This class implements a linked list based vector and performs various
 *      operations to it. This class creates nodes which can be pushed and popped
 *      on and off of a vector.
 *
 * Public Methods:
 *                          Vector()
 *                          Vector(Vector& other)
 *                          Vector(int *A, int size)
 *                          Vector(string FileName)
 *      void                pushFront(int val)
 *      void                pushFront(Vector other)
 *      void                pushRear(int val)
 *      void                pushRear(Vector other)
 *      void                pushAt(int index, int val)
 *      void                inOrderPush(int val)
 *      int                 popFront()
 *      int                 popRear()
 *      int                 popAt(int index)
 *      int                 find(int val)
 *      void                print(ofstream& outfile)
 *
 * Private Methods:
 *      Node*               front
 *      Node*               rear
 *
 * Usage:
 *
 *      Vector v():                                 //Create an instance of Vector
 *      Vector v(Vector other)                      //using any of the constructors
 *      Vector v(int*A, int size)                   
 *      Vector v(string FileName)
 *
 *      v.push(int)                                 //use any of the methods to 
 *      v.pop()                                     //manipulate the vector
 *
 */

#ifndef VECTOR_H
#define VECTOR_H
#include <fstream>
using namespace std;


class Node
{
public:

    int data;
    Node* next;

/**
* Public    : Node
*
* Description:
*      This functions gives the node a value
*
* Params:
*      [int]  :   value to place into node
*
* Returns:
*      void
*/
    Node(int val);
};

class Vector
{
    Node* front;
    Node* rear;

public:

/**
 * Public    : Vector
 *
 * Description:
 *      This function sets front and rear to NULL
 *
 * Params:
 *      None
 *
 * Returns:
 *      void
 */
 Vector();

 /**
 * Public    : Vector
 *
 * Description:
 *      This function copies an array into a vector
 *
 * Params:
 *      [int*]  :   array of ints
 *      [int]   :   size of array
 *
 * Returns:
 *      void
 */
Vector(int* A, int size);

/**
* Public    : Vector
*
* Description:
*      This function copies a vector into another vector
*
* Params:
*      [Vector]  :   another vector
*
* Returns:
*      void
*/
Vector(Vector& other);

/**
* Public    : Vector
*
* Description:
*      This function copies data from an input file into the vector
*
* Params:
*      [string]  :   name of the input file
*
* Returns:
*      void
*/
Vector(string FileName);

/**
* Public    : pushFront
*
* Description:
*      This function pushes a value to the front of a vector
*
* Params:
*      [int]  :   value to place into vector node
*
* Returns:
*      void
*/
void pushFront(int val);

/**
* Public    : pushFront
*
* Description:
*      This function pushes a vector onto another vector
*
* Params:
*      [Vector]  :   vector to push onto another vector
*
* Returns:
*      void
*/
void pushFront(Vector other);

/**
* Public    : pushRear
*
* Description:
*      This function pushes a value to the rear of a vector
*
* Params:
*      [int]  :   value to place into vector node
*
* Returns:
*      void
*/
void pushRear(int val);

/**
* Public    : pushRear
*
* Description:
*      This function pushes a vector to the rear of another vector
*
* Params:
*      [Vector]  :   vector to push onto another vector
*
* Returns:
*      void
*/
void pushRear(Vector other);

/**
* Public    : pushAt
*
* Description:
*      This function pushes a node into the vector at the given index
*
* Params:
*      [int]  :   index to push node into vector
*      [int]  :   value to push into vector
*
* Returns:
*      void
*/
void pushAt(int index, int val);

/**
* Public    : inOrderPush
*
* Description:
*      This function pushes a value to the vector in order
*
* Params:
*      [int]  :   value to push into the vector
*
* Returns:
*      void
*/
void inOrderPush(int val);

/**
* Public    : popFront
*
* Description:
*      This function pops the first node in the vector
*
* Params:
*      None
*
* Returns:
*      [int]  :   value popped off of the vector        
*/
int popFront();

/**
* Public    : popRear
*
* Description:
*      This function pops the last node in the vector
*
* Params:
*      None
*
* Returns:
*      [int]  :   value popped off of the vector
*/
int popRear();

/**
* Public    : popAt
*
* Description:
*      This function pops a node at the given index
*
* Params:
*      [int]  :   index to pop node at
*
* Returns:
*      [int]  :   value popped off of the vector
*/
    int popAt(int index);

/**
* Public    : find
*
* Description:
*      This function finds a value and returns the index if its there
*
* Params:
*      [int]  :   value to search for
*
* Returns:
*      [int]  :   index that the value is at in the vector
*/
    int find(int val);

/**
* Public    : print
*
* Description:
*      This functions outputs the vector
*
* Params:
*      [ofstream]  :   output file
*
* Returns:
*      void
*/
    void print(ofstream& outfile);
};

#endif