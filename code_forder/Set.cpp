#include "Set.h"
set::set(std::string name)
{
	set_name = name;
}

void set::Print_Set()
{
	std::cout << "set x direction force: " << this->force_x << std::endl;
	std::cout << "set y direction force: " << this->force_y << std::endl;
	for (int i = 0; i < particle_set.size(); i++)
	{
		particle_set[i]->Print_particle();
	}
}

void set::add_particle(particle* A)
{
	int overlap = 0;
	for (int i = 0; i < particle_set.size(); i++)
	{
		if (particle_set[i]->particle_name == A->particle_name)
		{
			std::cout << "이미 포함된 particle입니다." << std::endl;
			overlap = 1;
		}
		if (particle_set[i]->location[0] == A->location[0] && particle_set[i]->location[1] == A->location[1])
		{
			std::cout << "이미 해당 위치에 particle이 있습니다." << std::endl;
			overlap = 1;
		}
	}
	if (overlap == 0)
	{
		particle_set.push_back(A);
		std::cout << "Particle " << A->particle_name << " is added to set " << this->set_name << std::endl;
	}
}

void set::add_force(force* A)
{
	int overlap = 0;
	for (int i = 0; i < force_set.size(); i++)
	{
		if (force_set[i]->force_name == A->force_name)
		{
			std::cout << "이미 포함된 force입니다." << std::endl;
			overlap = 1;
		}
	}
	if (overlap == 0)
	{
		force_set.push_back(A);
		std::cout << "Force " << A->force_name << " is added to set " << this->set_name << std::endl;
		force_x += A->get_force_x();
		force_y += A->get_force_y();
	}
}

void set::delete_particle(particle* A)
{
	for (int i = 0; i < particle_set.size(); i++)
	{
		if (particle_set[i] == A) //check if address is same
		{
			particle_set.erase(particle_set.begin() + i);
		}
	}
}

void set::delete_force(force * A)
{
	force_x -= A->get_force_x();
	force_y -= A->get_force_y();

	for (int i = 0; i < force_set.size(); i++)
	{
		if (force_set[i] == A) //check if address is same
		{
			force_set.erase(force_set.begin() + i); //if address is same, erase it
		}
	}
}
