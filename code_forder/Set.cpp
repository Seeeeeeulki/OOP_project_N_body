#include "Set.h"
set::set(int num)
{
	set_num = num;
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

void set::add_force(force A)
{
}

void set::delete_particle(int A)
{
}
