#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <sstream>
#include <stack>
#include <cstddef>
#include <cctype>

namespace calculator
{
    class Calculator
    {
    public:
        Calculator() = default;
        ~Calculator() = default;

        double calculate(const std::string& expression)
        {
            std::istringstream iss(expression);
            std::string token;
            while (iss >> token)
            {
                if (isOperator(token))
                {
                    double operand2 = operands.top();
                    operands.pop();
                    double operand1 = operands.top();
                    operands.pop();
                    operands.push(applyOperator(token, operand1, operand2));
                }
                else
                {
                    operands.push(std::stod(token));
                }
            }
            return operands.top();
        }

    private:
        bool isOperator(const std::string& token)
        {
            return token == "+" || token == "-" || token == "*" || token == "/";
        }

        double applyOperator(const std::string& token, double operand1, double operand2)
        {
            if (token == "+")
            {
                return operand1 + operand2;
            }
            else if (token == "-")
            {
                return operand1 - operand2;
            }
            else if (token == "*")
            {
                return operand1 * operand2;
            }
            else if (token == "/")
            {
                return operand1 / operand2;
            }
            else
            {
                throw std::runtime_error("Invalid operator");
            }
        }

        std::stack<double> operands;
    };
}
