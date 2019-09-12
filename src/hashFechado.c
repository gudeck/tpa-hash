//
// Created by guzuc on 11/09/2019.
//

#include "headers/hashFechado.h"

void addFechado(HashClientes *hash, ItemCliente *novoRegistro, FuncaoHash funcaoHash) {

    int indice = funcaoHash(novoRegistro, hash);
    ItemCliente *registro = hash->registro[indice];

    if (registro == NULL)
        hash->registro[indice] = novoRegistro;
    else {
        hash->colisoesTotal++;
        hash->registro[indice]->colisoesPosicao++;
        while (registro->proximo != NULL) registro = registro->proximo;
        registro->proximo = novoRegistro;
        novoRegistro->anterior = registro;
    }
    hash->ocupado++;
}

void readFechado(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {
    ItemCliente *aux = buscaRegistroFechado(hash, registro, funcaoHash);
    if (aux != NULL)
        printf("\nOs dados solicitados foram: %d %s %f", aux->cliente->codigo, aux->cliente->nome, aux->cliente->saldo);
}

void deleteFechado(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    ItemCliente *aux = buscaRegistroFechado(hash, registro, funcaoHash);
    if (aux != NULL) {
        printf("\nOs dados do cliente de codigo %d foram excluidos", aux->cliente->codigo);
        excluiRegistro(aux);
    }
}

ItemCliente *buscaRegistroFechado(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    int indice = funcaoHash(registro, hash);
    ItemCliente *aux;

    if (indice < 0 || !hash->registro[indice]) {
        printf("\nO registro procurado nao foi encontrado");
        return NULL;
    }
    aux = hash->registro[indice];
    while (aux != NULL) {
        if (aux->cliente->codigo == registro->cliente->codigo) break;
        aux = aux->proximo;
    }
    if (aux == NULL) {
        printf("\nO registro procurado nao foi encontrado");
        return NULL;
    }
    return aux;
}


