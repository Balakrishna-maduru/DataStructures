#include<stdlib.h>
#include<stdio.h>
#include<math.h>
struct Node {
	int data;
	struct Node* next;
};

void Insert(Node** head, int data, int n) {

	struct Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if (n == 1) {
		temp->next = *head;
		*head = temp;
		return;
	}
	Node* temp1 = *head;
	for (int i = 0;i < n - 2; i++) {
		temp1 = temp1->next;
	}
	temp->next = temp1->next;
	temp1->next = temp;
}

void Print(Node* head) {
	printf("List is: ");
	while (head != NULL) {
		printf(" %d", head->data);
		head = head->next;
	}
	printf("\n");
}

void PrintMiddleNode(Node* head) {
	Node* temp = head;
	int size = 0;
	int mid = 0;
	while (temp != NULL) {
		temp = temp->next;
		size++;
	}
	mid = ceil(size / 2);
	for (int i = 0;i < mid;i++)
		head = head->next;

	printf("Mid Element in list : %d\n", head->data);
}

void PrintMiddleNodeUsingTwoPointers(Node* head) {
	struct Node* slowPointer = head;
	struct Node* fastPointer = head;

	while (fastPointer != NULL && fastPointer->next != NULL) {
		slowPointer = slowPointer->next;
		fastPointer = fastPointer->next->next;
	}
	printf("Mid Element in list : %d\n", slowPointer->data);
}

int PrintMiddleUsingRecirsion(Node* head, int size, int count) {
	printf(" %d\n", size);
	size++;
	count++;
	if (head == NULL)
		return size;
	size = PrintMiddleUsingRecirsion(head->next, size, count);
//	if (ceil(size / 2) == count)
//		printf("Mid Element in list : %d\n", head->data);
}

int main() {
	int i;
	struct Node* head = NULL;
	Insert(&head, 1, 1);
	Insert(&head, 2, 2);
	Insert(&head, 3, 3);
	Insert(&head, 4, 4);
	Insert(&head, 5, 5);
//	Insert(&head, 6, 6);
//	Insert(&head, 7, 7);
	Print(head);
	PrintMiddleNode(head);
	PrintMiddleNodeUsingTwoPointers(head);
	i = PrintMiddleUsingRecirsion(head, 0, 0);
	return 0;
}