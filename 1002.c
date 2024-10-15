#include <stdio.h>
 
int main() {
    double area=0, pi=3.14159, raio=0;
    
    scanf("%lf", &raio);
    
    area = raio*raio*pi;
    printf("A=%.4lf\n", area);
 
    return 0;
}