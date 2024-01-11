/*
	Employee 는, 특정 종업원 한명의 정보를 유지보수한다.

	이 클래스의 메서드 들은 종업원 정보를 조회하고 변경할 수 있게 한다.

	Employee 클래스는 자신의 정보를 출력하는 메서드도 내장한다.

	그리고 급여와 직급을 조정하는 메서드도 제공한다.
*/

#pragma once
#include <string>

// 네임스페이스로 생성된 모든 항목을 모든 코드에 적용하여, 심벌이름에 대한 매핑 단위를 이룬다.
namespace Records {
	// 신입사원의 첫 급여 액수.
	const int kDefaultStartingSalary = 30000;

	/*
		Records 네임스페이스 안에 있기 때문에, 안에서는 선언으로 접근할 수 있지만,
		외부에서는 Records::kdefaultStartingSalary 로 접근해야한다.
	*/

	class Employee
	{
	public:
		Employee();
		~Employee();
		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire(); // 종업원 채옹 또는 재채용
		void fire(); // 종업원 해고
		void display() const; // 콘솔에 종업원 정보 출력

		// 게터와 세터
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool getIsHired() const;
		// 아래부분은 private 데이터 부분으로, 클래스 밖에서는 볼수도, 수정할 수도 없다.
		// get과 set으로만 접근 가능하다.

	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber;
		int mSalary;
		bool mHired;
	};
}