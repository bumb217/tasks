#include <express.h>
#include <vector>
#include <stack>

using namespace std;

void makeOperation(vector <int> &numbers,char operation)
{
    if ((operation == '!' || operation ==  '?'))
    {
        int number = numbers.back();
        numbers.pop_back();
        if (operation == '?')number = number * ( -1);
        numbers.push_back(number);
        return;
    }
    int second = numbers.back();
    numbers.pop_back();
    int first = numbers.back();
    numbers.pop_back();
    int number;
    switch (operation) {
    case '-' :
    {
        number = first - second;
        break;
    }
    case '+' :
    {
        number = first + second;
        break;
    }
    case '*' :
    {
        number = first * second;
        break;
    }
    case '/' :
    {
        if (second != 0) number = first / second;
        else cout << "ERROR! div by 0\n";
        break;
    }

    default:
        break;
    }
    numbers.push_back(number);
}

bool isOperation(char sign)
{
    if (sign == '-' || sign == '+' || sign == '*' ||sign == '/') return true;
    else return false;
}

bool isNumber(char sign)
{
    if (sign - '0' >= 0 && sign- '0' <= 9) return true;
    else return false;
}



int priority(char operation)
{
    // *,/ have the highest priority => 2
    // +,- have less priority then (*,/) => 1
    if (operation == '+' || operation == '-') return 1;
    if (operation == '*' || operation == '/') return 2;
    if (operation == '!' || operation == '?') return 3;
    // !- unary +
    // ? unary -;
    else return -1;
}

int calculate2 (string& expression)
{
    vector <int> numbers;
    vector <int> operations;


    bool unary = true;

    char tempSign;
    for (unsigned int i = 0; i < expression.size(); i++)
    {
        tempSign = expression[i];
        if (tempSign != ' ')
        {
            if (tempSign == '(')
            {
                operations.push_back(tempSign);
                unary = true;
            }
            else
            {
                if (tempSign == ')')
                {
                    //unary = false;
                    while (operations.back() != '(')
                    {
                        makeOperation(numbers,operations.back());
                        operations.pop_back();
                    }
                    //delete (
                    operations.pop_back();
                    unary = false;
                }
                else
                {//have operation
                    if (isOperation(tempSign))
                    {
                        char tempOperation = tempSign;
                        if (unary && tempSign == '-') tempOperation = '?';
                        if (unary && tempSign == '+') tempOperation = '!';
                        while (!operations.empty() && priority(tempOperation) <= priority(operations.back()) )
                        {
                            makeOperation(numbers,operations.back());
                            operations.pop_back();
                        }
                        cout <<"##" << tempOperation << "##";
                        operations.push_back(tempOperation);
                        unary = true;
                    }
                    else
                    {//have number
                        int newNumber = 0;
                        unsigned int currIndex = i;
                        while (isNumber(expression[currIndex]) && currIndex < expression.size())
                        {
                               newNumber *= 10;
                               newNumber += expression[currIndex] - '0';
                               currIndex++;
                        }
                        unary = false;
                        i = currIndex - 1;
                        numbers.push_back(newNumber);
                    }
                }

            }
        }
    }

    while (!operations.empty())
    {
        makeOperation(numbers,operations.back());
        operations.pop_back();
    }

    return numbers.back();
}

