//
// Created by 2017122760013 on 09/09/2019.
//

#include "main.h"

#include <time.h>
#include <locale.h>

/*
 Crie uma estrutura de dados que seja possível armazenar os dados gerados pelo aplicativo fornecido pelo professor
 e seja possível Adicionar, Pesquisar e Remover um elemento. Desenvolva Utilizando:

Hashing aberta com tamanho inicial 500 e load factor > 70%, dobre o tamanho da estrutura a cada crescimento
 e utilize a função de divisão para inserir os elementos na hash (2 Ponto).
Replique a estrutura acima utilizando uma função de dobra (1 Ponto)
Hashing Fechado (1 Ponto). //Só função de divisão
No fim de cada leitura do arquivo, cada algoritmo deve retornar uma lista contendo o número de elementos inseridos,
 o número de colisões ocorridas e o número de colisões por posição (1 Ponto).

Para gerar esse arquivo faça uma varredura na hash, gerando
 uma linha no arquivo para cada registro, separado por ";" (1 Ponto

Gere um relatório do trabalho contendo a analise do
 pior e melhor caso de busca nos 3 algoritmos. (1 Ponto).

Envie aqui o arquivo fonte (.c) contendo o código do seu
 trabalho e o relatório do trabalho compactados em um arquivo zip.*/

int main(int argc, char *argv[]) {
    HashClientes *dados = (HashClientes *) malloc(1 * sizeof(HashClientes));
    dados->clientes = (ItemCliente *) malloc(500 * sizeof(ItemCliente));
    printf("%n %n", sizeof(dados) / sizeof(HashClientes), sizeof(dados) / sizeof(HashClientes));
//    setlocale(LC_ALL, NULL);
//
//    FILE *arquivo;
//    arquivo = fopen("DadosBancoPulini.txt", "r");
//
//    if (arquivo != NULL) {
//
//        fclose(arquivo);
//    }

    return 0;
}


HashClientes *getHashAberto(FILE *arquivo) {

    HashClientes *dados = (HashClientes *) calloc(1, sizeof(HashClientes));
    ItemCliente *novoCliente;

    char *codigo, *nome, *saldo, linha[99];

    while (fgets(linha, 99, arquivo) != NULL) {

        codigo = strtok(linha, "|");
        nome = strtok(NULL, "|");
        saldo = strtok(NULL, "\n");

        if (strlen(linha) <= 1) break;
        removeCaractere(saldo, ',');

        novoCliente = (ItemCliente *) calloc(1, sizeof(ItemCliente));
        novoCliente->cliente = (Cliente *) calloc(1, sizeof(Cliente));
        novoCliente->cliente->nome = (char *) calloc(strlen(nome) + 1, sizeof(char));

        novoCliente->cliente->codigo = atoi(codigo);
        strcpy(novoCliente->cliente->nome, nome);
        novoCliente->cliente->saldo = atof(saldo);

        inserirDivisao(dados, novoCliente);
//        inserirDobra(dados, novoCliente);

    }

    return dados;
}

void removeCaractere(char *string, char caractere) {

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == caractere) {
            for (int j = i; string[j] != '\0'; ++j) {
                string[j] = string[j + 1];
            }
        }
    }
}

void inserirDivisao(HashClientes *clientes, ItemCliente *novoCliente) {


}

void inserirDobra(HashClientes *clientes, ItemCliente *novoCliente) {

}

