#include "Utility.h"

void utility::print_usage()
{
	std::cout << "Particles: " << all_particle.size() << std::endl;
	std::cout << "Sets: " << all_set.size() << std::endl;
	std::cout << "Forces: " << all_force.size() << std::endl;
}

void utility::delete_particle(particle* A)
{
	for (int i = 0; i < all_set.size(); i++) //particle이 set에 속해 있으면 그 set에서 지운다
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
		if (all_particle[i] == A) //주소가 같은지 확인한다
		{
			all_particle.erase(all_particle.begin() + i); //주소가 같으면 지운다
		}
	}
}

void utility::delete_force(force* A)
{
	for (int i = 0; i < all_set.size(); i++) //force가 set에 속해 있으면 그 set에서 지운다
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
		if (all_force[i] == A) //주소가 같은지 확인한다
		{
			all_force.erase(all_force.begin() + i); //주소가 같으면 지운다
		}
	}
}

void utility::delete_all() //particle 지우고 force지우고 set을 지운다(순서 바꾸지 말 것)
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
	if (all_particle.size() == 0 && all_force.size()==0 && all_set.size() == 0) //모든 동적할당이 제대로 지워지면 실행
	{
		std::cout << "All particles deleted" << std::endl;
		std::cout << "All forces deleted" << std::endl;
		std::cout << "All sets deleted" << std::endl;
	}
}
