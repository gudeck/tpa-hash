//
// Created by guzuc on 09/09/2019.
//

#ifndef TPA_HASH_HASH_H
#define TPA_HASH_HASH_H

#include "main.h"
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


HashClientes *criaHash(int tamanho, double loadFactor);

HashClientes *expandeHash(HashClientes *hash, FuncaoInsercao funcaoInsercao, FuncaoHash funcaoHash);

HashClientes *getHash(FILE *arquivo, FuncaoInsercao funcaoInsercao, FuncaoHash funcaoHash);

int hashDivisao(ItemCliente *registro, HashClientes *hash);

int hashDobra(ItemCliente *registro, HashClientes *hash);

bool isAvailable(HashClientes *hash);

void read(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash, FuncaoPesquisa funcaoPesquisa);

#endif //TPA_HASH_HASH_H
