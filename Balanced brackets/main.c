#include <stdio.h>
#include <stdlib.h>

struct bracket
{
    char type;
    unsigned int position;
};
typedef struct bracket bracket;



//typedef char stackType;
typedef bracket stackType;
struct stack
{
    unsigned int index ;
    unsigned int capacity;
    stackType array[100];
};
typedef struct stack stack;

//
// very simple Stack operations
//

void push(stack*,stackType);
stackType pop(stack*);
char isEmpty(stack*);

//
//Balanced brackets functions
//

char isBalanced(char*, int*);


int main()
{

    int pos = 0;
    char *s = gets(s);
    if(isBalanced(s,&pos)) printf("Success");
    else printf("%d",pos+1); //1-based index


    return 0;
}


void push(stack *mys, stackType element)
{
    if(mys->index < mys->capacity) mys->array[mys->index++] = element;
}

stackType pop(stack* mys)
{
    if(!isEmpty(mys)) return mys->array[--mys->index];
}


char isEmpty(stack* mys)
{
    if(mys->index == 0 ) return 1;
    else return 0;
}


char isBalanced(char *st, int *pos)
{
    stack temp;
    temp.capacity = 10;
    temp.index = 0;
    *pos = 0;
    stackType tmpBracket;

    unsigned int i =0;
    while(st[i] != '\0')
    {
        if(st[i] =='{' || st[i] == '[' || st[i] == '(')
            {
                tmpBracket.type = st[i];
                tmpBracket.position = i;
                push(&temp,tmpBracket); //open bracket detected
            }
        else if(st[i] =='}' || st[i] == ']' || st[i] == ')') //closed bracket detected
        {
            if(isEmpty(&temp))
            {
                *pos = i+1 ;
                return 0; //no open bracket for the closed bracket, not balanced
            }

            else
            {
                tmpBracket = pop(&temp);
                if
                (
                   st[i] == ']' && tmpBracket.type !='[' ||
                   st[i] == '}' && tmpBracket.type !='{' ||
                   st[i] == ')' && tmpBracket.type !='('
                )
                {
                    *pos = i+1; //closing bracket
                    return 0;  //not balanced
                }
            }
        }
        i++; //increment the loop
    }
    if(isEmpty(&temp)) return 1; // if there are no remaining open brackets
    else
    {
        tmpBracket = pop(&tmpBracket);
        *pos = tmpBracket.position; //opening bracket
        return 0;
    }
}
