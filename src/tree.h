#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value);
Node* insert(Node* root, int value);
void displayTree(Node* root);
void deleteTree(Node* root);
Node* generateRandomTree(int n);
Node* createTreeFromUserInput(int n);
Node* deleteNode(Node* root, int value);
Node* findMinNode(Node* root);
int getMaxLevel(Node* root);
void displayMaxLevel(Node* root);
void printLongestPath(Node* root);
void suggestRotations(Node* root);

#endif 
