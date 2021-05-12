#include "Date.h"

class Worker
{
public:
	std::string name;
	std::string surname;
	std::string patronymic;

	Date birth;

	std::string IDNumber;
	std::string IdentificationNumber;

	std::string  SocialInsurance;

	std::string  Background;

	std::string  post;
	int salary;
	bool onWork;
	int HolidayTimes;

	std::string remark;

	Date entry;

	Worker(std::string _name, std::string _surname, std::string _patronymic,
		int _birthDay, int _birthMounth, int _birthYear,
		std::string _IDNumber, std::string _IdentificationNumber,
		std::string  _SocialInsurance, std::string  _Background,
		std::string  _post, int _salary,
		int _entryDay, int _entryMounth, int _entryYear);

	Worker();

	std::string FIO();

	int FreeWeeks();

	void ShowInfo();
};

