## P02 - AutoComplete
### Cooper Wolf
### Description:

This program implements a linked list and includes a JSON object. The program begins
by reading in a dictionary and storing it into a JSON object. The user is then 
asked to enter keys. As soon as the user enters a valid character, the program will
inform the user how long it took to find those words and a list of ten words 
will be printed to the screen that contain the string of characters the user entered. 
It will also print the numbers of words that contain that string entered. When the 
user types the 'enter' button or there is only one matching word remaining, the program
will print out the definition of the word. To end the program, the user needs to type
in 'Z'. This program was created to introduce me to JSON and what it is capable of,
coloring text, and using a timer. 

### Files

|   #   | File             | Description                                            |
| :---: | ---------------- | --------------------------------------------------     |
|   1   |    [Main.cpp](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/main.cpp)      | Main driver of my project.                     |
|   2   |    [json.hpp](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/json.hpp)      | file contains json definitions.                |
|   3   |    [mygetch.hpp](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/mygetch.hpp)   | Get character without printing.                |
|   4   |    [animals.txt](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/animals.txt)   | Animals names.                                 |
|   5   |    [timer.hpp](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/timer.hpp)     | Include timer.                                 |
|   6   |    [termcolor.hpp](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/termcolor.hpp) | Color text.                                    |
|   7   |    [dictionary.txt](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/dictionary.txt)    | Words.                                     |
|   8   |    [dictionary.json](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/dictionary.json)   | Words with definitions.                    |

### Instructions

- My program expects you to enter in letters.
- To terminate the program, key in 'Z'.

- Example Command:
    - Type keys to begin. Type 'Z' to quit.

- Example Output:

Continue typing keys, or type 'Z' to quit.

Current Substring: 'creat'
21 words found in 0.1512 seconds

Auto-Fill:
creat creatable create creatic creatin creatinin
creation creational creationism creative 



Continue typing keys, or type 'Z' to quit.

Current Substring: 'doctor'
7 words found in 0.1184 seconds

Auto-Fill:
doctor doctoral drctorally doctorate doctoress
doctorly doctorship



Continue typing keys, or type 'Z' to quit

Current Substring: 'cooperatio' 
1 words found in 0.1293 seconds 

Auto-Fill:
cooperation 

1. The act of coöperating, or of operating together to one end; joint operation; concurrent effort or labor. Not holpen by the coöperation of angels. Bacon. 2. (Polit. Econ.)  The association of a number of persons for their benefit.



Continue typing keys, or type 'Z' to quit.

Current Substring: 'opel'
1 words found in 0.1197 seconds

Auto-Fill:
opelet 

A bright-colored European actinian (Anemonia, or Anthea, sulcata); -- so called because it does not retract its tentacles.