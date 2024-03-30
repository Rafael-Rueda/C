#include <iostream>
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Node {
	public:
		int data;
		Node *next;
};

Node *LStart = NULL;

void printList() {
	Node *aux;
	aux = LStart;
	int c = 0;
	
	if (aux != NULL) {
		printf("=-=-=-=-=-= Imprimindo a lista encadeada =-=-=-=-=-=\n");
			
		while (aux != NULL) {
			printf("[Index: %d] | [Data: %d] | [Next: %p]\n", c, aux->data, aux->next);
			aux = aux->next;
			c++;
		}
		
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	} else {
		printf("Nothing to print !\n");
	}
}

void appendFront(int value) {
	Node *aux;
	aux = (Node*) malloc(sizeof(Node));
	aux->data = value;
	aux->next = LStart;
	LStart = aux;
}

void appendLast(int value) {
	Node *aux;
	Node *aux2;
	
	aux = LStart;
	aux2 = (Node*) malloc(sizeof(Node));
	
	while(aux->next != NULL) {
		aux = aux->next;
	}
	
	aux2->data = value;
	aux2->next = NULL;
	
	aux->next = aux2;
	
}

int popFront() {
	if (LStart == NULL) {
		printf("Empty list !\n");
		return -1;	
	}
	
	Node *aux;
	aux = LStart;
	
	int poppedData = aux->data;
	
	LStart = LStart->next;
	free(aux);
	
	return poppedData;
}

int popLast() {
	if (LStart == NULL) {
		printf("Empty list !\n");
		return -1;	
	}
	
	Node *aux;
	Node *aux2;
	
	aux = LStart;
	aux2 = LStart;
	
	while (aux->next != NULL) {
		if (aux != aux2 && aux2->next != NULL) {
			aux2 = aux2->next;
		}
		aux = aux->next;
	}
	
	int poppedData = aux->data;
	
	aux2->next = NULL;
	free(aux);
	
	return poppedData;
}

void remove(int index) {
	int c = 0;
	Node *aux;
	Node *aux2;
	
	aux = LStart;
	aux2 = NULL;
	while (aux->next != NULL && c != index) {
		aux2 = aux;
		aux = aux->next;
		c++;
	}
	
	if (aux == NULL) {
		printf("Invalid index\n");
		return;
	}
	
	aux2->next = aux->next;
	free(aux);
}

bool search(int value) {
	int c = 0;
	Node *aux;
	
	aux = LStart;
	
	while (aux != NULL) {
		if (aux->data == value) {
			printf("Value found at index: %d\n", c);
			return true;
		}
		aux = aux->next;
		c++;
	}
	
	printf("Value not found !\n");
	return false;
}

int main(int argc, char** argv) {
	
	printList();
	appendFront(9);
	printList();
	appendFront(12);
	printList();
	appendLast(15);
	printList();
	appendLast(15);
	printList();
	popFront();
	printList();
	popLast();
	printList();
	appendFront(99);
	appendFront(98);
	appendFront(97);
	appendLast(10);
	appendLast(11);
	appendLast(12);
	printList();
	remove(5);
	printList();
	search(99);
	popLast();
	popLast();
	popLast();
	popLast();
	popFront();
	popFront();
	popFront();
	popFront();
	popLast();
	printList();
	
	
	return 0;
}

