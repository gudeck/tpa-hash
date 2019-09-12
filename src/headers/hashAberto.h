//
// Created by guzuc on 11/09/2019.
//

#ifndef TPA_HASH_HASHABERTO_H
#define TPA_HASH_HASHABERTO_H

#include "hash.h"

void addAberto(HashClientes *hash, ItemCliente *novoRegistro, FuncaoHash funcaoHash);

void deleteAberto(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash);

ItemCliente *buscaRegistroAberto(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash);

#endif //TPA_HASH_HASHABERTO_H
