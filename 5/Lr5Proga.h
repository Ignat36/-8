#include <iostream>
#include <random>
#include <time.h>

struct Node
{
	Node* next;
	char data;

	Node();
	Node(char value);
};

struct Queue
{
	Node* First, * Last;
	int size;

	bool empty();
	Queue();
	void push(char data);
	void pop();
	char front();
	void free();
};

struct ListNode
{
	char data;
	int queueNumber;
	char action;
	ListNode* next, * prev;

	ListNode(char value);
	ListNode();
};

struct List
{
	ListNode* First;
	int size;
	int n;
	Queue* qArr;

	List(int n);
	void add(char data, char act, int num);
	void addRand();
	ListNode* front();
	bool empty();
	void pop();
	void free();
};

void solve(List* task);