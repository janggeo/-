#include<iostream>
#include<string>

using namespace std;

#include "Student.h"

/*Student 멤버함수*/
void Student::Initialize(){/*멤버 "",0또는 NULL로 초기화*/
	m_name="";
	m_hakbun=0;
	m_subnum=0;
	m_sub=NULL;
	m_aveGPA=0;
}
void Student::Initialize(string name,int hakbun,int subnum,Subject* sub){ /*인자값으로 멤버 초기화, aveGPA는 CalcAveGPA를 호출하여 계산*/
	m_name=name;
	m_hakbun=hakbun;
	m_subnum=subnum;
	m_sub=sub;
	CalcAveGPA();/*aveGPA계산*/
}

void Student::InputValue(int &value){/*m_hakbun,m_subnum 입력용*/
	int temp;
	cin>>temp;
	cin.ignore(); /*버퍼비우기*/
	value=temp;
}
void Student::InputValue(string &value){/*m_name 입력용*/
	getline(cin,value);
}
void Student::InputData(){/*Student의 멤버변수 입력*/
	cout<<"학생 이름: ";
	InputValue(m_name);
	cout<<"학번 : ";
	InputValue(m_hakbun);
	cout<<"과목수 : ";
	InputValue(m_subnum);

	m_sub=new Subject[m_subnum];	/*입력받은 m_subnum만큼 Subject동적할당*/
	
	for(int i=0;i<m_subnum;i++){
		m_sub[i].InputData();/*m_subnum만큼 동적할당된 각 Subject멤버변수 입력*/
	}
	CalcAveGPA();/*학생의 평균 평점 계산*/
}
void Student::PrintData(){/*학생 정보 출력*/
	cout<<"========================================"<<endl;
	cout<<"  이름 : "<<GetName()<<"\t학번 : "<<GetHakbun()<<endl;
	m_sub->PrintTitle();
	for(int i=0;i<GetSubNum();i++){/*과목수 만큼 반복하여 과목정보 출력*/
		m_sub[i].PrintData();
	}
	cout<<"---------------------------------------"<<endl;
	cout<<"\t\t\t평균평점   "<<GetAveGPA()<<endl;
}
void Student::CalcAveGPA(){/*평균 평점계산*/
	float GPA_sum=0;
	for(int i=0;i<m_subnum;i++){/*각 과목의 평점을 GPA_sum에 더한다*/
		GPA_sum += m_sub[i].GetGPA();
	}
	m_aveGPA = GPA_sum / m_subnum;/*GPA_sum을 과목수로 나누어 평균평점 계산*/
}
void Student::Remove(){/*동적할당된 Subject 해제*/
	delete []m_sub; /*m_sub가 가리키는 힙공간 해제*/
	cout<<"delete";
}