#include "Worker.h"

Worker::Worker(std::string _name, std::string _surname, std::string _patronymic,
	int _birthDay, int _birthMounth, int _birthYear,
	std::string _IDNumber, std::string _IdentificationNumber,
	std::string  _SocialInsurance, std::string  _Background,
	std::string  _post, int _salary,
	int _entryDay, int _entryMounth, int _entryYear)
{
	name = _name;
	surname = _surname;
	patronymic = _patronymic;

	birth = Date(_birthYear, _birthMounth, _birthDay);

	IDNumber = _IDNumber;
	IdentificationNumber = _IdentificationNumber;

	SocialInsurance = _SocialInsurance;
	Background = _Background;
	post = _post;
	salary = _salary;

	entry = Date(_entryYear, _entryMounth, _entryDay);

	remark = "";
	HolidayTimes = 0;
	onWork = true;
}

Worker::Worker() 
{
	post = "";
	HolidayTimes = 0; 
	entry = Date(2021, 5, 5);
}

std::string Worker::FIO()
{
	return surname + " " + name + " " + patronymic;
}

int Worker::FreeWeeks()
{
	Date current = Date(2021, 5, 5);
	return ((current.year - entry.year) * 12 + current.month - entry.month) / 3 - HolidayTimes * 2;
}

void Worker::ShowInfo()
{
	printf("ФИО : %s\n", FIO().c_str());
	printf("Дата рождения : %s\n", birth.show().c_str());
	printf("Номер паспорта : %s\n", IDNumber.c_str());
	printf("Идентификационный номер : %s\n", IdentificationNumber.c_str());
	printf("Номер соц. страхования : %s\n", SocialInsurance.c_str());
	printf("Образование : %s\n", Background.c_str());
	printf("Должность : %s\n", post.c_str());
	printf("Заработная плата : %d\n", salary);
	printf("Дата поступления на работу : %s\n", entry.show().c_str());
}