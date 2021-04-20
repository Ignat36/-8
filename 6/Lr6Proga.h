#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>

struct Node
{
	Node* left, * right;
	std::string key;
	int amount;
	int priority;

	Node(std::string n_key);
};

std::pair<Node*, Node*> split(Node* root, std::string key);

Node* merge(Node* left, Node* right);

Node* ins(Node* root, Node* v);

void insert(Node*& root, std::string v);

void free(Node* root);

void fill(std::vector<Node*>& arr, Node* root);

bool comp(Node* a, Node* b);