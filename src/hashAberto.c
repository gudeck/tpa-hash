//
// Created by guzuc on 11/09/2019.
//

#include "headers/hashAberto.h"

void addAberto(HashClientes *hash, ItemCliente *novoRegistro, FuncaoHash funcaoHash) {

    int indice = funcaoHash(novoRegistro, hash);

    while (hash->registro[indice] != NULL) {
        if (hash->registro[indice]->excluido)break;
        else {
            hash->colisoesTotal++;
            hash->registro[indice]->colisoesPosicao++;
        }
        if (indice < hash->tamanho) indice++;
        else indice = 0;
    }
    if (hash->registro[indice] == NULL)
        hash->ocupado++;
    hash->registro[indice] = novoRegistro;
    hash->registro[indice]->excluido = false;
}

void deleteAberto(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    ItemCliente *aux = buscaRegistroAberto(hash, registro, funcaoHash);

    if (aux != NULL) {
        printf("\nOs dados do cliente de codigo %d foram excluidos", aux->cliente->codigo);
        aux->cliente = NULL;
        aux->excluido = true;
    }
}

void readAberto(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    ItemCliente *aux = buscaRegistroAberto(hash, registro, funcaoHash);

    if (aux != NULL)
        printf("\nOs dados solicitados foram: %d %s %f", aux->cliente->codigo, aux->cliente->nome, aux->cliente->saldo);
}

ItemCliente *buscaRegistroAberto(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    int indice, i;
    bool parar = false;
    ItemCliente *aux;

    i = indice = funcaoHash(registro, hash);
    if (indice < 0 || !hash->registro[indice]) {
        printf("\nO registro procurado nao foi encontrado");
        return NULL;
    }
    while (i != indice && !parar) {
        if (hash->registro[i] != NULL)
            if (hash->registro[i]->cliente != NULL)
                if (hash->registro[i]->cliente->codigo != registro->cliente->codigo)
                    break;
        if (i < hash->tamanho) i++;
        else {
            i = 0;
            parar = true;
        }
    }
    aux = hash->registro[i];
    if ((i == indice && parar) || aux->excluido) {
        printf("\nO registro procurado não foi encontrado");
        return NULL;
    }
    return aux;
}

