//
// Created by guzuc on 11/09/2019.
//

#include <stdio.h>
#include "headers/hashFechado.h"

void adicionarFechado(HashClientes *hash, ItemCliente *novoRegistro, FuncaoHash funcaoHash) {

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

void excluirFechado(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    ItemCliente *aux = buscarFechado(hash, registro, funcaoHash);
    if (aux != NULL) {
        printf("\nOs dados do cliente de codigo %d foram excluidos", aux->cliente->codigo);
        if (!aux->anterior) {
            hash->registro[funcaoHash(registro, hash)] = aux->proximo;
            aux->proximo->colisoesPosicao = aux->colisoesPosicao;
        }
        excluirRegistro(aux);
        hash->ocupado--;
    }
}

ItemCliente *buscarFechado(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    int indice = funcaoHash(registro, hash);
    ItemCliente *aux;

    if (indice < 0 || !hash->registro[indice]) {
        printf("\nO registro procurado nao foi encontrado");
        return NULL;
    }
    aux = hash->registro[indice];
    if (aux == NULL) {
        printf("\nO registro procurado nao foi encontrado");
        return NULL;
    }
    while (aux != NULL) {
        if (aux->cliente->codigo == registro->cliente->codigo)
            break;
        aux = aux->proximo;
    }
    return aux;
}


