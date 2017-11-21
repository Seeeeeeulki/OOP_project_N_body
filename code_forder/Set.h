#pragma once
#include "Particle.h"
#include "Force.h"
#include <vector>
class set:public particle				//N_body_simulation���� particle�� ǥ��
{
private:
	std::vector<particle> particle_set; //particle�� list�� �����Ѵ�
	double force_x;						//set�� ����Ǵ� ��ü x���� ��
	double force_y;						//set�� ����Ǵ� ��ü y���� ��
public:
	void Print_Set();					//set�� ������ ����Ѵ�
	void add_particle(particle A);		//set�� particle list�� particle A�� �ִ´�.
	void add_force(force A);			//set�� force�� force A�� ���� ���Ѵ�
	void delete_particle(int A);		//Ư�� particle�� set���� �����Ѵ�.
};