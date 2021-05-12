#include "Worker.h"

class Organization
{
private:
	struct Node
	{
		Node* next;
		Worker data;

		Node() { next = nullptr;  }
		Node(Worker value) { data = value; next = nullptr; }

	} *List;

	int length;

public:
	void employ(Worker value);
	void fire(Worker value);
	void fire();
	Worker findSoc(std::string value);
	Worker findID(std::string value);
	Worker findIdentNum(std::string value);
	Worker findFIO(std::string value);
	void ShowOnWork();
	void ShowOnHoliday();
	void fireOlder(int value = 64);
	int size();
	void output(FILE* file);

	Organization();
	~Organization();
};