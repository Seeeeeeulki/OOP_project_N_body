#pragma once
#include "Particle.h"
#include "Force.h"
#include <vector>
class set				//N_body_simulation���� set�� ǥ��
{
public:
	std::vector<particle*> particle_set; //particle�� list�� �����Ѵ�
	double force_x = 0;					 //set�� ����Ǵ� ��ü x���� ��
	double force_y = 0;				 	 //set�� ����Ǵ� ��ü y���� ��
	std::string set_name;			 	 //set �̸�

	set(std::string name);
	void Print_Set();					//set�� ������ ����Ѵ�
	void add_particle(particle* A);		//set�� particle list�� particle A�� �ִ´�.
	void add_force(force* A);			//set�� force�� force* A�� ���� ���Ѵ�
	void delete_particle(particle* A);		//Ư�� particle�� set���� �����Ѵ�.
};