#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Amigo {
    char nome[50];
    struct Amigo *proximo;
} Amigo;

Amigo* criarAmigo(char *nome) {
    Amigo* novoAmigo = (Amigo*) malloc(sizeof(Amigo));
    strcpy(novoAmigo->nome, nome);
    novoAmigo->proximo = NULL;
    return novoAmigo;
}

void adicionarAmigo(Amigo **inicio, char *nome) {
    Amigo *novoAmigo = criarAmigo(nome);
    if (*inicio == NULL) {
        *inicio = novoAmigo;
    } else {
        Amigo *temp = *inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoAmigo;
    }
}

Amigo* encontrarUltimo(Amigo *inicio) {
    if (inicio == NULL) return NULL;
    while (inicio->proximo != NULL) {
        inicio = inicio->proximo;
    }
    return inicio;
}

void inserirAntesDe(Amigo **inicio, char *nomeReferencia, Amigo *novaLista) {
    if (*inicio == NULL) return;

    if (strcmp((*inicio)->nome, nomeReferencia) == 0) {
        Amigo *ultimoNovaLista = encontrarUltimo(novaLista);
        ultimoNovaLista->proximo = *inicio;
        *inicio = novaLista;
        return;
    }

    Amigo *anterior = *inicio;
    Amigo *atual = (*inicio)->proximo;

    while (atual != NULL && strcmp(atual->nome, nomeReferencia) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        Amigo *ultimoNovaLista = encontrarUltimo(novaLista);
        ultimoNovaLista->proximo = atual;
        anterior->proximo = novaLista;
    } else {
        Amigo *ultimo = encontrarUltimo(*inicio);
        ultimo->proximo = novaLista;
    }
}

void imprimirLista(Amigo *inicio) {
    int primeiro = 1;
    while (inicio != NULL) {
        if (!primeiro) {
            printf(" ");
        }
        printf("%s", inicio->nome);
        primeiro = 0;
        inicio = inicio->proximo;
    }
    printf("\n");
}

int main() {
    Amigo *listaAmigos = NULL;
    Amigo *novaListaAmigos = NULL;
    char lista_atual[1000], nova_lista[1000], amigo_indicado[50];

    fgets(lista_atual, sizeof(lista_atual), stdin);
    lista_atual[strcspn(lista_atual, "\n")] = '\0';

    char *token = strtok(lista_atual, " ");
    while (token != NULL) {
        adicionarAmigo(&listaAmigos, token);
        token = strtok(NULL, " ");
    }

    fgets(nova_lista, sizeof(nova_lista), stdin);
    nova_lista[strcspn(nova_lista, "\n")] = '\0';

    token = strtok(nova_lista, " ");
    while (token != NULL) {
        adicionarAmigo(&novaListaAmigos, token);
        token = strtok(NULL, " ");
    }

    fgets(amigo_indicado, sizeof(amigo_indicado), stdin);
    amigo_indicado[strcspn(amigo_indicado, "\n")] = '\0';

    if (strcmp(amigo_indicado, "nao") == 0) {
        Amigo *ultimo = encontrarUltimo(listaAmigos);
        if (ultimo != NULL) {
            ultimo->proximo = novaListaAmigos;
        } else {
            listaAmigos = novaListaAmigos;
        }
    } else {
        inserirAntesDe(&listaAmigos, amigo_indicado, novaListaAmigos);
    }

    imprimirLista(listaAmigos);

    return 0;
}
