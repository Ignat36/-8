#include "Lr6Proga.h"

Node::Node(std::string n_key)
{
	key = n_key;
	amount = 1;
	priority = rand() * rand() + rand() * rand();
	left = right = nullptr;
}

std::pair<Node*, Node*> split(Node* root, std::string key)
{
	if (!root)
		return { nullptr, nullptr };

	if (key > root->key)
	{
		std::pair<Node*, Node*> tmp = split(root->right, key);
		root->right = tmp.first;
		return { root, tmp.second };
	}
	else
	{
		std::pair<Node*, Node*> tmp = split(root->left, key);
		root->left = tmp.second;
		return { tmp.first, root };
	}
}

Node* merge(Node* left, Node* right)
{
	if (!left) return right;
	if (!right) return left;

	if (left->priority > right->priority)
	{
		left->right = merge(left->right, right);
		return left;
	}
	else
	{
		right->left = merge(left, right->left);
		return right;
	}
}

Node* ins(Node* root, Node* v)
{
	if (!root)
		return v;

	if (root->key == v->key)
	{
		root->amount++;
		delete v;
		return root;
	}

	if (root->priority >= v->priority)
	{
		if (root->key > v->key)
		{
			root->left = ins(root->left, v);
			return root;
		}
		else
		{
			root->right = ins(root->right, v);
			return root;
		}
	}
	else
	{
		std::pair<Node*, Node*> tmp = split(root, v->key);
		v->left = tmp.first;
		v->right = tmp.second;
		return v;
	}
}

void insert(Node*& root, std::string v)
{
	Node* tmp = root;
	while (tmp && tmp->key != v)
		if (tmp->key > v)
			tmp = tmp->left;
		else
			tmp = tmp->right;

	if (tmp)
		tmp->amount++;
	else
	{
		Node* tmp = new Node(v);

		if (!tmp)
		{
			printf("Can not allocate memory");
			exit(0);
		}

		root = ins(root, tmp);
	}
}

void free(Node* root)
{
	if (root)
	{
		free(root->left);
		free(root->right);
		delete root;
	}
}

void fill(std::vector<Node*>& arr, Node* root)
{
	if (root)
	{
		arr.push_back(root);
		fill(arr, root->left);
		fill(arr, root->right);
	}
}

bool comp(Node* a, Node* b)
{
	return a->amount < b->amount;
}

int main()
{
	srand(time(NULL));

	Node* tree = nullptr;
	FILE* file;
	file = fopen("text.txt", "r");

	if (file == NULL)
	{
		printf("Can not open file");
		exit(0);
	}

	char tmp[100];
	while (fscanf(file, "%s", &tmp, sizeof(tmp)) != -1)
		insert(tree, std::string(tmp));

	std::vector<Node*> arr;
	fill(arr, tree);
	sort(arr.begin(), arr.end(), comp);

	for (int i = 0; i < arr.size(); i++)
		printf("%s  ---  %d\n", arr[i]->key.c_str(), arr[i]->amount);

	free(tree);
	return 0;
}