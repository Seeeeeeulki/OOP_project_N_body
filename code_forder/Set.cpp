#include "Set.h"
set::set(std::string name)
{
	set_name = name;
}

void set::Print_Set()
{
	for (int i = 0; i < particle_set.size(); i++)
	{
		particle_set[i]->Print_particle();
	}
}

void set::add_particle(particle* A)
{
	particle_set.push_back(A);
}

void set::add_force(force* A)
{
	force_x += A->get_force_x();
	force_y += A->get_force_y();
}

void set::delete_particle(int A)
{
}
