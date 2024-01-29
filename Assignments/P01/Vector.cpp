#include <fstream>
#include <iostream>
#include "Vector.h"

using std::cout;

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

    cout << "]";
    outfile << "]";
}