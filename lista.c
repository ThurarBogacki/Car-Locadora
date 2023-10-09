
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "data.h"


/* Funções listas users*/


Users* inserir_users(Users* lista, char nome[], int cnh, char telefone[]){
    Users *no_um; 
    no_um = (Users*)malloc(sizeof(Users));
    strncpy(no_um->nome, nome, sizeof(no_um->nome) - 1);
    no_um->nome[sizeof(no_um->nome) - 1] = '\0';
    no_um->cnh=cnh;
    strncpy(no_um->telefone, telefone, sizeof(no_um->telefone) - 1);
    no_um->telefone[sizeof(no_um->telefone) - 1] = '\0';
    no_um->prox = lista;
    return no_um;
}

Veiculos* inicializa_zerado(Veiculos* maior){
    Veiculos *no_um; 
    no_um = (Veiculos*)malloc(sizeof(Veiculos));
    no_um->km = 0;
    return no_um;
}


/*Funçoes listas veiculos*/


Veiculos* inserir_veiculos(Veiculos* lista, char modelo[], char placa[], int km, int ano, float diaria){
    Veiculos *no_um; 
    no_um = (Veiculos*)malloc(sizeof(Veiculos));
    strncpy(no_um->modelo, modelo, sizeof(no_um->modelo) - 1);
    no_um->modelo[sizeof(no_um->modelo) - 1] = '\0';
    no_um->ano=ano;
    no_um->km=km;
    no_um->diaria=diaria;
    no_um->locado=0;
    strncpy(no_um->placa, placa, sizeof(no_um->placa) - 1);
    no_um->placa[sizeof(no_um->placa) - 1] = '\0';
    no_um->prox = lista;
    return no_um;
}


Locacoes* adiciona_locacao(Locacoes* lista, char usuario[], char modelo[], int valor_pago, Date data1, Date data2, int cnh){
    Locacoes *no_um; 
    no_um = (Locacoes*)malloc(sizeof(Locacoes));
    strncpy(no_um->carro, modelo, sizeof(no_um->carro) - 1);
    no_um->carro[sizeof(no_um->carro) - 1] = '\0';
    strncpy(no_um->user, usuario, sizeof(no_um->user) - 1);
    no_um->user[sizeof(no_um->user) - 1] = '\0';
    no_um->cnh = cnh;
    no_um->data1 = data1;
    no_um->data2 = data2;
    no_um->ativa = true;
    no_um->valor = valor_pago;
    no_um->prox = lista;
    return no_um;
}

