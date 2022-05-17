/*[2021076029] [장정환]
	1)g++컴파일러를 이용하였습니다.
	g++ Sungjuk.cpp Subject.cpp Subject.h Student.cpp Student.h -o Sungjuk
	2)2)제 컴퓨터에서는 과목이나 학생을 한글로 입력하면 안됩니다..
	*/
/*
	1)Stuent.h에는 Subject.h이 include되어있다.
	2)따라서 Sungjuk.cpp 파일에서 Student.h을 include하면 Subject.h도 include된다.
	3)헤더파일은 다리역할 Subject.cpp, Student.cpp과 main함수를 연결해준다.
	4)Student.cpp에서도 Subject클래스가 필요하지만 Student.h에 Subject.h가 Include되어 있기 때문에 괜찮다.
	5)ifndef endif를 이용 헤더파일이 중복선언 될 경우를 막는다.
	*/

#include<iostream>
using namespace std;


#include"Student.h"

int main(void){
	/*st2의 subject선언 및 초기화*/
	Subject sub[2]; 
	sub[0].Initialize("컴퓨터",3,"C");	
	sub[1].Initialize("현대무용",2,"A");

	Student st1,st2;

	st1.Initialize();	/*st1 초기화*/
	st2.Initialize("홍길동",2013909845,2,sub);	/*st2 초기화*/
	st1.InputData();	/*사용자로부터 멤버 입력받는다*/

	/*st1멤버 출력 */
	cout<<"\n"<<"st1정보"<<"\n";
	st1.PrintData();	
	/*st2멤버 출력*/
	cout<<"\n"<<"st2정보"<<"\n";
	st2.PrintData();
	/*과목수만큼 동적 할당된 Subject 해제*/
	st1.Remove();
	return 0;
}