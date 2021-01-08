#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void Enqueue(int data) {
	Node* node = (struct Node*)malloc(sizeof(struct Node*));
	node->data = data;
	node->next = NULL;
	if (front == NULL && rear == NULL) {
		front = rear = node;
	}
	else
		rear->next = node;
		rear = node;
}

void Dequeue() {
	struct Node* node = front;
	if (front == NULL) return;
	if (front == rear)
		front = rear = NULL;
	else
		front = front->next;
	free(node);
	
}

void Front() {
	if (front == NULL) {
		printf("Error: Queue is Empty");
		return;
	}
	printf("Front: %d\n", front->data);
}
void Print() {
	struct Node* temp = front;
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");

}


int main() {
	Enqueue(1);Print();
	Enqueue(2);Print();
	Enqueue(3);Print();
	Enqueue(4);Print();
	Dequeue();Print();
	Dequeue();Print();
	Dequeue();Print();
	Enqueue(5);Print();
	Enqueue(6);Print();
	Enqueue(7);Print();
	Enqueue(8);Print();
	Front();
	return 0;
}