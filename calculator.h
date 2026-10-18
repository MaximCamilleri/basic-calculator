#include <vector>
#include <map>
#include <string>
#include <stack>

class Calculator{
    private: 
        void build_stacks(std::stack<float>& num_stack, std::stack<char>& ops_stack, std::string expression);
        float run_idmas(std::string expression);

        float add(float num1, float num2);
        float subtract(float num1, float num2);
        float multiply(float num1, float num2);
        float divide(float num1, float num2);
        float power(float num1, float num2);
    
    public:
        Calculator();

        using opsFunctionPointer = float (Calculator::*)(float, float);
        std::vector<char> ops_valid;
        std::vector<std::vector<char>> ops_priority;
        std::map<char, opsFunctionPointer> ops_to_function;
        
        float run(std::string expresion);
};