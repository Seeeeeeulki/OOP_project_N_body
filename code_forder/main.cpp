#include "main.h"
#include <iostream>
#include <string>
#include <sstream>		//stringsteam을 사용하기 위해 선언
#include <iterator>		//istream_iterator을 사용하기 위해 선언


void run_simulation_ru(int duration)
{
}

void run_simulation_rv(int duration)
{
}

int main(void)
{
	utility utility; //메모리를 관리할 클래스 변수
	std::string complete_command; //명령어를 저장하는 변수


	while (1) //pp받을 때까지 반복한다
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, complete_command);				//한 줄을 통째로 입력받는다
		std::stringstream stringstream(complete_command);		//sring형을 srtingstream class에 넣는다
		std::vector<std::string> command((std::istream_iterator<std::string>(stringstream)), std::istream_iterator<std::string>());	//스페이스바를 기준으로 split한다
		//split된 입력값은 차례대로 command vector에 쌓이게 된다

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
			std::cout << "ru입력됨" << std::endl;
		}

		else if (command[0] == "rv") //rv <duration>: run the simulation for <duration> seconds and print out the location of each particle (x and y coordinates) at each tick
		{
			std::cout << "rv입력됨" << std::endl;
		}

		else if (command[0] == "qq") //stop the simulation
		{
			break;
		}

		else  //해당하는 명령어가 없을 때
		{
			std::cout << "잘못된 명령어를 입력하였습니다." << std::endl;
		}
	}

	std::cout <<"Done(프로그램을 종료합니다)" << std::endl;

	return 0;
}