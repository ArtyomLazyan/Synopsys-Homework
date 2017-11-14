#include <iostream>

void checkWrongExpression()
{
        char ch = std::cin.get();

        if (ch == '\n')
        {
            std::cin.putback(ch);
            return;
        }

        if ((ch >= '0' && ch <= '9') || (ch == '+') || (ch == '-') || (ch == '/') || (ch == '*') || (ch == ' ') || (ch == '(') || (ch == ')'))
        {
            std::cin.putback(ch);
            return;
        }
        else
        {
            std::cout << "Error: Wrong expression! \n";
            exit(-1);
        }
}

float getNumberFromString()
{
    float res = 0;

    checkWrongExpression();

    while (true)
    {
        char ch = std::cin.get();

        if (ch == ' ')
            continue;

        if (ch >= '0' && ch <= '9')
        {
            res = res * 10 + ch - '0';
        }
        else
        {
            std::cin.putback(ch);
            return res;
        }
    }
}

float checkBrackets();

float checkMultiplyDivision()
{
    float x = checkBrackets();

    checkWrongExpression();

    while (true)
    {
        char ch = std::cin.get();

        if (ch == ' ')
            continue;

        switch (ch)
        {
            case '*':
                x *= checkBrackets();
                break;

            case '/':
                x /= checkBrackets();
                break;

            default:
                std::cin.putback(ch);
                return x;
        }
    }
}

float checkAdditionSubstraction()
{
    float x = checkMultiplyDivision();

    checkWrongExpression();

    while (true)
    {
        char ch = std::cin.get();

        if (ch == ' ')
            continue;

        switch (ch)
        {
            case '+':
                x += checkMultiplyDivision();
                break;

            case '-':
                x -= checkMultiplyDivision();
                break;

            default:
                std::cin.putback(ch);
                return x;

        }
    }
}

float checkBrackets()
{
    char ch = std::cin.get();

    if (ch == '(')
    {
        float x = checkAdditionSubstraction();

        // clear spaces until ')' character
        while (true)
        {
            ch = std::cin.get();
            if (ch == ')')
                break;
        }

        return x;
    }
    else
    {
        std::cin.putback(ch);
        return getNumberFromString();
    }
}


int main(int argc, char const *argv[]) {

    std::cout << "Set expression: ";

    float res = checkAdditionSubstraction();

    std::cout << "Result = " << res << std::endl;



    return 0;
}
