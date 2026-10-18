#include "calculator.cpp"
#include <iostream>

std::string test_1 = "2^2^2"; // 16
std::string test_2 = "1+2^2+1"; // 6
std::string test_3 = "20+30"; // 50
std::string test_4 = "2^2+1*5/6-1"; // 3.8333

int main(){
    Calculator calc;
    float ret = calc.run(test_4);
    std::cout << ret;

    return 0;
}
