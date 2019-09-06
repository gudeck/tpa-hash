//
// Created by gudeck on 18/08/2019.
//

#ifndef TPA_ANALISE_E_COMPLEXIDADE_LISTACLIENTES_H
#define TPA_ANALISE_E_COMPLEXIDADE_LISTACLIENTES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cliente.h"

typedef struct structItemCliente {
    Cliente *cliente;
    struct structItemCliente *anterior, *proximo;
} ItemCliente;

typedef struct {
    ItemCliente *primeiro, *ultimo;
} ListaClientes;

ListaClientes *getListaClientes(FILE *arquivo);

void inserirCliente(ListaClientes *clientes, ItemCliente *novoCliente);

#endif //TPA_ANALISE_E_COMPLEXIDADE_LISTACLIENTES_H
