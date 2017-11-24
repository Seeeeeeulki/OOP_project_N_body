#include "Utility.h"

void utility::print_usage()
{
	std::cout << "Particles: " << all_particle.size() << std::endl;
	std::cout << "Sets: " << all_set.size() << std::endl;
	std::cout << "Forces: " << all_force.size() << std::endl;
}

void utility::delete_particle(particle* A)
{
	for (int i = 0; i < all_set.size(); i++) //particle�� set�� ���� ������ �� set���� �����
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
		if (all_particle[i] == A) //�ּҰ� ������ Ȯ���Ѵ�
		{
			all_particle.erase(all_particle.begin() + i); //�ּҰ� ������ �����
		}
	}
}

void utility::delete_force(force* A)
{
	for (int i = 0; i < all_set.size(); i++) //force�� set�� ���� ������ �� set���� �����
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
		if (all_force[i] == A) //�ּҰ� ������ Ȯ���Ѵ�
		{
			all_force.erase(all_force.begin() + i); //�ּҰ� ������ �����
		}
	}
}

void utility::delete_all() //particle ����� force����� set�� �����(���� �ٲ��� �� ��)
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
	if (all_particle.size() == 0 && all_force.size()==0 && all_set.size() == 0) //��� �����Ҵ��� ����� �������� ����
	{
		std::cout << "All particles deleted" << std::endl;
		std::cout << "All forces deleted" << std::endl;
		std::cout << "All sets deleted" << std::endl;
	}
}
