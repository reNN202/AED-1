#include <stdio.h>
#include <string.h>

double valorNota(char nota) {
    switch (nota) {
        case 'W': return 1.0;
        case 'H': return 0.5;
        case 'Q': return 0.25;
        case 'E': return 0.125;
        case 'S': return 0.0625;
        case 'T': return 0.03125;
        case 'X': return 0.015625;
        default: return 0.0;
    }
}

int main() {
    int corretos;
    double duracao;
    char musica[1000];

    while (1) {
        if (scanf("%[^\n]\n", musica) == EOF) 
            break;
        if (strcmp(musica, "*") == 0) 
            break;

        corretos = 0;
        duracao = 0.0;
        int tamanho = strlen(musica);

        for (int i = 0; i < tamanho; i++) {
            if (musica[i] == '/') {
                if (duracao == 1.0) 
                    corretos++;
                duracao = 0.0;
            } else {
                duracao += valorNota(musica[i]);
            }
        }

        printf("%d\n", corretos);
    }

    return 0;
}
