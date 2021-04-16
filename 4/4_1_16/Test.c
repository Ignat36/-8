#include "4_1_16.h"
#include <assert.h>

void StrlenCheck()
{
	const char* tmp1 = "#$%^&";
	
	assert(strlen(tmp1) == 5);
	printf_s("\nstrlen complited");
}

void StrcmpCheck()
{
	const char* tmp1 = "#$%^&";
	const char* tmp2 = "#$%^&";
	const char* tmp3 = "12345";

	assert(strcmp(tmp1, tmp2) && !strcmp(tmp2, tmp3));
	printf_s("\nstrcmp complited");
}

void InsertCheck()
{
	const char* tmp1 = "(";
	char* tmp2 = (char*)malloc(10 * sizeof(char));
	tmp2 = "12345";
	insert(&tmp2, tmp1, 0);
	assert(strcmp(tmp2, "(12345"));
	printf_s("\ninsert complited");
	free(tmp2);
}

#undef main

int main()
{
	StrlenCheck();
	StrcmpCheck();
	InsertCheck();
	return 0;
}