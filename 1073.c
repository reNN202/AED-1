#include <stdio.h>

int main() {
    int numero;
    scanf("%d", &numero);

    for (int i = 2; i <= numero - (numero % 2); i += 2)
        printf("%d^2 = %d\n", i, i * i);

    return 0;
}
