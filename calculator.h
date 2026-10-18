#include <string>

class Calculator{
    private: 
        float add(float num1, float num2);
        float subtract(float num1, float num2);
        float multiply(float num1, float num2);
        float divide(float num1, float num2);
        void parse();
    
    public:
        Calculator();
        float run(std::string expresion);
};