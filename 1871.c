#include <stdio.h>

int main() {
    int M, N, soma;
    char resposta[11];

    while(scanf("%d %d", &M, &N)) {
        if (M == 0 && N == 0) break;

        soma = M + N;

        snprintf(resposta, sizeof(resposta), "%d", soma);

        printf("%s\n", resposta);
    }

    return 0;
}
