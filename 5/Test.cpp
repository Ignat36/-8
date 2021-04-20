#include "Lr5Proga.h"

void QueueEmptyCheck()
{
	Queue q = Queue();
	Queue w = Queue(); w.push('l');

	printf("Queue::empty");
	if (q.empty() && !w.empty())
		printf(" complited\n");
	else
		printf(" faild\n");

	q.free();
	w.free();
}

void QueuePushCheck()
{
	Queue w = Queue(); w.push('l');

	printf("Queue::push");
	if (w.front() == 'l')
		printf(" complited\n");
	else
		printf(" faild\n");

	w.free();
}

void QueuePopCheck()
{
	Queue w = Queue(); w.push('l'); w.pop();

	printf("Queue::pop");
	if (w.empty())
		printf(" complited\n");
	else
		printf(" faild\n");

	w.free();
}

void QueueFrontCheck()
{
	Queue w = Queue(); w.push('2'); w.push('l');

	printf("Queue::front");
	if (w.front() == '2')
		printf(" complited\n");
	else
		printf(" faild\n");

	w.free();
}

void ListAddCheck()
{
	int n = 3;
	List l = List(n);

	l.add('1', 'A', 2);

	printf("List::add");
	if (l.front()->data == '1')
		printf(" complited\n");
	else
		printf(" faild\n");

	l.free();
}

void ListFrontCheck()
{
	int n = 3;
	List l = List(n);

	l.add('6', 'A', 0);
	l.add('1', 'A', 2);

	printf("List::front");
	if (l.front()->data == '1')
		printf(" complited\n");
	else
		printf(" faild\n");

	l.free();
}

void ListEmptyCheck()
{
	int n = 3;
	List l = List(n);
	List m = List(n);

	l.add('6', 'A', 0);
	l.add('1', 'A', 2);

	printf("List::empty");
	if (m.empty() && !l.empty())
		printf(" complited\n");
	else
		printf(" faild\n");

	l.free();
	m.free();
}

void ListPopCheck()
{
	int n = 3;
	List l = List(n);

	l.add('6', 'A', 0); 
	l.add('1', 'A', 2); l.pop();

	printf("List::pop");
	if (l.front()->data == '6')
		printf(" complited\n");
	else
		printf(" faild\n");

	l.free();
}

#undef main

int main()
{
	QueueEmptyCheck();
	QueuePushCheck();
	QueuePopCheck();
	QueueFrontCheck();
	ListAddCheck();
	ListFrontCheck();
	ListEmptyCheck();
	ListPopCheck();

	return 0;
}