#include "4_2_16.h"
#include <assert.h>

void strlenCheck()
{
	const char* tmp1 = "#$%^&";

	assert(strlen(tmp1) == 5);
	printf_s("\nstrlen complited");
}

void copyCheck()
{
	char* res;
	copy(&res, "#$%^&");

	assert(strcmp(res, "#$%^&"));
	printf_s("\ncopy complited");
}

void sizeCheck()
{
	char** res = (char**)malloc(2 * sizeof(char*));

	if (*res == NULL)
	{
		printf_s("Can not allocate memory");
		exit(0);
	}

	copy(&res[0], "12345");
	copy(&res[1], "#$%^&");
	assert(size(res) == 1);
	printf_s("\nsize complited");
	free(res[0]);
	free(res[1]);
	free(res);
}

void strcmpCheck()
{
	const char* tmp1 = "#$%^&";
	const char* tmp2 = "#$%^&";
	const char* tmp3 = "12345";

	assert(strcmp(tmp1, tmp2) && !strcmp(tmp2, tmp3));
	printf_s("\nstrcmp complited");
}

void strcpyCheck()
{
	const char* tmp3 = "12345";
	char* res = strcpy(tmp3, 0, 2);
	assert(strcmp(res, "12"));
	printf_s("\nstrcpy complited");
	free(res);
}

void straddCheck()
{
	const char* tmp2 = "#$%^&";
	const char* tmp3 = "12345";
	char* res = stradd(tmp2, tmp3);
	assert(strcmp(res, "#$%^& + 12345"));
	printf_s("\nstradd complited");
	free(res);
}

void UnionArraysCheck()
{
	char** res = (char**)malloc(2 * sizeof(char*));
	if (*res == NULL)
	{
		printf_s("Can not allocate memory");
		exit(0);
	}
	copy(&res[0], "12345");
	copy(&res[1], "#$%^&");

	char** res1 = (char**)malloc(2 * sizeof(char*));
	if (*res1 == NULL)
	{
		printf_s("Can not allocate memory");
		exit(0);
	}
	copy(&res1[0], "54321");
	copy(&res1[1], "#$%^&");
	UnionArrays(&res, res1);
	assert(strcmp(res[0], "12345") && strcmp(res[1], "54321"));
	printf_s("\nUnionArrays complited");
	free(res[0]); free(res[1]); free(res[2]); free(res);
}

#undef main

int main()
{
	
	strlenCheck();
	copyCheck();
	sizeCheck();
	strcmpCheck();
	strcpyCheck();
	straddCheck();
	UnionArraysCheck();

	return 0;
}
