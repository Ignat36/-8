#include "4_2_16.h"

int strlen(const char* str)
{
	int res = 0;
	while (str[res] != '\0')
		res++;

	return res;
}

void copy(char **to, const char* str)
{
	*to = (char*)malloc((strlen(str) + 4) * sizeof(char));
	if (*to == NULL)
	{
		printf_s("Can not allocate memory");
		exit(0);
	}
	for (int i = 0; i <= strlen(str); i++)
		(*to)[i] = str[i];
}

int size(const char **stringArr)
{
	int res = 0;

	while (!strcmp(stringArr[res],"#$%^&"))
		res++;

	return res;
}

int strcmp(const char* str1, const char* str2)
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

void buildVert(struct MyBor **vert)
{
	*vert = (struct MyBor*)malloc(sizeof(struct MyBor));
	if (*vert == NULL)
	{
		printf_s("Can not allocate memory");
		exit(0);
	}
	(*vert)->exsists = 0;
	for (int i = 0; i < 33; i++)
		(*vert)->characters[i] = NULL;
	return;
}

char* strcpy(const char* str, int pos, int kol)
{
	int n = strlen(str);

	if (kol == -1)
		kol = n - pos;

	char* res = (char*)malloc((kol+2) * sizeof(char));
	if (res == NULL)
	{
		printf_s("Can not allocate memory");
		exit(0);
	}

	int i;
	for (i = pos; i < pos + kol; i++)
		res[i - pos] = str[i];
	res[i-pos] = '\0';
	return res;
}

char* stradd(const char* str1, const char* str2)
{
	int n = strlen(str1);
	int m = strlen(str2);
	char* res = (char*)malloc((n + m + 6) * sizeof(char));
	if (res == NULL)
	{
		printf_s("Can not allocate memory");
		exit(0);
	}

	int i;
	for (i = 0; i < n; i++)
		res[i] = str1[i];

	res[i] = ' '; i++;
	res[i] = '+'; i++;
	res[i] = ' '; i++;

	int j;
	for (j = 0; j < m; j++)
		res[i + j] = str2[j];
	res[i + j] = '\0';

	return res;
}

void UnionArrays(char*** mainArr, char** sideArr)
{
	int l1 = size(*mainArr), l2 = size(sideArr);
	*mainArr = (char**)realloc(*mainArr, (l1 + l2 + 1) * sizeof(char*));
	if (*mainArr == NULL)
	{
		printf_s("Can not allocate memory");
		exit(0);
	}

	for (int i = 0; i < l2; i++)
	{
		copy(&(*mainArr)[l1 + i], sideArr[i]);
		free(sideArr[i]);
	}
	free(sideArr[l2]); free(sideArr);
	copy(&(*mainArr)[l1 + l2], "#$%^&");
}

char** getArray(char* word, char** addSplitArr)
{
	int n = size(addSplitArr);

	if (!n)
	{
		free(addSplitArr[0]); free(addSplitArr);
		char** res = (char**)malloc(2 * sizeof(char*));
		if (res == NULL)
		{
			printf_s("Can not allocate memory");
			exit(0);
		}
		copy(&res[0], word);
		copy(&res[1], "#$%^&");
		return res;
	}

	char** res = (char**)malloc((n + 1) * sizeof(char*));
	if (res == NULL)
	{
		printf_s("Can not allocate memory");
		exit(0);
	}
	
	for (int i = 0; i < n; i++)
	{
		res[i] = stradd(word, addSplitArr[i]);
		free(addSplitArr[i]);
	}
	free(addSplitArr[n]); free(addSplitArr);
	copy(&res[n], "#$%^&");
	
	return res;
}

void addStringToBor(struct MyBor **root, const char *string, int index)
{
	if (index == strlen(string))
	{
		(*root)->exsists = 1;
		return;
	}

	if (string[index] < 'à' || string[index] > 'ÿ')
	{
		printf("%s\n", string);
		return;
	}

	if ((*root)->characters[string[index] - 'à'] == NULL)
		buildVert(&(*root)->characters[string[index] - 'à']);

	addStringToBor(&(*root)->characters[string[index] - 'à'], string, index + 1);

	return;
}

char **GetAllSplitting(struct MyBor* root, struct MyBor* vert, const char* str, int index) 
{
	char** res = (char**)malloc(sizeof(char*));
	if (res == NULL)
	{
		printf_s("Can not allocate memory");
		exit(0);
	}
	copy(&res[0], "#$%^&");

	if (vert->characters[str[index] - 'à'] == NULL)
		return res;

	if (index == strlen(str) - 1)
	{
		if (vert->characters[str[index] - 'à']->exsists)
			return getArray(str, res);
		else
			return res;
	}

	UnionArrays( &res,
				 GetAllSplitting(root, vert->characters[str[index] - 'à'], str, index + 1));

	if (vert->characters[str[index] - 'à']->exsists)
	{
		char* pref = strcpy(str, 0, index + 1);
		char* post = strcpy(str, index + 1, -1);
		char** tmp = getArray( pref,
							   GetAllSplitting(root, root, post, 0));

		if (!strcmp(tmp[0], pref))
			UnionArrays(&res, tmp);

		free(pref); free(post);
	}

	return res;
}

void BuildBor(struct MyBor **root, char* Name)
{
	FILE* file;
	int n;
	if ((file = fopen(Name, "r")) == NULL)
	{
		printf_s("Can not open the file");
		return 0;
	}

	fscanf_s(file, "%d", &n);
	char tmp[40];

	for (int i = 0; i < n; i++)
	{
		fscanf_s(file, "%s", &tmp, sizeof(tmp));
		addStringToBor(root, tmp, 0);
	}

	fclose(file);
}

void PrintAllSplitings(struct MyBor* root, char* Name)
{
	FILE* file;
	int n;
	if ((file = fopen(Name, "r")) == NULL)
	{
		printf_s("Can not open the file");
		return 0;
	}

	fscanf_s(file, "%d", &n);
	char tmp[40];

	for (int i = 0; i < n; i++)
	{
		fscanf_s(file, "%s", &tmp, sizeof(tmp));
		char** words = GetAllSplitting(root, root, tmp, 0);
		int n = size(words);
		for (int j = 0; j < n; j++)
			if(!strcmp(tmp, words[j]))
				printf_s("%s  =  %s\n", tmp, words[j]);

		for (int j = 0; j <= n; j++)
			free(words[j]);
		free(words);
	}

	fclose(file);
}

void FreeBor(struct MyBor* root) 
{
	if (root == NULL)
		return;

	for (int i = 0; i < 33; i++)
		if (root->characters[i] != NULL)
			FreeBor(root->characters[i]);

	free(root);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct MyBor* bor = NULL;
	buildVert(&bor);
	BuildBor(&bor, "words.txt");

	PrintAllSplitings(bor, "words.txt");
	
	FreeBor(bor);
	return 0;
}
