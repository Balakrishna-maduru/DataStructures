#include<stdio.h>

int front = -1;
int rear = -1;
int N = 5;
int A[10];

bool IsEmpty() {
	if (front == -1 and rear == -1)
		return true;
	else
		return false;
}

void Enqueue(int data) {
	if((rear+1)%N == front)
		return;
	if(IsEmpty()) {
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear + 1) % N;
	}
	A[rear] = data;
}

void Dequeue() {
	if(IsEmpty())
		return;
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else
		front = (front + 1) % N;
}

int Front() {
	if (front == -1) {
		printf("Error : Queue is empty");
		return 0;
	}
	return A[front];
}
void Print() {
	for (int i = 0;i < N;i++)
		printf("%d ",A[i]);
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

	return 0;
}