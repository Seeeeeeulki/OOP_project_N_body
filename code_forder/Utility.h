#pragma once
#include "Set.h"
class utility
{
public:
	std::vector<particle*> all_particle;//save all particle
	std::vector<set*> all_set;			//save all set
	std::vector<force*> all_force;		//save all force

	bool enable_gravity = true;			//variable that determine about gravity functional
	int timetick = 5;					//variable meaning timetick

	void print_usage();				//print memory usage
	void delete_particle(particle* A);			//delete particle from memory
	void delete_force(force* A);			//delete force from memory
	void delete_all();				//memory initialize
};
