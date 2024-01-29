#include <iostream>
#include <fstream>
//#include "Vector.h"

using namespace std;

//DONT FORGET COMMENTS

class Node
{
public:

    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Vector
{
    Node* front;
    Node* rear;

public:

    Vector()
    {
        front = rear = NULL;
    }

    Vector(int* A, int size)
    {
        front = rear = NULL;

        //pushing array into vector
        for (int i = 0; i < size; i++)
        {
            pushRear(A[i]);
        }
    }
    Vector(Vector& other)
    {
        front = rear = NULL;

        Node* temp = other.front;

        while (temp)
        {
            pushRear(temp->data);
            temp = temp->next;
        }
    }
    Vector(string FileName)
    {
        front = rear = NULL;
        int x;

        ifstream infile;

        //opening user input file
        infile.open(FileName);

        //copying file data into vector
        infile >> x;
        pushFront(x);
        while(infile >> x)
        { 
            pushRear(x);
        }
    }

    void pushFront(int x)
    {
        Node* temp = new Node(x);

        //checking if vector is empty
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

    //POSSIBILITY --- could do for loop and pushAt(i+1,value) every time;
    void pushFront(Vector other)
    {
        //  int x;
          //Node* temp = other.rear;

    }


    void pushRear(int x)
    {
        Node* temp = new Node(x);

        //checking if vector is empty
        if (front == NULL)
        {
            rear = temp;
            front = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            rear->next = NULL;
        }
    }
    //should be easy. just need to traverse other.vector and push.rear temp.
    void pushRear(Vector other)
    {
        Node* temp = other.front;

        while (temp)
        {
            pushRear(temp->data);
            temp = temp->next;
        }
    }

    void pushAt(int index, int val)
    {
        int size = 0;
        Node* temp = front;

        //checking size of Vector
        while (temp)
        {
            temp = temp->next;
            size++;
        }

        //if index is 0, pushing to front of vector
        if (index == 0)
            pushFront(val);

        //if index is larger than vector size, error message
        else if (index > size)
            cout << "Index to too large";

        //placing value into vector at the index
        else
        {
            Node* temp2 = new Node(val);
            temp = front;
            for(int i = 0; i < index-1; i++)
            {
                temp = temp->next;
            }
            temp2->next = temp->next;
            temp->next = temp2;
        }
    }

    int popFront()
    {
        int x;
        //checking if vector is empty
        if (front == NULL)
            return -1;

        Node* temp = front;
        front = front->next;
        x = temp->data;
        delete temp;
        return x;
    }

    int popRear()
    {
        int x;
        //checking if vector is empty
        if (rear == NULL)
            return -1;
        else
        {
            Node* temp = front;
            //looping til temp is pointing to second to last node
            while (temp->next != rear)
            {
                temp = temp->next;
            }

            //removing last node
            rear = temp;
            temp = rear->next;
            rear->next = NULL;
            x = temp->data;
            delete temp;
            return x;
        }
    }

    int popAt(int index)
    {
            int size = 0;
            Node* temp = front;
            Node* temp2 = front;

            //if index is 0, popping front
            if(index == 0)
            {
                return popFront();
            }

            //checking size of Vector
            while (temp)
            {
                temp = temp->next;
                size++;
            }
            //returning -1 if index if greater than size
            if (index >= size)
                return -1;

            else
            {
                //looping to pop value at index
                for (int i = 0; i < index; i++)
                {
                    temp = temp2;
                    temp2 = temp2->next;
                }
                temp->next = temp2->next;
                return temp2->data;
            }
    }

    int find(int val)
    {
        int i = 0;
        Node* temp = front;
        while (temp != NULL)
        {
            if (temp->data == val)
                return i;
            temp = temp->next;
            i++;
        }
            return -1;
    }

    void print()
    {
        Node* temp = front;
        //looping til temp = NULL
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

//Opens outfile file
void openFile(ofstream& outfile);

//gets input file name
void setFileName(string& infile_name);

//Prints the heading
void heading(ofstream& outfile);

//DONT FORGET COMMENTS

int main()
{
    //getting input/output files
    ofstream outfile;
   // heading(outfile);
   // string infile_name;
   // setFileName(infile_name);
   // openFile(outfile);

    int x = 0;

    Vector v1;
    v1.pushFront(18);
    v1.pushFront(20);
    v1.pushFront(25);
    v1.pushRear(18);
    v1.pushRear(20);
    v1.pushRear(25);
    v1.print();

    cout << endl;

    int A[] = { 11,25,33,47,51 };
    Vector v2(A, 5);
    v2.print();

    cout << endl;

    v2.pushFront(9);
    //v2.inOrderPush(27);
    v2.pushRear(63);
    v2.print();

    cout << endl;

    v1.pushRear(v2);
    v1.print();

    cout << endl;

    x = v1.popFront();
    x = v1.popFront();
    x = v1.popFront();
    v1.print();

    cout << endl << x << endl;

    x = v1.popRear();
    x = v1.popRear();
    x = v1.popRear();
    v1.print();

    cout << endl << x << endl;

    x = v2.popAt(3);
    v2.print();

    cout << endl << x << endl;

    x = v2.find(51);
    cout << x << endl;

    x = v2.find(99);
    cout << x << endl;

    Vector v3(v1);
    v3.print();

    cout << endl;

    //v3.pushFront(v2);
    v3.print();

    cout << endl;

//    Vector v4(infile_name);
//    v4.pushRear(v3);
//    v4.print();


}

//Prints heading
void heading(ofstream& outfile)
{
    outfile << "Cooper Wolf\n"
         << "February 5, 2024\n"
         << "Spring - 3013\n";
}

//Opens outfile
void openFile(ofstream& outfile)
{
    //characters to enter file name
    char outFileName[40];

    //opening user output file
    cout << "Enter the output file name: ";
    cin >> outFileName;
    outfile.open(outFileName);
}

//Gets input file name
void setFileName(string &infile_name)
{
    cout << "Enter input file name: ";
    cin >> infile_name;
}