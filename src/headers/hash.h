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

typedef int (*FuncaoCalculo)(ItemCliente *, HashClientes *);

typedef ItemCliente *(*FuncaoBuscar)(HashClientes *, ItemCliente *, FuncaoCalculo);

typedef void (*FuncaoInsercao)(HashClientes *, ItemCliente *, FuncaoCalculo);


HashClientes *criarHash(int tamanho, double loadFactor);

HashClientes *expandirHash(HashClientes *hash, FuncaoInsercao funcaoInsercao, FuncaoCalculo funcaoHash);

HashClientes *preencherHash(FILE *arquivo, FuncaoInsercao funcaoInsercao, FuncaoCalculo funcaoHash);

int formulaDivisao(ItemCliente *registro, HashClientes *hash);

//int formulaDobra(ItemCliente *registro, HashClientes *hash);

bool inserirDisponivel(HashClientes *hash);

void buscar(HashClientes *hash, ItemCliente *registro, FuncaoCalculo funcaoHash, FuncaoBuscar funcaoPesquisa);

#endif //TPA_HASH_HASH_H
