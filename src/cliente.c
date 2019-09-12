//
// Created by guzuc on 09/09/2019.
//

#include "headers/cliente.h"

Cliente *criaCliente(int codigo, char *nome, double saldo) {

    Cliente *novoCliente = (Cliente *) calloc(1, sizeof(Cliente));
    novoCliente->nome = (char *) calloc(strlen(nome) + 1, sizeof(char));

    novoCliente->codigo = codigo;
    strcpy(novoCliente->nome, nome);
    novoCliente->saldo = saldo;
    return novoCliente;
}

ItemCliente *criaRegistro(Cliente *cliente) {

    ItemCliente *novoRegistro = (ItemCliente *) calloc(1, sizeof(ItemCliente));

    novoRegistro->cliente = cliente;
    novoRegistro->colisoesPosicao = 0;
    novoRegistro->excluido = false;
    novoRegistro->anterior = NULL;
    novoRegistro->proximo = NULL;
    return novoRegistro;
}

void *excluiRegistro(ItemCliente *registro) {

    if (registro->anterior != NULL)
        registro->anterior->proximo = registro->proximo;
    if (registro->proximo != NULL)
        registro->proximo->anterior = registro->anterior;
    free(registro);
}
