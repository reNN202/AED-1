#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char senha[101];
    int comprimento, invalido, maiuscula, minuscula, numero;

    while(fgets(senha, sizeof(senha), stdin) != NULL){
        comprimento = strlen(senha);

        if(comprimento < 6 || comprimento > 32){
            printf("Senha invalida.\n");
            continue;
        }

        invalido = 0;
        maiuscula = 0;
        minuscula = 0;
        numero = 0;

        for(int i = 0; i < comprimento; ++i){
            if(isalpha(senha[i])){
                if(senha[i] == tolower(senha[i])) minuscula = 1;
                else maiuscula = 1;
            } else if(isdigit(senha[i])) numero = 1;
            else{
                invalido = 1;
                break;
            }
        }

        if(invalido || !(maiuscula && minuscula && numero)){
            printf("Senha invalida.\n");
        } else {
            printf("Senha valida.\n");
        }
    }

    return 0;
}
