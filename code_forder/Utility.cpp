#include "Utility.h"

void utility::print_usage()
{
	std::cout << "Particles: " << all_particle.size() << std::endl;
	std::cout << "Sets: " << all_set.size() << std::endl;
	std::cout << "Forces: " << all_force.size() << std::endl;
}

void utility::delete_particle(particle* A)
{
	for (int i = 0; i < all_particle.size(); i++)
	{
		if (all_particle[i] == A) //주소가 같은지 확인한다
		{
			all_particle.erase(all_particle.begin() + i);
		}
	}
}

void utility::delete_force()
{
}

void utility::delete_all()
{
}
