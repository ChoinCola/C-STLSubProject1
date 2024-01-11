/*
	클래스 정의를 작성하면서 클래스에 대한 테스트를 별도의 독립코드로 수행하면 편리하다.

	Employee 클래스에 대한 테스트 코드를  main 에 담아. 작성이 완료되고

	어느정도 작동할것 이라는 생각이 들면, 테스트 코드를 주석해제하여. 테스트를 한다.

	테스트가 끝나면, 다시 주석으로 감싸 main()함수가 함꼐 컴파일되어 실제 사용할 

	main함수와 충돌하지 않도록 한다.
*/

//#pragma once
//#include <iostream>
//#include "Employee.h"
//
//using namespace std;
//using namespace Records;
//
//int main()
//{
//	cout << "Testing the Employee Class." << endl;
//	Employee emp;
//	emp.setFirstName("John");
//	emp.setLastName("Doe");
//	emp.setEmployeeNumber(71);
//	emp.setSalary(50000);
//	emp.promote();
//	emp.promote(50);
//	emp.hire();
//	emp.display();
//
//	return 0;
//}