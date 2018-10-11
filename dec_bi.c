#include <stdio.h>

void dec2bin(int dec) {
  if (dec <= 0) {
    return;
  } else {
    dec2bin(dec / 2);
    printf("%d", dec % 2);
  }
}

int main() {
  int dec;
  printf("Digite um numero inteiro: ");
  scanf("%d", &dec);
  printf("Resultado: ");
  dec2bin(dec);
  printf("\n");
  return 0;
}
