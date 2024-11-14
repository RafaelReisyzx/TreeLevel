#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

static int isRootDisplayed = 0;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar memória para o nó.\n");
        return NULL;
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}


int getMaxLevel(Node* root) {
    if (root == NULL) {
        return -1;  
    }
    
    int leftLevel = getMaxLevel(root->left);
    int rightLevel = getMaxLevel(root->right);
    
    return (leftLevel > rightLevel ? leftLevel : rightLevel) + 1;
}


void displayMaxLevel(Node* root) {
    int maxLevel = getMaxLevel(root);
    printf("Nível máximo da árvore: %d\n", maxLevel);
}


void printLongestPath(Node* root) {
    if (root == NULL) {
        return;
    }


    int leftLevel = getMaxLevel(root->left);
    int rightLevel = getMaxLevel(root->right);

    if (leftLevel > rightLevel) {
        printf("%d -> ", root->value);
        printLongestPath(root->left);
    } else {
        printf("%d -> ", root->value);
        printLongestPath(root->right);
    }
}


void displayTree(Node* root) {
    if (root == NULL) {
        return;
    }
    

    if (!isRootDisplayed) {
        printf("Raiz Principal:%d\n", root->value);
        isRootDisplayed = 1;  
    }
    
    
    if (root->left != NULL)
        printf("Filho Esquerdo de %d:%d\n", root->value, root->left->value);
    else
        printf("Filho Esquerdo de %d:NULL\n", root->value);
    
    if (root->right != NULL)
        printf("Filho Direito de %d:%d\n", root->value, root->right->value);
    else
        printf("Filho Direito de %d:NULL\n", root->value);

    displayTree(root->left);
    displayTree(root->right);
}


void deleteTree(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}


Node* generateRandomTree(int n) {
    srand(time(NULL));
    Node* root = NULL;
    printf("Números aleatórios gerados para a árvore:\n");
    for (int i = 0; i < n; i++) {
        int randomValue = rand() % 100 + 1; 
        printf("%d ", randomValue);
        root = insert(root, randomValue);
    }
    printf("\n");


    isRootDisplayed = 0;

    displayMaxLevel(root);
    printf("Caminho mais longo: ");
    printLongestPath(root);
    printf("\n");

    return root;
}

Node* createTreeFromUserInput(int n) {
    Node* root = NULL;
    printf("Digite os números para a árvore:\n");
    for (int i = 0; i < n; i++) {
        int value;
        printf("Número %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    isRootDisplayed = 0;

    displayMaxLevel(root);
    printf("Caminho mais longo: ");
    printLongestPath(root);
    printf("\n");

    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMinNode(root->right);

        root->value = temp->value;

        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

Node* findMinNode(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

void suggestRotations(Node* root) {
    if (root == NULL) {
        return;  
    }

    int leftLevel = (root->left != NULL) ? getMaxLevel(root->left) : -1; 
    int rightLevel = (root->right != NULL) ? getMaxLevel(root->right) : -1; 

    if (leftLevel > rightLevel) {
        printf("Sugerindo rotação à direita no nó com valor %d, pois a subárvore esquerda é mais profunda.\n", root->value);
    } else if (rightLevel > leftLevel) {
        printf("Sugerindo rotação à esquerda no nó com valor %d, pois a subárvore direita é mais profunda.\n", root->value);
    } else {
        printf("A árvore parece estar equilibrada. Nenhuma rotação necessária neste nó com valor %d.\n", root->value);
    }

    if (root->left != NULL) {
        suggestRotations(root->left);
    }
    if (root->right != NULL) {
        suggestRotations(root->right);
    }
}
