#include <stdio.h>

int main() {
  double A, B, C;
  double PI = 3.14159;

  scanf("%lf %lf %lf", &A, &B, &C);

  double areaTriangulo = (A * C) / 2.0;
  double areaCirculo = PI * C * C;
  double areaTrapezio = ((A + B) * C) / 2.0;
  double areaQuadrado = B * B;
  double areaRetangulo = A * B;

  printf("TRIANGULO: %.3f\n", areaTriangulo);
  printf("CIRCULO: %.3f\n", areaCirculo);
  printf("TRAPEZIO: %.3f\n", areaTrapezio);
  printf("QUADRADO: %.3f\n", areaQuadrado);
  printf("RETANGULO: %.3f\n", areaRetangulo);

  return 0;
}
