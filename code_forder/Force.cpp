#include "Force.h"

force::force(std::string force_name, std::string set_force, double x, double y)
{
	this->force_name = force_name;
	this->set_force = set_force;
	this->x = x;
	this->y = y;
}

void force::print_force()
{
	std::cout << "Force " << force_name << " applied to set " << set_force << ": (" << x << ", " << y << ")" << std::endl;
}
