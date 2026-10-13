#include <stdio.h>

#define MAX 20

int main() {
    int codigo[MAX];
    char nome[MAX][50];
    float preco[MAX];
    int quantidade[MAX];
    int total = 0;

    int opcao;
    int i;
    int codigoBusca;
    int posicao;
    int c;
    int ok;

    do {
        printf("\n===== SISTEMA DE CADASTRO =====");
        printf("\n1 - Cadastrar");
        printf("\n2 - Consultar");
        printf("\n3 - Listar");
        printf("\n4 - Alterar");
        printf("\n5 - Excluir");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                if (total >= MAX) {
                    printf("\nLimite maximo de cadastros atingido.\n");
                } else {
                    printf("\n--- Cadastro de produto ---");
                    printf("\nCodigo: ");
                    scanf("%d", &codigoBusca);

                    posicao = -1;
                    for (i = 0; i < total; i++) {
                        if (codigo[i] == codigoBusca) {
                            posicao = i;
                        }
                    }

                    if (posicao != -1) {
                        printf("\nJa existe um produto com esse codigo.\n");
                    } else {
                        codigo[total] = codigoBusca;
                        printf("Nome: ");
                        scanf(" %49[^\n]", nome[total]);

                        printf("Preco (use ponto, ex: 59.90): ");
                        do {
                            ok = (scanf("%f", &preco[total]) == 1);
                            while ((c = getchar()) != '\n' && c != EOF) {
                                if (c != ' ' && c != '\t') ok = 0;
                            }
                            if (!ok) printf("Valor invalido. Digite o preco novamente: ");
                        } while (!ok);

                        printf("Quantidade: ");
                        do {
                            ok = (scanf("%d", &quantidade[total]) == 1);
                            while ((c = getchar()) != '\n' && c != EOF) {
                                if (c != ' ' && c != '\t') ok = 0;
                            }
                            if (!ok) printf("Valor invalido. Digite a quantidade novamente: ");
                        } while (!ok);

                        total++;
                        printf("\nProduto cadastrado com sucesso!\n");
                    }
                }
                break;

            case 2:
                printf("\nCodigo a consultar: ");
                scanf("%d", &codigoBusca);

                posicao = -1;
                for (i = 0; i < total; i++) {
                    if (codigo[i] == codigoBusca) {
                        posicao = i;
                    }
                }

                if (posicao == -1) {
                    printf("\nRegistro nao encontrado.\n");
                } else {
                    printf("\nCodigo: %d", codigo[posicao]);
                    printf("\nNome: %s", nome[posicao]);
                    printf("\nPreco: %.2f", preco[posicao]);
                    printf("\nQuantidade: %d\n", quantidade[posicao]);
                }
                break;

            case 3:
                if (total == 0) {
                    printf("\nNenhum registro cadastrado.\n");
                } else {
                    printf("\n--- Lista de produtos ---");
                    for (i = 0; i < total; i++) {
                        printf("\nCodigo: %d", codigo[i]);
                        printf("\nNome: %s", nome[i]);
                        printf("\nPreco: %.2f", preco[i]);
                        printf("\nQuantidade: %d\n", quantidade[i]);
                    }
                }
                break;

            case 4:
                printf("\nCodigo do produto a alterar: ");
                scanf("%d", &codigoBusca);

                posicao = -1;
                for (i = 0; i < total; i++) {
                    if (codigo[i] == codigoBusca) {
                        posicao = i;
                    }
                }

                if (posicao == -1) {
                    printf("\nRegistro nao encontrado.\n");
                } else {
                    printf("\nDigite os novos dados (o codigo e mantido).");
                    printf("\nNovo nome: ");
                    scanf(" %49[^\n]", nome[posicao]);

                    printf("Novo preco (use ponto, ex: 59.90): ");
                    do {
                        ok = (scanf("%f", &preco[posicao]) == 1);
                        while ((c = getchar()) != '\n' && c != EOF) {
                            if (c != ' ' && c != '\t') ok = 0;
                        }
                        if (!ok) printf("Valor invalido. Digite o preco novamente: ");
                    } while (!ok);

                    printf("Nova quantidade: ");
                    do {
                        ok = (scanf("%d", &quantidade[posicao]) == 1);
                        while ((c = getchar()) != '\n' && c != EOF) {
                            if (c != ' ' && c != '\t') ok = 0;
                        }
                        if (!ok) printf("Valor invalido. Digite a quantidade novamente: ");
                    } while (!ok);
                    printf("\nProduto alterado com sucesso!\n");
                }
                break;

            case 5:
                printf("\nCodigo do produto a excluir: ");
                scanf("%d", &codigoBusca);

                posicao = -1;
                for (i = 0; i < total; i++) {
                    if (codigo[i] == codigoBusca) {
                        posicao = i;
                    }
                }

                if (posicao == -1) {
                    printf("\nNao foi possivel excluir.\n");
                } else {
                    for (i = posicao; i < total - 1; i++) {
                        codigo[i] = codigo[i + 1];
                        preco[i] = preco[i + 1];
                        quantidade[i] = quantidade[i + 1];

                        int j = 0;
                        while (nome[i + 1][j] != '\0') {
                            nome[i][j] = nome[i + 1][j];
                            j++;
                        }
                        nome[i][j] = '\0';
                    }
                    total--;
                    printf("\nProduto excluido com sucesso!\n");
                }
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
