 /**Implemeta a decomposição de um número inteiro positivo na soma de todos os possı́veis fatores
 * Usou-se recursividade para aplicar o conceito de desfragmentação do numero.
 * f(n) = resultado(n) = desfragmentação de n na sua soma de todos seus possiveis fatores
 * Exemplo, para o numero 3 temos:
 * f(3)
 * 3 + f(0) n - 0
 * 2 + f(1) n - 1
 * 1 + f(3) n - 2
 * Assim temos sempre o numero 3, que é o de entrada, sendo decomposto em suas somas que é a decomposição
 * do numero que foi subtraido em n
 * 
 * @author Rubio Torres
 */

 #include<stdio.h>
 #include<stdlib.h>
 

/**Estruturas criadas para armazenar alista de cada fator com suas multiplicações
* @author Rubio Torres
* A struct Num_decomposto vai receber em cada parte da sua lista o fator que esta sendo decomposto
* Ele possui mais uma lista dentro deles que vai receber os fatores de suas somas
*/

typedef struct LISTA_NUM {
    int n;
    struct LISTA_NUM *proximo;
} Lista_numeros;

typedef struct Num_decomposto {
    Lista_numeros *decompo_numeros;
    struct Num_decomposto *proximo;
} num_decomposto;

/**Imprime a lista que contém o numero decomposto
* @author Rubio Torres
* @param  resultado num_composto* - Lista com as listas que contém a decomposição
*/

void imprimir(num_decomposto* resultado){
    for(printf("Decomposicao:\n");resultado != NULL;resultado = resultado->proximo){
        for(; resultado->decompo_numeros != NULL;resultado->decompo_numeros = resultado->decompo_numeros->proximo){
            printf("%d", resultado->decompo_numeros->n);
            if(resultado->decompo_numeros->proximo != NULL){
                printf(" + ");
            }
        }
        printf("\n");

    }
}

/**Decompõe o numero e o armazena nas listas*
* @author Rubio Torres
* @param  entrada int - Numero a ser decomposto
* @return num_decomposto - Lista final dos numeros decompostos
*/

num_decomposto *resultados(int entrada){
    num_decomposto *parcial_a; //Lista que vai armazenar a "ponta" da lista a ser trabalhada
    num_decomposto *atual; // Lista que vamos trabalhar
    if(entrada == 0){ // Caso o numero seja 0 não há como decompor
        printf("%d",0);
        return NULL;
    } 
    atual = (num_decomposto *) malloc(sizeof(num_decomposto));   //Inicializa a lista que vamos trabalhar com o tamanho de nosso struct
    parcial_a = atual; //Aponta para a ponta da nossa lista vigente
    Lista_numeros *inicio = (Lista_numeros *) malloc(sizeof(Lista_numeros)); //Inicializa o vetor para receber o numero inicial
    inicio->n = entrada;//Inicializa nosso vetor com o primeiro caso onde n = entrada f(entrada)
    inicio->proximo = NULL;//inicializa o proximo numero apontando para o null

    parcial_a->decompo_numeros = inicio; // Coloca a lista recem criada na nossa lista principal
    parcial_a->proximo = NULL; //inicializa o proximo numero apontando para o null
    

    for(int posicao=entrada-1; posicao>0; posicao--){ // Decresce nosso numero para fazer f(n-1)
        // Após ter decrescido o numero chamamos a função novamente com nosso novo n -> n = n-1
        //Cria uma lista de uma lista ounde a primeira vai conter nosso fator vigente n-1 e as outras, sua decomposição em soma
        for(num_decomposto *parcial_resultado = resultados(entrada-posicao);parcial_resultado != NULL;parcial_resultado = parcial_resultado->proximo){
            if(parcial_resultado->decompo_numeros->n <= posicao){//Verifica se o proximo numero não é maior que o nosso fator para que não haja casos repetidos como 2 + 1 e 1 + 2
                num_decomposto *parcial_b = (num_decomposto *) malloc(sizeof(num_decomposto));//Alloca o tamanho de um num_composto
                Lista_numeros *parcial_c = (Lista_numeros *) malloc(sizeof(Lista_numeros));//Alloca o tamanho de uma lista_numeros
                parcial_c->n = posicao;// Inicializa com o numero da nossa  posição atual
                parcial_c->proximo = NULL;//Aponta o proximo como NULL
                parcial_c->proximo = parcial_resultado->decompo_numeros;
                parcial_b->decompo_numeros = parcial_c;
                parcial_b->proximo = NULL;
                atual->proximo = parcial_b; 
                atual = parcial_b;// aponta a lista vigente para a recem criada
            } 
        }
    }

    return parcial_a;
}

int main(){

    int entrada;
    num_decomposto *resultado;
    printf("Digite um numero inteiro: ");
    scanf("%d", &entrada);
    resultado= resultados(entrada);
    imprimir(resultado);

    return 0;
}
