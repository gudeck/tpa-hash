//
// Created by guzuc on 09/09/2019.
//

#include "headers/hash.h"

HashClientes *criaHash(int tamanho, double loadFactor) {

    HashClientes *novaHash = (HashClientes *) calloc(1, sizeof(HashClientes));

    novaHash->ocupado = 0;

    novaHash->tamanho = tamanho;
    novaHash->loadFactor = loadFactor;

    novaHash->registro = (ItemCliente **) calloc(tamanho, sizeof(ItemCliente *));

    return novaHash;
}

//(int (*funcaoHash)(Cliente *, int))
HashClientes *expandeHash(
        HashClientes *hash,
        void (*funcaoInsercao)(HashClientes *, ItemCliente *, int (*)(Cliente *, int)),
        int (*funcaoHash)(Cliente *, int)) {

    HashClientes *novaHash = criaHash(hash->tamanho * 2, hash->loadFactor);
    ItemCliente *registro;

    for (int i = 0; i < hash->tamanho; ++i) {
        registro = hash->registro[i];
        if (registro != NULL) {
            registro->excluido = false;
            funcaoInsercao(novaHash, registro, funcaoHash);
        }
    }

    free(hash);
    return novaHash;
}

HashClientes *getHash1(FILE *arquivo) {

    HashClientes *hash = criaHash(500, 0.7);
    ItemCliente *novoRegistro;
    Cliente *novoCliente;

    char *codigoString, *nome, *saldoString, linha[99];
    int codigo;
    double saldo;
    while (fgets(linha, 99, arquivo) != NULL) {
        if (!isAvailable(hash)) {
            hash = expandeHash(hash, inserirAberto, hashDivisao);
        }

        codigoString = strtok(linha, "|");
        nome = strtok(NULL, "|");
        saldoString = strtok(NULL, "\0");

        codigo = strtol(codigoString, NULL, 10);
        saldo = strtod(removeCaractere(saldoString, '.'), NULL);

        novoCliente = criaCliente(codigo, nome, saldo);
        novoRegistro = criaRegistro(novoCliente);

        inserirAberto(hash, novoRegistro, hashDivisao);

    }
    return hash;
}

HashClientes *getHash2(FILE *arquivo) {

    HashClientes *hash = criaHash(500, 0.7);
    ItemCliente *novoRegistro;
    Cliente *novoCliente;

    char *codigoString, *nome, *saldoString, linha[99];
    int codigo;
    double saldo;
    while (fgets(linha, 99, arquivo) != NULL) {
        if (!isAvailable(hash)) {
            hash = expandeHash(hash, inserirAberto, hashDobra);
        }

        codigoString = strtok(linha, "|");
        nome = strtok(NULL, "|");
        saldoString = strtok(NULL, "\0");

        codigo = strtol(codigoString, NULL, 10);
        saldo = strtod(removeCaractere(saldoString, '.'), NULL);

        novoCliente = criaCliente(codigo, nome, saldo);
        novoRegistro = criaRegistro(novoCliente);

        inserirAberto(hash, novoRegistro, hashDobra);

    }
    return hash;
}

HashClientes *getHash3(FILE *arquivo) {

    HashClientes *hash = criaHash(500, 0.7);
    ItemCliente *novoRegistro;
    Cliente *novoCliente;

    char *codigoString, *nome, *saldoString, linha[99];
    int codigo;
    double saldo;
    while (fgets(linha, 99, arquivo) != NULL) {
        if (!isAvailable(hash)) {
            hash = expandeHash(hash, inserirFechado, hashDivisao);
        }

        codigoString = strtok(linha, "|");
        nome = strtok(NULL, "|");
        saldoString = strtok(NULL, "\0");

        codigo = strtol(codigoString, NULL, 10);
        saldo = strtod(removeCaractere(saldoString, '.'), NULL);

        novoCliente = criaCliente(codigo, nome, saldo);
        novoRegistro = criaRegistro(novoCliente);

        inserirFechado(hash, novoRegistro, hashDivisao);

    }
    return hash;
}

int hashDivisao(Cliente *cliente, int tamanho) {
    return cliente->codigo % tamanho;
}

int hashDobra(Cliente *cliente, int tamanho) {


    return 0;
}

void inserirAberto(HashClientes *hash, ItemCliente *novoRegistro, int (*funcaoHash)(Cliente *, int)) {

    int indice = funcaoHash(novoRegistro->cliente, hash->tamanho);

    while (hash->registro[indice] != NULL) {
        if (indice < hash->tamanho) indice++;
        else indice = 0;
    }

    hash->registro[indice] = novoRegistro;
    hash->ocupado++;
}

void inserirFechado(HashClientes *hash, ItemCliente *novoRegistro, int (*funcaoHash)(Cliente *, int)) {

    int indice = funcaoHash(novoRegistro->cliente, hash->tamanho);
    ItemCliente *aux = hash->registro[indice];

    while (aux->proximo != NULL && !aux->proximo->excluido) {
        aux = aux->proximo;
    }

    hash->registro[indice] = novoRegistro;
    hash->ocupado++;

}

bool isAvailable(HashClientes *hash) {
    return (double) hash->ocupado < ((double) hash->tamanho * hash->loadFactor);
}



