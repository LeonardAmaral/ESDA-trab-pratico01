#include<stdlib.h>
#include <stdio.h>
#include<string.h>

typedef struct {
     int codigo_jogador;
    char nome_jogador[50];
    char apelido[20];
    char drata_in_contrato[20];
    char data_fin_contrato[20];
    int nr_golo;
    int nr_jogador;
    int ativo;	
} jogador;
	
typedef struct {
	 char nome[30];
    int codigo_equipa;
	jogador j[20];
}equipa;
//Funcoes
void menu();
void dadosequipa();
void dadosjogador();
void mostrar_resultado();
void terceiro();
void menu(){
	int opc;
		printf("______________Menu_________________\n");
		do{
		printf("1.Cadastrar equipa\n2.Cadastrar Jogador\n3.Mostrar\n4.Elimanar terceiro jogador\n5.sair\n");
		scanf("%d",&opc);
		    switch(opc){
			case 1:
			dadosequipa();
				break;
			case 2:
			dadosjogador();
				break;
			case 3:
			mostrar_resultado();
			break;
			case 4:
            terceiro();
            break;
			case 5:
				exit(0);
			default:
            printf("opc invalida");
            break;
			}
		
		}while(opc!=0);
	
}
void dadosequipa( equipa *dados){
	int opc;
	 system("cls");
	do{	
	printf("nome: \n");
	scanf("%s",&dados->nome);
	setbuf(stdin,NULL);
	printf("Digite o codigo da equipa:\n");
	scanf("%d",&dados->codigo_equipa);
	printf("1.continuar\n0.sair para voltar ao menu\n");
	}while(opc!=0);
	
	FILE *cria = fopen("recebe.dat","a");
    if(cria!=NULL)
	{
	   	fprintf(cria,"%d %s\n",dados->codigo_equipa,dados->nome);
		//printf("Cadastrado com sucesso.");
	}
	fclose(cria);
}
void dadosjogador(jogador *dadosj){
	int opc;
	do{
		system("cls");
		printf("Digite o numero do jogador:\n");	
		scanf("%d",&dadosj->nr_jogador);	 		 
		printf("Digite o codigo do jogor: \n");
		scanf("%d",&dadosj->codigo_jogador);
		printf("Nome do jogador:\n");
		scanf("%s",&dadosj->nome_jogador);
		setbuf(stdin,NULL);
		printf("Apelido:\n");
		scanf("%s",&dadosj->apelido);
		setbuf(stdin,NULL);
	 	printf("Digite a data de inicio do contrato:\n");
   	    scanf("%s",&dadosj->drata_in_contrato);
		printf("Digite a data do fim do contrato:\n"); 
		scanf("%s",&dadosj->data_fin_contrato);
		printf("Digite numero de golos:\n");
		scanf("%d",&dadosj->nr_golo);
		printf("1.Continuar\n0.sair\n");
		scanf("%d",&opc);
	}while(opc!=0);
	FILE *fich = fopen("recebesegundo.txt","a");
    if(fich!=NULL)
	{
	   	fprintf(fich,"%d %d %s %s %s %s %d \n",dadosj->nr_jogador,dadosj->codigo_jogador,dadosj->nome_jogador,dadosj->apelido,dadosj->data_in_contrato,dadosj->data_fin_contrato,dadosj->nr_golo);
	
	}
	fclose(fich);

}
void mostrar_resultado(equipa *equipa2, jogador *joga){
		char last, seg;
	    FILE *ficheiro;
		ficheiro=fopen("recebe.txt","r");
		printf("nome: \n");
		last = fscanf(ficheiro,"%d %s\n",&equipa2->codigo_equipa,&equipa2->nome); 
		while(last!=EOF)
		{
			printf("%d %s\n",equipa2->codigo_equipa,&equipa2->nome);
			last = fscanf(ficheiro,"%d %s\n",&equipa2->codigo_equipa,&equipa2->nome); 
		}		
		fclose(ficheiro);
		//pagando jogadores
        FILE *segundo_ficheiro;
		segundo_ficheiro=fopen("recebesegundo.txt","r");
		seg = fscanf(segundo_ficheiro," %d %d %s %s %s %s %d \n",&joga->nr_jogador,&joga->codigo_jogador,&joga->nome_jogador,&joga->apelido,&joga->data_in_contrato,&joga->data_fin_contrato,&joga->nr_golo);
		while(seg!=EOF){
			printf("%d %d %s %s %s %s %d \n",&joga->nr_jogador,&joga->codigo_jogador,&joga->nome_jogador,&joga->apelido,&joga->data_in_contrato,&joga->data_fin_contrato,&joga->nr_golo);
			seg=fscanf(segundo_ficheiro,"%d %d %s %s %s %s %d \n",&joga->nr_jogador,&joga->codigo_jogador,&joga->nome_jogador,&joga->apelido,&joga->data_in_contrato,&joga->data_fin_contrato,&joga->nr_golo);
		}
		fclose(segundo_ficheiro);
		
}
void terceiro( jogador *jog){
	for(int i=0; i<jog->codigo_jogador; i++){
	if(jodador[i]==codigo_jogador){
		   printf("%d",&codigo_jogador);	
	}
	}
}

int main(){
		menu();
	   return 0;	
}