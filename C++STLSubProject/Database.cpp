#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;
namespace Records {
    // 시작시 고유 번호의 시작값을 설정한다.
    Records::Database::Database() : mNextEmployeeNumber(kFirstEmployeeNumber)
    {
    }
    /*
        새로운 Employee객체를 생성하고 종업원 정보를 설정한 뒤, 데이터베이스에 추가한다.
        새로운 종업원이 추가되면, mNestEmployeeNumber를 1증가시켜, 다음 번호중복이 발생하지 않도록 한다.
    */
    Employee& Records::Database::addEmployee(const std::string& firstName, const std::string& lastName)
    {
        Employee theEmployee;
        theEmployee.setFirstName(firstName);
        theEmployee.setLastName(lastName);
        theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
        theEmployee.hire();
        mEmployees.push_back(theEmployee);
        return mEmployees[mEmployees.size() - 1];
    }
    /*
        구간 지정 for루프를 통해, 인자로 주어진 조건에 맞는 종업원이 있는지 검사하고,
        존재하지 않으면 익셉션을 발생한다.
    */
    Employee& Records::Database::getEmployee(int employeeNumber)
    {
        for (auto& employee : mEmployees) {
            if (employee.getEmployeeNumber() == employeeNumber) {
                return employee;
            }
        }
    }

    Employee& Records::Database::getEmployee(const std::string& firstName, const std::string& lastName)
    {
        for (auto& employee : mEmployees) {
            if (employee.getFirstName() == firstName &&
                employee.getLastName() == lastName) {
                return employee;
            }
        }
    }
    /*
        display또한, 해당되는 객체의 모든 항목을 display호출하여 종업원 정보를 콘솔에 출력한다.
    */
    void Records::Database::displayAll() const
    {
        for (const auto& employee : mEmployees) {
            employee.display();
        }
    }

    void Records::Database::displayCurrent() const
    {
        for (const auto& employee : mEmployees) {
            if (employee.getIsHired())
                employee.display();
        }
    }

    void Records::Database::displayFormer() const
    {
        for (const auto& employee : mEmployees) {
            if (!employee.getIsHired())
                employee.display();
        }
    }
}