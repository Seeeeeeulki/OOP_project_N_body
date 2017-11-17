#pragma once
#include "Particle.h"
#include "Force.h"
#include <vector>
class set:public particle				//N_body_simulation에서 particle을 표현
{
private:
	std::vector<particle> particle_set; //particle의 list를 저장한다
	double force_x;						//set에 적용되는 전체 x방향 힘
	double force_y;						//set에 적용되는 전체 y방향 힘
public:
	void Print_Set();					//set의 정보를 출력한다
	void add_particle(particle A);		//set의 particle list에 particle A를 넣는다.
	void add_force(force A);			//set의 force에 force A의 힘을 더한다
	void delete_particle(int A);		//특정 particle을 set에서 제외한다.
};