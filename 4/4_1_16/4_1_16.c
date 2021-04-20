#include "4_1_16.h"

int strlen(const char *str)
{
	int res = 0;
	while (str[res] != '\0')
		res++;
	return res;
}

int strcmp(const char *str1, const char *str2)
{
	int l1 = strlen(str1), l2 = strlen(str2);
	
	if (l1 == l2)
	{
		for (int i = 0; i < l1; i++)
			if (str1[i] != str2[i])
				return 0;
		return 1;
	}

	return 0;
}

void insert(char **str, const char *ins, int pos) 
{
	int addSize = strlen(ins) ,size = strlen(*str);

	char* tmp = *str;
	*str = (char*)malloc((addSize + size + 4) * sizeof(char));

	if (*str == NULL)
	{
		printf("Can not allocate memory");
		exit(0);
	}

	for (int i = 0; i < size; i++)
		(*str)[i] = tmp[i];
	free(tmp);

	for (int i = size - 1; i >= pos; i--)
		(*str)[i + addSize] = (*str)[i];

	(*str)[size + addSize] = '\0';

	for (int i = pos; i < pos + addSize; i++)
		(*str)[i] = ins[i - pos];

	return;
}

int main()
{
	char** text = (char**)malloc(100 * sizeof(char*));

	if (text == NULL)
	{
		printf("Can not allocate memory");
		exit(0);
	}

	printf("Enter text : \n");

	int i = -1;
	do
	{
		i++;
		text[i] = (char*)malloc(100 * sizeof(char));

		if (text[i] == NULL)
		{
			printf("Can not allocate memory");
			exit(0);
		}

		int j = 0;
		char c = getchar();
		while (c != '\n')
		{
			if (j < 100)
			{
				text[i][j] = c;
				j++;
			}
			c = getchar();
		}
		text[i][j] = '\0';
	} while (!strcmp(text[i], "end"));

	for (int j = 0; j < i; j++)
	{
		int k = 0;
		int n = strlen(text[j]);
		while (k < n)
		{
			if (text[j][k] >= '0' && text[j][k] <= '9')
			{
				int start = k+1;
				int num = 0;

				insert(&text[j], "(", k);
				k++;
				n++;

				while (text[j][k] >= '0' && text[j][k] <= '9')
				{
					num *= 10;
					num += text[j][k] - '0';
					k++;
				}

				if (num % 2)
				{
					while (start < k)
					{
						text[j][start] = '+';
						start++;
					}
				}
				else
				{
					while (start < k)
					{
						text[j][start] = '-';
						start++;
					}
				}

				insert(&text[j], ")", k);
				k++;
				n++;
			}
			k++;
		}
	}

	for (int j = 0; j < i; j++)
	{
		int n = strlen(text[j]);
		for (int k = 0; k < n; k++)
		{
			printf_s("%c", text[j][k]);
		}
		printf_s("\n");
	}


	for (int j = 0; j <= i; j++)
		free(text[j]);
	free(text);

	return 0;
}