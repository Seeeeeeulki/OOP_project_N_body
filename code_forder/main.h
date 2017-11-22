#pragma once
#include<time.h>//타이머를 실행시켜주기 위한 c내부 시간함수
#include"Utility.h"

particle* find_particle(utility utility, int command) //입력에 맞는 번호의 particle의 주소를 반환
{
	for (int i = 0; i<utility.all_particle.size(); i++)
	{
		if (utility.all_particle[i]->particle_num == command) //particle_num이 command의 숫자와 동일할 때 출력한다
		{
			return utility.all_particle[i];
		}
	}
}

set* find_set(utility utility, int command) //입력에 맞는 번호의 set의 주소를 반환
{
	for (int i = 0; i < utility.all_set.size(); i++)
	{
		if (utility.all_set[i]->set_num == command)
		{
			return utility.all_set[i];
		}
	}
}

void run_simulation_ru(int duration); //ru명령어 시뮬레이션을 duration시간동안 실행한다
void run_simulation_rv(int duration); //rv명령어 시뮬레이션을 duration시간동안 실행한다
