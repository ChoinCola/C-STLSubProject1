#pragma once
/*
	프로그램의 마지막 부분은 사용자가 종업원 데이터베이스를 편리하게 이용할 수 있게 해주는 메뉴 방식의
	사용자 인터페이스 이다.
*/

/*
	main 함수는 메뉴를 출력하는 루프로 이루어진다.

	선택한 메뉴 항목을 실행하고 다시 메뉴로 돌아오기를 반복한다.

	각 행동은 별도의 함수로 분리하여. 정의하되 종업원 정보의 출력처럼

	간단한것 은 해당 명령 케이스에 바로 구현한다.
*/

#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"
using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main()
{
	Database employeeDB;
	bool done = false;
	
	while (!done) {
		int selection = displayMenu();
		switch (selection) {
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
		case 0:
			done = true;
			break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}
	return 0;
}
/*
	메뉴를 출력하고, 사용자의 선택을 기다린다.

	이때, 사용자가 충실하게 메뉴의 요구 조건에 응답한다고 가정한다.

	숫자를 입력하라 했을 때, 무조건 숫자를 입력한다고 가정한다.
*/
int displayMenu()
{
	int selection;
	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) List all employees" << endl;
	cout << "5) List all current employees" << endl;
	cout << "6) List all former employees" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "--->";
	cin >> selection;
	return selection;
}
/*
	doHire 함수는 새로운 종업원의 이름을 사용자로부터 받고, 데이터베이스에 추가한다.

	만약 에러가 발생하면 메시지를 출력하고 작업을 반복한다.
*/
void doHire(Database& db)
{
	string firstName;
	string lastName;

	cout << "First name?";
	cin >> firstName;
	cout << "Last name?";
	cin >> lastName;

	try {
		db.addEmployee(firstName, lastName);
	}
	catch (const std::exception& exception) {
		cerr << "Unable to add new employee: " << exception.what() << endl;
	}
}

/*
	해고와 승진을 위한 doFire()와 doPromote() 함수는 데이터베이스에 주어진 고유 번호의 종업원이 있는지 물어보고
	Employee 객체를 얻어와서 그 객체의 메서드를 이용해 작업을 수행한다.
*/
void doFire(Database& db)
{
	int employeeNumber;
	cout << "Employee number? ";
	cin >> employeeNumber;
	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employee " << employeeNumber << " terminated." << endl;
	}
	catch (const std::exception& exception) {
		cerr << "Unable to terminate employee: " << exception.what() << endl;
	}
}

void doPromote(Database& db)
{
	int employeeNumber;
	int raiseAmount;

	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a raise? ";
	cin >> raiseAmount;
	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	}
	catch (const std::exception& exception) {
		cerr << "Unable to terminate employee: " << exception.what() << endl;
	}
}

void doDemote(Database& db)
{

}
