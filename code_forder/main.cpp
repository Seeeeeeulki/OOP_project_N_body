#include "main.h"
#include <iostream>
#include <string>
#include <sstream>		//stringsteam�� ����ϱ� ���� ����
#include <iterator>		//istream_iterator�� ����ϱ� ���� ����


void run_simulation_ru(int duration)
{
}

void run_simulation_rv(int duration)
{
}

int main(void)
{
	utility utility; //�޸𸮸� ������ Ŭ���� ����
	std::string complete_command; //��ɾ �����ϴ� ����


	while (1) //pp���� ������ �ݺ��Ѵ�
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, complete_command);				//�� ���� ��°�� �Է¹޴´�
		std::stringstream stringstream(complete_command);		//sring���� srtingstream class�� �ִ´�
		std::vector<std::string> command((std::istream_iterator<std::string>(stringstream)), std::istream_iterator<std::string>());	//�����̽��ٸ� �������� split�Ѵ�
		//split�� �Է°��� ���ʴ�� command vector�� ���̰� �ȴ�

		if (command[0] == "pa") //pa: print information about all the particles
		{

		}

		else if (command[0] == "pp") //pp <particle>: print information of particle <particle>
		{

		}

		else if (command[0] == "ps") //ps <set>: print information of set <set>
		{

		}

		else if (command[0] == "pf") //pf: print information of forces
		{

		}

		else if (command[0] == "pt") //pt: print the current time (in seconds)
		{

		}

		else if (command[0] == "pm") //pm: print memory usage, i.e., the number of particles, sets and forces
		{

		}

		else if (command[0] == "pg") //pg: print whether gravity is enabled
		{

		}

		else if (command[0] == "ap") //ap <particle> <mass> <x> <y> <v_x> <v_y>: Add a particle <particle> with given mass and initial x, y 
									//location and x, y speed, i.e., initial location is given as a vector (<x>, <y>) and initial velocity 
									//is given as a vector (<v_x>, <v_y>)
		{

		}

		else if (command[0] == "as") //as <set>: add a set <set>
		{

		}

		else if (command[0] == "ae") //ae <set> <particle>: add a particle <particle> to a set <set>
		{

		}

		else if (command[0] == "af") //af <force> <set> <x> <y>: add a force <force>, which is imposed on the particles in set <set> whose size is given as a vector (<x>, <y>)
		{

		}

		else if (command[0] == "dp") //dp <particle>: delete particle <particle>
		{

		}

		else if (command[0] == "de") //de <set> <particle>: delete particle <particle> from set <set>. Note that this does not delete particle, but remove a particle from a set
		{

		}

		else if (command[0] == "df") //df <force>: delete force <force>
		{

		}

		else if (command[0] == "da") //da: delete all particles, sets and forces
		{

		}

		else if (command[0] == "ct") //ct <tick>: change timetick (in seconds)
		{

		}

		else if (command[0] == "cg") //cg <bool>: enable gravity if <bool> is "true", and disable gravity if <bool> is "false"
		{

		}

		else if (command[0] == "cp") //cp <particle> <bool>: fix or unfix the location of particle <particle>, depending on <bool>
		{

		}

		else if (command[0] == "ru") //ru <duration>: run the simulation for <duration> seconds
		{
			std::cout << "ru�Էµ�" << std::endl;
		}

		else if (command[0] == "rv") //rv <duration>: run the simulation for <duration> seconds and print out the location of each particle (x and y coordinates) at each tick
		{
			std::cout << "rv�Էµ�" << std::endl;
		}

		else if (command[0] == "qq") //stop the simulation
		{
			break;
		}

		else  //�ش��ϴ� ��ɾ ���� ��
		{
			std::cout << "�߸��� ��ɾ �Է��Ͽ����ϴ�." << std::endl;
		}
	}

	std::cout <<"Done(���α׷��� �����մϴ�)" << std::endl;

	return 0;
}