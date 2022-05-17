#include<iostream>
#include<iomanip>

using namespace std;

#include"Subject.h"

/*Subject 멤버함수*/
void Subject::Initialize(){	//Subject클래스 초기화
	m_name=" ";
	m_hakjum=0;
	m_grade=" ";
	m_GPA=0.0f;
}
void Subject::Initialize(string name, int hakjum, string grade){
	m_name=name;
	m_hakjum=hakjum;
	m_grade=grade;
	CalcGPA();
}
void Subject::InputValue(int &value){	//int형 관련 멤버변수 입력
	int temp;
	cin>>temp;
	cin.ignore();	//버퍼비우기
	value=temp;
}
void Subject::InputValue(string &value){	//string형 관련 멤버변수 입력
	getline(cin,value);
}
void Subject::InputData(){	//멤버변수 입력
	cout<<"과목이름:";
	InputValue(m_name);	
	cout<<"학점:";
	InputValue(m_hakjum);
	/*정해진 등급을 입력 받을때 까지 반복*/
	do{
	cout<<"등급:";
	InputValue(m_grade);
	CalcGPA();
	}while(check_grade!=true);
}
void Subject::PrintTitle(){	//
	cout<<"---------------------------------------"<<endl;
	cout<<"교과목명\t학점수\t등급\t평점"<<endl;
	cout<<"---------------------------------------"<<endl;
}
void Subject::PrintData(){	//멤버변수 출력
	cout<<m_name;
	/*과목 이름길이에 따라 과목뒤 빈칸출력을 다르게하여 출력을 일정하게*/
	for(int i=0;i<20-(m_name.length());i++){
		if((m_name.length())>=20){	/*20을 넘어가면 그냥 출력*/
			break;
		}
		cout<<" "; 	/*빈칸출력*/
	}
	cout<<m_hakjum;
	cout<<right<<setw(7)<<m_grade;
	cout<<right<<setw(7)<<m_GPA<<endl;
}
void Subject::CalcGPA(){	//멤버 m_grade 값과 멤버 m_hakjum에 따라 m_GPA계산
	if (m_grade == "A+") {
		m_GPA = 4.5 * m_hakjum; check_grade=true;
	}
	else if (m_grade == "A0" || m_grade == "A") {
		m_GPA = 4.0 * m_hakjum; check_grade=true;
	}
	else if (m_grade == "B+") {
		m_GPA = 3.5 * m_hakjum; check_grade=true;
	}
	else if (m_grade == "B0" || m_grade == "B") {
		m_GPA = 3.0 * m_hakjum; check_grade=true;
	}
	else if (m_grade == "C+") {
		m_GPA = 2.5 * m_hakjum; check_grade=true;
	}
	else if (m_grade == "C0" || m_grade == "C") {
		m_GPA = 2.0 * m_hakjum; check_grade=true;
	}
	else if (m_grade == "D+") {
		m_GPA = 1.5 * m_hakjum; check_grade=true;
	}
	else if (m_grade == "D0" || m_grade == "D") {
		m_GPA = 1.0 * m_hakjum; check_grade=true;
	}
	else if (m_grade == "F") {
		m_GPA = 0.0 * m_hakjum; check_grade=true;
	}
	else {/*false를 반환하여 제대로된 학점을 입력하도록 유도*/
		cout << "A+,A0,B+,B0,C+,C0,D+,D0,F중 하나를 입력해주세요." << endl; check_grade=false;
	}
}