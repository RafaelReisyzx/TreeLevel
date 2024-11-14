#include "tree.h"

int main() {
    Node* root = NULL;
    int choice, n, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Criar árvore aleatória\n");
        printf("2. Criar árvore\n");
        printf("3. Adicionar novo elemento na árvore\n");
        printf("4. Exibir árvore\n");
        printf("5. Deletar árvore\n");
        printf("6. Exibir Sugestões\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o número de elementos para a árvore: ");
                scanf("%d", &n);
                root = generateRandomTree(n);
                break;

            case 2:
                printf("Digite o número de elementos para a árvore: ");
                scanf("%d", &n);
                root = createTreeFromUserInput(n);
                break;

            case 3:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value);
                root = insert(root, value);
                displayMaxLevel(root);
                printf("Caminho mais longo: ");
                printLongestPath(root);
                printf("\n");
                break;

            case 4:
                displayTree(root);
                break;

            case 5:
                deleteTree(root);
                root = NULL;
                printf("Árvore deletada.\n");
                break;

            case 6:
                suggestRotations(root);
                break;

            case 7:
                deleteTree(root);
                exit(0);

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
