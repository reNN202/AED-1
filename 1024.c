#include <stdio.h>
#include <string.h>

void primeira_passada(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] += 3;
        }
    }
}

void segunda_passada(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void terceira_passada(char* str) {
    int len = strlen(str);
    for (int i = len / 2; i < len; i++) {
        str[i] -= 1;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char str[1004];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        primeira_passada(str);
        segunda_passada(str);
        terceira_passada(str);

        printf("%s\n", str);
    }

    return 0;
}
