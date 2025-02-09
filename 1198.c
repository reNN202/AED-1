#include <stdlib.h>
#include <stdio.h>

int main() {
    long long int hashmat, oponente;

    while (scanf("%lld %lld", &hashmat, &oponente) != EOF)
        printf("%lld\n", llabs(hashmat - oponente));

    return 0;
}
