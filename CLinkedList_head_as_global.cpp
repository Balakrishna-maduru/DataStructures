#include<stdlib.h>
#include<stdio.h>

struct Node {
	int data;
	struct Node* next;
};

void Insert(Node** head, int x) {

	struct Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if (*head != NULL) temp->next = *head;
	*head = temp;
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
	int n, i, x;
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		printf("Enter then number \n");
		scanf("%d", &x);
		Insert(&head, x);
		Print(head);
	}
}