#include<stdio.h>
#include<string.h>

struct fraction
{
	int numerator;
	int denominator;
};

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void line()
{
	int i = 0;
	while (i < 50)
	{
		printf("=");
		i++;
	}
	printf("\n");
}

void print_fract(struct fraction x, int brackets_flag, int sign_flag, int coeff_flag)
{
	if (sign_flag)
	{
		if (x.numerator > 0)
			printf("+ ");
		else if (x.numerator < 0)
			printf("- ");
		if (x.numerator < 0) x.numerator = -x.numerator;
	}

	if (x.numerator < 0)
		printf("-");
	if (x.numerator < 0) x.numerator = -x.numerator;

	if (x.denominator == 1)
	{
		if(!(x.numerator == 1 && coeff_flag))
			printf("%d", x.numerator);
		return;
	}

	if (brackets_flag)
		printf("(");

	printf("%d / %d", x.numerator, x.denominator);

	if (brackets_flag)
		printf(")");
}

struct MyPolinom
{
	struct fraction a;
	struct fraction b;
	struct fraction c;
	struct fraction d;
	int C;
};

int gcd(int a, int b)
{
	if (a < b)
		swap(&a, &b);
	while (b)
	{
		a %= b;
		swap(&a, &b);
	}

	return a;
}

void adduce_factor(struct fraction *x)
{
	int temp = gcd(x->numerator, x->denominator);
	int sign = 1;
	if (x->numerator < 0)
		sign = -1;
	x->numerator /= temp;
	x->denominator /= temp;
	x->numerator *= sign;
	x->denominator *= sign;
}

int getInput()
{
	int i = 0;
	char buffer[100];

	scanf("%s", buffer);

	if (strlen(buffer) > 20) return -999999787;

	if (buffer[0] == ' ')
	{
		return -999999787;
	}

	if (buffer[i] == '-')
	{
		i++;
	}

	for (; i < strlen(buffer); i++)
	{
		if (buffer[i] > '9' || buffer[i] < '0') return -999999787;
	}
	return atoi(&buffer);
}

void input(struct MyPolinom *polinom)
{
	int tmp = -999999787;
	polinom->C = 0;
	printf("ax^3 + bx^2 + cx + d\n");
	while (tmp == -999999787)
	{
		printf("Enter coefficient a : ");
		tmp = getInput();
		if(tmp == -999999787) printf("Invalid input\n");
	}
	polinom->a.numerator = tmp; polinom->a.denominator = 1;

	tmp = -999999787;
	while (tmp == -999999787)
	{
		printf("Enter coefficient b : ");
		tmp = getInput();
		if (tmp == -999999787) printf("Invalid input\n");
	}
	polinom->b.numerator = tmp; polinom->b.denominator = 1;

	tmp = -999999787;
	while (tmp == -999999787)
	{
		printf("Enter coefficient c : ");
		tmp = getInput();
		if (tmp == -999999787) printf("Invalid input\n");
	}
	polinom->c.numerator = tmp; polinom->c.denominator = 1;

	tmp = -999999787;
	while (tmp == -999999787)
	{
		printf("Enter coefficient d : ");
		tmp = getInput();
		if (tmp == -999999787) printf("Invalid input\n");
	}
	polinom->d.numerator = tmp; polinom->d.denominator = 1;
}

void output(struct MyPolinom *polinom)
{
	int temp = 0, kol = 0;
	if (polinom->a.numerator) { print_fract(polinom->a, 1, temp, 1); printf("x^3 "); temp++; kol++; }
	if (polinom->b.numerator) { print_fract(polinom->b, 1, temp, 1); printf("x^2 "); temp++; kol++; }
	if (polinom->c.numerator) { print_fract(polinom->c, 1, temp, 1); printf("x "); temp++; kol++; }
	if ((polinom->d.numerator || !kol) && (kol || !polinom->C)) { print_fract(polinom->d, 0, temp, 0); kol++; }

	if (polinom->C)
	{
		if (kol)
			printf("+ C");
		else
			printf("C");
	}
	printf("\n\n");
}

void differentiate(struct MyPolinom* polinom)
{
	polinom->d = polinom->c;
	polinom->c = polinom->b; polinom->c.numerator *= 2; adduce_factor(&polinom->c);
	polinom->b = polinom->a; polinom->b.numerator *= 3; adduce_factor(&polinom->b);
	polinom->a.numerator = 0; polinom->a.denominator = 1;
	polinom->C = 0;
}

void integrate(struct MyPolinom* polinom)
{
	polinom->a = polinom->b; polinom->a.denominator *= 3; adduce_factor(&polinom->a);
	polinom->b = polinom->c; polinom->b.denominator *= 2; adduce_factor(&polinom->b);
	polinom->c = polinom->d;
	polinom->d.numerator = 0; polinom->d.denominator = 1;
	polinom->C = 1;
}

void count(struct MyPolinom polinom)
{
	int x;
	float ans;
	printf("Enter x : ");
	scanf("%d", &x);

	polinom.a.numerator *= x * x * x;
	polinom.b.numerator *= x * x;
	polinom.c.numerator *= x;

	adduce_factor(&polinom.a);
	adduce_factor(&polinom.b);
	adduce_factor(&polinom.c);

	ans = polinom.a.numerator / (float)(polinom.a.denominator) + polinom.b.numerator / (float)(polinom.b.denominator) + polinom.c.numerator / (float)(polinom.c.denominator) + polinom.d.numerator / (float)(polinom.d.denominator);

	printf("Expression equal : %f\n\n", ans);
}

int main()
{
	int request = 1;
	struct MyPolinom polinom;
	input(&polinom);

	while (request)
	{
		line();
		printf(" Press 1 to enter new polynom\n Press 2 to get current polynom\n Press 3 to differentiate polynom\n Press 4 to integrate polynom\n Press 5 to count polynom up for an X\n Press 0 to quit programm\n\n Your request : ");
		request = getInput();
		printf("\n");

		switch (request)
		{
		case 1:
			input(&polinom);
			break;
		case 2:
			output(&polinom);
			break;
		case 3:
			differentiate(&polinom);
			break;
		case 4:
			integrate(&polinom);
			break;
		case 5:
			count(polinom);
			break;
		case 0:
			break;
		default:
			printf("Invalid input\n");
			break;
		}
		line();
	}
	return 0;
}