#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "lista.h"

void init_locadora(Veiculos* veiculos, Users* users, Locacoes* locacoes){
    int sair = 0;
    while (!sair)
    {
        int ctrl;
        printf("**** BEM VINDO A LOCADORA ****\n\n 1- Cadastrar Veiculo    |  6- Devolver Veiculo \n 2- Listar Veiculo       |  7- Listar Locacoes \n 3- Cadastrar Clientes   |  8- Relatorios \n 4- Listar Clientes      |  9- Sair \n 5- Realizar Locacao     |\n");
        scanf ("%d", &ctrl);

        switch (ctrl){
            case 1:
                veiculos = cadastrar_veiculo(veiculos);
                break;
            case 2:
                imprimir_lista_veiculos(veiculos);
                break;
            case 3:
                users = cadastrar_user(users);
                break;
            case 4:
                imprimir_lista_user(users);
                break;
            case 5:
                locacoes = realizar_locacao(locacoes, users, veiculos);
                break;
            case 6:
                locacoes = devolve_locacao(locacoes, veiculos, users);
                break;
            case 7:
                imprimir_lista_locacoes(locacoes);
                break;
            case 8:
                relatorios(locacoes, users, veiculos);
                break;
            case 9:
                sair = 1;
                break;
            default:
                printf("Opcao invalida \n");
        }
    }
}

int main(){
    Veiculos* veiculos=NULL;
    Users* users=NULL;
    Locacoes* locacoes=NULL;
    init_locadora(veiculos, users, locacoes);
}

