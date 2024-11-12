#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char item[21];
    struct No *proximo;
} No;

No* criarNo(char *item) {
    No *novoNo = (No*) malloc(sizeof(No));
    strcpy(novoNo->item, item);
    novoNo->proximo = NULL;
    return novoNo;
}

void adicionarItem(No **inicio, char *item) {
    No *novoNo = criarNo(item);
    if (*inicio == NULL) {
        *inicio = novoNo;
    } else {
        No *temp = *inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }
}

int itemExistente(No *inicio, char *item) {
    No *temp = inicio;
    while (temp != NULL) {
        if (strcmp(temp->item, item) == 0) {
            return 1;
        }
        temp = temp->proximo;
    }
    return 0;
}

void ordenarLista(No *inicio) {
    No *i, *j;
    char temp[21];
    for (i = inicio; i != NULL; i = i->proximo) {
        for (j = i->proximo; j != NULL; j = j->proximo) {
            if (strcmp(i->item, j->item) > 0) {
                strcpy(temp, i->item);
                strcpy(i->item, j->item);
                strcpy(j->item, temp);
            }
        }
    }
}

void imprimirLista(No *inicio) {
    int primeiro = 1;
    while (inicio != NULL) {
        if (!primeiro) {
            printf(" ");
        }
        printf("%s", inicio->item);
        primeiro = 0;
        inicio = inicio->proximo;
    }
    printf("\n");
}

void liberarLista(No *inicio) {
    No *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();  // Limpa o buffer

    for (int i = 0; i < N; i++) {
        No *lista = NULL;
        char item[21];

        // Leitura de itens até o final da linha
        while (scanf("%s", item) == 1) {
            if (!itemExistente(lista, item)) {
                adicionarItem(&lista, item);
            }
            if (getchar() == '\n') break;  // Se a leitura for uma nova linha, quebra o loop
        }

        ordenarLista(lista);
        imprimirLista(lista);
        liberarLista(lista);
    }

    return 0;
}
