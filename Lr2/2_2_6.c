#include <stdio.h>
#include <math.h>

int factorial(int n)
{
	if (n < 0) return 0;
	if (n == 0) return 1;
	else return n * factorial(n - 1);
}

double calcRight(double x, int n, double E, int *numberE)
{
	double result = 0, right = 0, temp = x;
	for (int i = 1; i <= n; i++)
	{
		right += temp;
		temp *= (-1 * x * x) / ((2. * i + 1) * (2.*i));
		if (i == n) result = right;
		if (abs(sin(x) - right) < E && *numberE == 0) 
			*numberE = i;
	}
	if (*numberE == 0)
		*numberE = n+13;

	return result;
}

int positiveIntegerInput(char buffer[])
{
	int i = 0, result;
	for (; buffer[i] != '\0'; i++)
	{
		if (i > 8) return 0;
		if (buffer[i] > '9' || buffer[i] < '0') return 0;
	}
	result = atoi(buffer);
	if (result == 0) return 0;
	return 1;
}

int floatInput(char buffer[])
{
	int i;

	if (strlen(buffer) > 20) return 0;
	for (i = 0; i < strlen(buffer); i++)
	{
		if ((buffer[i] > '9' || buffer[i] < '0') && buffer[i] != '.' && buffer[i] != '-') return 0;
	}
	return 1;
}


int main()
{
	int numberE = 0; /* | sin (X) - right | < EPSILON, when N = nEps */
	double x, E;
	int n;
	char buffer[30];

	printf_s("Enter integer N : ");
	scanf_s("%s", buffer, sizeof(buffer));
	while (positiveIntegerInput(buffer) == 0)
	{
		printf_s("Incorrect input! Enter positive integer number (<9 digits)!\n");
		scanf_s("%s", buffer, sizeof(buffer));
	}
	n = atoi(buffer);

	printf_s("Enter float -1 <= X <= 1: ");
	scanf_s("%s", buffer, sizeof(buffer));
	while (floatInput(buffer) == 0)
	{
		printf_s("Incorrect input! Enter float number (<9 digits)!\n");
		scanf_s("%s", buffer, sizeof(buffer));
	}
	x = atof(buffer);


	printf_s("Enter float E : ");
	scanf_s("%s", buffer, sizeof(buffer));
	while (floatInput(buffer) == 0)
	{
		printf_s("Incorrect input! Enter real number (<9 digits)!\n");
		scanf_s("%s", buffer, sizeof(buffer));
	}
	E = atof(buffer);
	E = abs(E);
	printf_s("left = %f, right = %f\n", sin(x), calcRight(x, n, E, &numberE));
	printf_s("When N = %d\n", numberE);

	return 0;
}