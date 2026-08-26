#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[50];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    char expression[50];
    char *token;

    fgets(expression, sizeof(expression), stdin);

    token = strtok(expression, " \n");

    while (token != NULL) {
        if (token[0] >= '0' && token[0] <= '9') {
            push(atoi(token));
        }
        else {
            int b = pop();
            int a = pop();
            int result;

            if (token[0] == '+')
                result = a + b;
            else if (token[0] == '-')
                result = a - b;
            else if (token[0] == '*')
                result = a * b;
            else
                result = a / b;

            push(result);
        }

        token = strtok(NULL, " \n");
    }

    printf("%d", pop());

}