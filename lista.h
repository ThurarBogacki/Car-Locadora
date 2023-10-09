#include <stdbool.h>
#ifndef FUNC
#define FUNC

struct lst_veiculo{
    char modelo[25];
    char placa[7];
    int ano;
    int km;
    float diaria;
    bool locado;
    struct lst_veiculo* prox;
};
typedef struct lst_veiculo Veiculos;

struct lst_user{
    char nome[25];
    int cnh;
    char telefone[15];
    struct lst_user* prox;
};
typedef struct lst_user Users;

struct date{
    int day;
    int month;
    int year;
}; typedef struct date Date;

struct locacoes{
    char user[25];
    char carro[25];
    float valor;
    int cnh;
    Date data1;
    Date data2;
    bool ativa; 
    struct locacoes* prox;
};typedef struct locacoes Locacoes;


/*Funções listas da struct Users*/
Users* inserir_users(Users* lista, char nome[], int cnh, char telefone[]);

/*Funçoes listas da struct Veiculos*/
Veiculos* inserir_veiculos(Veiculos* lista, char modelo[], char placa[], int ano, int km, float diaria);

Locacoes* adiciona_locacao(Locacoes* locacoes, char usuario[], char modelo[], int valor_pago, Date data1, Date data2, int cnh);

Veiculos* inicializa_zerado(Veiculos* maior);


#endif