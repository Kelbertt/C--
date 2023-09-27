#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
//#define K 10 = MAX de mem�ria disponivel


//Facilitar o gerenciamento dos buffers, armaazenando o ponteiro do arquivo ordenado relativo aquele buffer, assim como o tamanho maximo e a posi��o dele//
 struct arquivo{
    FILE *f;
    int pos, MAX;
    int *buffer;
};


//Fun��o auxiliar que serve para facilitar a etapa de salvar os dados de um vetor em um arquivo.//
 void salvaArquivo(char *nome, int *V, int tam, int mudaLinhaFinal){
    int i;
    FILE *f = fopen(nome,"a");
    for(i=0; i < tam-1; i++)
        fprintf(f,"%d\n",V[i]);
    if(mudaLinhaFinal == 0)
        fprintf(f,"%d",V[tam-1]);
    else
        fprintf(f,"%d\n",V[tam-1]);
    fclose(f);
}

//Outra Fun��o auxiliar � fun��o criArquivosOrdenados 
 int compara(const void *a, const void *b){
    if(*(int*)a == *(int*)b)
        return 0;//iguais
    else
        if(*(int*)a < *(int*)b)
            return -1; //vem antes
        else
            return 1; //vem depois
}

//Fun��o para gerar um arquivo com valores inteiros aleat�rio//
 void criArquivoTeste(char *nome){
    int i;
    FILE *f = fopen(nome,"w");
    srand(time(NULL));
    for(i=1; i < 1000; i++)
        fprintf(f,"%d\n",rand());
    fprintf(f,"%d",rand());
    fclose(f);
}

//Basicamente, esta fun��o abre o arquivo original (linha 16) e, enquanto houver dados no arquivo (linhas 17-27), l� um valor do arquivo e armazena no vetor V (linha 18). Sempre que o total de valores lidos for igual ao tamanho do vetor, os dados s�o ordenados usando a fun��o quickSort (Figura 3.13) e um novo arquivo tempor�rio � gerado (linhas 20-26).
int criArquivosOrdenados(char *nome){
    int V[N];
    char novo[20];
    int K = 0, total = 0;
    FILE *f = fopen(nome,"r");
    while(!feof(f)){
        fscanf(f,"%d",&V[total]);
        total++;
        if(total == N){
            K++;
            sprintf(novo,"Temp%d.txt",K);
            qsort(V,total,sizeof(int),compara);
            salvaArquivo(novo, V, total,0);
            total = 0;
        }
    }

//Uma vez terminado o arquivo, verifica-se se n�o existem ainda dados no buffer (linha 69). Em caso afirmativo, um novo arquivo de dados ordenados � gerado (linhas 29-32). Por fim, a fun��o retorna o n�mero de arquivos ordenados gerados (linha 76).
    if(total > 0){
        K++;
        sprintf(novo,"Temp%d.txt",K);
        qsort(V,total,sizeof(int),compara);
        salvaArquivo(novo, V, total,0);
    }
    fclose(f);
    return K;
}

//Fun��es respons�veis por copiar os dados do arquivo para o buffer//
//Apenas l� T elementos de um arquivo e armazena no respectivo buffer. Caso o arquivo termine antes que se possam leros T elementos, ele � fechado//
void preencheBuffer(struct arquivo* arq, int T){
    int i;
    if(arq->f == NULL)
        return;

    arq->pos = 0;
    arq->MAX = 0;
    for(i=0; i<T; i++){
        if(!feof(arq->f)){
            fscanf(arq->f,"%d",&arq->buffer[arq->MAX]);
            arq->MAX++;
        }else{
            fclose(arq->f);
            arq->f = NULL;
            break;
        }
    }
}

//Percorre todos os buffers de entrada que ainda cont�m dados e os compara para descobrir o �ndice do buffer (idx) cuja posi��o atual(pos) � a menor dentre todos os buffers//
 int procuraMenor(struct arquivo* arq,int K,int T,int* menor){
    int i, idx = -1;
    for(i=0; i<K; i++){
        if(arq[i].pos < arq[i].MAX){
            if(idx == -1)
                idx = i;
            else{
                if(arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos])
                    idx = i;
            }
        }
    }
    if(idx != -1){
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if(arq[idx].pos == arq[idx].MAX)
            preencheBuffer(&arq[idx],T);
        return 1;
    }else
        return 0;

}

//Recebe como par�metros o nome do arquivo a ser salvo com os dados ordenados, o n�mero de arquivos (K) e o tamanho m�ximo de cada buffer (T).
void merge(char *nome, int K, int T){
    char novo[20];

//Cria o buffer de sa�da e os buffers de entrada
	int i;
    int *saida = (int*)malloc(T*sizeof(int));
    struct arquivo* arq;
    arq = (struct arquivo*)malloc(K*sizeof(struct arquivo));
    
// Para cada buffer de entrada � aberto o seu arquivo, alocada mem�ria para o seu buffer e T elementos do arquivo s�o copiados para dentro do buffer, utilizando a fun��o preencheBuffer//
    for(i=0; i < K; i++){
        sprintf(novo,"Temp%d.txt",i+1);
        arq[i].f = fopen(novo,"r");
        arq[i].MAX = 0;
        arq[i].pos = 0;
        arq[i].buffer = (int*)malloc(T*sizeof(int));
        preencheBuffer(&arq[i],T);
    }
    int menor, qtdSaida = 0;
    
//enquanto houver arquivos para processar (linha 148), copiamos esse elemento para o buffer de sa�da (linha 149-150) e, sempre que a quantidade de elementos no buffer de sa�da for igual ao tamanho m�ximo do buffer (T), os dados s�o salvos em arquivo e a quantidade de dados no buffer � zerada (linhas 151-154).
    while(procuraMenor(arq,K,T,&menor) == 1){
        saida[qtdSaida] = menor;
        qtdSaida++;
        if(qtdSaida == T){
            salvaArquivo(nome, saida, T,1);
            qtdSaida= 0;
        }
    }

//verificamos se ainda existem dados no buffer de sa�da e, em caso afirmativo, salvamo-los em arquivo.//
    if(qtdSaida != 0)
        salvaArquivo(nome, saida, qtdSaida,1);

//Por fim, liberamos a memoria associada a cada buffer.//
    for(i=0; i<K; i++)
        free(arq[i].buffer);
    free(arq);
    free(saida);

}

//Fun��o (e char novo) para criar os arquivos ordenados e retornar ao K arquivos gerados//
//Em seguida, a fun��o calcula o tamanho, T, dos K+1 buffers necess�rios para a etapa de merge, apaga o arquivo original e chama a fun��o respons�vel pela etapade intercala��o//
void mergeSortExterno(char *nome){
    char novo[20];
    int K = criArquivosOrdenados(nome);
    int i, T = N / (K + 1);
    printf("Nro de arquivos:%d\n",K);
    printf("K:%d\n",T);

    remove(nome);
    merge(nome,K,T);

    for(i=0; i<K; i++){
        sprintf(novo,"Temp%d.txt",i+1);
        remove(novo);
    }
    printf("Fim!\n");

}

void verificaArquivoOrdenado(char *nome){
    int v1,v2, erro = 0;
    FILE *f = fopen(nome,"r");
    fscanf(f,"%d",&v1);
    while(!feof(f)){
        fscanf(f,"%d",&v2);
        if (v2 < v1){
            erro = 1;
            break;
        }
    }
    fclose(f);
    if(erro)
        printf("Valores fora de ordem!\n");
    else
        printf("Arquivo corretamente ordenado!\n");
}


int main(){
    criArquivoTeste("dados.txt");
    system("pause");
    mergeSortExterno("dados.txt");
    verificaArquivoOrdenado("dados.txt");
    system("pause");
    return 0;
}
