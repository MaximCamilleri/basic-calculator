#include <stack>
#include <iostream>

void printStack(std::stack<float> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";
}