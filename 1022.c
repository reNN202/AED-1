#include <stdio.h>

struct Fracao {
    int num, den;
};

struct Fracao soma(struct Fracao f1, struct Fracao f2) {
    struct Fracao resultado;
    resultado.num = f1.num * f2.den + f2.num * f1.den;
    resultado.den = f1.den * f2.den;
    return resultado;
}

struct Fracao subtrai(struct Fracao f1, struct Fracao f2) {
    struct Fracao resultado;
    resultado.num = f1.num * f2.den - f2.num * f1.den;
    resultado.den = f1.den * f2.den;
    return resultado;
}

struct Fracao multiplica(struct Fracao f1, struct Fracao f2) {
    struct Fracao resultado;
    resultado.num = f1.num * f2.num;
    resultado.den = f1.den * f2.den;
    return resultado;
}

struct Fracao divide(struct Fracao f1, struct Fracao f2) {
    struct Fracao resultado;
    resultado.num = f1.num * f2.den;
    resultado.den = f2.num * f1.den;
    return resultado;
}

int mdc(int a, int b) {
    return (b == 0) ? a : mdc(b, a % b);
}

struct Fracao simplifica(struct Fracao f) {
    int divisor = (f.num < 0) ? mdc(-f.num, f.den) : mdc(f.num, f.den);
    f.num /= divisor;
    f.den /= divisor;
    return f;
}

int main() {
    int N;
    char operador;
    struct Fracao f1, f2, resultado;

    scanf("%d\n", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d / %d %c %d / %d\n", &f1.num, &f1.den, &operador, &f2.num, &f2.den);

        switch (operador) {
        case '+':
            resultado = soma(f1, f2);
            break;
        case '-':
            resultado = subtrai(f1, f2);
            break;
        case '*':
            resultado = multiplica(f1, f2);
            break;
        case '/':
            resultado = divide(f1, f2);
            break;
        }

        printf("%d/%d = ", resultado.num, resultado.den);
        resultado = simplifica(resultado);
        printf("%d/%d\n", resultado.num, resultado.den);
    }

    return 0;
}
