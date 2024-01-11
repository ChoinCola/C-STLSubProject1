/*
	Employee ��, Ư�� ������ �Ѹ��� ������ ���������Ѵ�.

	�� Ŭ������ �޼��� ���� ������ ������ ��ȸ�ϰ� ������ �� �ְ� �Ѵ�.

	Employee Ŭ������ �ڽ��� ������ ����ϴ� �޼��嵵 �����Ѵ�.

	�׸��� �޿��� ������ �����ϴ� �޼��嵵 �����Ѵ�.
*/

#pragma once
#include <string>

// ���ӽ����̽��� ������ ��� �׸��� ��� �ڵ忡 �����Ͽ�, �ɹ��̸��� ���� ���� ������ �̷��.
namespace Records {
	// ���Ի���� ù �޿� �׼�.
	const int kDefaultStartingSalary = 30000;

	/*
		Records ���ӽ����̽� �ȿ� �ֱ� ������, �ȿ����� �������� ������ �� ������,
		�ܺο����� Records::kdefaultStartingSalary �� �����ؾ��Ѵ�.
	*/

	class Employee
	{
	public:
		Employee();
		~Employee();
		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire(); // ������ ä�� �Ǵ� ��ä��
		void fire(); // ������ �ذ�
		void display() const; // �ֿܼ� ������ ���� ���

		// ���Ϳ� ����
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool getIsHired() const;
		// �Ʒ��κ��� private ������ �κ�����, Ŭ���� �ۿ����� ������, ������ ���� ����.
		// get�� set���θ� ���� �����ϴ�.

	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber;
		int mSalary;
		bool mHired;
	};
}