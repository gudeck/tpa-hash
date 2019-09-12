//
// Created by guzuc on 11/09/2019.
//

#ifndef TPA_HASH_HASHFECHADO_H
#define TPA_HASH_HASHFECHADO_H

#include "hash.h"

void addFechado(HashClientes *hash, ItemCliente *novoRegistro, FuncaoHash funcaoHash);

void expandeFechado(HashClientes *hash, ItemCliente *novoRegistro, FuncaoHash funcaoHash);

void readFechado(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash);

ItemCliente *buscaRegistroFechado(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash);

void deleteFechado(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash);


#endif //TPA_HASH_HASHFECHADO_H
