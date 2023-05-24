#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b)
{
	double* da = (double*)a, * db = (double*)b;
	return *da - *db;
}

int main()
{
	int n;
	double *d;
	int i;

	printf("\nEnter the size of the array: ");
	scanf_s("%d", &n);

	d = (double*)malloc(n * sizeof(double));
	
	for (i = 0; i < n; i++)
	{
		printf("\nEnter a number:");
		scanf_s("%lf", &d[i]);
	}

	qsort(d, n, sizeof(double), compare);

	for (i = 0;i < n;i++)
	{
		printf("\n%.1lf ", d[i]);
	}
	free(d);
	return 0;
}