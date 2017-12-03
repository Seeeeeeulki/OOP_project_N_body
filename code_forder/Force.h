#pragma once
#include <string>
#include <iostream>
class force		//class that meaning 'force' in the simulation
{
private:
	double x;	//x-direction force
	double y;	//y-direction force

public:
	std::string force_name;//represent force's name
	std::string set_force; //represent set which is applied the force

	force(std::string force_name, std::string set_force, double x, double y); //force initialization
	void print_force();		//print force information
	void set_force_x(double force_x) //set x-direction force
	{
		x = force_x;
	}
	void set_force_y(double force_y) //set y-direction force
	{
		y = force_y;
	}
	double get_force_x()	//return x-diretion force
	{
		return x;
	}
	double get_force_y()	//return y-direction force
	{
		return y;
	}
};
