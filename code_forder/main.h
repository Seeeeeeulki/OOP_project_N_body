#pragma once
#include"Utility.h"
#include<math.h>

double time = 0;						//current time을 의미하는 변수
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

void run_simulation_ru(utility utility, double duration) //ru명령어 시뮬레이션을 duration시간동안 실행한다
{
	double unit_time = 0.01;
	double count = 0;
	while (count < duration)
	{
		count += unit_time;
		for (int a = 0; a < utility.all_set.size(); a++)
		{
			if (utility.enable_gravity == true) //만유인력에 대한 구문
			{
				for (int b = 0; b < utility.all_set[a]->particle_set.size(); b++)
				{
					for (int c = 0; c < utility.all_set[a]->particle_set.size(); c++)
					{
						if (c != b)
						{
							long double x_gap = utility.all_set[a]->particle_set[b]->location[0] - utility.all_set[a]->particle_set[c]->location[0];//b와 c의 x축 거리차
							long double y_gap = utility.all_set[a]->particle_set[b]->location[1] - utility.all_set[a]->particle_set[c]->location[1];//b와 c의 y축 거리차
							double b_mass = utility.all_set[a]->particle_set[b]->mass;//b의 무게
							double c_mass = utility.all_set[a]->particle_set[c]->mass;//c의 무게
							long double r = sqrt(pow(x_gap, 2) + pow(y_gap, 2));//b와 c의 거리
							utility.all_set[a]->particle_set[b]->velocity[0] += 6.67259*b_mass*c_mass / r*x_gap*unit_time/pow(10,11);//unit_time만큼의 x축에 대한 만유인력가속을 더해준다.
							utility.all_set[a]->particle_set[b]->velocity[1] += 6.67259*b_mass*c_mass / r*y_gap*unit_time/pow(10,11);//unit_time만큼의 y축에 대한 만유인력가속을 더해준다.
						}
					}
				}
			}
			for (int b = 0; b < utility.all_set[a]->force_set.size(); b++)
			{
				for (int c = 0; c < utility.all_set[a]->particle_set.size(); c++)
				{
					utility.all_set[a]->particle_set[c]->velocity[0] += utility.all_set[a]->force_set[b]->get_force_x() / utility.all_set[a]->particle_set[c]->mass*unit_time;
					utility.all_set[a]->particle_set[c]->velocity[1] += utility.all_set[a]->force_set[b]->get_force_y() / utility.all_set[a]->particle_set[c]->mass*unit_time;
				}
			}
		}
		time += unit_time;
	}
}
void run_simulation_rv(int duration); //rv명령어 시뮬레이션을 duration시간동안 실행한다
