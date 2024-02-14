#include <iostream>
#include "json.hpp"
#include <fstream>
#include <algorithm>
#include "mygetch.hpp"
using namespace std;

using json = nlohmann::json;

struct wordNode
{
public:
string word;
wordNode* next;

wordNode()
{
  word = " ";
  next = NULL;
}

wordNode(string word)
{
  this->word = word;
  next = NULL;
}
};

class List
{
private:
wordNode* head;

public:
List()
{
  head = NULL;
}

~List()
{
  wordNode *nodePtr = head;  // Start at head of list
  while (nodePtr != NULL)
    {
      // garbage keeps track of node to be deleted
      wordNode *temp = nodePtr;
      nodePtr = nodePtr->next;
      // Deleting trash
      delete temp;
    }
}

void push(string word)
{
  wordNode* temp = new wordNode(word);

  if(head == NULL)
    head = temp;
  else
  {
    wordNode* temp2 = head;
    while(temp2->next)
      {
        temp2 = temp2->next;
      }
    temp2->next = temp;
  }
}

bool find(string item)
{
  wordNode* temp = head;
  while(temp)
    {
      if(temp->word == item)
        return true;
      else
        temp = temp->next;
    }
  return false;
}

int getNumItems()
{
  wordNode* temp = head;
  int num_items=0;
  while(temp)
    {
      temp = temp->next;
      num_items++;
    }
  return num_items;
}

void destroy()
{
  wordNode*prt = head;
  wordNode*prt2 = head;
  while(prt)
    {
      prt2->next = NULL;
      prt = prt->next;
      prt2=prt;
    }
  head = NULL;
}

void print()
{
  wordNode* temp = head;
  int i=0;

  while(temp && i < 10)
    {
      cout << temp->word << " ";
      temp = temp->next;
      i++;
    }
}

};

int main() {

  //int i=0;
  int k;
  string filePath = "animals.txt";
  ifstream infile(filePath);
  json jobject;
  string file_words;
  int size = 0;
  string word = "";
  string key;
  bool deleting = false;
  bool found = false;
  string newword = "";
  List l1;
  
  // loading JSON with words
  while(infile >> file_words)
      {
        jobject.push_back(file_words);
        size++;
      }

  cout << "Type keys to begin. Type 'Z' to quit.\n\n";
  
  // looping til input is not 'Z'
  while ((k = getch()) != 'Z') {

    // 
    if ((int)k == 127) {
        if (word.size() > 0) {
            word = word.substr(0, word.size() - 1);
            deleting = true;
        }
    } else {
        deleting = false;
        // Make sure a letter was pressed and only letter
        if (!isalpha(k)) {
            cout << "Letters only!" << endl;
            sleep(1);
            continue;
        }

        // We know its a letter, lets make sure its lowercase.
        // Any letter with ascii value < 97 is capital so we
        // lower it.
        if ((int)k < 97) {
            k += 32;
        }
        word += k; // append char to word
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
          //i++;

    if ((int)k != 32) { // if k is not a space print it
        key = to_string(k);
      
        cout << "   Current Substr: " << word << endl;
        cout << "Found " << l1.getNumItems() << " words\n";
        cout << "\nAuto-fill: ";
        l1.print();
        l1.destroy();
        cout << "\n\n";

   }
   } 
}