#include "Particle.h"
particle::particle(std::string name, double mass, double x, double y, double v_x, double v_y)
{
	particle_name = name; //particle_name 초기화
	this->mass = mass;	//mass 초기화
	location[0] = x;	//x위치 초기화
	location[1] = y;	//y위치 초기화
	velocity[0] = v_x;	//x속도 초기화
	velocity[1] = v_y;	//y속도 초기화
}

void particle::Print_particle()
{
	std::cout << "Particle: " << particle_name << std::endl;
	std::cout << "	Location: (" << location[0] << ", " << location[1] << ")" << std::endl;
	std::cout << "	Velocity: (" << velocity[0] << ", " << velocity[1] << ")" << std::endl;
}
