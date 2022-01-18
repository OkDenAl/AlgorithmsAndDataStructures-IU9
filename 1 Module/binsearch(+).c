#include <stdio.h>
#pragma warning (disable: 4996)

int arr[7] = {1, 2, 3, 4, 5, 7, 10};
int X = 7;


int compare(unsigned long i) {
	if (arr[i] < X) return -1;
	if (arr[i] > X) return 1;
	if (arr[i] == X) return 0;
}

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
	size_t left=0, right=nel,index;
	while (left +1 < right) {
		index =(right + left) / 2;
		if ((compare(index)) == 1) right = index;
		else left=index;
	}
	return left;
}

int main() {
	printf("%d", binsearch(10, compare));
	return 0;
}
