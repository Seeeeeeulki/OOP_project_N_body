#pragma once
#include <iostream>
#include <String>

class particle			//class of 'particle' in N_body_simulation
{
public:
	double location[2]; 	//particle's location [x,y]
	double velocity[2]; 	//particle's velocity [x,y]
	double mass;			//particle's mass
	bool fixed = false;			//boolean value that determine particle's movement, initial value is false
	std::string particle_name;	//particle's name


	particle(std::string name, double mass, double x, double y, double v_x, double v_y); //particle class value initialize
	void Print_particle(); //print particle object's information
};
