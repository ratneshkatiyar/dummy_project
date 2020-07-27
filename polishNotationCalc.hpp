#pragma once
#include <iostream>
#include <stack>
#include <utility>

namespace dev
{
    /*!
 * \brief Exception class for Calculator.
 */
    class Exception final : public std::exception
    {
    public:
        template <typename T>
        Exception(T &&msg)
            : mMsg(std::forward<T>(msg))
        {
        }

        const char *what() const noexcept override
        {
            return mMsg.c_str();
        }

    private:
        const std::string mMsg;
    };

    class PolishCalc
    {
    public:
        double calc(const std::string&);

    private:
        bool isNumeric(const char num);
        bool isOperator(const char num);
        double performOperation(const char operation, const double firstOperand, const double secOperand);
        void pushOperandInStack(const std::string &, int& curr_pos);
        std::pair<double,double> getOperandFromStack();
        std::stack<double> mStack;
    };

} // namespace dev
