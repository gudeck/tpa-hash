//
// Created by 2017122760013 on 09/09/2019.
//

#include <locale.h>
#include <stdio.h>
#include "headers/main.h"
#include "headers/hashFechado.h"

int main(int argc, char *argv[]) {

    setlocale(LC_ALL, NULL);

    FILE *arquivo = fopen("../DadosBancoPulini.txt", "r");

    if (arquivo != NULL) {
        HashClientes *hash = preencherHash(arquivo, adicionarFechado, formulaDivisao);

        mostrarHash(hash);

        fclose(arquivo);
    }
    return 0;
}

char *removerCaractere(char *string, char caractere) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == caractere) {
            for (int j = i; string[j] != '\0'; ++j) {
                string[j] = string[j + 1];
            }
        }
    }
    return string;
}

void gerarArquivoCSV(HashClientes *hash) {
    FILE *csv = fopen("../relatorioColisoes.csv", "w+");
    fprintf(csv, "Posição;Número de Colisões\n");
    for (int i = 0; i < hash->tamanho; ++i) {
        if (hash->registro[i] && hash->registro[i]->colisoesPosicao > 0)
            fprintf(csv, "%d;%d\n", i, hash->registro[i]->colisoesPosicao);
    }
    fprintf(csv, "\nTotal:;%d", hash->colisoesTotal);
    fclose(csv);
}

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