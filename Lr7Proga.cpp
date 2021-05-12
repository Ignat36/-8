#include "Organization.h"
#include <locale>
#include <Windows.h>

void line()
{
	for (int i = 0; i < 70; i++)
		printf("*");

	printf("\n");
}

int main()
{
    system("cls");
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Date current = Date(2021, 5, 5);

    FILE* file = fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("Can not open file");
        exit(0);
    }

    Organization A;
    int request = 1;
    int request1;
    bool task = true;
    Worker temp;

    char buffer[80];

    int n, x;
    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%s", buffer); temp.surname = buffer;
        fscanf(file, "%s", buffer); temp.name = buffer;
        fscanf(file, "%s", buffer); temp.patronymic = buffer;

        fscanf(file, "%s", buffer); temp.IDNumber = buffer;
        fscanf(file, "%s", buffer); temp.IdentificationNumber = buffer;
        fscanf(file, "%s", buffer); temp.SocialInsurance = buffer;

        fscanf(file, "%d", &x); temp.birth.year = x;
        fscanf(file, "%d", &x); temp.birth.month = x;
        fscanf(file, "%d", &x); temp.birth.day = x;

        fscanf(file, "%s", buffer); temp.post = buffer;
        fscanf(file, "%d", &x); temp.salary = x;
        fscanf(file, "%s", buffer); temp.Background = buffer;

        fscanf(file, "%d", &x); temp.entry.year = x;
        fscanf(file, "%d", &x); temp.entry.month = x;
        fscanf(file, "%d", &x); temp.entry.day = x;

        A.employ(temp);
    }

    fclose(file);

    do
    {
        system("cls");

        if (task)
        {
            line();
            printf("Чтобы найти сотрудника введите \t\t\t\t 1\n");
            printf("Чтобы нанять сотрудника введите \t\t\t 2\n");
            printf("Чтобы сократить штаты введите \t\t\t\t 3\n");
            printf("Чтобы вывести список сотрудников в отпуске введите \t 4\n");
            printf("Чтобы вывести список сотрудников не в отпуске введите \t 5\n");
            printf("Чтобы закончить программу введите \t\t\t 0\n");
            line();

            while (!scanf("%d", &request) || !(request < 6 && request >= 0))
            {
                printf("Введите цифру от 0 до 5 : ");
                while (getchar() != '\n') {}
            }

            switch (request)
            {
            case 1:
                system("cls");
                line();
                printf("Выберите пункт, по которому будет осуществляться поиск\n");
                printf("ФИО : \t\t\t\t1\n");
                printf("Номер паспорта : \t\t2\n");
                printf("Идентификационный номер : \t3\n");
                printf("Номер соц. страхования : \t4\n");
                line();

                while (!scanf("%d", &request1) || !(request1 < 4 && request1 > 0))
                {
                    printf("Введите цифру от 1 до 4 : ");
                    while (getchar() != '\n') {}
                }

                switch (request1)
                {
                case 1:

                    system("cls");
                    printf("Введите фамилию : "); scanf("%s", buffer); temp.surname = buffer;
                    printf("Введите имя : "); scanf("%s", buffer); temp.name = buffer;
                    printf("Введите отчество : "); scanf("%s", buffer); temp.patronymic = buffer;

                    temp = A.findFIO(temp.FIO());
                    if (temp.post == "")
                    {
                        printf("Сотрудника с таким ФИО не найдено : введите 0, чтобы продолжить ");

                        while (!scanf("%d", &request1) || request1)
                        {
                            printf("Введите 0, чтобы продолжить : ");
                            while (getchar() != '\n') {}
                        }
                    }
                    else
                        task = false;

                    break;

                case 2:

                    system("cls");
                    printf("Введите номер паспорта : "); scanf("%s", buffer); temp.IDNumber = buffer;

                    temp = A.findID(temp.IDNumber);
                    if (temp.post == "")
                    {
                        printf("Сотрудника с таким номером паспорта не найдено : введите 0, чтобы продолжить ");

                        while (!scanf("%d", &request1) || request1)
                        {
                            printf("Введите 0, чтобы продолжить : ");
                            while (getchar() != '\n') {}
                        }
                    }
                    else
                        task = false;

                    break;

                case 3:

                    system("cls");
                    printf("Введите идентификационный номер : "); scanf("%s", buffer); temp.IdentificationNumber = buffer;

                    temp = A.findID(temp.IdentificationNumber);
                    if (temp.post == "")
                    {
                        printf("Сотрудника с таким идентификационным номером не найдено : введите 0, чтобы продолжить ");

                        while (!scanf("%d", &request1) || request1)
                        {
                            printf("Введите 0, чтобы продолжить : ");
                            while (getchar() != '\n') {}
                        }
                    }
                    else
                        task = false;

                    break;

                case 4:

                    system("cls");
                    printf("Введите номер соц. страхования : "); scanf("%s", buffer); temp.IdentificationNumber = buffer;

                    temp = A.findID(temp.IdentificationNumber);
                    if (temp.post == "")
                    {
                        printf("Сотрудника с таким номером соц. страхования не найдено : введите 0, чтобы продолжить ");

                        while (!scanf("%d", &request1) || request1)
                        {
                            printf("Введите 0, чтобы продолжить : ");
                            while (getchar() != '\n') {}
                        }
                    }
                    else
                        task = false;

                    break;

                default:
                    break;
                }
                break;

            case 2:

                system("cls");

                printf("Введите фамилию : "); scanf("%s", buffer); temp.surname = buffer;
                printf("Введите имя : "); scanf("%s", buffer); temp.name = buffer;
                printf("Введите отчество : "); scanf("%s", buffer); temp.patronymic = buffer;

                printf("Введите номер паспорта : "); scanf("%s", buffer); temp.IDNumber = buffer;
                printf("Введите идентификационный номер : "); scanf("%s", buffer); temp.IdentificationNumber = buffer;
                printf("Введите номер соц. страхования : "); scanf("%s", buffer); temp.SocialInsurance = buffer;

                printf("Введите год рождения : "); while (!scanf("%d", &temp.birth.year) && temp.birth.year > 0) { printf("Введите число : "); while (getchar() != '\n') {} }
                printf("Введите месяц рождения : "); while (!scanf("%d", &temp.birth.month) && temp.birth.month > 0 && temp.birth.month < 13) { printf("Введите число : "); while (getchar() != '\n') {} }
                printf("Введите день рождения : "); while (!scanf("%d", &temp.birth.day) && temp.birth.day > 0 && temp.birth.day < 32) { printf("Введите число : "); while (getchar() != '\n') {} }

                printf("Введите должность : "); scanf("%s", buffer); temp.post = buffer;
                printf("Введите оклад : "); while (!scanf("%d", &temp.salary) && temp.salary > 0 && temp.salary < 32) { printf("Введите число : "); while (getchar() != '\n') {} }
                printf("Введите образование : "); scanf("%s", buffer); temp.Background = buffer;

                A.employ(temp);

                break;

            case 3:

                A.fireOlder();

                break;

            case 4:

                A.ShowOnHoliday();

                break;

            case 5:

                A.ShowOnWork();

                break;

            default:
                break;
            }
        }
        else
        {
            line();
            temp.ShowInfo();
            line();

            line();
            printf("Вывести срок работы \t\t\ 1\n");
            printf("Вывести кол-во недель отпуска \t 2\n");
            printf("Уволить работника \t\t 3\n");
            printf("Вернуться назад \t\t 0\n");
            line();

            while (!scanf("%d", &request) || !(request < 4 && request >= 0))
            {
                printf("Введите цифру от 0 до 3 : ");
                while (getchar() != '\n') {}
            }
            
            switch (request)
            {
            case 1:

                printf("Сотрудник проработал %d дней : введите 0, чтобы продолжить ", current - temp.entry);
                
                while (!scanf("%d", &request1) || request1)
                {
                    printf("Введите 0, чтобы продолжить : ");
                    while (getchar() != '\n') {}
                }

                break;

            case 2:

                printf("Сотруднику доступно %d недель отпуска : введите 0, чтобы продолжить ", temp.FreeWeeks());

                while (!scanf("%d", &request1) || request1)
                {
                    printf("Введите 0, чтобы продолжить : ");
                    while (getchar() != '\n') {}
                }

                break;

            case 3:

                task = true;
                A.fire(temp);

                break;

            default:
                task = true;
                request = 1;
                break;
            }
        }

    } while (request);

    A.output(file);

}