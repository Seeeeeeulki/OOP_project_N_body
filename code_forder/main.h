#pragma once
#include"Utility.h"
particle* no_particle = new particle("no_particle", 0, 0, 0, 0, 0);  //return when there is no matching particle
set* no_set = new set("no_set");								//return when there is no matching set
force* no_force = new force("no_force", " ", 0, 0);		//return when there is no matching force

particle* find_particle(utility utility, std::string command) //return address of particle whose number matches to name
{
	for (int i = 0; i<utility.all_particle.size(); i++)
	{
		if (utility.all_particle[i]->particle_name == command) //print when particle_name and command's number are same
		{
			return utility.all_particle[i];
		}
	}
	return no_particle;//when there is no correct particle, return dummy particle(no_particle)
}

set* find_set(utility utility, std::string command) //return set of particle whose number matches to name
{
	for (int i = 0; i < utility.all_set.size(); i++)
	{
		if (utility.all_set[i]->set_name == command)
		{
			return utility.all_set[i];
		}
	}
	return no_set; //when there is no correct set, return dummy set(no_set)
}

force* find_force(utility utility, std::string command)
{
	for (int i = 0; i < utility.all_force.size(); i++)
	{
		if (utility.all_force[i]->force_name == command)
		{
			return utility.all_force[i];
		}
	}
	return no_force; //when there is no correct force, return dummy force(no_force)
}