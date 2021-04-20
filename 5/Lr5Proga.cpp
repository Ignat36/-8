#include "Lr5Proga.h"

Node::Node()
{
	next = nullptr;
}

Node::Node(char value)
{
	data = value;
	next = nullptr;
}

bool Queue::empty()
{
	return Last == First ? true : false;
}

Queue::Queue()
{
	size = 0;
	First = new Node();

	if (!First)
	{
		printf("Can not allocate memory");
		exit(0);
	}

	Last = First;
}

void Queue::push(char data)
{
	Last->next = new Node(data);

	if (!Last->next)
	{
		printf("Can not allocate memory");
		exit(0);
	}

	Last = Last->next;
	size++;
}

void Queue::pop()
{
	if (!empty())
	{
		Node* tmp = First->next;
		delete First;
		First = tmp;

		size--;
	}
}

char Queue::front()
{
	return empty() ? First->data : First->next->data;
}

void Queue::free()
{
	while (!empty())
		pop();

	delete First;
}

ListNode::ListNode(char value)
{
	data = value;
	next = prev = nullptr;
}

ListNode::ListNode()
{
	next = prev = nullptr;
	data = rand() % 100 + 36;
}

List::List(int n)
{
	this->n = n;

	First = new ListNode();
	size = 0;
	qArr = new Queue[n];

	if (!First || !qArr)
	{
		printf("Can not allocate memory");
		exit(0);
	}

	for (int i = 0; i < n; i++)
		qArr[i] = Queue();
}

void List::add(char data, char act, int num)
{
	size++;
	ListNode* tmp = new ListNode(data);
	if (!tmp)
	{
		printf("Can not allocate memory");
		exit(0);
	}
	tmp->next = First->next;
	tmp->prev = First;
	First->next = tmp;
	tmp->action = act;
	tmp->queueNumber = num;
}

void List::addRand()
{
	size++;
	ListNode* tmp = new ListNode();
	if (!tmp)
	{
		printf("Can not allocate memory");
		exit(0);
	}
	tmp->next = First->next;
	tmp->prev = First;
	First->next = tmp;
	tmp->action = rand() % 2 ? 'A' : 'D';
	tmp->queueNumber = rand() % n;
}

ListNode* List::front()
{
	return First->next ? First->next : First;
}

bool List::empty()
{
	return size == 0;
}

void List::pop()
{
	if (!empty())
	{
		ListNode* tmp = First->next;
		delete First;
		First = tmp;

		size--;
	}
}

void List::free()
{
	while (!empty())
		pop();
	delete First;

	for (int i = 0; i < n; i++)
		qArr[i].free();

	delete qArr;
}

void solve(List* task)
{
	while (!task->empty())
	{
		if (task->front()->action == 'A')
			task->qArr[task->front()->queueNumber].push(task->front()->data);
		else
			task->qArr[task->front()->queueNumber].pop();

		task->pop();
	}
}

int main()
{
	srand(time(NULL));
	int n;

	printf("Enter integer n : ");
	while (!scanf_s("%d", &n))
	{
		printf("Worng input, try again : ");
		while (getchar() != '\n') {}
	}

	List MyList = List(n);
	for (int i = 0; i < 100; i++)
		MyList.addRand();
	solve(&MyList);
	MyList.free();
	return 0;
}