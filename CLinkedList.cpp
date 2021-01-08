#include<stdlib.h>
#include<stdio.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head;

void Insert(int x) {

	struct Node* temp1 = (Node*)malloc(sizeof(struct Node));
	temp1->data = x;
	temp1->next = head;
	head = temp1;

}

void Print() {
	struct Node* temp = head;
	printf("List is: ");
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");

}

int main() {
	head = NULL;
	printf("How many numbers?\n");
	int n, i, x;
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		printf("Enter then number \n");
		scanf("%d", &x);
		Insert(x);
		Print();
	}
}