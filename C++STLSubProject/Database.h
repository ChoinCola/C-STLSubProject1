
/*
	������ ���̽� Ŭ������ std::vector Ŭ������ �̿��� Employee ��ü���� ��´�.

	�����ͺ��̽��� ���ο� �������� ���� ������ ��ȣ�� �ڵ����� �ο����� �� �־�� �Ѵ�.

	�̸� ���� ���۹�ȣ�� �����ϴ� ��� ������ �����Ѵ�.
*/
#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"
/*
	�����ͺ��̽��� ���ο� �������� ����� �� �ܼ��� �̸�(first name)�� ��(last name)�� �����ϸ� �ȴ�.

	������ ��� �Լ��� ���ǻ� ��� ������ �� ���� ������ Employee ��ü�� �����Ѵ�.

	�ܺο����� getEmployee() �ż���� ������ ��ü�� ���� �� �ִµ�, �� �޼���� �������� �ĺ��ϱ� ����
	
	������ ��ȣ�� �Է¹ްų� ���� �̸��� �Է¹��� �� �ֵ��� �� ���� �������� �����.
*/
namespace Records {
	const int kFirstEmployeeNumber = 1000;
	
	class Database
	{
	public:
		Database();
		Employee& addEmployee(const std::string& firstName,
			const std::string& lastName);
		Employee& getEmployee(int employeeNumber);
		Employee& getEmployee(const std::string& firstName,
			const std::string& lastName);

		/*
			�����ͺ��̽��� ��� ������ ���ڵ��� �߾� ����� �̱� ������ ��ü �������� ���� �����
			����, ������� ������, ������ ������ ����� �����Ͽ� ����� �� �־�� �Ѵ�.
		*/

		void displayAll() const;
		void displayCurrent() const;
		void displayFormer() const;

		/*
			mEmployees�� Employee ��ü���� ��´�. mNextEmployeeNumber ������ ���ο� �������� ���Ǿ��� ��
			�Ҵ��� ������ȣ�� �����Ѵ�.
		*/
	private:
		std::vector<Employee> mEmployees;
		int mNextEmployeeNumber;
	};
}