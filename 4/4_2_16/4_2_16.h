#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct MyBor
{
	unsigned char exsists;

	struct MyBor* characters[33];
};

int strlen(const char* str);

void copy(char** to, const char* str);

int size(const char** stringArr);

int strcmp(const char* str1, const char* str2);

void buildVert(struct MyBor** vert);

char* strcpy(const char* str, int pos, int kol);

char* stradd(const char* str1, const char* str2);

void UnionArrays(char*** mainArr, char** sideArr);

char** getArray(char* word, char** addSplitArr);

void addStringToBor(struct MyBor** root, const char* string, int index);

char** GetAllSplitting(struct MyBor* root, struct MyBor* vert, const char* str, int index);

void BuildBor(struct MyBor** root, char* Name);

void PrintAllSplitings(struct MyBor* root, char* Name);

void FreeBor(struct MyBor* root);
