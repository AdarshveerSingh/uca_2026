#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[31];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';

    return stack[top--];
}

int main() {
    char expression[31];

    scanf("%30s", expression);

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (c == '(' || c == '[' || c == '{') {
            push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            char open = pop();

            if (open == '\0') {
                printf("false");
                return 0;
            }

            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                printf("false");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("true");
    else
        printf("false");

    return 0;
}