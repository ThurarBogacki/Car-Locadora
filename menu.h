#include "lista.h" 
Veiculos* cadastrar_veiculo(Veiculos* veiculos);
void imprimir_lista_veiculos(Veiculos* veiculos);
Users* cadastrar_user(Users* users);
void imprimir_lista_user(Users* user);
Locacoes* realizar_locacao(Locacoes *locacoes, Users* users, Veiculos* viculos);
void imprimir_lista_locacoes(Locacoes* locacoes);
Locacoes* devolve_locacao(Locacoes* locacoes, Veiculos* veiculos, Users* users);
void relatorios(Locacoes* locacoes, Users* users, Veiculos* veiculos);