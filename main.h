//
// Created by 2017122760013 on 09/09/2019.
//

#ifndef TPA_HASH_MAIN_H
#define TPA_HASH_MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct structCliente {
    int codigo;
    char *nome;
    double saldo;
} Cliente;

typedef struct structItemCliente {
    Cliente *cliente;
    bool excluido;
    struct structItemCliente *proximo;
} ItemCliente;

typedef struct {
    int tamanho;
    int preenchimento;
    double loadFactor;
    ItemCliente *clientes;
} HashClientes;

HashClientes *getHashAberto(FILE *arquivo);

HashClientes *getHashFechado(FILE *arquivo);

void removeCaractere(char *string, char caractere);

void inserirDivisao(HashClientes *clientes, ItemCliente *novoCliente);

void inserirDobra(HashClientes *clientes, ItemCliente *novoCliente);

#endif //TPA_HASH_MAIN_H
