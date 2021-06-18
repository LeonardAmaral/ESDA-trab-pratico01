#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include <time.h>
#define max_nr_jogador 4




typedef struct{
    int codigo_jogador;
    char nome_jogador[30];
    char apelido[20];
    char data_in_contrato[20];
    char data_fin_contrato[20];
    int nr_golo;
    int nr_jogador;
    int ativo;
}jogador;
typedef struct{
    char nome[30];
    int codigo_equipa;
	jogador j[20]; 
}equipa;
//prototipo das minhas funcoes
void menu01();
void cadastrar_equipa();
void cadastrar_jogador();
void mostrar_resultado();
void menu01(){
    int opc;
    system("cls");
    do{
        printf("\n1.Cadastrar equipas\n2.Cadatrar jogor\n3.Mostrar resultado\n4.Fechar o programa\n");
        scanf("%d",&opc);
        switch(opc){
        case 1:
            cadastrar_equipa();
            break;
        case 2:
            cadastrar_jogador();
            break;
        case 3:
        	mostrar_resultado();
        	break;
        case 4:
        	exit(0);
            default:
            printf("opc invalida");
            break;
            }
    }while(opc!=0);
}
void cadastrar_equipa(equipa dados1){
    int opc;
    system("cls");
    do{
     printf("Digite o nome da equipa:\n");
     scanf("%s",&dados1.nome);
     setbuf(stdin,NULL);
    printf("Digite o codigo da equipa:\n");
    scanf("%d",&dados1.codigo_equipa);
    printf("1.continuar\n0.sair para voltar ao menu\n");
    scanf("%d",&opc);
    }while(opc!=0);
    FILE *file = fopen("recebe.dat","a");
    if(file!=NULL)
	{
	   	fprintf(file,"%d %s\n",dados1.codigo_equipa,dados1.nome);
		printf("Cadastrado com sucesso.");
	}
	fclose(file);
}
void cadastrar_jogador(jogador dados){
    	char nome_jogador[40];
    	char apelido[40];
		int opc,i;
    	system("cls");
		
		do{
		system("cls");
		printf("Digite o numero do jogador:\n");	
		 for(i=0; i<2; i++){
			scanf("%d",&dados.nr_jogador);	 		 
		printf("Digite o codigo do jogor: \n");
		scanf("%d",&dados.codigo_jogador);
		printf("Nome do jogador:\n");
		scanf("%s",&nome_jogador);
		setbuf(stdin,NULL);
		printf("Apelido:\n");
		scanf("%s",&apelido);
		setbuf(stdin,NULL);
	 	printf("Digite a data de inicio do contrato:\n");
		scanf("%s",&dados.data_in_contrato);
		printf("Digite a data do fim do contrato:\n"); 
		scanf("%s",&dados.data_fin_contrato);
		printf("Digite numero de golos:\n");
		scanf("%d",&dados.nr_golo);
		}
		printf("1.Continuar\n0.sair\n");
		scanf("%d",&opc);
		}while(opc!=0);
}
void mostrar_resultado(){
		char last;
		equipa equipa2;
	    FILE *ficheiro;
		ficheiro=fopen("recebe.dat","r");

		printf("nome: \n");
		last = fscanf(ficheiro,"%d %s\n",&equipa2.codigo_equipa,equipa2.nome); // 
		while(last!=EOF)
		{
			printf("%d %s\n",equipa2.codigo_equipa,equipa2.nome);
			last = fscanf(ficheiro,"%d %s\n",&equipa2.codigo_equipa,equipa2.nome); // 
		}		
		fclose(ficheiro);
}
//metodo principal
int main(){

     menu01();

    return 0;
}
