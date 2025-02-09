#include <stdio.h>
#include <string.h>

int ehVogal(char letra){
    switch(letra){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': return 1;
        default: return 0;
    }
}

int main(){
    int inicio, fim;
    int engraçada;
    char risada[51];

    scanf("%s", risada);

    inicio = 0;
    fim = strlen(risada) - 1;
    engraçada = 1;

    while(inicio < fim){
        if(ehVogal(risada[inicio]) && ehVogal(risada[fim])){
            if(risada[inicio] != risada[fim]){
                engraçada = 0;
                break;
            }
            ++inicio;
            --fim;
        } else {
            if(!ehVogal(risada[inicio])) ++inicio;
            if(!ehVogal(risada[fim])) --fim;
        }
    }

    printf("%c\n", engraçada ? 'S' : 'N');

    return 0;
}
