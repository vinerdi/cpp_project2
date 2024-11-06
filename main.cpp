#include <iostream>
#include <stack>
#include <string>

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

void checkBrackets(const std::string& str) {
    std::stack<char> stack;
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];

        
        if (ch == ';') {
            break;
        }

        
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty()) {
                
                std::cout << "Error: extra closing bracket at position " << i << "\n";
                std::cout << str.substr(0, i + 1) << "\n";
                return;
            }
            else {
                char top = stack.top();
                if (isMatchingPair(top, ch)) {
                    stack.pop(); 
                }
                else {
                    
                    std::cout << "Error: incorrect pair of brackets at position " << i << "\n";
                    std::cout << str.substr(0, i + 1) << "\n";
                    return;
                }
            }
        }
    }

    
    if (!stack.empty()) {
        std::cout << "Error: missing closing bracket for an opening bracket\n";
        while (!stack.empty()) stack.pop(); 
    }
    else {
        std::cout << "The string is correct\n";
    }
}

int main() {
    std::string str;
    std::cout << "Enter a string to check: ";
    std::getline(std::cin, str);

    checkBrackets(str);

    return 0;
}
