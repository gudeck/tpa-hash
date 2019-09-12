//
// Created by 2017122760013 on 09/09/2019.
//


/*
 Crie uma estrutura de dados que seja possível armazenar os dados gerados pelo aplicativo fornecido pelo professor
 e seja possível Adicionar, Pesquisar e Remover um elemento. Desenvolva Utilizando:

Hashing aberta com tamanho inicial 500 e load factor > 70%, dobre o tamanho da estrutura a cada crescimento
 e utilize a função de divisão para inserir os elementos na registro (2 Ponto).
Replique a estrutura acima utilizando uma função de dobra (1 Ponto)
Hashing Fechado (1 Ponto). //Só função de divisão
No fim de cada leitura do arquivo, cada algoritmo deve retornar uma lista contendo o número de elementos inseridos,
 o número de colisões ocorridas e o número de colisões por posição (1 Ponto).

Para gerar esse arquivo faça uma varredura na registro, gerando
 uma linha no arquivo para cada registro, separado por ";" (1 Ponto

Gere um relatório do trabalho contendo a analise do
 pior e melhor caso de busca nos 3 algoritmos. (1 Ponto).

Envie aqui o arquivo fonte (.c) contendo o código do seu
 trabalho e o relatório do trabalho compactados em um arquivo zip.*/

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

        hash = getHash(arquivo, addFechado, hashDivisao);
//        hash = getHash(arquivo, addAberto, hashDivisao);
        printf("\n\n\n%d %d\n\n", hash->colisoesTotal, hash->ocupado);
        for (int i = 0; i < hash->tamanho; ++i) {
            if (hash->registro[i] && hash->registro[i]->colisoesPosicao > 0)
                printf("\nPosicao %d: %d colisoes", i, hash->registro[i]->colisoesPosicao);
        }
        mostrarHash(hash);
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
