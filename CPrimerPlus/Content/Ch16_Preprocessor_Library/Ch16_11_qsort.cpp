/* qsorter.c -- 用 qsort() 排序一个内含随机值的数组 */
#include <cstdlib>
#include <cstdio>
//#pragma warning(disable:4996)

#define NUM 40
void fillArray(int arr[], int n);
void showArray(const int arr[], int n);
int myComp(const void * p1, const void * p2);

int main(void)
{
	int arr[NUM];
	fillArray(arr, NUM);
	puts("Random list:");
	showArray(arr, NUM);
	qsort(arr, NUM, sizeof(int), myComp);
	puts("Sorted list:");
	showArray(arr, NUM);
	return 0;
}

void fillArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
}

void showArray(const int arr[], int n)
{
	int i = 0;
	for (; i < n; i++)
	{
		printf("%9d", arr[i]);
		if (i % 5 == 4)
			putchar('\n');
	}
	if (i % 5 == 4)
		putchar('\n');
}

int myComp(const void * p1, const void * p2)
{
	int a, b;
	a = *(int *)p1;
	b = *(int *)p2;
	if (a > b) return 1;
	else if (a < b) return -1;
	else return 0;
}

// tips: 
//   1. 示例中 myComp() 为递增排序
//   2. puts() 会自动换行