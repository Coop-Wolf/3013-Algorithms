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
using namespace std;


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

    Vector v3(v1);                  // copying v1 vector into v3
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

Node::Node(int val)
{
    data = val;
    next = NULL;
}

Vector::Vector()
{
    front = rear = NULL;
}

Vector::Vector(int* A, int size)
{
    front = rear = NULL;

    // pushing array into vector
    for (int i = 0; i < size; i++)
    {
        pushRear(A[i]);
    }
}

Vector::Vector(Vector& other)
{
    front = rear = NULL;

    Node* temp = other.front;

    //traversing other vector pushing nodes to rear of this vector
    while (temp)
    {
        pushRear(temp->data);
        temp = temp->next;
    }
}

    Vector::Vector(string FileName)
    {
        front = rear = NULL;
        int x;                      //variable to store input file data

        ifstream infile;

        // opening user input file
        infile.open(FileName);

        // copying file data into vector
        infile >> x;
        pushFront(x);

        //reading in values til file is empty
        while (infile >> x)
        {
            pushRear(x);
        }
    }

    void Vector::pushFront(int val)
    {
        Node* temp = new Node(val);

        // checking if vector is empty
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            temp->next = front;
            front = temp;
        }
    }

void Vector::pushFront(Vector other)
{
    int i = 0;                      //variable to store index
    Node* temp = other.front;

    // traversing other vector
    while (temp)
    {
        // pushing other vector onto front of this vector
        pushAt(i, temp->data);
        temp = temp->next;
        i++;
    }

}

    void Vector::pushRear(int val)
    {
        Node* temp = new Node(val);

        // checking if vector is empty
        if (front == NULL)
        {
            rear = temp;
            front = temp;
        }
        // pushing node to back of vector
        else
        {
            rear->next = temp;
            rear = temp;
            rear->next = NULL;
        }
    }

void Vector::pushRear(Vector other)
{
    Node* temp = other.front;

    // traversing other.vector pushing nodes to this->vector
    while (temp)
    {
        pushRear(temp->data);
        temp = temp->next;
    }
}

    void Vector::pushAt(int index, int val)
    {
        int size = 0;
        Node* temp = front;

        // checking size of Vector
        while (temp)
        {
            temp = temp->next;
            size++;
        }

        // if index is 0, pushing to front of vector
        if (index == 0)
            pushFront(val);

        // if index is larger than vector size, error message
        else if (index > size)
            cout << "Index to too large\n";

        // placing value into vector at the index
        else
        {
            Node* temp2 = new Node(val);
            temp = front;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            temp2->next = temp->next;
            temp->next = temp2;
        }
    }

void Vector::inOrderPush(int val)
{
    Node* temp = new Node(val);
    Node* temp2 = front;
    int i = 0;                          // variable to track the index

    // if value is less than front, pushFront
    if (front->data > val)
        pushFront(temp->data);

    //if value is more than rear, pushRear
    else if (rear->data < val)
        pushRear(temp->data);

    // if value is somewhere between, traverse list
    else
    {
        // traversing til value is less than node
        while (temp2->data < val && temp2->next)
        {
            temp2 = temp2->next;
            i++;
        }
        // pushing new node to correct index
        pushAt(i, temp->data);
    }
}

int Vector::popFront()
{
    int x;                          // variable to store popped value
    Node* temp = front;

    // checking if vector is empty
    if (front == NULL)
        return -1;

    // switching front to second item and deleting first
    front = front->next;
    x = temp->data;
    delete temp;
    return x;
    }

    int Vector::popRear()
    {
        int x;                      // variable to store popped value

        // checking if vector is empty
        if (rear == NULL)
            return -1;
        else
        {
            Node* temp = front;

            // looping til temp is pointing to second to last node
            while (temp->next != rear)
            {
                temp = temp->next;
            }

            // removing last node
            rear = temp;
            temp = rear->next;
            rear->next = NULL;
            x = temp->data;
            delete temp;
            return x;
        }
    }

int Vector::popAt(int index)
{
    int size = 0;               // variable to store size of vector
    Node* temp = front;
    Node* temp2 = front;

    // if index is 0, popping front
    if (index == 0)
    {
        return popFront();
    }

    // checking size of Vector
    while (temp)
    {
        temp = temp->next;
            size++;
    }
    // returning -1 if index if greater than size
    if (index >= size)
    {
        cout << "Index is too large\n";
        return -1;
    }

    else
    {
        // looping to pop value at index
        for (int i = 0; i < index; i++)
        {
            temp = temp2;
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        return temp2->data;
    }
}

int Vector::find(int val)
{
    int i = 0;                      // variable to use for index
    Node* temp = front;

    // traversing vector
    while (temp != NULL)
    {
        // if item is found, return index
        if (temp->data == val)
            return i;

        temp = temp->next;
        i++;
    }
    return -1;
}

void Vector::print(ofstream& outfile)
{
    Node* temp = front;

    cout << "[ ";
    outfile << "[ ";
    // looping til temp = NULL
    while (temp)
    {
        cout << temp->data << " ";
        outfile << temp->data << " ";
        temp = temp->next;
    }

    cout << " ]";
    outfile << " ]";
}