#include <stdio.h>

int main() {
    int quantidade, numero, dentro = 0, fora = 0;

    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &numero);
        if (numero >= 10 && numero <= 20)
            dentro++;
        else
            fora++;
    }

    printf("%d in\n%d out\n", dentro, fora);

    return 0;
}
