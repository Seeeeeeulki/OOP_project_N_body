#pragma once
#include "Set.h"
class utility
{
public:
	std::vector<particle*> all_particle;//모든 particle를 저장한다
	std::vector<set*> all_set;			//모든 set를 저장한다
	std::vector<force*> all_force;		//모든 force를 저장한다
	bool enable_gravity = true;			//gravity 기능 여부를 결정하는 변수
	double time=0;						//current time을 의미하는 변수

	void print_usage();				//memory 사용량 출력
	void delete_particle();			//particle을 메모리에서 제거
	void delete_force();			//force를 메모리에서 제거
	void delete_all();				//메로리 초기화
};