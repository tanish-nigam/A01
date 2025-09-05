#include <stdio.h>
#include <stdlib.h>
#include "A01.h"

//creates a new Node 
Node *createNode(char input)
{
	Node *newNode = malloc(sizeof(Node));
	newNode->name = input;
	newNode->child = NULL;
	newNode->sibiling =  NULL;
	return newNode; 
}

//prints the sturcture we create
void printStruct(Node *parent)
{
	printf("%c", parent->name);
	if(parent->sibiling != NULL)
	{
		printStruct(parent->sibiling);
	}
	if(parent->child == NULL)
	{
		printf("\n#"); 
	}
	else
	{
		printf("\n");
		printStruct(parent->child);
	}
}

void makeHiearchy(char *filename)//should be node type
{
	FILE *file = fopen(filename, "r");
	if(file == NULL){

		return;// NULL;
	}

	char buffer[256];
	fgets(buffer, 256, file);
	Node *parent = createNode(buffer[0]);
       	Node *child = createNode(buffer[1]);
	parent->child = child;	
	while(fgets(buffer, 256, file) != NULL)
	{
		if(buffer[1] == parent->name)
		{
			addParent(buffer[0], buffer[1], parent);
		}
		addChild(buffer[0], buffer[1], parent);
	}	
}

//searches for parent then ensures there are no sibilings, when there are sibilings it gets to last sibiling then adds new sibiling
void addChild(char parent, char child, Node *head)
{
	
}

void addParent(char parent, char child, Node *head)
{
	
}

		
