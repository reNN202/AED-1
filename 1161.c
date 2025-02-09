#include <string.h>
#include <stdio.h>

long long F[21];

long long fatorial(int n) {
    if (F[n] == 0)
        F[n] = n * fatorial(n - 1);
    return F[n];
}

int main() {
    int M, N;

    memset(F, 0, sizeof(F));
    F[0] = 1;

    while (scanf("%d %d", &M, &N) != EOF) {
        printf("%lld\n", fatorial(M) + fatorial(N));
    }

    return 0;
}
