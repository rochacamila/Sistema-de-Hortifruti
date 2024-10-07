#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    int id;
    char nome[50];
    float preco_compra;
    float preco_venda;
} Produto;

// Fun��o para limpar a tela
void limpar_tela() {
    system("clear || cls");
}

// Fun��o para exibir o layout inicial
void exibir_layout() {
    limpar_tela();

}

// Fun��o para salvar os produtos no arquivo CSV
void salvar_arquivo(Produto produtos[], int quantidade) {
    FILE *arquivo = fopen("produtos.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Cabe�alho do arquivo
    fprintf(arquivo, "ID,Nome,Preco de Compra,Preco de Venda\n");

    // Salvando os produtos
    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d,%s,%.2f,%.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco_compra, produtos[i].preco_venda);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso no arquivo produtos.csv!\n");
}

// Fun��o para comparar produtos por nome (usada no qsort)
int compara_nome(const void *a, const void *b) {
    Produto *prodA = (Produto *)a;
    Produto *prodB = (Produto *)b;
    return strcmp(prodA->nome, prodB->nome);
}

// Fun��o principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    Produto produtos[MAX]; // Array para armazenar os produtos
    int quantidade = 0, opcao;
    int opcaovenda, opcaocc, financeiro, financeiro1;

    // Carregar produtos do arquivo
    FILE *arquivo = fopen("produtos.csv", "r");
    if (arquivo != NULL) {
        char linha[100];
        fgets(linha, sizeof(linha), arquivo); // Ignora o cabe�alho
        while (fscanf(arquivo, "%d,%49[^,],%f,%f\n", &produtos[quantidade].id, produtos[quantidade].nome, &produtos[quantidade].preco_compra, &produtos[quantidade].preco_venda) == 4) {
            quantidade++;
        }
        fclose(arquivo);
    }

    while (1) {
        exibir_layout();
        printf("Bem-vindo � aba de administrador. Digite o n�mero do m�dulo que voc� deseja acessar:\n");
        printf("1- Vendas\n");
        printf("2- Compra / Cadastro\n");
        printf("3- Financeiro\n");
        printf("4- Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1) { // M�dulo de Vendas
            while (1) {
                printf("Escolha uma op��o:\n");
                printf("1- Registrar pedido de venda\n");
                printf("2- Cancelar pedido de venda\n");
                printf("3- Retornar ao menu anterior\n");
                scanf("%d", &opcaovenda);

                if (opcaovenda == 1) {
                    printf("Registrar pedido de venda (em desenvolvimento)...\n");
                    // Implementar l�gica para registrar pedido de venda
                } else if (opcaovenda == 2) {
                    printf("Qual pedido deseja cancelar? (em desenvolvimento)...\n");
                    // Implementar l�gica para cancelar pedido de venda
                } else if (opcaovenda == 3) {
                    break; // Retorna ao menu anterior
                } else {
                    printf("Op��o n�o encontrada, digite novamente.\n");
                }
            }
        } else if (opcao == 2) { // M�dulo de Compra/Cadastro
            while (1) {
                printf("Escolha uma op��o:\n");
                printf("1- Registrar nova compra\n");
                printf("2- Registrar novos produtos\n");
                printf("3- Retornar ao menu anterior\n");
                scanf("%d", &opcaocc);

                if (opcaocc == 1) {
                    printf("Registre quais produtos foram comprados (em desenvolvimento)...\n");
                    // Implementar l�gica para registrar compras
                } else if (opcaocc == 2) { // Cadastro de Novos Produtos
                    Produto novo_produto;
                    novo_produto.id = quantidade + 1;

                    printf("Digite o nome do produto:\n> ");
                    scanf(" %49[^\n]", novo_produto.nome); // L� o nome do produto

                    printf("Digite o pre�o de compra do produto:\n> ");
                    scanf("%f", &novo_produto.preco_compra); // L� o pre�o de compra

                    printf("Digite o pre�o de venda do produto:\n> ");
                    scanf("%f", &novo_produto.preco_venda); // L� o pre�o de venda

                    // Adiciona o novo produto ao array
                    produtos[quantidade] = novo_produto;
                    quantidade++;

                    // Ordena os produtos por nome
                    qsort(produtos, quantidade, sizeof(Produto), compara_nome);

                    // Salva os produtos no arquivo CSV
                    salvar_arquivo(produtos, quantidade);

                    printf("\nProduto cadastrado com sucesso!\n\n");
                    printf("Pressione Enter para continuar...");
                    getchar(); // Limpa o buffer
                    getchar(); // Aguarda o usu�rio pressionar Enter
                } else if (opcaocc == 3) {
                    break; // Retorna ao menu anterior
                } else {
                    printf("Op��o n�o encontrada, digite novamente.\n");
                }
            }
        } else if (opcao == 3) { // M�dulo Financeiro
            while (1) {
                printf("Escolha uma op��o:\n");
                printf("1- Emitir relat�rio financeiro\n");
                printf("2- Realizar pagamento\n");
                printf("3- Retornar ao menu anterior\n");
                scanf("%d", &financeiro);

                if (financeiro == 1) {
                    printf("Digite o m�s e ano de refer�ncia (em desenvolvimento)...\n");
                    // Implementar l�gica para emitir relat�rio financeiro
                } else if (financeiro == 2) {
                    printf("1- Pagamento de funcion�rio\n");
                    printf("2- Pagamento de fornecedor\n");
                    printf("3- Despesas (Aluguel, luz, �gua, etc)\n");
                    printf("4- Pagar clientes (Reembolso/Devolu��o)\n");
                    printf("5- Retornar ao menu principal\n");
                    scanf("%d", &financeiro1);

                    if (financeiro1 >= 1 && financeiro1 <= 4) {
                        printf("Escolha a op��o %d (em desenvolvimento)...\n", financeiro1);
                        // Implementar l�gica para realizar pagamento
                    } else if (financeiro1 == 5) {
                        break; // Retorna ao menu anterior
                    } else {
                        printf("Op��o n�o encontrada, digite novamente.\n");
                    }
                } else if (financeiro == 3) {
                    break; // Retorna ao menu anterior
                } else {
                    printf("Op��o n�o encontrada, digite novamente.\n");
                }
            }
        } else if (opcao == 4) {
            printf("\nSaindo do sistema... At� mais!\n");
            break; // Sai do sistema
        } else {
            printf("Op��o inv�lida, tente novamente.\n");
        }
    }
    return 0;
}
