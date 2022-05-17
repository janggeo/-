#ifndef SUBJECT_H
#define CIRCLE_H
#include<string>
#include<iostream>

using namespace std;

class Subject{	//subject객체
	protected:
		string m_name;	//과목명
		int m_hakjum;	//학점
		string m_grade;	//등급
		float m_GPA;	//평점
		bool check_grade=true; //등급이 제대로 입력되었는지 체크
	public:
		void Initialize();	//멤버변수 초기화
		void Initialize(string name, int hakjum, string grade);	//인자값으로 멤버변수 초기화
		void InputValue(int &value);		//int형 값 입력
		void InputValue(string &value);	//string형 값 입력
		void InputData();	//멤버변수 값 입력
							//내부적으로 InputValue()이용
		void PrintTitle();	//멤버변수에 대한 title Text출력
		void PrintData();	//멤버변수 값 출력
		void CalcGPA();		//평점 계산
	public:
		string GetName() const{	// 과목명 반환
			return m_name;
		}	//m_name return
		int GetHakjum() const {	//학점 반환
			return m_hakjum;
		}	//m_hakjum return
		string GetGrade() const{	//등급 반환
			return m_grade;
		}	//m_grade return
		float GetGPA() const{	//평점 반환
			return m_GPA;
		}	//m_GPA retrun
};
#endif