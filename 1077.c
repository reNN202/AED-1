#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 300

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, char c) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = c;
    }
}

char desempilhar(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[(p->topo)--];
    }
    return '\0';
}

char topo(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[p->topo];
    }
    return '\0';
}

int precedencia(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

int ehOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void converterInfixaParaPosfixa(char *infixa, char *posfixa) {
    Pilha p;
    inicializar(&p);
    int i, j = 0;
    char c;

    for (i = 0; infixa[i] != '\0'; i++) {
        c = infixa[i];

        if (isalnum(c)) {
            posfixa[j++] = c;
        } else if (c == '(') {
            empilhar(&p, c);
        } else if (c == ')') {
            while (!vazia(&p) && topo(&p) != '(') {
                posfixa[j++] = desempilhar(&p);
            }
            desempilhar(&p);
        } else if (ehOperador(c)) {
            while (!vazia(&p) && precedencia(topo(&p)) >= precedencia(c)) {
                posfixa[j++] = desempilhar(&p);
            }
            empilhar(&p, c);
        }
    }

    while (!vazia(&p)) {
        posfixa[j++] = desempilhar(&p);
    }

    posfixa[j] = '\0';
}

int main() {
    int n, i;
    char infixa[MAX], posfixa[MAX];

    scanf("%d\n", &n);

    for (i = 0; i < n; i++) {
        fgets(infixa, sizeof(infixa), stdin);
        infixa[strcspn(infixa, "\n")] = '\0';
        converterInfixaParaPosfixa(infixa, posfixa);
        printf("%s\n", posfixa);
    }

    return 0;
}