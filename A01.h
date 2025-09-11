#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name; // Name of node
    struct node *child;
    struct node *sibling;
    struct node *parent;
} Node;

Node *createNode(char input);
Node *findNode(Node *root, char name);
int addRelationship(Node **trees, int *size, char parentChar, char childChar);
int hasCycle(Node *node);
void printLevel(Node *nodes[], int count);
void printHierarchy(Node *root);
void freeTree(Node *node);
int comp(const void *a, const void *b);
