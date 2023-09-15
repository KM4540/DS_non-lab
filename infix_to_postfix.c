#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // Return a special character to indicate an empty stack
}

// Function to get the precedence of an operator
int getPrecedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix) {
    int i, j;
    struct Stack* stack = createStack(strlen(infix) + 1);
    if (!stack) // Check if the stack was created successfully
        return;

    char postfix[strlen(infix) + 1];
    for (i = 0, j = 0; infix[i]; ++i) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(stack, c);
        } else if (c == ')') {
            while (!isEmpty(stack) && stack->array[stack->top] != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && stack->array[stack->top] == '(') {
                pop(stack); // Pop the '(' from the stack
            }
        } else if (isOperator(c)) {
            while (!isEmpty(stack) && getPrecedence(c) <= getPrecedence(stack->array[stack->top])) {
                postfix[j++] = pop(stack);
            }
            push(stack, c);
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix string

    printf("Postfix Expression: %s\n", postfix);

    free(stack->array);
    free(stack);
}

int main() {
    char infix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
