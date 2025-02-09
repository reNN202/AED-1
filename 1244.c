#include <stdio.h>
#include <string.h>

typedef struct {
    char texto[3000];
} Palavra;

void ordenarPorTamanho(Palavra *palavras, unsigned tam);

int main() {
    unsigned short casos;
    unsigned short i, j, k;

    scanf("%hu", &casos);

    Palavra palavras[60];
    char entrada[3000];

    while (casos--) {
        memset(palavras, 0, sizeof(palavras));
        memset(entrada, 0, sizeof(entrada));
        scanf(" %[^\n]", entrada);

        i = j = k = 0;
        while (1) {
            while (entrada[i] != ' ') {
                if (entrada[i] == '\0') break;
                palavras[j].texto[k++] = entrada[i++];
            }

            palavras[j].texto[k] = '\0';

            if (entrada[i] == '\0') break;

            i++; j++;
            k = 0;
        }

        j++;
        ordenarPorTamanho(palavras, j);

        for (i = 0; i < j; i++) {
            if (i != 0) printf(" ");
            printf("%s", palavras[i].texto);
        }
        printf("\n");
    }

    return 0;
}

void ordenarPorTamanho(Palavra *palavras, unsigned tam) {
    short i = 1, j;
    Palavra pivo;

    while (i < tam) {
        j = i - 1;
        pivo = palavras[i];

        while (j >= 0 && strlen(palavras[j].texto) < strlen(pivo.texto)) {
            palavras[j + 1] = palavras[j];
            j--;
        }

        palavras[j + 1] = pivo;
        i++;
    }
}