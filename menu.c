#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "data.h"
#include "lista.h"

Veiculos* cadastrar_veiculo(Veiculos* veiculos){
    int ano, km; 
    float diaria;
    char placa[6];
    char modelo[25];
    printf("\n Digite o modelo do veiculo: ");
    scanf("%s", modelo);
    printf("\n Digite a placa do veiculo: ");
    scanf("%s", placa);
    printf("\n Digite a quantia de km do veiculo: ");
    scanf("%d", &km);
    printf("\n Digite o ano do veiculo: ");
    scanf("%d", &ano);
    printf("\n Digite o valor da diaria: ");
    scanf("%f", &diaria);
    veiculos = inserir_veiculos(veiculos, modelo, placa, km, ano, diaria);
    return veiculos;
}


void imprimir_lista_veiculos(Veiculos* veiculos) {
        for (Veiculos* p = veiculos; p != NULL; p = p->prox){
        printf("\n-------------------------------------------------\n");
        printf("Modelo: %s\n", p->modelo);
        printf("Placa: %s\n", p->placa);
        printf("Quilometragem: %dKM\n", p->km);
        printf("Ano: %d\n", p->ano);
        printf("Diaria: R$%.2f\n\n", p->diaria);
    }     
}

Users* cadastrar_user(Users* users){
    int cnh; 
    char telefone[15];
    char nome[25];
    printf("\n Digite o nome do usuario: ");
    scanf("%s", nome);
    printf("\n Digite o telefone: ");
    scanf("%s", telefone);
    printf("\n Digite a cnh: ");
    scanf("%d", &cnh);
    users = inserir_users(users, nome, cnh, telefone);
    return users;
}

void imprimir_lista_user(Users* users) {
        for (Users* p = users; p != NULL; p = p->prox){
        printf("\n-------------------------------------------------\n");
        printf("Nome: %s\n", p->nome);
        printf("Telefone: %s\n", p->telefone);
        printf("CNH: %d\n\n", p->cnh);
    }     
}

int procura_user(Users* users, char usuario[]){
    Users* p;
    int achou;
    for(p=users; p!=NULL; p=p->prox){
        achou = strcmp(p->nome, usuario);
    }
    return achou;
}

Veiculos* procura_carro(Veiculos* veiculos, char carro[]){
    Veiculos* p;
    for(p=veiculos; p!=NULL; p=p->prox){
        if(strcmp(p->modelo, carro)){
            return p;
            break;
        }
    }
    return NULL;
}

int usuario_existe(Users* users, char usuario[]){
    Users* p;
    int achou = 1;
    for(p=users; p!=NULL; p=p->prox){
        achou = strcmp(usuario, p->nome);
        if(!achou){
            return achou;
        }
    }
    return achou;
}

int carro_existe(Veiculos* veiculos, char carro[]){
    Veiculos* p;
    int achou = 1;
    for(p=veiculos; p!=NULL; p=p->prox){
        achou = strcmp(carro, p->modelo);
        if(!achou){
                return achou;
        }
    }
    return achou;
}

Veiculos* carro_locado(Veiculos* veiculo, char carro[], Veiculos* ponteiro_locado){
    Veiculos* p;
    int achou;
    for(p=veiculo; p!=NULL; p=p->prox){
        achou = strcmp(carro, p->modelo);
        if(!achou){
            ponteiro_locado = p;
            return ponteiro_locado;
        }
    }
    return NULL;
}

int cnh_existe(Users* users, int cnh, char usuario[]){
    Users* p;
    for(p=users; p!=NULL; p=p->prox){
        if(p->cnh == cnh && !strcmp(p->nome, usuario)){
            return 1;
        }
    }
    return 0;
}
Locacoes* realizar_locacao(Locacoes* locacoes, Users* users, Veiculos* veiculos){
    Date data1, data2;
    char usuario[25], carro[25];
    int total_pago, dias_locados, cnh;
    Veiculos* ponteiro_locado = NULL;
    printf("Qual usuario deseja locar? ");
    scanf("%s", usuario);
    if(!usuario_existe(users, usuario)){
        printf("Qual a CNH? ");
        scanf("%d", &cnh);
        if(cnh_existe(users, cnh, usuario)){
            printf("Qual carro deseja locar? ");
            scanf("%s", carro);
            if(!carro_existe(veiculos, carro)){
                printf("Dia da retirada DD/MM/AAAA: ");
                scanf("%d %d %d", &data1.day, &data1.month, &data1.year);
                printf("Dia da devolucao DD/MM/AAAA: ");
                scanf("%d %d %d", &data2.day, &data2.month, &data2.year);
                dias_locados = daysBetweenDates(data1, data2)+1;
                if(dias_locados > 0){
                    ponteiro_locado = carro_locado(veiculos, carro, ponteiro_locado);
                    if(ponteiro_locado->locado){
                        printf("Este carro ja esta locado \n");
                    }else{
                        ponteiro_locado->locado = true;
                        total_pago = dias_locados*ponteiro_locado->diaria;
                        locacoes = adiciona_locacao(locacoes, usuario, carro, total_pago, data1, data2, cnh); 
                        printf("CARRO LOCADO COM SUCESSO \n");
                    }        
                }
            }else{
                printf("Carro nao achado\n");
            }
        }else{
            printf("Nao foi achado esse usuario com essa CNH");
        }
    }else{
        printf("Usuario nao achado\n");
    }
    return locacoes;
}

void imprimir_lista_locacoes(Locacoes* locacoes){
    Locacoes* p;
    for(p=locacoes;p!=NULL;p=p->prox){
        printf("\n-------------------------------------------------\n");
        printf("Nome: %s\n", p->user);
        printf("CNH: %d\n", p->cnh);
        printf("Modelo: %s\n", p->carro);
        printf("Retirada: %d/%d/%d\n", p->data1.day, p->data1.month, p->data1.year);
        printf("Devolucao: %d/%d/%d\n", p->data2.day, p->data2.month, p->data2.year);
        printf("Valor Pago: R$%.2f\n", p->valor);
        if(p->ativa){
            printf("Situacao: Ativa\n");
        }else{
            printf("Situacao: Inativa\n");
        }
    }
}

Locacoes* devolve_locacao(Locacoes* locacoes, Veiculos* veiculos, Users* users){
    char user[25];
    char carro[25];
    int km, cnh;
    Locacoes* p = NULL;
    Veiculos* car_ponteiro = NULL;
    printf("Qual o usuario? ");
    scanf("%s", user);
    if(!usuario_existe(users, user)){
        printf("Qual a cnh? ");
        scanf("%d", &cnh);
        if(cnh_existe(users, cnh, user)){
            printf("Qual o carro que deseja desalocar? ");
            scanf("%s", carro);
            if(!carro_existe(veiculos, carro)){
                car_ponteiro = carro_locado(veiculos, carro, car_ponteiro); 
                printf("Quantos KM voce rodou com o carro? ");
                scanf("%d", &km);
                if(locacoes!=NULL){
                        for(p = locacoes; p!=NULL; p=p->prox){
                        if(!strcmp(p->carro,carro) && !strcmp(p->user, user)){
                            if(p->ativa){
                                p->ativa = false;
                                car_ponteiro->km = car_ponteiro->km + km;
                                car_ponteiro->locado = false;
                                printf("CARRO DESALOCADO COM SUCESSO\n");
                            }else{
                                printf("Voce ja devolveu este carro");
                            }
                        }
                    }
                }else{
                    printf("Nao existem locacoes");
                }
            }else{
                printf("Nao foi achado locacao ativa sua com este carro \n");
            }
        }else{
            printf("Nao foi encontrado essa locacao\n");
        }
    }else{
        printf("Usuario nao encontrado \n");
    }
    return locacoes;
}


 /*         RELATÓRIOOOS       */


void locacoes_ativas(Locacoes* locacoes){
    Locacoes* p;
    if(locacoes!=NULL){
        for(p=locacoes;p!=NULL;p=p->prox){
            if(p->ativa){
                printf("\n-------------------------------------------------\n");
                printf("Nome: %s\n", p->user);
                printf("Modelo: %s\n", p->carro);
                printf("Retirada: %d/%d/%d\n", p->data1.day, p->data1.month, p->data1.year);
                printf("Devolucao: %d/%d/%d\n", p->data2.day, p->data2.month, p->data2.year);
                printf("Valor Pago: R$%.2f\n", p->valor);
                printf("Situacao: Ativa\n");
            }
        }
    }else{
        printf("Nao existem locacoes\n");
    }
}

void locacoes_user(Locacoes* locacoes){
    int cnh;
    Locacoes* p;
    printf("De qual CNH deseja consultar? ");
    scanf("%d", &cnh);
    if(locacoes!=NULL){
        for(p=locacoes; p!=NULL; p=p->prox){
            if(p->cnh == cnh){
                printf("\n-------------------------------------------------\n");
                printf("Nome: %s\n", p->user);
                printf("Modelo: %s\n", p->carro);
                printf("Retirada: %d/%d/%d\n", p->data1.day, p->data1.month, p->data1.year);
                printf("Devolucao: %d/%d/%d\n", p->data2.day, p->data2.month, p->data2.year);
                printf("Valor Pago: R$%.2f\n", p->valor);
                if(p->ativa){
                    printf("Situacao: Ativa\n");
                }else{
                    printf("Situacao: Inativa\n");
                }
            }
        }
    }else{
        printf("Nao existem locacoes\n");
    }
}

void faturamento(Locacoes* locacoes){
    Locacoes* p;
    int mes, ano;
    float total = 0;
    printf("Qual MM/AAAA deseja consultar o faturamento? ");
    scanf("%d %d", &mes, &ano);
    for(p=locacoes; p!=NULL; p=p->prox){
        if(p->data1.month == mes && p->data1.year == ano){
            total+=p->valor;
        }
    }
    printf("\n O faturamento da locadora no mes %d/%d foi de R$%.2f\n", mes, ano, total);
}

void carros_disponiveis(Veiculos* veiculos){
    printf("ESSES SAO OS CARROS DISPONIVEIS");
    Veiculos* p;
    for(p=veiculos;p!=NULL;p=p->prox){
        if(!p->locado){
            printf("Carro: %s\n", p->modelo); 
            printf("Placa: %s\n", p->placa); 
        }
    }
}

/*FUNCAO MAGICA PRA ACHAR OS TRES MAIS RODADOS ---- QUEBREI CABEÇA E CHEGUEI NESSA MAGIA (TA FEIO MAS FUNCIONA)*/
void veiculos_rodados(Veiculos* veiculos){
    Veiculos* maior1=NULL;
    Veiculos* maior2=NULL;
    Veiculos* maior3=NULL;
    maior1 = inicializa_zerado(maior1);
    maior2 = inicializa_zerado(maior2);
    maior3 = inicializa_zerado(maior3);

    for(Veiculos* p=veiculos;p!=NULL;p=p->prox){
        if(p->km > maior1->km){
            maior1 = p;
        }
    }
    printf("1- Modelo: %s | Placa: %s | KM: %d\n", maior1->modelo, maior1->placa, maior1->km);

    for(Veiculos* q=veiculos;q!=NULL;q=q->prox){
        if(q->km > maior2->km && strcmp(q->placa, maior1->placa) != 0 && q->km <= maior1->km){
            maior2 = q;
        }
    }
    printf("2- Modelo: %s | Placa: %s | KM: %d\n", maior2->modelo, maior2->placa, maior2->km);
    for(Veiculos* r=veiculos;r!=NULL;r=r->prox){
        if(r->km > maior3->km && strcmp(r->placa, maior1->placa) != 0 && strcmp(r->placa, maior2->placa) != 0 && r->km <= maior2->km){
            maior3 = r;
        }
    }
    printf("3- Modelo: %s | Placa: %s | KM: %d\n", maior3->modelo, maior3->placa, maior3->km);
}


void relatorios(Locacoes* locacoes, Users* users, Veiculos* veiculos){
    int sair = 0;
    while (!sair)
    {
        printf("**** BEM VINDO A LOCADORA ****\n\n 1- Locacoes Ativas        |  2- Locacoes por Cliente \n 3- Faturamento Mensal     |  4- Veiculos Mais Rodados \n 5- Veiculos Disponiveis   |  6- Sair\n");
        int ctrl;
        scanf("%d", &ctrl);
        switch (ctrl){
            case 1:
                locacoes_ativas(locacoes);
                break;
            case 2:
                locacoes_user(locacoes);
                break;
            case 3:
                faturamento(locacoes);
                break;
            case 4:
                veiculos_rodados(veiculos);
                break;
            case 5:
                carros_disponiveis(veiculos);
                break;
            case 6:
                sair = 1;
                break;
            default:
                printf("Opcao invalida\n");
        }        
    }
}