#include "calculator.h"
#include "helper.cpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>



Calculator::Calculator(){
    this->ops_valid = {'(', '^', '*', '/', '+', '-'};
    this->ops_priority = {{'^'}, {'*', '/'}, {'+', '-'}};
    this->ops_to_function = {
        {'^', &Calculator::power},
        {'*', &Calculator::multiply},
        {'/', &Calculator::divide},
        {'+', &Calculator::add},
        {'-', &Calculator::subtract}
    };
};

float Calculator::run(std::string expression){
    std::stack<float> num_stack;
    std::stack<char> ops_stack;
    this->build_stacks(num_stack, ops_stack, expression);

    run_bidmas(num_stack, ops_stack);
    if(num_stack.size() > 1){
        throw std::invalid_argument("Input Expression is not Valid");
    }
    return num_stack.top();
}

void Calculator::run_bidmas(std::stack<float>& num_stack, std::stack<char>& ops_stack){
    for(std::vector<char>& ops_target : this->ops_priority){
        // Move down the stack looking for calculations including the target operator 
        std::stack<float> num_temp;
        std::stack<char> ops_temp;
        num_temp.push(num_stack.top());
        num_stack.pop();

        while(ops_stack.size() > 0){ 
            char op = ops_stack.top();
            ops_stack.pop();

            if(op == '('){
                break;
            }
            
            if(std::find(ops_target.begin(), ops_target.end(), op) != ops_target.end()){
                float num2 = num_temp.top();
                num_temp.pop();
                float num1 = num_stack.top();
                num_stack.pop();
                num_temp.push((this->*ops_to_function.at(op))(num1, num2));

            } else {
                ops_temp.push(op);
                num_temp.push(num_stack.top());
                num_stack.pop();
            }
        }

        // Rebuild the stack
        while(num_temp.size() > 0){
            num_stack.push(num_temp.top());
            num_temp.pop();
        }
        while(ops_temp.size() > 0){
            ops_stack.push(ops_temp.top());
            ops_temp.pop();
        }
    }
}

void Calculator::build_stacks(std::stack<float>& num_stack, std::stack<char>& ops_stack, std::string expression){
    std::string working_number = {};
    for(char& c : expression){
        // Numbers
        if(c >= '0' && c <= '9'){
            working_number.push_back(c);
            continue;
        } 
        else if(working_number.size() > 0){ 
            num_stack.push(std::stof(working_number));
            working_number = "";
        }
        
        // Operators
        if(c == ')'){
            this->run_bidmas(num_stack, ops_stack);
        } 
        else if (c == ' '){
            continue;
        } 
        else if(std::find(this->ops_valid.begin(), this->ops_valid.end(), c) != this->ops_valid.end()){
            ops_stack.push(c);
        } 
        else {
            throw std::invalid_argument(c + " is not a valid character");
        }
    }
    
    if(working_number.size() > 0){
        num_stack.push(std::stof(working_number));
    }
}

// Calculations
float Calculator::add(float num1, float num2){return num1 + num2;}

float Calculator::subtract(float num1, float num2){return num1 - num2;}

float Calculator::multiply(float num1, float num2){return num1 * num2;}

float Calculator::divide(float num1, float num2){return num1 / num2;}

float Calculator::power(float num1, float num2){
    if(num2 != 0){
        return num1 * this->power(num1, num2-1);
    }
    else {
        return 1;
    }
}


