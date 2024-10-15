#include <stdio.h>
 
int main() {
 int anos=0, meses=0, dias=0, x=0;
 
 scanf("%i", &dias);
    anos= dias/365;
    x=dias%365;
    meses=x/30;
    x=x%30;
    
  printf("%i ano(s)\n", anos);
  printf("%i mes(es)\n", meses);
  printf("%i dia(s)\n", x);
    
    return 0;
}