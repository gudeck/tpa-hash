//
// Created by guzuc on 09/09/2019.
//

#include <stdlib.h>
#include <string.h>
#include "headers/hash.h"
#include "headers/main.h"

HashClientes *criarHash(int tamanho, double loadFactor) {

    HashClientes *novaHash = (HashClientes *) calloc(1, sizeof(HashClientes));

    novaHash->colisoesTotal = 0;
    novaHash->ocupado = 0;
    novaHash->tamanho = tamanho;
    novaHash->loadFactor = loadFactor;
    novaHash->registro = (ItemCliente **) calloc(tamanho, sizeof(ItemCliente *));
    return novaHash;
}

HashClientes *expandirHash(HashClientes *hash, FuncaoInsercao funcaoInsercao, FuncaoHash funcaoHash) {

    HashClientes *novaHash = criarHash(hash->tamanho * 2, hash->loadFactor);
    ItemCliente *registro;

    for (int i = 0; i < hash->tamanho; ++i) {
        registro = hash->registro[i];
        if (registro != NULL && !registro->excluido)
            funcaoInsercao(novaHash, registro, funcaoHash);
    }
    novaHash->colisoesTotal = hash->colisoesTotal;
    novaHash->ocupado = hash->ocupado;
    free(hash);
    return novaHash;
}

HashClientes *preencherHash(FILE *arquivo, FuncaoInsercao funcaoInsercao, FuncaoHash funcaoHash) {
    rewind(arquivo);

    HashClientes *hash = criarHash(500, 0.7);
    ItemCliente *novoRegistro;
    Cliente *novoCliente;
    char *nome;
    char linha[99];
    char *saldoString;
    char *codigoString;
    int codigo;
    double saldo;

    while (fgets(linha, 99, arquivo) != NULL) {
        if (!inserirDisponivel(hash)) {
            hash = expandirHash(hash, funcaoInsercao, funcaoHash);
        }
        codigoString = strtok(linha, "|");
        nome = strtok(NULL, "|");
        saldoString = strtok(NULL, "\0");

        codigo = strtol(codigoString, NULL, 10);
        saldo = strtod(removerCaractere(saldoString, '.'), NULL);

        novoCliente = criarCliente(codigo, nome, saldo);
        novoRegistro = criarRegistro(novoCliente);
        funcaoInsercao(hash, novoRegistro, funcaoHash);
    }
    return hash;
}

int formulaDivisao(ItemCliente *registro, HashClientes *hash) {
    if (registro == NULL || registro->cliente == NULL) return -1;
    return registro->cliente->codigo % hash->tamanho;
}

//int formulaDobra(ItemCliente *registro, HashClientes *hash) {
//
//    return 0;
//}

bool inserirDisponivel(HashClientes *hash) {
    return hash->ocupado * 1.0 < ((hash->tamanho * 1.0) * hash->loadFactor);
}

void buscar(HashClientes *hash, ItemCliente *registro, FuncaoHash funcaoHash, FuncaoPesquisa funcaoPesquisa) {
    ItemCliente *aux = funcaoPesquisa(hash, registro, funcaoHash);
    if (aux != NULL)
        printf("\nOs dados solicitados foram: %d %s %f", aux->cliente->codigo, aux->cliente->nome, aux->cliente->saldo);
}



