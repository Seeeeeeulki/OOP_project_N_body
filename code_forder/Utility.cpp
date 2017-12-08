#include "Utility.h"
#include <Windows.h>
#include <math.h>
void utility::print_usage()
{
	std::cout << "Particles: " << all_particle.size() << std::endl;
	std::cout << "Sets: " << all_set.size() << std::endl;
	std::cout << "Forces: " << all_force.size() << std::endl;
}

void utility::delete_particle(particle* A)
{
	for (int i = 0; i < all_set.size(); i++) //if particle is in set, delete from that set
	{
		for (int i2 = 0; i2 < all_set[i]->particle_set.size(); i2++)
		{
			if (all_set[i]->particle_set[i2]->particle_name == A->particle_name)
			{
				all_set[i]->delete_particle(all_set[i]->particle_set[i2]);
			}
		}
	}

	for (int i = 0; i < all_particle.size(); i++)
	{
		if (all_particle[i] == A) //check if address is same
		{
			all_particle.erase(all_particle.begin() + i); //if the address is same, erase it
		}
	}
}

void utility::delete_force(force* A)
{
	for (int i = 0; i < all_set.size(); i++) //if the force is in set, erase from that set
	{
		for (int i2 = 0; i2 < all_set[i]->force_set.size(); i2++)
		{
			if (all_set[i]->force_set[i2]->force_name == A->force_name)
			{
				all_set[i]->delete_force(all_set[i]->force_set[i2]);
			}
		}
	}

	for (int i = 0; i < all_force.size(); i++)
	{
		if (all_force[i] == A) //check if address is same
		{
			all_force.erase(all_force.begin() + i); //if the address is same, erase it
		}
	}
}

void utility::delete_all() //delete particle, delete force, delete set(DO NOT CHANGE ORDER!)
{
	while (1)
	{
		int num = all_particle.size();
		if (num == 0)
			break;
		delete_particle(all_particle[num - 1]);
	}
	while (1)
	{
		int num = all_force.size();
		if (num == 0)
			break;
		delete_force(all_force[num - 1]);
	}
	while (1)
	{
		int num = all_set.size();
		if (num == 0)
			break;
		set* erase = all_set[num-1];
		all_set.erase(all_set.begin() + num - 1);
		delete erase;
		//std::cout << all_set.size() << std::endl; //test code

	}
	if (all_particle.size() == 0 && all_force.size()==0 && all_set.size() == 0) //if all dynamic allocation has been deleted, execute it
	{
		std::cout << "All particles deleted" << std::endl;
		std::cout << "All forces deleted" << std::endl;
		std::cout << "All sets deleted" << std::endl;
	}
}
void utility::run_simulation_ru(utility utility, double duration) //run simulation for duration
{
	double unit_time = 0.01;
	int count = 0;
	while (count < duration / pow(unit_time, 2))
	{
		if (GetAsyncKeyState(VK_ESCAPE)) //simulation stop when when 'ESC' key pressed
		{
			std::cout << "ESCAPE-PRESSED" << std::endl;
			break;
		}

		std::cout << "\r" << "processing" << (count*unit_time / duration) << "%";
		count += 1 / unit_time;
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
							utility.all_set[a]->particle_set[b]->velocity[0] -= 6.67259*c_mass / r * x_gap*unit_time / pow(10, 11);//accelate x gravity of unit_time to velocity
							utility.all_set[a]->particle_set[b]->velocity[1] -= 6.67259*c_mass / r * y_gap*unit_time / pow(10, 11);//accelate y gravity of unit_time to velocity
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
}
void utility::run_simulation_rv(utility utility, double duration) //run simulation for duration and print particle information per time_tick
{
	double unit_time = 0.01;
	int count = 0;
	while (count < duration / pow(unit_time, 2))//check duration
	{
		if (GetAsyncKeyState(VK_ESCAPE)) //simulation stop when esc pressed
		{
			std::cout << "ESCAPE-PRESSED" << std::endl;
			break;
		}

		std::cout << "processing" << (count*unit_time / duration) << "%\r";
		count += 1 / unit_time;
		if (utility.all_particle.size() != 0)//check particles size if 0 we do not have to print out information about particles
		{
			float a = count * pow(unit_time, 2);
			if (fmod(a, utility.timetick) == 0)//if timetick print
				for (int i = 0; i < utility.all_particle.size(); i++)
				{
					std::cout << count * pow(unit_time, 2) << "second simulation" << std::endl;
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
							utility.all_set[a]->particle_set[b]->velocity[0] -= 6.67259*c_mass / r * x_gap*unit_time / pow(10, 11);//accelate x gravity of unit_time to velocity
							utility.all_set[a]->particle_set[b]->velocity[1] -= 6.67259*c_mass / r * y_gap*unit_time / pow(10, 11);//accelate y gravity of unit_time to velocity
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
}
