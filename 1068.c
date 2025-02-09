#include <stdio.h>
#include <string.h>

int verifica_balanco_parenteses(char *);

int main() {
    char expressao[1100];

    while (scanf(" %s", expressao) != EOF) {
        if (verifica_balanco_parenteses(expressao))
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}

int verifica_balanco_parenteses(char *str) {
    int contador = 0;

    if (*str == ')')
        return 0;

    while (*str && contador >= 0) {
        if (*str == '(')
            contador++;
        if (*str == ')')
            contador--;
        str++;
    }

    return contador == 0;
}
