#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;
namespace Records {
    // ���۽� ���� ��ȣ�� ���۰��� �����Ѵ�.
    Records::Database::Database() : mNextEmployeeNumber(kFirstEmployeeNumber)
    {
    }
    /*
        ���ο� Employee��ü�� �����ϰ� ������ ������ ������ ��, �����ͺ��̽��� �߰��Ѵ�.
        ���ο� �������� �߰��Ǹ�, mNestEmployeeNumber�� 1��������, ���� ��ȣ�ߺ��� �߻����� �ʵ��� �Ѵ�.
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
        ���� ���� for������ ����, ���ڷ� �־��� ���ǿ� �´� �������� �ִ��� �˻��ϰ�,
        �������� ������ �ͼ����� �߻��Ѵ�.
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
        display����, �ش�Ǵ� ��ü�� ��� �׸��� displayȣ���Ͽ� ������ ������ �ֿܼ� ����Ѵ�.
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