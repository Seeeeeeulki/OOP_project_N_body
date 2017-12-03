#pragma once
#include "Particle.h"
#include "Force.h"
#include <vector>
class set				//class 'set' of N_body_simulation
{
public:
	std::vector<particle*> particle_set; //save list of particle
	std::vector<force*> force_set;		 //save force applied on set

	double force_x = 0;					 //entire x-direction force applied on set
	double force_y = 0;				 	 //entire y-direction force applied on set
	std::string set_name;			 	 //set name

	set(std::string name);
	void Print_Set();					//print set's information
	void add_particle(particle* A);		//add particle A in particle list of set
	void add_force(force* A);			//add force A in force of set
	void delete_particle(particle* A);		//delete certain particle in set
	void delete_force(force* A);
};
