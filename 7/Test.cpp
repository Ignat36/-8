#include "Organization.h"

void DateCheck()
{
    Date A = Date(2003, 5, 13), B = Date(2001, 9, 11), C = Date(2001, 9, 11);

    bool res = true;

    res &= B == C;
    res &= A != B;
    res &= A > B;
    res &= B < A;
    res &= B >= C;
    res &= C <= B;
    res &= (B - C) == 0;

    printf("Data check ");

    if (B.show() == "11.09.2001" && res)
        printf("complited\n");
    else
        printf("failed\n");
}

void WorkerCheck()
{
    Worker tmp = Worker("Èãíàò", "Øàğãîğîäñêèé", "Ñåğãååâè÷", 13, 5, 2003, "615gfh5654", "g4hfg5h6f51", "0", "-----", "Áîã", 10024, 13, 5, 2003);

    printf("Worker check ");

    if (tmp.FIO() == "Øàğãîğîäñêèé Èãíàò Ñåğãååâè÷" && tmp.FreeWeeks())
        printf("complited\n");
    else
        printf("failed\n");
}

void OrganizationCheck()
{
    bool res = true;;
    Worker tmp = Worker("Èãíàò", "Øàğãîğîäñêèé", "Ñåğãååâè÷", 13, 5, 2003, "615gfh5654", "g4hfg5h6f51", "0", "-----", "Áîã", 10024, 13, 5, 2003);
    Organization A;

    A.ShowOnWork();  printf("\n");

    res &= A.size() == 0;

    A.employ(tmp);

    FILE* file = nullptr;
    A.output(file, "test.txt");

    res &= A.size() == 1;

    res &= A.findFIO(tmp.FIO()).IDNumber == tmp.IDNumber && A.findID(tmp.IDNumber).IdentificationNumber == tmp.IdentificationNumber && A.findSoc(tmp.SocialInsurance).IdentificationNumber == tmp.IdentificationNumber && A.findIdentNum(tmp.IdentificationNumber).IDNumber == tmp.IDNumber;

    A.fire();

    res &= A.size() == 0;

    tmp = Worker("Èãíàò", "Øàğãîğîäñêèé", "Ñåğãååâè÷", 13, 5, 1003, "615gfh5654", "g4hfg5h6f51", "0", "-----", "Áîã", 10024, 13, 5, 2003); tmp.onWork = false;
    A.employ(tmp);
    A.ShowOnHoliday(); printf("\n");
    A.fireOlder();

    res &= A.size() == 0;

    printf("Organization check ");

    if(res)
        printf("complited\n");
    else
        printf("failed\n");
    
}

#undef main

int main()
{
    DateCheck();
    WorkerCheck();
    OrganizationCheck();
}
