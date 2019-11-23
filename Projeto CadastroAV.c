#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int codigo;
void menu_cliente();
void menu_loja();
void cadastrar_cliente();
void cadastrar_produto();
void listar_produto();
void listar_cliente();
int Login();
void comprar_produto();
int Pesquisar_jogo_codigo(int codigo);
int Pesquisar_cliente_usuario(int usuario);
void remover_produto();
void Emoldurar(char string[]);

struct produto{
	int ano;
	char descricao[MAX];
	int valor;
	char genero[MAX];
	int code;
};
typedef struct produto Produto;

struct cliente{
	char nome[MAX];
	int senha;
	char endereco[MAX];
	int saldo;
	int usuario;
};
typedef struct cliente Clientes;

int main(){
	
	int escolha, menu, Ncliente;
	FILE *arq;
	
	
	do {
		system("cls");
	    Emoldurar("Loja Games");
		Emoldurar("1 - Menu de Clientes");
		Emoldurar("2 - Menu de Gerente");
		Emoldurar("3 - Sair");
		printf("\nInforme a sua Escolha:\n");
		scanf("%i", &escolha);
		
		switch(escolha){
			case 1:{
				menu_cliente();
				break;
			}
			
			case 2:{
				menu_loja();
				break;
			}
			
			case 3:{
				menu = 3;
				break;
			}
				
		}
		
	} while(menu != 3);
	
}


void Emoldurar(char string[]){
	
	int i, tamanho;
	tamanho=strlen(string);
	for(i=0;i<(59-tamanho/2);i++){
		printf(" ");
	}
	printf("\xC9");
	for(i=0;i<tamanho;i++){
		printf("\xCD");
	}
	printf("\xBB\n");
	for(i=0;i<(59-tamanho/2);i++){
		printf(" ");
	}
	printf("\xBA%s\xBA\n", string);
	for(i=0;i<(59-tamanho/2);i++){
		printf(" ");
	}
	printf("\xC8");
	for(i=0;i<tamanho;i++){
		printf("\xCD");
	}
	printf("\xBC\n");
	
}

void menu_cliente(){
	
	int esc;
	
	system("cls");
	
	Emoldurar("1 - Cadastrar");
	Emoldurar("2 - login");
	scanf("%i", &esc);
	
	
	if(esc == 1){
		cadastrar_cliente();
		
	}else if(esc == 2){
		Login();
	}
}

void cadastrar_cliente(){

int i, tam, j, pse;
	char aux[7];
	Clientes x, y[100];
	FILE* arq;
	arq = fopen("Clientes.txt","a+");
	if(arq==NULL){
		system("cls");
		printf("Erro ao abrir o arquivo.\n\n");
		system("pause");
	}else{
		system("cls");
		tam = fread(&y[0],sizeof(Clientes),100,arq);
	}
	fclose(arq);
	arq = fopen("Clientes.txt","a+");
	system("cls");
	if(arq==NULL){
		printf("Erro ao abrir o arquivo.\n\n");
		system("pause");
	}else{
		Emoldurar("Cadastro Cliente");
		printf("\n");
		printf("Nome: ");
		fflush(stdin);
		gets(x.nome);
		strupr(x.nome);
		printf("Usuario: ");
		fflush(stdin);
		scanf("%i", &x.usuario);
		printf("Endereco: ");
		fflush(stdin);
		gets(x.endereco);
		strupr(x.endereco);
		printf("Saldo: ");
		fflush(stdin);
		scanf("%i", &x.saldo);
		printf("Senha: ");
		fflush(stdin);
		scanf("%i", &x.senha);
		//printf("Informe quantos jogos serao adicionados ao estoque: ");
		//fflush(stdin);
		//scanf("%d", &x.estoque);
		if(fwrite(&x,sizeof(Clientes),1,arq) == NULL){
			system("cls");
			printf("Erro ao salvar informacoes.\n\n");
			system("pause");
		}
	}
	fclose(arq);
	
}

void cadastrar_produto(){
	
	int i, tam, j, pse;
	char aux[7];
	Produto x, y[100];
	FILE* arq;
	arq = fopen("Games.txt","a+");
	if(arq==NULL){
		system("cls");
		printf("Erro ao abrir o arquivo.\n\n");
		system("pause");
	}else{
		system("cls");
		tam = fread(&y[0],sizeof(Produto),100,arq);
	}
	fclose(arq);
	arq = fopen("Games.txt","a+");
	system("cls");
	if(arq==NULL){
		printf("Erro ao abrir o arquivo.\n\n");
		system("pause");
	}else{
		Emoldurar("Cadastro de Games");
		printf("\n");
		printf("Informe o Genero do jogo: ");
		fflush(stdin);
		gets(x.genero);
		strupr(x.genero);
		printf("Informe o nome do Jogo: ");
		fflush(stdin);
		gets(x.descricao);
		strupr(x.descricao);
		
		x.code = codigo;
		printf("Codigo do jogo: %i\n ",x.code);
		codigo++;
		printf("Informe o ano de lançamento do Jogo: ");
		fflush(stdin);
		scanf("%i", &x.ano);
		printf("Informe o valor do Jogo: ");
		fflush(stdin);
		scanf("%i", &x.valor);
		if(fwrite(&x,sizeof(Produto),1,arq) == NULL){
			system("cls");
			printf("Erro ao salvar informacoes.\n\n");
			system("pause");
		}
	}
	fclose(arq);
	
}

void menu_loja(){
	int esc, menu = 1, senha;
	system("cls");
	Emoldurar("Menu Loja");
	printf("\n");
	printf("Senha:");
	fflush(stdin);
	scanf("%i", &senha);
	
	if(senha != 123456){
		system("cls");
		Emoldurar("Senha incorreta");
		system("pause");
	}else{
	
	do{
		system("cls");
		Emoldurar("1 - Cadastrar Jogos");
		Emoldurar("2 - Listar Jogos");
		Emoldurar("3 - Listar Clientes");
		Emoldurar("4 - Remover Jogos do estoque");
		Emoldurar("5 - Sair do menu de loja");
		printf("\n\n Escolha:");
		fflush(stdin);
		scanf("%i", &esc);
	
		if(esc == 1){
			cadastrar_produto();
		
		}else if(esc == 2){
			listar_produto();
		
		}else if(esc == 3){
			listar_cliente();
		}else if(esc == 5){
			menu++;
			break;
		}else if(esc == 4){
			remover_produto();
		}
	
	
	
	}while(menu = 1);	
}
}

void listar_produto(){
	
	int tam, i;
	Produto x[100];
	FILE* arq;
	arq = fopen("Games.txt","r");
	if(arq==NULL){
		system("cls");
		printf("Erro ao abrir o arquivo Games.\n\n");
		system("pause");
	}else{
		system("cls");
		tam = fread(&x[0],sizeof(Produto),100,arq);
	}
	fclose(arq);
	Emoldurar("Jogos");
	for(i=0;i<tam;i++){
		printf("Genero: %s\n", x[i].genero);
		printf("Nome: %s\n", x[i].descricao);
		printf("Ano: %i\n", x[i].ano);
		printf("Valor: %i\n", x[i].valor);
		printf("Codigo: %i\n\n", x[i].code);
	}
	system("pause");
	
}

void listar_cliente(){
	
	int tam, i;
	Clientes x[100];
	FILE* arq;
	arq = fopen("Clientes.txt","r");
	if(arq==NULL){
		system("cls");
		printf("Erro ao abrir o arquivo Games.\n\n");
		system("pause");
	}else{
		system("cls");
		tam = fread(&x[0],sizeof(Clientes),100,arq);
	}
	fclose(arq);
	Emoldurar("Clientes");
	for(i=0;i<tam;i++){
		printf("Nome: %s\n", x[i].nome);
		printf("Usuario: %i\n", x[i].usuario);
		printf("Endereco: %s\n", x[i].endereco);
		printf("Saldo: %i\n", x[i].saldo);
		printf("Senha: %i\n\n", x[i].senha);
	}
	system("pause");
		
}

void remover_produto(){
	
	int i, tam, j, aux, index;
	Produto  y[100];
	FILE* arq;
	arq = fopen("Games.txt","r+");
	if(arq==NULL){
		system("cls");
		printf("Erro ao abrir o arquivo .\n\n");
		system("pause");
	}else{
		system("cls");
		tam = fread(&y[0],sizeof(Produto),100,arq);
	}
	fclose(arq);
	do{
		system("cls");
		Emoldurar("Remover Produtos");
		printf("\n");
		printf("Informe o codigo do produto: ");
		scanf("%d", &aux);
		index=Pesquisar_jogo_codigo(aux);
		if(index==-1){
			system("cls");
			printf("Usuario inexistente, por favor informe um usuario valido.\n\n");
			system("pause");
		}
	}while(index==-1);
	arq = fopen("Games.txt","w");
	if(arq==NULL){
		system("cls");
		printf("Erro ao abrir o arquivo.\n\n");
		system("pause");
	}else{
		for(i=0;i<tam;i++){
			if(i!=index){
				if(fwrite(&y[i],sizeof(Produto),1,arq) == NULL){
					system("cls");
					printf("Erro ao salvar informacoes.\n\n");
					system("pause");
				}
			}
		}
	}
	fclose(arq);
	system("cls");
	printf("Jogo retirado com sucesso.\n\n");
	sleep(2);
	
}

int Pesquisar_jogo_codigo(int codigo){
	
	int tam, i;
	Produto x[100];
	FILE* arq;
	arq = fopen("Games.txt","r");
	if(arq==NULL){
		system("cls");
		printf("Erro ao abrir o arquivo.\n\n");
		system("pause");
	}else{
		tam = fread(&x[0],sizeof(Produto),100,arq);
	}
	fclose(arq);
	for(i=0;i<tam;i++){
		if(x[i].code==codigo){
			return i;
		}
	}
	return -1;
	
}

int Login(){
	
	int usuario, senha, i=3, j, tam, cod2, index, index2, auxiliar, menu = 1;
	char escj;
	char aux[7];
	Clientes x[100];
	FILE* arq;
	do{
		system("cls");
		Emoldurar("Login");
		printf("Usuario: ");
		scanf("%d", &usuario);
		printf("Senha: ");
		scanf("%i", &senha);
	
			arq = fopen("Clientes.txt","r");
			if(arq==NULL){
				system("cls");
				printf("Erro ao abrir o arquivo .\n\n");
				system("pause");
			}else{
				tam = fread(&x[0],sizeof(Clientes),100,arq);
			}
			fclose(arq);
			index = Pesquisar_cliente_usuario(usuario);
			if(index==-1){
				system("cls");
				printf("Usuario nao encontrado ou inexistente.\nInfome um usuario valido.\n\n");
				system("pause");
				i--;
			}else{
				auxiliar = x[index].senha;
				if(senha!=auxiliar){
					system("cls");
					printf("Senha invalida!\nVoce tem %d tentativas ate que o programa seja finalizado.\n\n", i-1);
					system("pause");
					i--;
				}else{
					system("cls");
					printf("Bem vindo, %s.", x[index].nome);
					sleep(2);
					do{
						
						system("cls");
						Emoldurar("1 - listar Jogos");
						Emoldurar("2 - Pesquisar Jogos");
						Emoldurar("3 - Comprar Jogos");
						Emoldurar("4 - Sair");
					
						int escolha;
						printf("\n\nEscolha: ");
						scanf("%i", &escolha);
					
						if(escolha == 1){
							listar_produto();
						}else if(escolha == 2){
							
							int cod, cod2;
							printf("\nInforme o codigo do jogo que voce procura: ");
							fflush(stdin);
							scanf("%i", &cod);
							
							int taman;
							Produto z[100];
							FILE* arqs;
							arqs = fopen("Games.txt","r");
							if(arqs==NULL){
								system("cls");
								printf("Erro ao abrir o arquivo.\n\n");
								system("pause");
							}else{
								system("cls");
								taman = fread(&z[0],sizeof(Produto),100,arq);
							}
							fclose(arqs);
							Emoldurar("Jogos");
							printf("Genero: %s\n", z[cod].genero);
							printf("Nome: %s\n", z[cod].descricao);
							printf("Ano: %i\n", z[cod].ano);
							printf("Valor: %i\n", z[cod].valor);
							printf("Codigo: %i\n\n", z[cod].code);
							system("pause");
							
							}else if(escolha == 3){
								comprar_jogos();
							}else if(escolha == 4){
								menu++;
								i = -1;
							}
			}while(menu == 1);
	}
	}
	}while(i>0);
	system("cls");
	return -2;
    //fclose(arq);

}

int Pesquisar_cliente_usuario(int usuario){
	
	int tam, i;
	Clientes x[100];
	FILE* arq;
	arq = fopen("Clientes.txt","r");
	if(arq==NULL){
		system("cls");
		printf("Erro ao abrir o arquivo.\n\n");
		system("pause");
	}else{
		tam = fread(&x[0],sizeof(Clientes),100,arq);
	}
	fclose(arq);
	for(i=0;i<tam;i++){
		if(x[i].usuario==usuario){
			return i;
		}
	}
	return -1;
	
}

void comprar_jogos(){
	
	listar_produto();
	int i, tam, tamanho, j, aux, index, us;
	Produto  y[100];
	FILE* arq;
	arq = fopen("Games.txt","r+");
	Clientes x[100];
	FILE* arqc;
	if(arq==NULL){
		system("cls");
		printf("Erro ao abrir o arquivo.\n\n");
		system("pause");
	}else{
		system("cls");
		tam = fread(&y[0],sizeof(Produto),100,arq);
	}
	fclose(arq);
	
	Emoldurar("Comprar Jogos");
	printf("Informe seu usuario para compra:");
	fflush(stdin);
	scanf("%i", &us);
	us--;
	
	arqc = fopen("Clientes.txt","a+");
	tamanho = fread(&x[0],sizeof(Clientes),100,arqc);
	system("cls");
	Emoldurar("Comprar Jogos");
	printf("O saldo da sua conta e de: %i", x[us].saldo);
	getch();
	do{
		system("cls");
		Emoldurar("Comprar Jogos");
		printf("\n");
		printf("");
		printf("Informe o codigo do produto: ");
		scanf("%d", &aux);
		index=Pesquisar_jogo_codigo(aux);
		if(index==-1){
			system("cls");
			printf("Codigo inexistente, por favor informe um Cdigo valido.\n\n");
			system("pause");
		}
	}while(index==-1);
	if(x[us].saldo < y[aux].valor){
		printf("\nVoce nao possui saldo suficiente");
		getch();
	}else{
	arq = fopen("Games.txt","w");
	if(x[us].saldo <= y[aux].valor){
		for(i=0;i<tam;i++){
			if(i!=index){
				if(fwrite(&y[i],sizeof(Produto),1,arq) == NULL){
					system("cls");
					printf("Erro ao salvar informacoes no arquivo\n\n");
					system("pause");
				}
			}
		}
	}
	x[us].saldo = x[us].saldo - y[aux].valor;
	fclose(arqc);
	fclose(arq);
	system("cls");
	Emoldurar("Comprar Jogos");
	printf("Jogo comprado com sucesso.\n\n");
	sleep(2);}
}
