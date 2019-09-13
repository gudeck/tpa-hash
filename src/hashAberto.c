//
// Created by guzuc on 11/09/2019.
//

#include <stdio.h>
#include <stdbool.h>
#include "headers/hashAberto.h"

void adicionarAberto(HashClientes *hash, ItemCliente *novoRegistro, FuncaoHash funcaoHash) {

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

void excluirAberto(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    ItemCliente *aux = buscarAberto(hash, registro, funcaoHash);

    if (aux != NULL) {
        printf("\nOs dados do cliente de codigo %d foram excluidos", aux->cliente->codigo);
        aux->cliente = NULL;
        aux->excluido = true;
    }
}

ItemCliente *buscarAberto(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    int i;
    int indice = funcaoHash(registro, hash);
    bool parar;
    ItemCliente *aux;

    if (indice < 0 || !hash->registro[indice]) {
        printf("\nO registro procurado nao foi encontrado");
        return NULL;
    }
    i = indice;
    parar = false;
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

