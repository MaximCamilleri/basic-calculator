#include "calculator.cpp"
#include <iostream>
#include <string>
#include <tuple>

std::vector<std::tuple<std::string, float>> get_tests(){
    return {
        {"2^2^2", 16},
        {"1+2^2+1", 6},
        {"20+30", 50},
        {"2^2+1*5/6-1", 3.8333},
        {"2^8-1", 255},
        {"(1+1)*10", 20},
        {"( 1 + 1 ) * 10", 20},
    };
}

int main(){
    Calculator calc;
    std::vector<std::tuple<std::string, float>> tests = get_tests();
    for(int i=0; i<tests.size(); i++){
        std::tuple<std::string, float> test = tests.at(i);
        float answer = calc.run(std::get<0>(test));

        std::cout << answer << " " << std::get<1>(test) << "\n";
    }
    return 0;
}


