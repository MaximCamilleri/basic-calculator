#include "calculator.cpp"
#include <iostream>

int main(){
    Calculator calc;
    float ret = calc.run("1+1");

    std::cout << ret;

    return 0;
}