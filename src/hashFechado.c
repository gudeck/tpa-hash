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
        while (registro->proximo != NULL) {
            if (registro->proximo->excluido)break;

            registro = registro->proximo;
        }

        registro->proximo = novoRegistro;
        registro->proximo->excluido = false;
        registro->proximo->proximo = NULL;
    }

    if (!hash->registro[indice]->excluido)
        hash->ocupado++;

}

void readFechado(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    int indice = funcaoHash(registro, hash);

    if (indice < 0) {
        printf("O registro procurado nao foi encontrado\n");
        return;
    }

    ItemCliente *aux = hash->registro[indice];

    while (aux != NULL) {
        if (aux->excluido) {
            aux = aux->proximo;
            continue;
        }

        if (aux->cliente->codigo == registro->cliente->codigo) break;

        aux = aux->proximo;
    }

    if (aux == NULL)
        printf("O registro procurado nao foi encontrado\n");
    else
        printf("Os dados solicitados foram: %d %s %f\n", aux->cliente->codigo, aux->cliente->nome, aux->cliente->saldo);
}

void deleteFechado(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    int indice = funcaoHash(registro, hash);

    if (indice < 0) {
        printf("O registro procurado nao foi encontrado\n");
        return;
    }

    ItemCliente *aux = hash->registro[indice];

    while (aux != NULL) {
        if (aux->cliente->codigo == registro->cliente->codigo) break;

        if (aux->excluido) {
            aux = aux->proximo;
            continue;
        }
        aux = aux->proximo;
    }

    if (aux == NULL)
        printf("O registro procurado nao foi encontrado\n");
    else {
        printf("Os dados do cliente de codigo %d foram excluidos\n", aux->cliente->codigo);

        aux->cliente = NULL;
        aux->excluido = true;
    }
}


