#include <stdio.h>
#include <stdlib.h>
#include "A01.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    Node *trees[26] = {NULL};
    int size = 0;
    char buffer[256];
    int valid = 1;
    while (fgets(buffer, sizeof(buffer), file) != NULL && valid) {
        char parentChar = buffer[0];
        char childChar = buffer[1];
        if (!addRelationship(trees, &size, parentChar, childChar)) {
            valid = 0;
            break;
        }
	}

	if (valid) {
        for (int i = 0; i < size; i++) {
            if (hasCycle(trees[i])) {
                valid = 0;
                break;
            }
        }
    }
    if (!valid) {
        printf("INVALID\n");
    } else {
		qsort(trees, size, sizeof(Node), comp);
        for (int i = 0; i < size; i++) {
            if (i > 0) {
				printf("\n");
			}
            printHierarchy(trees[i]);
        }
    }
    
    for (int i = 0; i < size; i++) {
        freeTree(trees[i]);
    }
    fclose(file);

    return EXIT_SUCCESS;
}
