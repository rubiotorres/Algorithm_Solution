/**Calculando fatorial com o conceito de BIGINT
 * @author Rubio Torres
 */

#include<stdio.h>
#include<stdlib.h>

/**Implemeta a impressão do BIGINT(vetor final)
* @author Rubio Torres
* @param  R_final int* - Vetor final contendo o resultado do fatorial(BIGINT)
* @param  tamanho int - Tamanho do numero(vetor) que contem o resultado
*/

void imprimir(int *R_final,int tamanho){
    int i;
    printf("Resultado: ");
    for (i=tamanho-1; i>=0; i--){
        printf("%d",R_final[i]);
    }
    putchar('\n');
}

/**Calcula e soma no vetor a sobra do numero e retorna o tamanho final do numero
* @author Rubio Torres
* @param  sobra int - Numero que sobrou na ultima multiplicação
* @param  tamanho int - Tamanho do vetor
* @param  parcial int* - Vetor que vai receber o numero
* @return int - Tamanho do vetor final
*/

int vaium(int sobra,int tamanho, int *parcial){
    int tam=tamanho;
    while(sobra != 0){
        (*(parcial+tam)) = sobra%10;
        sobra/=10;
        tam++;
    }
    return tam;
}

/**Arrasta todo o vetor multiplicando pelo multiplicador que é um numero crescente
* e armazena o algarismo menos significativo no vetor. Além disso armazenda todos
* os outros algarismos na sobra
* @author Rubio Torres
* @param  multiplicador int - numero crescente que vai multiplicar por cada numero no vetor
* @param  tamanho int - Tamanho do vetor
* @param  multiplicando int* - Vetor que vai receber o numero e que contem o numero já armazenado
* @return int - Tamanho do vetor final
*/

int multiplicacao(int multiplicador, int *multiplicando, int tamanho){
    int parcial_B, i,sobra;
    for(sobra=i=0;i<tamanho;i++){
        parcial_B = ((*(multiplicando+i))*multiplicador)+sobra;
        (*(multiplicando+i)) = parcial_B%10;
        sobra=parcial_B/10;
    }

    return vaium(sobra,tamanho,multiplicando);
}

/**Torna o multiplicando crescente de 0 ao numero desejado, além disso inicializa as variaveis e o vetor
* @author Rubio Torres
* @param  e_multiplicando int - Numero desejado o fatorial
* @param  fim int* - Vetor que vai receber o numero e que contem o numero já armazenado
* @return int - Tamanho do vetor final
*/

int p_deslocador (int e_multiplicando, int *fim){
    int tam_vetor, multiplicador;
    for(multiplicador = *(fim)= tam_vetor = 1; multiplicador <= e_multiplicando; multiplicador++){
        tam_vetor = multiplicacao(multiplicador,fim,tam_vetor);
    }
    return tam_vetor;
}

int main(){
    int multiplicando,*r_fim;
    r_fim=(int*)malloc(456570*sizeof(int));
    printf("Digite um numero inteiro: ");
    scanf("%d",&multiplicando);
    imprimir(r_fim,p_deslocador(multiplicando,r_fim));
    return 0;
}
