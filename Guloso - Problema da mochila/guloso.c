#include <stdio.h>
typedef struct ITENS
{
    int peso, valor;
} item;
void imprime(item *n_item, int n)
{
    for (int i = 0; i <= n; i++){
        printf("\n%d %d", n_item[i].peso, n_item[i].valor);
    }
    putchar('\n');
}
int mochila(item *n_item,int n, int W){
    int tamanho=0,i=0,j=0;
    while(1){
        if(W<=0){
            break;
        }
        if(i>n){
            break;
        }
        if((W-n_item[i].peso)>=0){
            W=W-n_item[i].peso;
            tamanho++;
        }
        else{
            n_item[i].peso=0;
        }
        i++;
    }
    return (tamanho-1);
} 
int dora_aventureira(item *n_item,item *final,int tamanho,int n){
    int i=0,j=0;
    while(i<=n){
        if(n_item[i].peso>0){
            final[j]=n_item[i];
            j++;
        }
        i++;
    }
}
void ordena(item *n_item, int n){
    item aux;
    for (int i = 0; i <= n; i++)
    {
        if (n_item[i].valor < n_item[i + 1].valor)
        {
            aux = n_item[i];
            n_item[i] = n_item[i + 1];
            n_item[i + 1] = aux;
            i=-1;
        }
    }
}
int main()
{
    char url[] = "numeros.txt";
    FILE *arq;
    int W, n, i = 0,tam_vetor;
    arq = fopen(url, "r");
    if (arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else
    {
        fscanf(arq, "%d\n", &W);
        fscanf(arq, "%d\n", &n);
        tam_vetor=n-1;
        item iniciais[tam_vetor];
        while ((fscanf(arq, "%d %d\n", &iniciais[i].peso, &iniciais[i].valor)) != EOF)
        {
            i++;
        }
        fclose(arq);
        ordena(&iniciais[0],tam_vetor);
        imprime(&iniciais[0],tam_vetor);
        int  tam_final=mochila(&iniciais[0],tam_vetor,W);
        item final[tam_final];
        dora_aventureira(&iniciais[0],&final[0],tam_final,tam_vetor);
        imprime(&final[0],tam_final);
        
    }

    return 0;
}