//
// Created by 2017122760013 on 09/09/2019.
//

#include "headers/main.h"
#include "headers/hash.h"
#include "headers/hashAberto.h"
#include "headers/hashFechado.h"

void mostrarHash(HashClientes *hash) {
    ItemCliente *registro;
    for (int i = 0; i < hash->tamanho; ++i) {
        registro = hash->registro[i];
        if (registro == NULL) printf("\n%d", i);
        else {
            while (registro != NULL) {
                printf("\n%d - %d %s %f", i, registro->cliente->codigo, registro->cliente->nome,
                       registro->cliente->saldo);
                registro = registro->proximo;
            }
        }
    }
}

int main(int argc, char *argv[]) {

    setlocale(LC_ALL, NULL);

    FILE *arquivo = fopen("../DadosBancoPulini.txt", "r");

    if (arquivo != NULL) {
        HashClientes *hash;

        Cliente *cliente = criaCliente(2334, "G", 13.0);
        ItemCliente *registro = criaRegistro(cliente);

        hash = getHash(arquivo, addFechado, hashDivisao);
//        hash = getHash(arquivo, addAberto, hashDivisao);
//        read(hash, registro, hashDivisao, buscaRegistroFechado);
        printf("\n\n\n%d %d\n\n", hash->colisoesTotal, hash->ocupado);
//        for (int i = 0; i < hash->tamanho; ++i) {
//            if (hash->registro[i] && hash->registro[i]->colisoesPosicao > 0)
//                printf("\nPosicao %d: %d colisoes", i, hash->registro[i]->colisoesPosicao);
//        }
//        mostrarHash(hash);
//        read(hash, registro, hashDivisao, buscaRegistroFechado);
        fclose(arquivo);
    }
    return 0;
}

char *removeCaractere(char *string, char caractere) {

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == caractere) {
            for (int j = i; string[j] != '\0'; ++j) {
                string[j] = string[j + 1];
            }
        }
    }
    return string;
}
