#include<stdlib.h>
#include<stdio.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;

void Print() {
	struct Node* temp = head;
	printf("List is: ");
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint() {
	struct Node* temp = head;
	if (temp == NULL) return;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	printf("Reverse : ");
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

Node* GetNewNode(int data) {
	struct Node* node = (Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;

	return node;

}

void InsertAtTail(int data) {
	Node* node = GetNewNode(data);
	struct Node* temp = head;
	if (head == NULL) {
		head = node;
		return;
	}
	while (temp->next != NULL) temp = temp->next;
	temp->next = node;
	node->prev = temp;
}

void InsertAtHead(int data) {
	Node* node = GetNewNode(data);
	if (head == NULL){
		head = node;
		return;
	}
	head->prev = node;
	node->next = head;
	head = node;

}
int main() {
	
	head = NULL;
	InsertAtHead(1);
	InsertAtHead(2);
	InsertAtHead(3);
	InsertAtHead(4);
	InsertAtTail(5);
	Print();
	ReversePrint();

	return 0;
}