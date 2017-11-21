#pragma once
#include "Set.h"
class utility
{
public:
	int particle_number=0;			//particle의 수를 저장한다
	int set_number=0;				//set의 수를 저장한다
	int force_number=0;				//force의 수를 저장한다
	bool enable_gravity = false;	//gravity 기능 여부를 결정하는 변수

	void print_usage();				//memory 사용량 출력
	void delete_particle();			//particle을 메모리에서 제거
	void delete_force();			//force를 메모리에서 제거
	void delete_all();				//메로리 초기화
};