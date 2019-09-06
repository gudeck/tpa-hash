//
// Created by gudeck on 19/08/2019.
//

#include "headers/Funcoes.h"
#include "headers/ListaClientes.h"
#include "headers/Ordenacao.h"

void gerarArquivoCSV(char *nomeArquivo, ListaPonteiros *ponteiros) {

    FILE *csv;
    csv = fopen(nomeArquivo, "w+");
    fprintf(csv, "Código;Nome;Saldo\n"); // A separação com ; cria as colunas no arquivo
    // Cada fprintf com \n cria uma linha no arquivo
    for (ItemPonteiro *i = ponteiros->primeiro; i != NULL; i = i->proximo) {

        fprintf(csv, "%d;%s;%.2lf\n",
                i->registro->cliente->codigo,
                i->registro->cliente->nome,
                i->registro->cliente->saldo);
    }

    fclose(csv);
}

void menu(FILE *arquivo) {

    int opcao;

    ListaClientes *listaClientes = getListaClientes(arquivo);

    printf("1 - Mostrar dados do arquivo\n");
    printf("2 - Ordenar por nome\n");
    printf("3 - Ordernar por saldo\n");
    printf("0 - Sair\n");
    printf("Selecione uma opção: \n");

    fflush(stdin);
    scanf(" %d", &opcao);

    switch (opcao) {

        case 1: {
            mostrarClientes(listaClientes);
            break;
        }
        case 2: {
            ListaPonteiros *listaBubbleSort = getListaPonteiros(listaClientes);
            ordenar(bubbleSort, listaBubbleSort);
            gerarArquivoCSV("../ordenacao_nome.csv", listaBubbleSort);
            break;
        }
        case 3: {
            ListaPonteiros *listaQuicksort = getListaPonteiros(listaClientes);
            ordenar(quickSort, listaQuicksort);
            gerarArquivoCSV("../ordenacao_saldo.csv", listaQuicksort);
            break;
        }
        case 0: {
            break;
        }
        default: {
            printf("A opção selecionada não existe!");
            fclose(arquivo);
            exit(0);
        }
    }
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
