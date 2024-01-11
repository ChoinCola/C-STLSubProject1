#include "Employee.h"
#include <iostream>

using namespace std;
/*
    Employee.cpp �� Ŭ������ �޼���鿡 ���� �����θ� ����ִ�.
    �����ڴ� ������ ����� �ʱ갪�� �����Ѵ�.
    ������ �̸��� ���鹮��,
    ��ȣ�� -1
    �޿��� ���Ա޿�,
    ������´� �̰������ �ʱ�ȭ�Ͽ� �����Ѵ�.
*/
Records::Employee::Employee()
    : mFirstName("")
    , mLastName("")
    , mEmployeeNumber(-1)
    , mSalary(kDefaultStartingSalary)
    , mHired(false)
{
}

Records::Employee::~Employee()
{
    // �������������Ͱ� �������� ��������, ������� �ʴ´�.
}

/*
    ������ ¡�踦 ���� promote()�� demote() �޼���� �ܼ��� setSalary()�޼��带 ȣ���Ͽ�
    �޿��� �����Ѵ�.

    ���� �Ķ���Ϳ� ���� ����Ʈ ������ �Լ� ����� ������ �� �� �ֵ�.

    �̶����� �Լ��� ���Ǻΰ� �ִ� �ҽ����Ͽ����� ����Ʈ���� ������ �ʴ´�.
    (.h���Ͽ����� ����Ʈ�� ������ �ȵǾ��ִ�. ���� �ű⼭ ���ټ��� �ִ�.)
*/
void Records::Employee::promote(int raiseAmount)
{
    setSalary(getSalary() + raiseAmount);
}

void Records::Employee::demote(int demeritAmount)
{
    setSalary(getSalary() - demeritAmount);
}

/*
    ä��� �ذ� ���� hire() fire()�޼���� �ܼ��� mHired������ �������
    true, false�� �ٲ۴�.
*/
void Records::Employee::hire()
{
    mHired = true;
}

void Records::Employee::fire()
{
    mHired = false;
}
/*
    display �޼���� �ֿܼ� ������ ��ü�� ���� ���¸� ����Ѵ�.
    ����,  EmployeeŬ���� ������ �Ϻ��̱� ������, get set���� �޼��带 ������� �ʰ�,
    ��������Ϳ� ���������� �����ϴ�.

    �׷���, Ŭ���� ���ο����� �������� ���� get set�� ����ϸ� ����.
*/
void Records::Employee::display() const
{
    cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
    cout << "-------------------------" << endl;
    cout << (mHired ? "Current Employee" : "Former Employee") << endl;
    cout << "Employee Number: " << getEmployeeNumber() << endl;
    cout << "Salary: $" << getSalary() << endl;
    cout << endl;
}
/*
    ���� ����, ���� �޼��尡 ��� �����Ͱ��� �����ϰų� �����ϴ� �۾��� ����Ѵ�.

    �̷� �޼��尡 ���� ���� ������ ó�� ��������, ���� �̷��� ���� ���͸� ����ϴ����� ����.

    ���Ϳ� ���Ͱ� ������, �ش� ���� �̿������ ����׸� ���� �극��ũ ����Ʈ�� �� �� �ְ�,
    Ŭ�������� �����͸� �����ϴ� ����� �ٲٰ� ������, ���Ϳ� ���͸� �����ϸ� �ȴٴ� ������ �ִ�.
*/
void Records::Employee::setFirstName(const std::string& firstName)
{
    mFirstName = firstName;
}

const std::string& Records::Employee::getFirstName() const
{
    return mFirstName;
}

void Records::Employee::setLastName(const std::string& lastName)
{
    mLastName = lastName;
}

const std::string& Records::Employee::getLastName() const
{
    return mLastName;
}

void Records::Employee::setEmployeeNumber(int employeeNumber)
{
    mEmployeeNumber = employeeNumber;
}

int Records::Employee::getEmployeeNumber() const
{
    return mEmployeeNumber;
}

void Records::Employee::setSalary(int newSalary)
{
    mSalary = newSalary;
}

int Records::Employee::getSalary() const
{
    return mSalary;
}

bool Records::Employee::getIsHired() const
{
    return mHired;
}
