typedef struct node{
	char name;//Name of node
	struct node *child;
	struct node *sibiling;
}Node;

Node *createNode(char input);
void printStruct(Node *parent);
void makeHiearchy(char *filename);
void addChild(char parent, char child);
