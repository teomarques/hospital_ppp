#ifndef TRAB_ESTRUTURAS_H
#define TRAB_ESTRUTURAS_H

#define TAMANHO 40

typedef struct node_doente{
    int id, tel, dia_nascimento, mes_nascimento, ano_nascimento;
    char nome[TAMANHO], cc[TAMANHO], email[TAMANHO];
    struct node_doente *next;
}node_doente_t;

typedef struct node_registro{
    int tmax, tmin, peso, altura, dia_registro, mes_registro, ano_registro;
    struct node_registro *next;
}node_registro_t;

typedef struct list_doente{
    size_t num_elems;
    node_doente_t *front_doente;
    node_registro_t *front_registro;
}list_doente_t;

#endif