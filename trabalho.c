/*
submissão: 
    pasta: projeto/
        bin/ -> executável
        docs/ -> documentação
        lib/ -> .h
        src/ -> .c
guardar os projetos:
    gcc -Wall -Wextra src/*.c
                        V
                busca tds os ficheiros .c
                e aloca em projeto/src/
    gcc -Wall -Wextra -o bin/proj -g
                           V       V
                guarda em proj-   roda e debuga
                eto/bin/proj,     o código
                sendo proj um 
                executável
valgrind --leak-check-full --track-origins-yes ./main
--> vai dizer o que o programa faz, e vai dizer se libertei a 
memória de todas as variáveis e onde estão os erros.
sempre libertar o mesmo tanto que foi feito malloc's

não utilizar scanf, usar o fgets e se quiser numero converter, 
sem utilizar o atoi()
cleanbuffer_removeline <- para remover \n e dps:
e colocar '\0'
Meter um ciclo até o input ser válido e uma mesagem caso seja inválido,
mas sem parar o projeto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trab_estruturas.h"

// INICIALIZA A LISTA DOENTE
void init_doente(list_doente_t *list_doente){
    list_doente -> num_elems = 0;
    list_doente -> front_doente = NULL;
}

// ANULA O NODO ATUAL DA LISTA DOENTE
int empty_doente(list_doente_t *list_doente){
    return list_doente -> front_doente == NULL;
}

// FAZ PRINT DE TODOS OS ELEMENTOS DA LISTA DOENTE
void print_list_doente(list_doente_t *list_doente){
    node_doente_t *node = list_doente -> front_doente;
    while(node != NULL){
        printf("qualquer coisa");
        node = node -> next;
    }
}

// LIMPA A LISTA DOENTE
void clear_doente(list_doente_t *list_doente){
    node_doente_t *node;
    while(list_doente -> front_doente != NULL){
        node = list_doente -> front_doente;
        list_doente -> front_doente = list_doente -> front_doente -> next;
        free(node);
    }
    init_doente(list_doente);
}

/* PERCORRE TODOS OS NODES DA LISTA DOENTE E ORDENA POR ORDEM ALFABÉTICA
void sort_doente(list_doente_t *list_doente, char *nome, node_doente_t **prev, node_doente_t **cur){
    *prev = NULL;
    *cur = list_doente -> front_doente;
    //while(*cur != NULL && strcmp((*cur) -> nome, nome) < 0){
    while(*cur != NULL){
        if(strcmp((*cur) -> nome, nome) < 0){
            *prev = *cur;
            *cur = (*cur) -> next;
        }else{
            *prev = (*cur) -> next;
            *cur = (*cur) -> next -> next;
        }
    }
}*/

// PESQUISA UM DOENTE POR ID E ORDENA POR NOME
void search_doente(list_doente_t *list_doente, int *id, char *nome[TAMANHO], node_doente_t **prev, node_doente_t **cur){
    *prev = NULL;
    *cur = list_doente -> front_doente;
    //while(*cur != NULL && strcmp((*cur) -> nome, nome) < 0){
    while(*cur != NULL){
        if(strcmp((*cur) -> nome, nome) < 0){
            *prev = *cur;
            *cur = (*cur) -> next;
        }else{
            *prev = (*cur) -> next;
            *cur = (*cur) -> next -> next;
        }
    }
}

// INSERIR ELEMENTO NO TOPO DA LISTA
void insert_doente(list_doente_t *list_doente, int id, int tel, int dia_nascimento, int mes_nascimento, int ano_nascimento, char nome[TAMANHO], char cc[TAMANHO], char email[TAMANHO]){
    node_doente_t *node = (node_doente_t*)malloc(sizeof(node_doente_t));
    node_doente_t *prev, *cur;
    if(node != NULL){
        node -> id = id;
        node -> tel = tel;
        node -> dia_nascimento = dia_nascimento;
        node -> mes_nascimento = mes_nascimento;
        node -> ano_nascimento = ano_nascimento;
        search_doente(list_doente, nome, &prev, &cur);
        if(prev != NULL){
            prev -> next = node;
            node -> next = cur;
        } else {
            list_doente -> front_doente = node;
            node -> next = cur;
        }
        list_doente -> num_elems++;
    }
}


// eliminar o primeiro elemento: list -> front = cur -> next; #o list -> front é sempre o primeiro elemento da lista
// eliminar um elemento no meio da lista: prev -> next = cur -> next;

void remove_node_doente(list_doente_t *list_doente, int id){
    node_doente_t *prev, *cur;
    search_doente(list_doente, &id, &prev, &cur);
    if(cur != NULL && cur -> id == id){
        if(prev != NULL) prev -> next = cur -> next;
        else list_doente -> front_doente = cur -> next;
        free(cur);
        list_doente -> num_elems --;
    }
}

int main(){
    int opcao;
    printf("-----TABELA DE AÇÕES-----\n\n");
    printf("1 - INTRODUZIR DADOS DE UM NOVO CLIENTE\n2 - ELIMINAR UM DOENTE EXISTENTE\n3 - LISTAR TODOS OS DOENTES POR ORDEM ALFABÉTICA\n4 - LISTAR OS DOENTES COM TENSÕES MÁXIMAS ACIMA DE UM VALOR\n5 - APRESENTAR TODA A INFORMAÇÃO DE UM DETERMINADO DOENTE\n6 - REGISTRAR AS TENSÕES, O PESO E A ALTURA DE UM DETERMINADO DOENTE NUM DETERMINADO DIA\n");
    fgets(opcao, 1, stdin);
    printf("%d", opcao);
}