/*****************************************************************************
*
*  Author:           Cooper Wolf
*  Email:            ctwolf1014@my.msutexas.edu
*  Label:            P01
*  Title:            AutoComplete
*  Course:           CMPS 3013
*  Semester:         Spring 2024
*
*  Description:
*        This program implements a linked list and includes a JSON object. The program begins
*        by reading in a list of animals and storing them into a JSON object. The user is then 
*        asked to enter keys. As soon as the user enters a valid character, a list of ten 
*        animals will be printed to the screen that contain the string on characters the user
*        entered. It will also print the numbers of animals that contain that string entered.
*        To end the program, the user needs to type in 'Z'. This program was created to
*        introduce me to JSON and what it is capable of. 
*        
*  Usage:
*       - This program already has the required files and prints all necessary data to screen
*       - 
*
*  Files:
*       main.cpp      : driver program
*       json.hpp      : json definitions
*       mygetch.hpp   : mygetch definitions
*       animals.txt   : file will animal names
*****************************************************************************/

#include <iostream>
#include "json.hpp"
#include <fstream>
#include <algorithm>
#include "mygetch.hpp"
using namespace std;
using json = nlohmann::json;


/*
 * wordNode
 *
 * Description:
 *      This struct implements the nodes for a list. Its variables, word and next
 *      allow it to store a string and the address of another node.
 *
 * Public Methods:
 *                          wordNode()
 *                          wordNode(string word)
 *
 * Private Methods:
 *      string               word
 *      wordNode*            next
 *
 * Usage:
 *
 *      wordNode w1():                                 // Create an instance of wordNode
 *      wordNode w2(string word)                       // using either of the constructors
 *
 */
struct wordNode
{
public:

string word;
wordNode* next;

/**
* Public    : wordNode
*
* Description:
*      This function gives the node an empty string
*
* Params:
*      none
*
* Returns:
*      void
*/
wordNode();

/**
* Public    : wordNode
*
* Description:
*      This function gives the node a word
*
* Params:
*      string  :   value to place into node
*
* Returns:
*      void
*/
wordNode(string word);
};

/*
 * List
 *
 * Description:
 *      This class implements a linked list. With the help of the wordNode struct,
 *      this class can push, look for, and remove words from the list.
 *
 * Public Methods:
 *                          List()
 *                         ~List()
 *      void                push(string word)
 *      void                destroy()
 *      void                print()
 *      int                 getNumItems()
 *      bool                find(string items)
 *
 * Private Methods:
 *      wordNode*           head
 *
 * Usage:
 *
 *      List l1():                                   // Create an instance of List
 *
 *      l1.push(string)                                 // use any of the methods to 
 *      l1.destory()                                    // manipulate the vector
 *
 */
class List
{
private:

wordNode* head;                             // variable that points to first node in the list

public:

/**
* Public    : List
*
* Description:
*      This function points head to NULL
*
* Params:
*      none
*
* Returns:
*      void
*/
List() { head = NULL; }

/**
* Public    : List
*
* Description:
*      This function deletes the list and returns memory
*
* Params:
*      none
*
* Returns:
*      void
*/
~List();

/**
* Public    : List
*
* Description:
*      This function adds a word to the list
*
* Params:
*      string  :   word to add to the list
*
* Returns:
*      void
*/
void push(string word);

/**
* Public    : List
*
* Description:
*      This function searches for a word in the list
*
* Params:
*      string  :   word to search for in the list
*
* Returns:
*      bool    :   depending on if word was in the list or not
*/
bool find(string item);

/**
* Public    : List
*
* Description:
*      This function adds a word to the list
*
* Params:
*      none
*
* Returns:
*      int  :     number of words in the list
*/
int getNumItems();

/**
* Public    : List
*
* Description:
*      This function removes all the words from the list
*
* Params:
*      none
*
* Returns:
*      void
*/
void destroy();

/**
* Public    : List
*
* Description:
*      This function prints all the words from the list
*
* Params:
*      none
*
* Returns:
*      void
*/
void print();

};

int main() 
{
  ifstream infile("animals.txt");           // creating input stream
  json jobject;                             // creating object of JSON
  List l1;                                  // creating object of List
  string file_words;                        // variablet to store strings from input file
  string word = "";                         // variable to store string entered by user
  string newword = "";                      // variable to store word from JSON object
  int k;                                    // variable used to getch
  bool deleting = false;                    // variable to determine if user pressed backspace
  bool found = false;                       // variablet to determine if word was found
  
  // loading JSON with words
  while(infile >> file_words)
      {
        jobject.push_back(file_words);
      }

  cout << "Type keys to begin. Type 'Z' to quit.\n\n";
  
  // looping til input is not 'Z'
  while ((k = getch()) != 'Z') 
    {

    // checking if user backspaced
    if ((int)k == 127) 
      {
        if (word.size() > 0) 
          {
            word = word.substr(0, word.size() - 1);
            deleting = true;
          }
      } 
    else 
      {
        deleting = false;
        // Make sure a letter was pressed and only letter
        if (!isalpha(k)) 
          {
            cout << "Letters only!" << endl;
            sleep(1);
            continue;
          }

        // lowercasing if user typed in a capital letter
        if ((int)k < 97) 
          {
            k += 32;
          }
        // concat char to word
        word += k;
      }

        // looping through the JSON object
        for (const auto& item : jobject.items())
          {
            found = false;

            // looping to compare characters
            for(int i =0;i<word.size();i++)
            {
              found = false;

              // checking if chars match
              if(item.value().get<string>()[i] == word[i])
               {
                 // checking if word is alread in list
                 if(!l1.find(item.value()))
                 {
                  newword = item.value();
                  found = true;
                 }
               }
              else 
                break;
            }
            // adding new word to list
            if(found)
            l1.push(newword);
          }

    // if k isn't a space, print it
    if ((int)k != 32) 
      {
        cout << "Current Substr: " << "'"<< word << "'" << endl;
        cout << l1.getNumItems() << " words found\n\n";

        // print list then remove the words in it
        l1.print();
        l1.destroy();
        cout << "\n\n";

     }
  } 
} // End of Main


wordNode::wordNode()
{
  word = " ";
  next = NULL;
}

wordNode::wordNode(string word)
{
  this->word = word;
  next = NULL;
}

List::~List()
{
  wordNode *nodePtr = head;                 // start at head of list
  while (nodePtr != NULL)
    {
      // garbage keeps track of node to be deleted
      wordNode *temp = nodePtr;
      nodePtr = nodePtr->next;
      // deleting trash
      delete temp;
    }
}

void List::push(string word)
{
  wordNode* temp = new wordNode(word);      // variable to point to new node

  if(head == NULL)
    head = temp;
  else
  {
    wordNode* temp2 = head;                 // variable to trace list
    while(temp2->next)
      {
        temp2 = temp2->next;
      }
    temp2->next = temp;
  }
}

bool List::find(string item)
{
  wordNode* temp = head;                    // variable to search the list

  // looping til end of list
  while(temp)
    {
      // if word is found get out of loop
      if(temp->word == item)
        return true;
      else
        temp = temp->next;
    }
  return false;
}


int List::getNumItems()
{
  wordNode* temp = head;                    // variable to traverse the list
  int num_items=0;

  // looping through list
  while(temp)
    {
      temp = temp->next;
      num_items++;
    }
  return num_items;
}

void List::destroy()
{
  wordNode* temp = head;                    // variable to traverse list
  wordNode* temp2 = head;                   // variable to traverse list

  // looping through list
  while(temp)
    {
      temp2->next = NULL;
      temp = temp->next;
      temp2 = temp;
    }
  head = NULL;
}

void List::print()
{
  wordNode* temp = head;                    // variable to traverse list
  int i = 0;                                // variable to keep track of words printed

  // looping til end of list or 10 words have been printed
  while(temp && i < 10)
    {
      cout << temp->word << ", ";
      temp = temp->next;
      i++;
    }
}