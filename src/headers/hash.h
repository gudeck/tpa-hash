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
} HashClientes, Hasahd;

typedef int (*FuncaoHash)(ItemCliente *, HashClientes *);

typedef void (*FuncaoInsercao)(HashClientes *, ItemCliente *, FuncaoHash);


HashClientes *criaHash(int tamanho, double loadFactor);

HashClientes *expandeHash(HashClientes *hash, FuncaoInsercao funcaoInsercao, FuncaoHash funcaoHash);

HashClientes *getHash(FILE *arquivo, FuncaoInsercao funcaoInsercao, FuncaoHash funcaoHash);

int hashDivisao(ItemCliente *registro, HashClientes *hash);

int hashDobra(ItemCliente *registro, HashClientes hash);

bool isAvailable(HashClientes *hash);

/*
HashClientes *expandeHash(HashClientes *hash, FuncaoInsercao funcaoInsercao, FuncaoHash funcaoHash) {

    HashClientes *novaHash = criaHash(hash->tamanho * 2, hash->loadFactor);
    ItemCliente *registro;
    printf("\n\n\n%d %d %d", hash->ocupado, hash->tamanho, novaHash->tamanho);
    for (int i = 0; i < hash->tamanho; ++i) {
        registro = hash->registro[i];
        if (registro != NULL) {
            while (registro != NULL) {

                registro->excluido = false;
                funcaoInsercao(novaHash, registro, funcaoHash);

                registro = registro->proximo;
            }
        }

    }

    free(hash);
    return novaHash;
}*/
#endif //TPA_HASH_HASH_H
