
/*
	데이터 베이스 클래스는 std::vector 클래스를 이용해 Employee 객체들을 담는다.

	데이터베이스는 새로운 종업원에 대해 종업원 번호를 자동으로 부여해줄 수 있어야 한다.

	이를 위해 시작번호를 정의하는 상수 변수를 선언한다.
*/
#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"
/*
	데이터베이스는 새로운 종업원을 등록할 때 단순히 이름(first name)과 성(last name)만 기입하면 된다.

	종업원 등록 함수는 편의상 등록 오나료 후 새로 생성된 Employee 객체를 리턴한다.

	외부에서는 getEmployee() 매서드로 종업원 객체를 얻을 수 있는데, 이 메서드는 종업원을 식별하기 위해
	
	종업원 번호를 입력받거나 성과 이름을 입력받을 수 있도록 두 가지 버전으로 만든다.
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
			데이터베이스는 모든 종업원 레코드의 중앙 저장소 이기 때문에 전체 종업원에 대한 목록은
			물론, 고용중인 종업원, 퇴직한 종업원 목록을 구분하여 출력할 수 있어야 한다.
		*/

		void displayAll() const;
		void displayCurrent() const;
		void displayFormer() const;

		/*
			mEmployees는 Employee 객체들을 담는다. mNextEmployeeNumber 변수는 새로운 종업원이 고용되었을 때
			할당할 고유번호를 지정한다.
		*/
	private:
		std::vector<Employee> mEmployees;
		int mNextEmployeeNumber;
	};
}