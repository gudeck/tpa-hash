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
    Cliente *cliente;
    bool excluido;
    struct structItemCliente *proximo;
} ItemCliente;

ItemCliente *criaRegistro(Cliente *cliente);

Cliente *criaCliente(int codigo, char *nome, double saldo);

#endif //TPA_HASH_CLIENTE_H
