#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}


int isEmpty(Stack *s) {
    return s->top == -1;
}


void push(Stack *s, char item) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = item;
    }
}


char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}


char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}


int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}


void infixToPostfix(const char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int j = 0;

    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isalnum(ch)) { 
            postfix[j++] = ch;
        } else if (ch == '(') { 
            push(&stack, ch);
        } else if (ch == ')') { 
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); 
        } else { 
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0; // Remove newline character

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

