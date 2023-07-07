#include <iostream>
#include <cstring>
#include "stack.h"

int main(int argc, char* argv[]) {
  Stack s;
  int i;
  int match = 1;  // Start with matched parentheses
  int openCount = 0;
  int closeCount = 0;
  int j;
  for(j=1;j<argc;j++){

  for (i = 0; i < strlen(argv[j]); i++) {
    switch (argv[j][i]) {
      case '[':
      case '{':
        s.push(argv[j][i]);
        openCount++;
        break;
      case ']':
        closeCount++;
        if (s.pop() != '[') match = 0;
        break;
      case '}':
        closeCount++;
        if (s.pop() != '{') match = 0;
        break;
    }

    if (match == 0) {
      break;  
    }
  }

 
    if (openCount > closeCount) {
    std::cout << "Too many open parentheses" << std::endl;
    }
    else if (closeCount > openCount) {
    std::cout << "Too many close parentheses" << std::endl;
    }
    else if (match == 0) {
    std::cout << "Parentheses did not match" << std::endl;
    }
    else {
    std::cout << "Parentheses matched" << std::endl;
    }
  }
  return 0;
}
