#ifndef STUDENT_H
#define STUDENT_H
#include"Subject.h"
class Student{
	protected:
		string m_name;	/*학생이름*/
		int m_hakbun;	/*학생 학번*/
		int m_subnum;	/*과목수*/
		Subject* m_sub;	/*수강한 과목정보*/
		float m_aveGPA;	/*평균 평점*/
		friend void ShowData(const Student& s);
	public:
		void Initialize();	/*"",0,또는 NULL로 초기화*/
		void Initialize(string name,int hakbun,int subnum,Subject* sub); /*인자값을 이용한 초기화*/
		void Remove();	/*동적할당 메모리 해제(m_sub)*/
		void InputValue(int& value); /*int형 변수에 값입력*/
		void InputValue(string& value);	/*stirng형 변수에 값입력*/
		void InputData(); /*멤버변수의 값을 사용자로부터 입력받는다*/
		void PrintData(); /*멤버변수값 출력*/
		void CalcAveGPA(); /*평균평점 계산*/
	public:
		string GetName() const{	// 학생이름 반환
			return m_name;
		}	//m_name return
		int GetHakbun() {	//학번 반환
			return m_hakbun;
		}	//m_hakjum return
		int GetSubNum() const{	//수강한 과목수 반환
			return m_subnum;
		}	//m_grade return
		float GetAveGPA() const{	//평균평점 반환
			return m_aveGPA;
		}	//m_GPA retrun
};
#endif
