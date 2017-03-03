#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


int My_str_compare(void *data1, void *data2){
	if (*(int *)data1 > *(int *)data2){
		return 1;
	}
	else {
		return -1;
	}
}

int Partition(void *data, int size, int left, int right, int My_compare(void *, void *))
{
	char *d = (char *)data;
	int i, mid;
	char *p = (char *)malloc(size);
	for (i = left + 1, mid = left; i <= right; i++){
		if (My_compare(d + size*i, d + size*left) > 0){
			mid++;
			memcpy(p, d + size*i, size);
			memcpy(d + size*i, d + size*mid, size);
			memcpy(d + size*mid, p, size);
		}
	}
	memcpy(p, d + size*mid, size);
	memcpy(d + size*mid, d+size*left,size);
	memcpy(d + size*left, p, size);
	return mid;
}

void My_qsort(void *data, int size, int left, int right, int My_compare(void *, void *))
{
	if (left >= right){
		return;
	}
	int mid = Partition(data, size, left, right, My_compare);
	My_qsort(data, size, left, mid - 1, My_compare);
	My_qsort(data, size, mid + 1, right, My_compare);
}

void My_Qsort(void *data, int size, int count, int My_compare(void *, void*))
{
	int right = count - 1;
	int left = 0;
	My_qsort(data, size, left, right, My_compare);
}

const int COUNT = 10000;

void test(){
	int a[COUNT] = { 0 };
	srand((unsigned int)time(NULL));
	for (int i = 0; i < COUNT; i++){
		a[i] = rand() % 100;
		printf("%d ", a[i]);
	}
	printf("\n");

	My_Qsort(a, sizeof(a[0]), sizeof(a) / sizeof(a[0]), My_str_compare);
	for (int i = 0; i < COUNT; i++){
		printf("%d ", a[i]);
	}
}


int main(void)
{
	test();
	system("pause");
	return 0;
}