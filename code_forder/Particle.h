#pragma once

class particle			//N_body_simulation에서 particle을 표현
{
protected:
	double location[2]; //particle의 위치 [x,y]
	double velocity[2]; //particle의 속도 [x,y]
	double mass;		//particle이 가진 질량
	bool movavle;		//particle의 움직임 여부를 결정하는 boolean값

public:
	void Print_particle(); //particle object의 정보를 출력하는 함수
};
