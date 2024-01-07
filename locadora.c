#include "locadora.h"

int ler_arquivo(FILE *arquivo, Carro *carros){
    
    int qtd_linhas;
    fscanf(arquivo, "%d", &qtd_linhas);
    //printf("linhas: %d\n", qtd_linhas);
    for(int i = 0; i< qtd_linhas; i++){
        fscanf(arquivo, "%d %s %s %s %s %s", &carros[i].identificador, carros[i].marca, carros[i].placa, carros[i].cor, carros[i].modelo, carros[i].ano);
        carros[i].alugado = false;
        //printf("%d %s %s %s %s %d \n",carros[i].identificador, carros[i].marca, carros[i].placa, carros[i].cor, carros[i].modelo, carros[i].ano);

    }
    return qtd_linhas;
}

void menu(){
    int op;
    int qtd_carros, qtd_locacao = 0;
    Carro carros[MAX];
    Locacao locacao[MAX];
    FILE *arquivo;
    arquivo = fopen("entrada.txt","r");
    qtd_carros = ler_arquivo(arquivo, carros);
    locacao->quantidade = 0;
    /*Preciso da lista de carrros no arquivo de entrada seja passada para o vetor de carros*/
    bool rodar = true; 
    while(rodar){
        printf("SEJA BEM VIDO\n");
        printf("Digite sua opção:\n");
        printf("1- Criar uma locacao\n");
        printf("2- Pesquisar Carro\n");
        printf("3- Visualizar locacao\n");
        printf("4- Remover locacao\n");
        printf("5- Sair do Programa\n");
        scanf("%d",&op);
        switch (op){
            case 1: 
                locacao[qtd_locacao] = criar_locacao(locacao, carros, qtd_carros, qtd_locacao); 
                qtd_locacao++; 
                break;
            case 2: pesquisar_carro(carros, qtd_carros); break;
            case 3: visualizar_locacao(locacao, qtd_locacao); break;
            case 4: remover(locacao, carros, qtd_locacao); break;
            case 5: break;
            default: printf("Erro, opcao invalida\n"); break; 
        }
        // system("clear||cls");
        if(op == 5){rodar = false;}
    }
}
Locacao criar_locacao(Locacao *locacao, Carro *carros, int qtd_carros, int qtd){
    char nome[MAX];
    Data data;
    int id ;
    int quantidade;
    printf("Nome do cliente: ");
    fscanf(stdin,"%s", nome);
    printf("Data da locacao: ");
    scanf("%d%d%d",&data.dia, &data.mes, &data.ano);
    printf("Quantidade de carros: ");
    scanf("%d",&quantidade);
    printf("Listar de carros disponiveis\n\n");
    for(int i = 0; i < quantidade; i++){
        printf("Selecione o carros desejado pelo seu indentificador: \n");
        listar_carros_disponiveis(carros, qtd_carros);
        fscanf(stdin,"%d", &id);

		strcpy(locacao[qtd].carros[i].marca, carros[id].marca);
        strcpy(locacao[qtd].carros[i].placa, carros[id].placa);
        strcpy(locacao[qtd].carros[i].cor, carros[id].cor);
        strcpy(locacao[qtd].carros[i].modelo, carros[id].modelo);
        strcpy(locacao[qtd].carros[i].ano, carros[id].ano);
        locacao[qtd].carros[i].identificador = id;
        carros[id].alugado = true;
        locacao[qtd].carros[i].alugado = true; 
    }
    locacao[qtd].quantidade = quantidade;
    strcpy(locacao[qtd].nome, nome);
    locacao[qtd].data = data;
    return locacao[qtd]; 
}
void pesquisar_carro(Carro *carros, int qtd_carros){
    char caracteristica[TAM];
    bool encontrado = false;
    printf("Digite uma caracteristica uma caracteristica: \n");
    fscanf(stdin,"%s", caracteristica);
    for(int i = 0; i < qtd_carros; i++){
        if(strcmp(carros[i].marca, caracteristica) == 0){
            imprimi_carro(carros[i]);
            encontrado = true;
        }
        else if(strcmp(carros[i].placa, caracteristica) == 0){
            imprimi_carro(carros[i]);
            encontrado = true;
        }
        else if(strcmp(carros[i].cor, caracteristica) == 0){
            imprimi_carro(carros[i]);
            encontrado = true;
        }
        else if(strcmp(carros[i].modelo, caracteristica) ==0){
            imprimi_carro(carros[i]);
            encontrado = true;
        }
        else if(strcmp(carros[i].ano, caracteristica) == 0){
            imprimi_carro(carros[i]);
            encontrado = true;
        }
    }
    if(encontrado == false){
        printf("Caracteristica nao encontrada\n");
    }
}

//imprimi a lista de carros.
void listar_todos_carros(Carro *carros, int qtd_carros){
    for(int i = 0; i < qtd_carros; i++){
        imprimi_carro(carros[i]);
    }
}
void listar_carros_disponiveis(Carro *carros, int qtd_carros){
    for(int i = 0; i < qtd_carros; i++){
        if(carros[i].alugado == false){
            imprimi_carro(carros[i]);
        }
    }
}
void imprimi_carro(Carro carro){
    printf("%d %s %s ",carro.identificador, carro.marca, carro.placa);
    printf("%s %s %s \n", carro.cor, carro.modelo, carro.ano);
}
void visualizar_locacao(Locacao *locacao, int qtd_locacao){
    for(int i = 0; i < qtd_locacao;i++){
        printf("%s ",locacao[i].nome);
        printf(" %d/%d/%d", locacao[i].data.dia, locacao[i].data.mes, locacao[i].data.ano);
        printf(" %d  ", locacao[i].quantidade);
        for(int j = 0; j < locacao[i].quantidade; j++ ){
            if(locacao[i].carros[j].alugado == true){
                imprimi_carro(locacao[i].carros[j]);
            }
        }
        printf("\n");
    }
    
}
void remover(Locacao *locacao,Carro *carros, int qtd_locacao){
    int id;
    char nome[TAM];
    printf("Digite seu nome:");
    fscanf(stdin,"%s", nome);
   
    for(int i = 0; i < qtd_locacao;i++){
        if (strcmp(locacao[i].nome, nome) == 0){
            listar_todos_carros(locacao[i].carros, locacao[i].quantidade);
            printf("Digite o Id do carro que deseja remover.");
            scanf("%d",&id);
            for(int j = 0; j < locacao[i].quantidade; j++){
                if(id == locacao[i].carros[j].identificador){
                    locacao[i].carros[j].alugado = false;
                    carros[id].alugado = false;  
                }
            }
        }
    }
}

