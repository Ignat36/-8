#include "Lr6Proga.h"

void SplitCheck()
{
	Node* vert = nullptr;
	insert(vert, "1"); insert(vert, "3");
	std::pair<Node*, Node*> tmp = split(vert, "2");

	printf("Treap split ");
	if (tmp.first->key == "1" && tmp.second->key == "3")
		printf("complited\n");
	else
		printf("faild\n");

	free(vert);
}

void MergeCheck()
{
	Node* vert = nullptr; Node* temp = nullptr;
	insert(vert, "1"); insert(temp, "3");

	vert = merge(vert, temp);
	std::pair<Node*, Node*> tmp = split(vert, "2");

	printf("Treap merge ");
	if (tmp.first->key == "1" && tmp.second->key == "3")
		printf("complited\n");
	else
		printf("faild\n");

	free(vert); free(temp);
}

void InsertCheck()
{
	Node* vert = nullptr;
	insert(vert, "1"); insert(vert, "3"); insert(vert, "1");
	std::pair<Node*, Node*> tmp = split(vert, "2");

	printf("Treap insert ");
	if (tmp.first->key == "1" && tmp.second->key == "3" && tmp.first->amount == 2)
		printf("complited\n");
	else
		printf("faild\n");

	free(vert);
}

void FillCheck()
{
	Node* vert = nullptr;
	insert(vert, "1"); insert(vert, "3"); insert(vert, "1"); insert(vert, "4"); insert(vert, "2");
	std::vector<Node*> arr;
	fill(arr, vert);

	printf("Treap->Vector ");
	if (arr.size() == 4)
		printf("complited\n");
	else
		printf("faild\n");

	free(vert);
}

void CompCheck()
{
	Node* vert = nullptr; Node* temp = nullptr;
	insert(vert, "1"); insert(temp, "3"); insert(temp, "3");

	printf("Compare ");
	if (comp(vert, temp))
		printf("complited\n");
	else
		printf("faild\n");

	free(vert); free(temp);
}

#undef main

int main()
{
	SplitCheck();
	MergeCheck();
	InsertCheck();
	FillCheck();
	CompCheck();
	return 0;
}