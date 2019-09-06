//
// Created by gudeck on 19/08/2019.
//

#include "headers/ListaClientes.h"
#include "headers/Funcoes.h"

ListaClientes *getListaClientes(FILE *arquivo) {

    ListaClientes *dados = (ListaClientes *) calloc(1, sizeof(ListaClientes));
    ItemCliente *novoCliente;

    char *codigo, *nome, *saldo;

    while (!feof(arquivo)) {

        fflush(stdin);

        codigo = strtok(fgets((char *) stdin, 100, arquivo), "|");
        nome = strtok(NULL, "|");
        saldo = strtok(NULL, "\n");

        removeCaractere(saldo, ',');

        novoCliente = (ItemCliente *) calloc(1, sizeof(ItemCliente));
        novoCliente->cliente = (Cliente *) calloc(1, sizeof(Cliente));
        novoCliente->cliente->nome = (char *) calloc(strlen(nome) + 1, sizeof(char));

        novoCliente->cliente->codigo = atoi(codigo);
        strcpy(novoCliente->cliente->nome, nome);
        novoCliente->cliente->saldo = atof(saldo);

        inserirCliente(dados, novoCliente);
    }

    return dados;
}

void inserirCliente(ListaClientes *clientes, ItemCliente *novoCliente) {
    if (clientes->primeiro == NULL) {
        clientes->primeiro = novoCliente;
        clientes->ultimo = novoCliente;
    } else {
        novoCliente->anterior = clientes->ultimo;
        clientes->ultimo->proximo = novoCliente;
        clientes->ultimo = novoCliente;
    }
}

void mostrarClientes(ListaClientes *clientes) {

    for (ItemCliente *i = clientes->primeiro; i != NULL; i = i->proximo) {

        printf("Código: %d \t\t Nome: %s \t\t Saldo: %lf \n",
               i->cliente->codigo,
               i->cliente->nome,
               i->cliente->saldo);
    }

    printf("\n");
}
