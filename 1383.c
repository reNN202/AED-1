#include <stdio.h>
#include <stdlib.h>


void ler(int su[9][9]){
     for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%i", &su[i][j]);
        }// for coluna        
    }// for linha
}

int funcTESTAN(int x){
    if(x>0 && x<10){
        return 1;
    }
    return 0;
}

int linha(int su[9][9], int x){
    int cont[10] = {0}; //vetor contador
    for(int i=0; i<9;i++){
        int y = su[x][i];
        if(funcTESTAN(y) == 0 || cont[y] != 0){
            return 0;
        }
        cont[y]++;
    }
    return 1;
}

int coluna(int su[9][9], int x ){
    int cont[10] = {0}; //vetor contador
    for(int i=0; i<9; i++){
        int y = su[i][x];
        if(funcTESTAN(y) == 0 || cont[y] != 0 ){
            return 0;
        }
        cont[y]++;
    }
    return 1;
}

int regiao3x3(int su[9][9], int x, int z){
    int cont[10] = {0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int y = su[x+i][z+j];
            if(funcTESTAN(y) == 0 || cont[y] != 0){
                return 0;
            }
            cont[y]++;
        }
    }
    return 1;
}

int sudokucompleto(int su[9][9]){
    for(int i=0; i<9;i++){
        if(linha(su,i) == 0 || coluna(su, i) == 0){
            return 0;
        }
    }
    for(int i=0; i<9;i+=3){
        for(int j=0;j<9;j+=3){
            if(regiao3x3(su,i,j) == 0){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%i", &n);

    for(int instancia = 1; instancia<=n; instancia++){
        int su[9][9];
            ler(su);
            printf("Instancia %i\n", n);

        if(sudokucompleto(su) == 1){
            printf("SIM\n");
        }
        else{
            printf("NÃO\n");
        }
    }
    return 0;

}