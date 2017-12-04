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

void run_simulation_ru(utility utility, double duration) //run simulation for duration
{
	double unit_time = 0.01;
	int count = 0;
	while (count < duration/pow(unit_time,2))
	{
		std::cout << "\r" << "processing" << (count*unit_time / duration) << "%" ;
		count += 1/unit_time;
		for (int a = 0; a < utility.all_set.size(); a++)
		{
			if (utility.enable_gravity == true) //gravity
			{
				for (int b = 0; b < utility.all_set[a]->particle_set.size(); b++)
				{
					for (int c = 0; c < utility.all_set[a]->particle_set.size(); c++)
					{
						if (c != b)//check b and c are different particeles
						{
							long double x_gap = utility.all_set[a]->particle_set[b]->location[0] - utility.all_set[a]->particle_set[c]->location[0];//x difference between particle b and c
							long double y_gap = utility.all_set[a]->particle_set[b]->location[1] - utility.all_set[a]->particle_set[c]->location[1];//y difference between particle b and c
							double c_mass = utility.all_set[a]->particle_set[c]->mass;//c의 무게
							long double r = sqrt(pow(x_gap, 2) + pow(y_gap, 2));//b와 c의 거리
							utility.all_set[a]->particle_set[b]->velocity[0] -= 6.67259*c_mass / r*x_gap*unit_time / pow(10, 11);//accelate x gravity of unit_time to velocity
							utility.all_set[a]->particle_set[b]->velocity[1] -= 6.67259*c_mass / r*y_gap*unit_time / pow(10, 11);//accelate y gravity of unit_time to velocity
						}
					}
				}
			}
			for (int b = 0; b < utility.all_set[a]->force_set.size(); b++)//apply force to particles of set
			{
				for (int c = 0; c < utility.all_set[a]->particle_set.size(); c++)
				{
					utility.all_set[a]->particle_set[c]->velocity[0] += utility.all_set[a]->force_set[b]->get_force_x() / utility.all_set[a]->particle_set[c]->mass*unit_time;//apply x force to particles
					utility.all_set[a]->particle_set[c]->velocity[1] += utility.all_set[a]->force_set[b]->get_force_y() / utility.all_set[a]->particle_set[c]->mass*unit_time;//apply y force to particles
				}
			}
			for (int i = 0; i < utility.all_set[a]->particle_set.size(); i++)//apply velocity to particles
			{
				if (utility.all_set[a]->particle_set[i]->fixed == false) //check whether paritlce is fixed or not
				{
					utility.all_set[a]->particle_set[i]->location[0] += utility.all_set[a]->particle_set[i]->velocity[0] * unit_time;//apply x velocity to particles
					utility.all_set[a]->particle_set[i]->location[1] += utility.all_set[a]->particle_set[i]->velocity[1] * unit_time;//apply y velocity to particles
				}
			}
		}
	}
	time += count*pow(unit_time,2);
}
void run_simulation_rv(utility utility , double duration) //run simulation for duration
{
	double unit_time = 0.01;
	int count = 0;
	while (count < duration / pow(unit_time, 2))//check duration
	{
		std::cout  << "processing" << (count*unit_time / duration) << "%\r";
		count += 1 / unit_time;
		if (utility.all_particle.size() != 0)//check particles size if 0 we do not have to print out information about particles
		{
			float a = count*pow(unit_time, 2);
			if (fmod(a,utility.timetick) == 0)//if timetick print
				for (int i = 0; i < utility.all_particle.size(); i++)
				{
					utility.all_particle[i]->Print_particle();
				}
		}
		for (int a = 0; a < utility.all_set.size(); a++)
		{
			if (utility.enable_gravity == true) //gravity
			{
				for (int b = 0; b < utility.all_set[a]->particle_set.size(); b++)
				{
					for (int c = 0; c < utility.all_set[a]->particle_set.size(); c++)
					{
						if (c != b)
						{
							long double x_gap = utility.all_set[a]->particle_set[b]->location[0] - utility.all_set[a]->particle_set[c]->location[0];//x difference between particle b and c
							long double y_gap = utility.all_set[a]->particle_set[b]->location[1] - utility.all_set[a]->particle_set[c]->location[1];//y difference between particle b and c
							double c_mass = utility.all_set[a]->particle_set[c]->mass;//mass of c
							long double r = sqrt(pow(x_gap, 2) + pow(y_gap, 2));//distance b and c 
							utility.all_set[a]->particle_set[b]->velocity[0] -= 6.67259*c_mass / r*x_gap*unit_time / pow(10, 11);//accelate x gravity of unit_time to velocity
							utility.all_set[a]->particle_set[b]->velocity[1] -= 6.67259*c_mass / r*y_gap*unit_time / pow(10, 11);//accelate y gravity of unit_time to velocity
						}
					}
				}
			}
			for (int b = 0; b < utility.all_set[a]->force_set.size(); b++)//apply force to particles of set
			{
				for (int c = 0; c < utility.all_set[a]->particle_set.size(); c++)
				{
					utility.all_set[a]->particle_set[c]->velocity[0] += utility.all_set[a]->force_set[b]->get_force_x() / utility.all_set[a]->particle_set[c]->mass*unit_time;//apply x force to particles
					utility.all_set[a]->particle_set[c]->velocity[1] += utility.all_set[a]->force_set[b]->get_force_y() / utility.all_set[a]->particle_set[c]->mass*unit_time;//apply y force to particles
				}
			}
			for (int i = 0; i < utility.all_set[a]->particle_set.size(); i++)//apply velocity to particles
			{
				if (utility.all_set[a]->particle_set[i]->fixed == false) //check whether paritlce is fixed or not
				{
					utility.all_set[a]->particle_set[i]->location[0] += utility.all_set[a]->particle_set[i]->velocity[0] * unit_time;//apply x velocity to particles
					utility.all_set[a]->particle_set[i]->location[1] += utility.all_set[a]->particle_set[i]->velocity[1] * unit_time;//apply y velocity to particles
				}
			}
		}
	}
	time += count*unit_time;
}
