#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da árvore genérica
typedef struct Node {
    int data;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

// Função para inserir um filho a um nó específico
void insertChild(Node* parent, int data) {
    Node* newNode = createNode(data);
    if (parent->firstChild == NULL) {
        parent->firstChild = newNode;
    } else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = newNode;
    }
}

// Função auxiliar para imprimir a árvore em formato de árvore
void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    // Imprime espaços para a indentação de acordo com o nível do nó
    for (int i = 0; i < level; i++) {
        printf("   ");
    }

    // Imprime o valor do nó
    printf("%d\n", root->data);

    // Imprime o primeiro filho e os irmãos do nó
    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

// Função para liberar a memória alocada pela árvore
void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->firstChild);
    freeTree(root->nextSibling);
    free(root);
}
// Função recursiva para buscar um valor na árvore
Node* search(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == value) {
        return root;
    }

    // Buscar no primeiro filho
    Node* found = search(root->firstChild, value);
    if (found != NULL) {
        return found;
    }

    // Buscar nos irmãos
    return search(root->nextSibling, value);
}

int main() {
    Node* root = createNode(1);
    insertChild(root, 2);
    insertChild(root, 3);
    insertChild(root, 4);

    Node* child2 = root->firstChild;
    insertChild(child2, 5);
    insertChild(child2, 6);

    Node* child3 = child2->nextSibling;
    insertChild(child3, 7);

    printf("Tree structure:\n");
    printTree(root,0);

    int valueToSearch = 5;
    Node* result = search(root, valueToSearch);
    if (result != NULL) {
        printf("Value %d found in the tree.\n", valueToSearch);
    } else {
        printf("Value %d not found in the tree.\n", valueToSearch);
    }

    // Liberar a memória alocada pela árvore
    freeTree(root);

    return 0;
}
