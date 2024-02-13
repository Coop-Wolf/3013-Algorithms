#include <iostream>
#include "json.hpp"
#include <fstream>
#include <algorithm>
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

void print()
{
  wordNode* temp = head;
  while(temp)
    {
      cout << temp->word << " ";
      temp = temp->next;
    }
}

};

int main() {

    string filePath = "animals.txt";
    ifstream infile(filePath);
    json jobject;
    string words;
    while(infile >> words)
      {
        jobject["dictiornary"].push_back(words);
      }
    cout << jobject << endl;
  
  List l1;
  l1.push("cooper");
  l1.push("Sammy");
  l1.print();
  
}