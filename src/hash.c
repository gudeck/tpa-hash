//
// Created by guzuc on 09/09/2019.
//

#include "headers/hash.h"
#include "headers/hashFechado.h"

HashClientes *criaHash(int tamanho, double loadFactor) {

    HashClientes *novaHash = (HashClientes *) calloc(1, sizeof(HashClientes));

    novaHash->ocupado = 0;
    novaHash->tamanho = tamanho;
    novaHash->loadFactor = loadFactor;
    novaHash->registro = (ItemCliente **) calloc(tamanho, sizeof(ItemCliente *));
    return novaHash;
}

HashClientes *expandeHash(HashClientes *hash, FuncaoInsercao funcaoInsercao, FuncaoHash funcaoHash) {

    HashClientes *novaHash = criaHash(hash->tamanho * 2, hash->loadFactor);
    ItemCliente *registro;

    for (int i = 0; i < hash->tamanho; ++i) {
        registro = hash->registro[i];
        while (registro != NULL) {
            registro->excluido = false;
            if (funcaoInsercao == addFechado)
                expandeFechado(novaHash, registro, funcaoHash);
            else
                funcaoInsercao(novaHash, registro, funcaoHash);
            registro = registro->proximo;
        }
    }
    novaHash->ocupado = hash->ocupado;
    free(hash);
    return novaHash;
}

HashClientes *getHash(FILE *arquivo, FuncaoInsercao funcaoInsercao, FuncaoHash funcaoHash) {
    rewind(arquivo);

    HashClientes *hash = criaHash(500, 0.7);
    ItemCliente *novoRegistro;
    Cliente *novoCliente;
    char *codigoString, *nome, *saldoString, linha[99];
    int codigo;
    double saldo;

    while (fgets(linha, 99, arquivo) != NULL) {
        if (!isAvailable(hash)) {
            hash = expandeHash(hash, funcaoInsercao, funcaoHash);
        }
        codigoString = strtok(linha, "|");
        nome = strtok(NULL, "|");
        saldoString = strtok(NULL, "\0");

        codigo = strtol(codigoString, NULL, 10);
        saldo = strtod(removeCaractere(saldoString, '.'), NULL);

        novoCliente = criaCliente(codigo, nome, saldo);
        novoRegistro = criaRegistro(novoCliente);
        funcaoInsercao(hash, novoRegistro, funcaoHash);
    }
    return hash;
}

int hashDivisao(ItemCliente *registro, HashClientes *hash) {
    if (registro == NULL || registro->cliente == NULL) return -1;
    return registro->cliente->codigo % hash->tamanho;
}

int hashDobra(ItemCliente *registro, HashClientes hash) {


    return 0;
}

bool isAvailable(HashClientes *hash) {
    return hash->ocupado * 1.0 < ((hash->tamanho * 1.0) * hash->loadFactor);
}




