#ifndef LISTAPESSOAS_H
#define LISTAPESSOAS_H

// DEFINE INFORMAÇÃO SOBRE UMA PESSOA -----------------------------
typedef struct pessoa {
    char nome[50];
    int idade;
}pessoa;
-------------------------------------------------------------------

// DEFINE A LISTA DE PESSOAS --------------------------------------
typedef struct noLista {
    pessoa pessoaLista;
    struct noLista * prox;
} noLista;
-------------------------------------------------------------------

// DEFINE A LISTA DE PONTEIROS PARA PESSOA 1 ----------------------
typedef noLista * pLista;
-------------------------------------------------------------------

// CRIA A LISTA DE PESSOAS ----------------------------------------
typedef struct noLista2 {
    pLista p;
    struct noLista2 * prox;
} noLista2;
-------------------------------------------------------------------

// DEFINE A LISTA DE PONTEIROS PARA PESSOA 2 ----------------------
typedef noLista2 * pLista2;
-------------------------------------------------------------------

// iNICIALIZAR FUNÇÕES --------------------------------------------
pLista cria ();

int vazia (pLista lista);

pLista destroi (pLista lista);

void procura (pLista lista, int chave, pLista *ant, pLista *actual);

void insere (pLista lista, struct pessoa p1);

void imprime (pLista lista);

pLista2 cria2 ();

int vazia2 (pLista2 lista2);

pLista2 destroi2 (pLista2 lista2);

void procura2 (pLista2 lista2, char * chave, pLista2 *ant, pLista2 *actual);

void insere2 (pLista2 lista2, pLista pont);

void imprime2 (pLista2 lista2);
-------------------------------------------------------------------

#endif