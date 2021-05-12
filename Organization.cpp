#include "Organization.h"

Organization::Organization()
{
	List = new Node();
	length = 0;
}

void Organization::employ(Worker value)
{
	length++;
	Node* tmp = List->next;
	List->next = new Node(value);

	if (!List->next)
	{
		printf("Can not allocate memory");
		exit(1);
	}

	List->next->next = tmp;
}

void Organization::fire()
{
	if (length)
	{
		length--;
		Node* tmp = List->next;
		List->next = tmp->next;
		delete tmp;
	}
}

void Organization::fire(Worker value)
{
	Node* tmp = List;
	for (int i = 0; i < length; i++)
	{
		if (tmp->next->data.IDNumber == value.IDNumber)
		{
			length--;
			Node* temp = tmp->next->next;
			delete tmp->next;
			tmp->next = temp;
			break;
		}

		tmp = tmp->next;
	}


	if (length)
	{
		length--;
		Node *tmp = List->next;
		List->next = tmp->next;
		delete tmp;
	}
}

Worker Organization::findSoc(std::string value)
{
	Node* tmp = List;
	for (int i = 0; i < length; i++)
	{
		if (tmp->next->data.SocialInsurance == value)
			return tmp->next->data;

		tmp = tmp->next;
	}

	return Worker();
}

Worker Organization::findID(std::string value)
{
	Node* tmp = List;
	for (int i = 0; i < length; i++)
	{
		if (tmp->next->data.IDNumber == value)
			return tmp->next->data;

		tmp = tmp->next;
	}

	return Worker();
}

Worker Organization::findIdentNum(std::string value)
{
	Node* tmp = List;
	for (int i = 0; i < length; i++)
	{
		if (tmp->next->data.IdentificationNumber == value)
			return tmp->next->data;

		tmp = tmp->next;
	}

	return Worker();
}

Worker Organization::findFIO(std::string value)
{
	Node* tmp = List;
	for (int i = 0; i < length; i++)
	{
		if (tmp->next->data.FIO() == value)
			return tmp->next->data;

		tmp = tmp->next;
	}

	return Worker();
}

void Organization::ShowOnWork()
{
	Node* tmp = List;
	for (int i = 0; i < length; i++)
	{
		if(tmp->next->data.onWork)
			tmp->next->data.ShowInfo();
		tmp = tmp->next;
	}
}

void Organization::ShowOnHoliday()
{
	Node* tmp = List;
	for (int i = 0; i < length; i++)
	{
		if (!tmp->next->data.onWork)
			tmp->next->data.ShowInfo();
		tmp = tmp->next;
	}
}

void Organization::fireOlder(int value)
{
	Date current = Date(2021, 5, 5);
	Node* tmp = List;
	for (int i = 0; i < length; i++)
	{
		if (current.year - tmp->next->data.birth.year > value)
		{
			length--;
			Node* t = tmp->next;
			tmp->next = t->next;
			delete t;
		}
		else
			tmp = tmp->next;
	}
}

int Organization::size()
{
	return length;
}

void Organization::output(FILE* file)
{
	file = fopen("input.txt", "w");

	if (file == NULL)
	{
		printf("Can not open file");
		exit(0);
	}

	Node* tmp = List;
	Worker temp = tmp->data;

	fprintf(file, "%d\n", size());
	for (int i = 0; i < size(); i++)
	{
		tmp = tmp->next;
		temp = tmp->data;

		fprintf(file, "%s ", temp.surname.c_str());
		fprintf(file, "%s ", temp.name.c_str());
		fprintf(file, "%s ", temp.patronymic.c_str());

		fprintf(file, "%s ", temp.IDNumber.c_str());
		fprintf(file, "%s ", temp.IdentificationNumber.c_str());
		fprintf(file, "%s ", temp.SocialInsurance.c_str());

		fprintf(file, "%d ", temp.birth.year);
		fprintf(file, "%d ", temp.birth.month);
		fprintf(file, "%d ", temp.birth.day);

		fprintf(file, "%s ", temp.post.c_str());
		fprintf(file, "%d ", temp.salary);
		fprintf(file, "%s ", temp.Background.c_str());

		fprintf(file, "%d ", temp.entry.year);
		fprintf(file, "%d ", temp.entry.month);
		fprintf(file, "%d\n", temp.entry.day);
	}

	fclose(file);
}

Organization::~Organization()
{
	Node* tmp;

	while (List)
	{
		tmp = List->next;
		delete List;
		List = tmp;
	}
}
