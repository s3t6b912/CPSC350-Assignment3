/* Main.cpp
  This is the main implementation of Assignment 3
  @author Sebastian Brumm
  @author brumm@chapman.edu
  @author Id:2319132
*/
#include <iostream>
#include <fstream>
#include "GenStack.h"

using namespace std;

//Not a long main function, really just reads through a file to find deliminators to add to a stack then will quit if there are any out of place
int main(int argc, char *argv[]) {
  string fileName = argv[1];
  string answer = "yes";
  ifstream input(argv[1]);
  GenStack<char> stack(10);
  int lineNum = 1;
  string line;

  while(answer == "yes"){
    ifstream input(fileName);
    while(getline(input,line)){
      for(int i = 0; i < line.length(); i++){
        if(line[i] == '{'){
          stack.push(line[i]);
        }
        if(line[i] == '('){
          stack.push(line[i]);
        }
        if(line[i] == '['){
          stack.push(line[i]);
        }
        if(line[i] == '}'){
          if(stack.peek() == '{'){
            stack.pop();
          }else if(stack.peek() == '('){
            cout << "Line " << lineNum << ": Expected ) and found " << line[i] << endl;
            return 0;
          }else if(stack.peek() == '['){
            cout << "Line " << lineNum << ": Expected ] and found " << line[i] << endl;
            return 0;
          }
        }
        if(line[i] == ')'){
          if(stack.peek() == '('){
            stack.pop();
          }else if(stack.peek() == '{'){
            cout << "Line " << lineNum << ": Expected } and found " << line[i] << endl;
            return 0;
          }else if(stack.peek() == '['){
            cout << "Line " << lineNum << ": Expected ] and found " << line[i] << endl;
            return 0;
          }
        }
        if(line[i] == ']'){
          if(stack.peek() == '['){
            stack.pop();
          }else if(stack.peek() == '('){
            cout << "Line " << lineNum << ": Expected ) and found " << line[i] << endl;
            return 0;
          }else if(stack.peek() == '{'){
            cout << "Line " << lineNum << ": Expected } and found " << line[i] << endl;
            return 0;
          }
        }
      }
      lineNum++;
    }
    input.close();
    if (!stack.isEmpty()){
      if(stack.peek() == '('){
        cout << "Reached end of file: missing )" << endl;
        return 0;
      }else if(stack.peek() == '{'){
        cout << "Reached end of file: missing }" << endl;
        return 0;
      }else{
        cout << "Reached end of file: missing ]" << endl;
        return 0;
      }
    }
    cout << "All the deliminators are present and not out of place.\n";
    cout << "Would you like to process another file? (yes/no)\n";
    cin >> answer;
    if(answer == "yes"){
      cout << "Enter the file name: \n";
      cin >> fileName;
      lineNum = 1;
    }
  }
  return 0;
}
