#include <stdio.h>
/**Implementa a potencia
 * Usou-se recursividade calcular a potencia
 * resultado = base*f(n) sendo n = expoente/10
 * @author Rubio Torres
 */
 /**Calcula a potencia atravez da recursividade
 * @author Rubio Torres
 * @param  base int - base de entrada
 * @param  exp int - expoente de entrada
 * @return int - potencia do numero
 */
int mult(int base, int exp){
  int resultado;
  if(exp==0){
    return 1;
  }
  resultado = base*mult(base,(exp-1));
  return resultado;


}
int main(int argc, char const *argv[]) {
  int base,exp;
  printf("Digite a base e o expoente inteiros: ");
  scanf("%d %d",&base,&exp );
  printf("Resultado: %d\n",mult(base,exp) );
  return 0;
}
