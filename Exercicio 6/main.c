#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LENGTH 100001

typedef struct {
    int top;
    char elements[MAX_LENGTH];
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

bool isStackEmpty(const Stack *s) {
    return s->top == -1;
}

bool push(Stack *s, char value) {
    if (s->top >= MAX_LENGTH - 1) {
        return false;
    }
    s->elements[++s->top] = value;
    return true;
}

char pop(Stack *s) {
    if (isStackEmpty(s)) {
        return '\0'; // Retornar um caractere nulo se a pilha estiver vazia
    }
    return s->elements[s->top--];
}

bool isMatch(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

int main() {
    int n;
    char str[MAX_LENGTH];
    Stack stack;
    bool result;

    scanf("%d", &n);

    while (n--) {
        scanf("%s", str);

        initializeStack(&stack);
        result = true;

        for (int i = 0; str[i] != '\0' && result; i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                if (!push(&stack, str[i])) {
                    result = false; // Falha ao empilhar, pilha cheia
                }
            } else {
                char topElement = pop(&stack);
                if (!isMatch(topElement, str[i])) {
                    result = false;
                }
            }
        }

        if (!isStackEmpty(&stack)) {
            result = false;
        }
        
        printf("%c\n", result ? 'S' : 'N');
    }

    return 0;
}
