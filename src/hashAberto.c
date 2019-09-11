//
// Created by guzuc on 11/09/2019.
//

#include "headers/hashAberto.h"

void addAberto(HashClientes *hash, ItemCliente *novoRegistro, FuncaoHash funcaoHash) {

    if (!isAvailable(hash)) {
        hash = expandeHash(hash, addAberto, funcaoHash);
    }

    int indice = funcaoHash(novoRegistro, hash);

    while (hash->registro[indice] != NULL) {
        if (hash->registro[indice]->excluido)break;

        if (indice < hash->tamanho) indice++;
        else indice = 0;
    }

    if (hash->registro[indice] == NULL)
        hash->ocupado++;

    hash->registro[indice] = novoRegistro;
    hash->registro[indice]->excluido = false;
}

void readAberto(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    int indice, i;
    bool parar = false;
    Cliente *cliente;

    i = indice = funcaoHash(registro, hash);

    if (indice < 0) {
        printf("O registro procurado nao foi encontrado\n");
        return;
    }

    while (hash->registro[i]->cliente->codigo != registro->cliente->codigo) {
        if (i < hash->tamanho) i++;
        else {
            if (parar) break;
            i = 0;
            parar = true;
        }
    }

    cliente = hash->registro[i]->cliente;

    if (i == indice && parar) printf("O registro procurado nao foi encontrado\n");
    else printf("Os dados solicitados foram: %d %s %f\n", cliente->codigo, cliente->nome, cliente->saldo);
}

void deleteAberto(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash) {

    int indice, i;
    bool parar = false;
    ItemCliente *aux;

    i = indice = funcaoHash(registro, hash);

    if (indice < 0) {
        printf("O registro procurado nao foi encontrado\n");
        return;
    }

    while (hash->registro[i]->cliente->codigo != registro->cliente->codigo) {
        if (i < hash->tamanho) i++;
        else {
            if (parar) break;
            i = 0;
            parar = true;
        }
    }

    aux = hash->registro[i];

    if (i == indice && parar) printf("O registro procurado não foi encontrado\n");
    else printf("Os dados do cliente de codigo %d foram excluidos\n", aux->cliente->codigo);

    aux->cliente = NULL;
    aux->excluido = true;

    printf("\n");
}

