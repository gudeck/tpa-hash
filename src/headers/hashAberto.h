//
// Created by guzuc on 11/09/2019.
//

#ifndef TPA_HASH_HASHABERTO_H
#define TPA_HASH_HASHABERTO_H

#include "hash.h"
#include "cliente.h"

void adicionarAberto(HashClientes *hash, ItemCliente *novoRegistro, FuncaoCalculo funcaoHash);

void excluirAberto(HashClientes *hash, ItemCliente *registro, FuncaoCalculo funcaoHash);

ItemCliente *buscarAberto(HashClientes *hash, ItemCliente *registro, FuncaoCalculo funcaoHash);

#endif //TPA_HASH_HASHABERTO_H
