// Написать алгоритм перевода из инфиксной записи в обратную польскую. Для его реализации нужны данные по приоритетам операций. Реализовать алгоритм, используя побитовые операции (&, |, ^).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 255
#define STACK_SIZE 255

char oper[STACK_SIZE] = {0};
int oend = 0;

void push(char v)
{
    oper[oend++] = v;
}

char pop()
{
    if (oend <= 0 || oend >= BUFFER_SIZE)
    {
        fprintf(stderr, "Stack overflow\n");
        exit(1);
    }
    return oper[--oend];
}

bool emptyStack()
{
    return oend == 0;
}

bool isOperator(char c)
{
    return c == '&' || c == '^' || c == '|';
}

int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '&')
        return 2;
    else if (c == '|')
        return 1;
    return 0;
}

int main(void)
{
    char c;
    int pos = 0;
    char answer[BUFFER_SIZE] = {0};
    char str[1000];
    int len = 0;
    while ((c = getchar()) != '\n')
    {
        str[len++] = c;
    }
    str[len] = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int number, size = 0;
            for (number = 0; str[i] >= '0' && str[i] <= '9'; i++, size++)
            {
                number = number * 10 + (str[i] - '0');
            }
            sprintf(answer + pos, "%d ", number);
            pos += size + 1;
            i--; 
        }
        else
        {
            c = str[i];
            if (isOperator(c))
            {
                while (!emptyStack() && priority(oper[oend - 1]) >= priority(c))
                {
                    sprintf(answer + pos, "%c ", pop());
                    pos += 2;
                }
                push(c);
            }
            else if (c == '(')
            {
                push(c);
            }
            else if (c == ')')
            {
                while (!emptyStack() && oper[oend - 1] != '(')
                {
                    sprintf(answer + pos, "%c ", pop());
                    pos += 2;
                }
                pop(); 
            }
        }
    }
    while (!emptyStack())
    {
        sprintf(answer + pos, "%c ", pop());
        pos += 2;
    }
    printf("%s\n", answer);
    return 0;
}
