#pragma once
#include<time.h>//타이머를 실행시켜주기 위한 c내부 시간함수
#include"Utility.h"

particle* no_particle = new particle("no_particle",0,0,0,0,0);  //해당하는 particle이 없을때 반환
set* no_set = new set("no_set");								//해당하는 set이 없을때 반환
force* no_force = new force("no_force", " ", 0, 0);		//해당하는 force가 없을때 반환

particle* find_particle(utility utility, std::string command) //이름에 맞는 번호의 particle의 주소를 반환
{
	for (int i = 0; i<utility.all_particle.size(); i++)
	{
		if (utility.all_particle[i]->particle_name == command) //particle_name이 command의 숫자와 동일할 때 출력한다
		{
			return utility.all_particle[i];
		}
	}
	return no_particle;//이름이 맞는 particle이 없을 때 더비 particle인 no_particle 반환
}

set* find_set(utility utility, std::string command) //이름에 맞는 번호의 set의 주소를 반환
{
	for (int i = 0; i < utility.all_set.size(); i++)
	{
		if (utility.all_set[i]->set_name == command)
		{
			return utility.all_set[i];
		}
	}
	return no_set; //이름이 맞는 set이 없을 때 더미 set인 no_Set을 반환
}

force* find_force(utility utility, std::string command)
{
	for (int i = 0; i < utility.all_force.size(); i++)
	{
		if (utility.all_force[i]->force_name == command)
		{
			return utility.all_force[i];
		}
	}
	return no_force; //이름이 맞는 force가 없을 때 더미 force인 no_force을 반환
}

void run_simulation_ru(int duration); //ru명령어 시뮬레이션을 duration시간동안 실행한다
void run_simulation_rv(int duration); //rv명령어 시뮬레이션을 duration시간동안 실행한다
