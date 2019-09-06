#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    FILE *arquivo;
    arquivo = fopen("../DadosBancoPulini.txt", "r+");

    if (arquivo != NULL) {

        fclose(arquivo);
    }

    return 0;
}