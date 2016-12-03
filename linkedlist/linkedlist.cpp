#include <iostream>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;

typedef struct _Node
{
	int data;
	struct _Node* next;
}Node;

/**iniial a node */
Node* alloc_node(int vlaue);

bool add_with_node(Node** pNode, Node* newNode);
bool add_with_value(Node** pNode, int value);

/**delete a node with a specified value */
bool delete_with_value(Node** pNode, int value);
bool _delete_with_value(Node** pNode, int value);

/**get the count of the linkedlist */
int count(Node* pNode);

void print_count(Node* pNode);
void print_nodes(Node* pNode);

int main(int argc, char** argv) {
	
	Node* a = alloc_node(4);
	
	Node* b = alloc_node(8);
	add_with_node(&a, b);
	
	add_with_value(&a, 3);
	print_nodes(a);
	print_count(a);
	
	delete_with_value(&a, 3);
	print_nodes(a);
	print_count(a);
	
	return 0;
}

Node* alloc_node(int value)
{
	Node* pNode;
	pNode = (Node*)malloc(sizeof(Node));
	
	pNode->data = value;
	pNode->next = NULL;
	
	return pNode;
}

bool add_with_node(Node** pNode, Node* newNode)
{
	if(NULL == *pNode){
		*pNode = newNode;
		return true;
	}
	
	add_with_node(&(*pNode)->next, newNode);
}

bool add_with_value(Node** pNode, int value)
{
	if(NULL == *pNode){
		return false;
	}
	
	Node* p = alloc_node(value);
	add_with_node(pNode, p);
}

bool delete_with_value(Node** pNode, int value)
{
	if(NULL == pNode || NULL == *pNode)
		return false;
	
	Node* temp;
	if(value == (*pNode)->data){
		temp = *pNode;
		*pNode = temp->next;
		free(temp);
		return true;
	}
	
	_delete_with_value(pNode, value);
}

bool _delete_with_value(Node** pNode, int value)
{
	if(NULL == *pNode)
		return false;
	
	Node* temp = (*pNode)->next;
	if(value == temp->data){
		(*pNode)->next = temp->next;
		free(temp);
		return true;
	}
	
	_delete_with_value(&(*pNode)->next, value);
}

int count(Node* pNode)
{
	int num = 0;
	while(NULL != pNode){
		num++;
		pNode = pNode->next;
	}
	return num;
}

void print_nodes(Node* pNode){
	if(NULL != pNode){
		printf("%d ",pNode->data);
		print_nodes(pNode->next);
	}else{
		printf("\n");
	}
}

void print_count(Node* pNode)
{
	printf("the count of node: %d\n",count(pNode));
}
