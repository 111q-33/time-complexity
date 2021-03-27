#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void findnum(int* n1, int*n2, int*arr, int size)
{
	int n = 0;
	int count = 0;
	int s1 = 0;
	int s2 = 0;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		n ^= arr[i];
	}
	int d = n;
	while (1)
	{
		if (d & 1)
		{
			break;
		}
		d = d >> 1;
		count++;
	}
	int arr1[50] = { 0 };
	int arr0[50] = { 0 };
	for (i = 0; i < size; i++)
	{
		if ((arr[i]>>count) & 1)
		{
			arr1[i] = arr[i];
		}
		else
		{
			arr0[i] = arr[i];
		}
	}
	for (i = 0; i < size; i++)
	{
		s1 ^= arr1[i];
		s2 ^= arr0[i];
	}
	*n1 = s1;
	*n2 = s2;
}
int main()
{
	int arr[] = { 1, 2, 10, 4, 1, 4, 3, 3 };
	int n1, n2;
	findnum(&n1, &n2, arr, sizeof(arr) / sizeof(arr[0]));
	printf("%d %d\n", n1, n2);
	return 0;
}