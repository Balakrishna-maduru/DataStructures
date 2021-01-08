#include<stdlib.h>
#include<stdio.h>

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

int main() {
	struct Node* head = NULL;
	printf("How many numbers?\n");
	int n, i, data, pos;
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		printf("Enter then number \n");
		scanf("%d%d", &data, &pos);
		Insert(&head, data, pos);
		Print(head);
	}
}