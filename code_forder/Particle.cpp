#include "Particle.h"
particle::particle(std::string name, double mass, double x, double y, double v_x, double v_y)
{
	particle_name = name; //particle_name initialization
	this->mass = mass;	//mass initialization
	location[0] = x;	//x location initialization
	location[1] = y;	//y location initialization
	velocity[0] = v_x;	//x velocity initialization
	velocity[1] = v_y;	//y velocity initialization
}

void particle::Print_particle()
{
	std::cout << "Particle: " << particle_name << std::endl;
	std::cout << "	Location: (" << location[0] << ", " << location[1] << ")" << std::endl;
	std::cout << "	Velocity: (" << velocity[0] << ", " << velocity[1] << ")" << std::endl;
}
