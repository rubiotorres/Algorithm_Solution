#include <stdio.h>
/**Implementa o quanto de digitos tem um numero
 * Usou-se recursividade para aplicar contar o numero de digito
 * cont = f(n) sendo n = n/10
 * @author Rubio Torres
 */
/**Clacula os digitos atravez da recursividade
 * @author Rubio Torres
 * @param  N int - Numero de entrada
 * @return int - numero de digitos
 */
int Digitos(int N) {
  int cont = 0;
  if (N > 0) {
    N = N / 10;
    cont = 1 + Digitos(N);
  }
  return cont;
}
int main(int argc, char const *argv[]) {
  int N;
  printf("Digite um numero inteiro: ");
  scanf("%d", &N);
  printf("Resultado: %d\n", Digitos(N));
  return 0;
}
