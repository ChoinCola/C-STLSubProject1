#include "Employee.h"
#include <iostream>

using namespace std;
/*
    Employee.cpp 는 클래스의 메서드들에 대한 구현부를 담고있다.
    생성자는 데이터 멤버의 초깃값을 설정한다.
    종업원 이름은 공백문자,
    번호는 -1
    급여는 신입급여,
    교용상태는 미고용으로 초기화하여 시작한다.
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
    // 동적생성데이터가 존재하지 않음으로, 사용하지 않는다.
}

/*
    승진과 징계를 위한 promote()와 demote() 메서드는 단순히 setSalary()메서드를 호출하여
    급여를 변경한다.

    정수 파라미터에 대한 디폴트 지정은 함수 선언부 에서만 할 수 있따.

    이때문에 함수의 정의부가 있는 소스파일에서는 디폴트값이 보이지 않는다.
    (.h파일에서는 디폴트값 선언이 안되어있다. 물론 거기서 해줄수도 있다.)
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
    채용과 해고를 위한 hire() fire()메서드는 단순히 mHired데이터 멤버값을
    true, false로 바꾼다.
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
    display 메서드는 콘솔에 종업원 객체의 현재 상태를 출력한다.
    물론,  Employee클래스 구현의 일부이기 때문에, get set같은 메서드를 사용하지 않고,
    멤버데이터에 직접접근이 가능하다.

    그러나, 클래스 내부에서라도 가독성을 위해 get set을 사용하면 좋다.
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
    밑의 게터, 세터 메서드가 멤버 데이터값을 리턴하거나 변경하는 작업을 담당한다.

    이런 메서드가 별로 옳지 않은것 처럼 보이지만, 보통 이러한 게터 세터를 사용하는편이 좋다.

    게터와 세터가 있으면, 해당 변수 이용시점에 디버그를 위한 브레이크 포인트를 걸 수 있고,
    클래스에서 데이터를 저장하는 방식을 바꾸고 싶을때, 게터와 세터만 수정하면 된다는 장점이 있다.
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
