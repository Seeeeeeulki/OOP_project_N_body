#include "Particle.h"
particle::particle(std::string name, double mass, double x, double y, double v_x, double v_y)
{
	particle_name = name; //particle_name �ʱ�ȭ
	this->mass = mass;	//mass �ʱ�ȭ
	location[0] = x;	//x��ġ �ʱ�ȭ
	location[1] = y;	//y��ġ �ʱ�ȭ
	velocity[0] = v_x;	//x�ӵ� �ʱ�ȭ
	velocity[1] = v_y;	//y�ӵ� �ʱ�ȭ
}

void particle::Print_particle()
{
	std::cout << "Particle: " << particle_name << std::endl;
	std::cout << "	Location: (" << location[0] << ", " << location[1] << ")" << std::endl;
	std::cout << "	Velocity: (" << velocity[0] << ", " << velocity[1] << ")" << std::endl;
}
