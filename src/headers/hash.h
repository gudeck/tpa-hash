//
// Created by guzuc on 09/09/2019.
//

#ifndef TPA_HASH_HASH_H
#define TPA_HASH_HASH_H

#include "main.h"
#include "cliente.h"

typedef struct {
    int tamanho;
    int ocupado;
    double loadFactor;
    ItemCliente **registro;
} HashClientes;

HashClientes *criaHash(int tamanho, double loadFactor);

HashClientes *getHash1(FILE *arquivo);

HashClientes *getHash2(FILE *arquivo);

HashClientes *getHash3(FILE *arquivo);

int hashDivisao(Cliente *cliente, int tamanho);

int hashDobra(Cliente *cliente, int tamanho);

void inserirFechado(HashClientes *hash, ItemCliente *novoRegistro, int (*funcaoHash)(Cliente *, int));

void inserirAberto(HashClientes *hash, ItemCliente *novoRegistro, int (*funcaoHash)(Cliente *, int));

bool isAvailable(HashClientes *hash);

HashClientes *expandeHash(
        HashClientes *hash,
        void (*funcaoInsercao)(HashClientes *, ItemCliente *, int (*)(Cliente *, int)),
        int (*funcaoHash)(Cliente *, int));

#endif //TPA_HASH_HASH_H
