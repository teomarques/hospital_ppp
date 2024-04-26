#ifndef TRAB_ESTRUTURAS_H
#define TRAB_ESTRUTURAS_H

#define TAMANHO 40

typedef struct inf_doente{
    int id, tel;
    char nome[TAMANHO], data_nascimento[TAMANHO], cc[TAMANHO], email[TAMANHO];
}inf_doente_t;

typedef struct inf_registro{
    int id, tmax, tmin, peso, altura;
    char data_registro[TAMANHO];
}inf_registros_t;

typedef struct list_doente{

}list_doente_t;

#endif