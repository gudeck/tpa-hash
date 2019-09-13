//
// Created by guzuc on 09/09/2019.
//

#ifndef TPA_HASH_CLIENTE_H
#define TPA_HASH_CLIENTE_H

#include <stdbool.h>

typedef struct structCliente {
    int codigo;
    char *nome;
    double saldo;
} Cliente;

typedef struct structItemCliente {
    Cliente *cliente;
    bool excluido;
    int colisoesPosicao;
    struct structItemCliente *anterior, *proximo;
} ItemCliente;


Cliente *criarCliente(int codigo, char *nome, double saldo);

ItemCliente *criarRegistro(Cliente *cliente);

void excluirRegistro(ItemCliente *registro);

#endif //TPA_HASH_CLIENTE_H
