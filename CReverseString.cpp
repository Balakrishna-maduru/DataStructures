#include<stdio.h>
#include<cstring>

int main() {
	int i, j;
	char temp;
	i = 0;
	char C[] = "HELLO";
	printf("%s\n", C);
	j = strlen(C);
	while (i < j) {
		temp = C[i];
		C[i] = C[j];
		C[j] = temp;
		i++;
		j--;
	}
	printf("%c \n", C[i]);
	return 0;
}