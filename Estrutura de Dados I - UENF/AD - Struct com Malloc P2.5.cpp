/* programa_memoria 0.3c */

#include <stdio.h>
#include <stdlib.h>

struct ST_DADOS {
	char nome[40];
	float salario;
	
	
	struct nascimento{ 											/* estrutura dentro de uma estrutura */
		int ano;
		int mes;
		int dia;
	} dt_nascimento;
};

int main(void){
	
	struct ST_DADOS *p; 										/* ponteiro para a estrutura */
	p= (struct ST_DADOS*)malloc(sizeof(struct ST_DADOS));		/* alocação de memória para o ponteiro de estrutura (completa diferente do dado no exercício anterior) */
	printf(" \n Entre com o nome -> ");
	scanf("%s", p -> nome);
	
	printf("Entre com o salario ->");
	scanf("%f", &p -> salario);
	
	printf(" Entre com o nascimento ->");
	scanf("%d%d%d", &p -> dt_nascimento.dia,
					&p -> dt_nascimento.mes,
					&p -> dt_nascimento.ano);
					
					
	printf(" \n ==== Dados Digitados ====");
	printf("\n Nome = %s", p -> nome);
	printf("\n Salario = %f", p -> salario);
	printf(" \n Nascimento = %d/%d/%d\n", p -> dt_nascimento.dia,
										  p -> dt_nascimento.mes,
										  p -> dt_nascimento.ano);
										  
	free (p);									  
}
