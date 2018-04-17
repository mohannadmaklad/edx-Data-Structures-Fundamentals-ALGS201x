#include <iostream>
#include <stack>
#include <string>


struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    Bracket tmpBracket {'{',0};
    std::string text;
    getline(std::cin, text);
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            tmpBracket.type = text[position];
            tmpBracket.position = position;
            opening_brackets_stack.push(tmpBracket);
        }

        else if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.empty())
            {
                std::cout << position+1 ;
                return 0;
            }
            else
            {
                tmpBracket = opening_brackets_stack.top();
                opening_brackets_stack.pop();
                if
                (
                   text[position] == ']' && tmpBracket.type !='[' ||
                   text[position] == '}' && tmpBracket.type !='{' ||
                   text[position] == ')' && tmpBracket.type !='('
                )
                {
                    std::cout << position+1;
                    return 0;
                }
            }
        }
    }


    if(opening_brackets_stack.empty()) std::cout << "Success";
    else
    {
        tmpBracket = opening_brackets_stack.top();
        std::cout << tmpBracket.position+1;
    }


    return 0;
}
