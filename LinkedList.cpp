#include <iostream>
using namespace std;

int main() {

	struct Node {
		int data;
		Node* link;
	};

	Node* A;
	A = NULL;

//	Node* temp = (Node*)malloc(sizeof(Node));
	Node* temp = new Node();
//	(*temp).data = 2;
//	(*temp).link = NULL;
	temp->data = 2;
	temp->link = NULL;

	A = temp;
	Node* temp1 = new Node();
	temp1->data = 4;
	temp1->link = NULL;

	Node* tempx = A;
	while (tempx->link != NULL) {
		tempx = tempx->link;
		cout << tempx->data;
	}
	tempx->link = temp1;
	return 0;
}