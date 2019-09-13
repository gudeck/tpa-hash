//
// Created by guzuc on 11/09/2019.
//

#ifndef TPA_HASH_HASHFECHADO_H
#define TPA_HASH_HASHFECHADO_H

#include "hash.h"
#include "cliente.h"

void adicionarFechado(HashClientes *hash, ItemCliente *novoRegistro, FuncaoCalculo funcaoHash);

void excluirFechado(HashClientes *hash, ItemCliente *registro, FuncaoCalculo funcaoHash);

ItemCliente *buscarFechado(HashClientes *hash, ItemCliente *registro, FuncaoCalculo funcaoHash);

#endif //TPA_HASH_HASHFECHADO_H
