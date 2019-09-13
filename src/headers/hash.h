//
// Created by guzuc on 09/09/2019.
//

#ifndef TPA_HASH_HASH_H
#define TPA_HASH_HASH_H

#include <stdio.h>
#include "cliente.h"

typedef struct {
    double loadFactor;
    int colisoesTotal;
    int ocupado;
    int tamanho;
    ItemCliente **registro;
} HashClientes;

typedef int (*FuncaoHash)(ItemCliente *, HashClientes *);

typedef ItemCliente *(*FuncaoPesquisa)(HashClientes *, ItemCliente *, FuncaoHash);

typedef void (*FuncaoInsercao)(HashClientes *, ItemCliente *, FuncaoHash);


HashClientes *criarHash(int tamanho, double loadFactor);

HashClientes *expandirHash(HashClientes *hash, FuncaoInsercao funcaoInsercao, FuncaoHash funcaoHash);

HashClientes *preencherHash(FILE *arquivo, FuncaoInsercao funcaoInsercao, FuncaoHash funcaoHash);

int formulaDivisao(ItemCliente *registro, HashClientes *hash);

//int formulaDobra(ItemCliente *registro, HashClientes *hash);

bool inserirDisponivel(HashClientes *hash);

void buscar(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash, FuncaoPesquisa funcaoPesquisa);

#endif //TPA_HASH_HASH_H
