//
// Created by guzuc on 09/09/2019.
//

#ifndef TPA_HASH_CLIENTE_H
#define TPA_HASH_CLIENTE_H

#include "main.h"

typedef struct structCliente {
    int codigo;
    char *nome;
    double saldo;
} Cliente;

typedef struct structItemCliente {
    bool excluido;
    Cliente *cliente;
    int colisoesPosicao;
    struct structItemCliente *anterior, *proximo;
} ItemCliente;

ItemCliente *criaRegistro(Cliente *cliente);

void *excluiRegistro(ItemCliente *registro);

Cliente *criaCliente(int codigo, char *nome, double saldo);

#endif //TPA_HASH_CLIENTE_H
