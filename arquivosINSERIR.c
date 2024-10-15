#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arq;
    char palavra[20];

    arq = fopen("arquivo_palavra.txt", "w");

    if(arq == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }//if
    printf("Insira uma palavra para inserir no arquivo: ");
    scanf("%s", &palavra);
    fprintf(arq, "%s", palavra);

    fclose(arq);
    printf("Dados gravados com sucesso!");
    return 0;
}//main