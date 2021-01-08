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

void Delete(Node** head, int pos) {
	struct Node* temp = *head;
	if (pos == 1) {
		*head = temp->next;
		free(temp);
		return;
	}
	for (int i = 0; i < pos - 2;i++)
		temp = temp->next;
	struct Node* temp1 = temp->next;
	temp->next = temp1->next;
	free(temp1);
}
void Reverse(Node** head) {
	struct Node *current,*next, *prev;
	current = *head;
	prev = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

void PrintRecursion(Node* head) {
	if (head == NULL) return;
	printf("%d ", head->data);
	PrintRecursion(head->next);
}

void ReverseRecursion(Node** head, Node* p) {
	if (p->next == NULL) {
		*head = p;
		return;
	}
	ReverseRecursion(head, p->next);
	struct Node* q = p->next;
	q->next = p;
	p->next = NULL;
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
	printf("PrintRecursion : ");
	PrintRecursion(head);
//	printf("\nReverse : ");
//	Reverse(&head);
//	Print(head);
	printf("\n Reverse list using recirsion : ");
	ReverseRecursion(&head, head);
	Print(head);
	printf("\nDeleting second elament : ");
	Delete(&head, 2);
	Print(head);
}