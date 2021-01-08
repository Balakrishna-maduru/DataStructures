#include<stdlib.h>
#include<stdio.h>
struct Node {
	int data;
	Node* next;
};

Node* head = NULL;
void Push(int data) {
	struct Node* node = (Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = head;
	head = node;
}

void Pop() {
	if (head == NULL)
		printf("Error : Stack is empty\n");
	head = head->next;
}

void Top() {
	struct Node* temp = head;
	if (temp == NULL)
		printf("Error : while top Stack is empty\n");
		return;
	printf("Top of the stack : %d\n", head->data);
}

void Print() {
	struct Node* temp = head;
	if (temp == NULL) {
		printf("Error : while printing stack is empty\n");
		return;
	}
	printf("List is: ");
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");

}

int main() {

	Push(1);Print();
	Push(2);Print();
	Pop();
	Push(3);Print();
	Push(4);Print();
	Pop();Print();
	Pop();Print();
	Pop();Print();
	Top();
	return 0;
}