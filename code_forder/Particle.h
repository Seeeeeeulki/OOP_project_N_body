#pragma once
#include <iostream>

class particle			//N_body_simulation에서 particle을 표현
{
protected:
	double location[2]; 	//particle의 위치 [x,y]
	double velocity[2]; 	//particle의 속도 [x,y]
	double mass;			//particle이 가진 질량
	bool movavle;			//particle의 움직임 여부를 결정하는 boolean값

public:
	int particle_num;	//particle 번호
	particle(int num, double mass, double x, double y, double v_x, double v_y); //particle 클래스 변수 초기화 하는 함수
	void Print_particle(); //particle object의 정보를 출력하는 함수
};
