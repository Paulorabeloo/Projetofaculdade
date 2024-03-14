#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char cat, ref, op = 'S';
    float valor, custo, imposto, total;
    while (op != 'N') {
        printf("\nInforme o valor do Produto: ");
        scanf("%f", &valor);
        printf("Informe a Categoria (A, L ou V): ");
        scanf(" %c", &cat);
        cat = toupper(cat);
        while (cat != 'A' && cat != 'L' && cat != 'V') {
            printf("\nCampo Inválido, tente novamente: ");
            scanf(" %c", &cat);
            cat = toupper(cat);
        }
        printf("Informe se o Produto tem que ser Refrigerado (S ou N): ");
        scanf(" %c", &ref);
        ref = toupper(ref);
        if (valor <= 20) {
            if (cat == 'A') custo = 5;
            else if (cat == 'L') custo = 10;
            else if (cat == 'V') custo = 15;
        }
        else if (valor <= 50) {
            if (ref == 'S') custo = 21;
            else custo = 12;
        }
        else {
            if (ref == 'S' && cat == 'A') custo = 6;
            else if (ref == 'S' && cat == 'L') custo = 2;
            else if (ref == 'S' && cat == 'V') custo = 4;
            else if (ref == 'A' || cat == 'V') custo = 0;
            else custo = 1;
        }
        imposto = (cat == 'A' && ref == 'S') ? valor * 0.04 : valor * 0.02;
        total = valor + imposto + custo;
        printf("\nO valor do Imposto do Produto será de %.2f", imposto);
        printf("\nO valor do Custo de Estocagem do Produto %c %c %.2f", cat, ref, custo);
        printf("\nO valor Total do Produto será de %.2f\n", total);
        printf("\nDeseja continuar com entrada de Produtos [S]im ou [N]ão: ");
        scanf(" %c", &op);
        op = toupper(op);
    }
    return 0;
}
