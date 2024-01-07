#ifndef __DAMA_H
#define __DAMA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#define TAM 25
#define MAX 50

typedef struct Data{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct Carro{
    char marca[TAM];
    char placa[TAM];
    char cor[TAM];
    char modelo[TAM];
    char ano[TAM];
    int identificador;
    bool alugado;   //inicializa com false;
}Carro;

//typedef struct locacao *Apontador;
typedef struct Locacao{
    char nome[MAX];
    Data data;
    Carro carros[MAX]; //lista de carros
    int quantidade; //quantidade de carros
    //Apontador prox;
}Locacao;

// typedef struct {
// 	Apontador ultimo,primeiro;
// } TIPO_LOCACAO;

//int pt*;
//pt = (struct pessoa*) calloc(50,sizeof(estruct pessoa))
//(struct pessoa*) malloc(50,sizeof(estruct pessoa))
//calloc inicializa com 0 e null
//malloc só reserva o espaço na memoria

int ler_arquivo(FILE *arquivo, Carro *carros);
void menu();
Locacao criar_locacao(Locacao *locacao, Carro *carros, int qtd_carros, int qtd);
void pesquisar_carro(Carro *Lista_carros, int tam);
void imprimi_carro(Carro carro);
void listar_todos_carros(Carro *carros, int qtd_carros);
void listar_carros_disponiveis(Carro *carros, int qtd_carros);
void visualizar_locacao(Locacao *locacao, int qtd_locacao);
int insere_alocacao(Locacao *locacao, char *marca, char *placa, char *cor, char *modelo , char *ano, int id);
void remover(Locacao *locacao,Carro *carros, int qtd_locacao);
#endif /* __DAMA_H */