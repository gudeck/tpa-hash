//
// Created by guzuc on 11/09/2019.
//

#ifndef TPA_HASH_HASHABERTO_H
#define TPA_HASH_HASHABERTO_H

#include "hash.h"
#include "cliente.h"

void adicionarAberto(HashClientes *hash, ItemCliente *novoRegistro, FuncaoHash funcaoHash);

void excluirAberto(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash);

ItemCliente *buscarAberto(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash);

#endif //TPA_HASH_HASHABERTO_H
