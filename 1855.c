#include <stdio.h>

int main() {
    int largura, altura;
    char mapa[100][100];
    int controle[100][100] = {0};

    scanf("%d %d", &largura, &altura);
    for (int i = 0; i < altura; i++)
        scanf("%s", mapa[i]);

    int x = 0, y = 0;
    int dx = 0, dy = 1;

    while (1) {
        if (x < 0 || x >= altura || y < 0 || y >= largura) {
            printf("!\n");
            return 0;
        }

        if (controle[x][y]) {
            printf("!\n");
            return 0;
        }

        controle[x][y] = 1;

        if (mapa[x][y] == '*') {
            printf("*\n");
            return 0;
        }

        if (mapa[x][y] == '>') {
            dx = 0;
            dy = 1;
        } else if (mapa[x][y] == '<') {
            dx = 0;
            dy = -1;
        } else if (mapa[x][y] == 'v') {
            dx = 1;
            dy = 0;
        } else if (mapa[x][y] == '^') {
            dx = -1;
            dy = 0;
        } else if (mapa[x][y] != '.') {
            printf("!\n");
            return 0;
        }

        x += dx;
        y += dy;
    }
    return 0;
}
