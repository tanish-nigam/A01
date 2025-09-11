#include "A01.h"

Node *createNode(char input) {
    Node *newNode = malloc(sizeof(Node));
    newNode->name = input;
    newNode->parent = NULL;
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

//BFS search algorithm for our tree
Node *findNode(Node *root, char name) {
    if (root == NULL) return NULL;
    if (root->name == name) return root;
    
    Node *result = findNode(root->sibling, name);
    if (result != NULL) return result;
    
    return findNode(root->child, name);
}

//Add the correct relationship for the child and parent
int addRelationship(Node **trees, int *size, char parentChar, char childChar) {
    for (int i = 0; i < *size; i++) {
        Node *existingChild = findNode(trees[i], childChar);
        if (existingChild != NULL) {
            if (existingChild->parent != NULL) {
                return 0; 
            }
        }
    }
    
    Node *parentNode = NULL;
    int parentTreeIndex = -1;
    
    for (int i = 0; i < *size; i++) {
        parentNode = findNode(trees[i], parentChar);
        if (parentNode != NULL) {
            parentTreeIndex = i;
            break;
        }
    }
    
    Node *childNode = NULL;
    int childTreeIndex = -1;
    
    for (int i = 0; i < *size; i++) {
        childNode = findNode(trees[i], childChar);
        if (childNode != NULL) {
            childTreeIndex = i;
            break;
        }
    }
    
    if (parentNode == NULL) {
        parentNode = createNode(parentChar);
        trees[*size] = parentNode;
        (*size)++;
    }
    
    if (childNode == NULL) {
        childNode = createNode(childChar);
    } else if (childTreeIndex != -1 && childTreeIndex != parentTreeIndex) {
        for (int i = childTreeIndex; i < *size - 1; i++) {
            trees[i] = trees[i + 1];
        }
        (*size)--;
    }
    
    childNode->parent = parentNode;
    
    //adds child in alphabetical order
    if (parentNode->child == NULL) {
        parentNode->child = childNode;
    } else {
        Node *current = parentNode->child;
        Node *prev = NULL;
        
        while (current != NULL && current->name < childChar) {
            prev = current;
            current = current->sibling;
        }
        
        if (prev == NULL) {
            childNode->sibling = parentNode->child;
            parentNode->child = childNode;
        } else {
            prev->sibling = childNode;
            childNode->sibling = current;
        }
    }
    
    return 1; 
}

//checks the nonvalid cycle case 
int hasCycle(Node *node) {
    if (node == NULL) return 0;
    
    Node *child = node;
    Node *parent = node;
    
    while (parent != NULL && parent->parent != NULL) {
        child = child->parent;
        parent = parent->parent;
        if (parent != NULL) parent = parent->parent;
        
        if (child == parent) {
            return 1;
        }
    }
    return 0;
}

void printLevel(Node *nodes[], int count) {
    if (count == 0) return;
    
    char *groups[26];
    int groupCount = 0;
    Node *nextLevel[26];
    int nextCount = 0;
    
    for (int i = 0; i < count; i++) {
        Node *node = nodes[i];
        
        if (node->child == NULL) {
            groups[groupCount] = malloc(sizeof(char)*2);
            groups[groupCount][0] = '#';
            groups[groupCount][1] = '\0';
            groupCount++;
        } else {
            int childCount = 0;
            Node *child = node->child;
            while (child != NULL) {
                childCount++;
                nextLevel[nextCount++] = child;
                child = child->sibling;
            }
            
            char *group = malloc(sizeof(char)*(childCount + 1));
            child = node->child;
            for (int j = 0; j < childCount; j++) {
                group[j] = child->name;
                child = child->sibling;
            }
            group[childCount] = '\0';
            groups[groupCount++] = group;
        }
    }
    
    for (int i = 0; i < groupCount; i++) {
        if (i > 0) printf(" ");
        printf("%s", groups[i]);
        free(groups[i]);
    }
    printf("\n");
    
    if (nextCount > 0) {
        printLevel(nextLevel, nextCount);
    }
}

void printHierarchy(Node *root) {
    if (root == NULL) return;
    
    printf("%c\n", root->name);
    
    Node *firstLevel[1];
	firstLevel[0] = root;
    printLevel(firstLevel, 1);
}

void freeTree(Node *node) {
    if (node == NULL) return;
    freeTree(node->child);
    freeTree(node->sibling);
    free(node);
}

int comp(const void *a, const void *b) {
    Node *x = (Node *)a;
    Node *y = (Node *)b;
	return (y->name - x->name);
}
