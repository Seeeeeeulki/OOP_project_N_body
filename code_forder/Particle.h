#pragma once
#include <iostream>
#include <String>

class particle			//N_body_simulation에서 particle을 표현
{
public:
	double location[2]; 	//particle의 위치 [x,y]
	double velocity[2]; 	//particle의 속도 [x,y]
	double mass;			//particle이 가진 질량
	bool fixed = false;			//particle의 움직임 여부를 결정하는 boolean값, 초기값은 false
	std::string particle_name;	//particle 이름


	particle(std::string name, double mass, double x, double y, double v_x, double v_y); //particle 클래스 변수 초기화 하는 함수
	void Print_particle(); //particle object의 정보를 출력하는 함수
};