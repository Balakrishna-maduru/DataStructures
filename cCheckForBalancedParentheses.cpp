#include<stdio.h>
#include<stack>
#include<cstring>

int main() {

	char str[] = "()";

	for (int i = 0; i < strlen(str);i++) {
		printf("%c ", str[i]);
	}

	return 0;
}