#include "main.h"
#include <sstream>		//stringsteam을 사용하기 위해 선언
#include <iterator>		//istream_iterator을 사용하기 위해 선언


int main(void)
{
	utility utility; //메모리를 관리할 클래스 변수
	std::string complete_command; //명령어를 저장하는 변수


	while (1) //pp받을 때까지 반복한다
	{
		std::cout << std::endl; //한 줄 띄우고 시작
		std::cout << "Enter a command: ";
		std::getline(std::cin, complete_command);				//한 줄을 통째로 입력받는다
		std::stringstream stringstream(complete_command);		//sring형을 srtingstream class에 넣는다
		std::vector<std::string> command((std::istream_iterator<std::string>(stringstream)), std::istream_iterator<std::string>());	//스페이스바를 기준으로 split한다
		//split된 입력값은 차례대로 command vector에 쌓이게 된다

		if (command[0] == "pa") //pa: print information about all the particles
		{
			if (utility.all_particle.size() == 0)
			{
				std::cout << "No particles" << std::endl;
			}
			for (int i = 0; i < utility.all_particle.size(); i++)
			{
				utility.all_particle[i]->Print_particle();
			}
		}

		else if (command[0] == "pp") //pp <particle>: print information of particle <particle>
		{
			if (find_particle(utility, command[1])->particle_name == "no_particle")
			{
				std::cout << "해당하는 particle이 없습니다." << std::endl;
			}
			else
			{
				find_particle(utility, command[1])->Print_particle();
			}
		}

		else if (command[0] == "ps") //ps <set>: print information of set <set>
		{
			if (find_set(utility, command[1])->set_name == "no_set")
			{
				std::cout << "해당하는 set이 없습니다." << std::endl;
			}
			else
			{
				std::cout << "--- Set " << find_set(utility, command[1])->set_name << " ---" << std::endl;
				find_set(utility, command[1])->Print_Set();
			}
		}

		else if (command[0] == "pf") //pf: print information of forces
		{
			if (find_force(utility, command[1])->force_name == "no_force")
			{
				std::cout << "해당하는 force가 없습니다." << std::endl;
			}
			else
			{
				find_force(utility, command[1])->print_force();
			}
		}

		else if (command[0] == "pt") //pt: print the current time (in seconds)
		{
			std::cout << "Current time is " << time << std::endl;
		}

		else if (command[0] == "pm") //pm: print memory usage, i.e., the number of particles, sets and forces
		{
			utility.print_usage();
		}

		else if (command[0] == "pg") //pg: print whether gravity is enabled
		{
			if (utility.enable_gravity == false)
			{
				std::cout << "Gravity is inactive now" << std::endl;
			}
			else
			{
				std::cout << "Gravity is avitve now" << std::endl;
			}
		}

		else if (command[0] == "ap") //ap <particle> <mass> <x> <y> <v_x> <v_y>: Add a particle <particle> with given mass and initial x, y 
									//location and x, y speed, i.e., initial location is given as a vector (<x>, <y>) and initial velocity 
									//is given as a vector (<v_x>, <v_y>)
		{
			utility.all_particle.push_back(new particle{command[1], std::stod(command[2]), std::stod(command[3]), std::stod(command[4]), std::stod(command[5]), std::stod(command[6]) });
			//particle을 new로 선언하고 주소를 all_particle vector변수에 차례대로 쌓는다
			std::cout << "particle " << utility.all_particle[utility.all_particle.size()-1]->particle_name << " added" << std::endl;
		}

		else if (command[0] == "as") //as <set>: add a set <set>
		{
			utility.all_set.push_back(new set(command[1]));
			//set을 new로 선언하고 주소를 all_set vector변수에 차례대로 쌓는다
			std::cout << "Set " << utility.all_set[utility.all_set.size() - 1]->set_name << " added" << std::endl;
		}

		else if (command[0] == "ae") //ae <set> <particle>: add a particle <particle> to a set <set>
		{
			if (find_particle(utility, command[2])->particle_name == "no_particle")
			{
				std::cout << "해당하는 particle이 없습니다." << std::endl;
			}
			else if (find_set(utility, command[1])->set_name == "no_set")
			{
				std::cout << "해당하는 set이 없습니다." << std::endl;
			}
			else
			{
				find_set(utility, command[1])->add_particle(find_particle(utility, command[2]));
			}
		}

		else if (command[0] == "af") //af <force> <set> <x> <y>: add a force <force>, which is imposed on the particles in set <set> whose size is given as a vector (<x>, <y>)
		{
			if (find_set(utility, command[2])->set_name == "no_set")
			{
				std::cout << "해당하는 set이 없습니다." << std::endl;
			}
			else
			{
				utility.all_force.push_back(new force(command[1], command[2], std::stod(command[3]), std::stod(command[4])));
				find_set(utility, command[2])->add_force(find_force(utility, command[1]));
			}
		}

		else if (command[0] == "dp") //dp <particle>: delete particle <particle>
		{
			//utility.all_particle에서 erase
			//미리 복사해둔 주소를 delete
			if (find_particle(utility, command[1])->particle_name == "no_particle")
			{
				std::cout << "해당하는 particle이 없습니다." << std::endl;
			}
			else
			{
				particle* erase = find_particle(utility, command[1]);
				utility.delete_particle(find_particle(utility, command[1])); //vector에서 지운다
				std::cout<<"Particle " << erase->particle_name << " deleted" << std::endl;
				delete erase; //동적할당을 헤재한다
			}
		}

		else if (command[0] == "de") //de <set> <particle>: delete particle <particle> from set <set>. Note that this does not delete particle, but remove a particle from a set
		{
			if (find_set(utility, command[1])->set_name == "no_set")
			{
				std::cout << "해당하는 set이 없습니다." << std::endl;
			}
			else if (find_particle(utility, command[2])->particle_name == "no_particle")
			{
				std::cout << "해당하는 particle이 없습니다." << std::endl;
			}
			else
			{
				find_set(utility, command[1])->delete_particle(find_particle(utility, command[2]));
				std::cout << "Particle " << find_particle(utility, command[2])->particle_name << " deleted form set " << find_set(utility, command[1])->set_name << std::endl;
			}
		}

		else if (command[0] == "df") //df <force>: delete force <force>
		{
			//utility.all_force에서 erase
			//미리 복사해둔 주소를 delete
			if (find_force(utility, command[1])->force_name == "no_force")
			{
				std::cout << "해당하는 force가 없습니다." << std::endl;
			}
			else
			{

				////구현 해야함
				force* erase = find_force(utility, command[1]);
				utility.delete_force(find_force(utility, command[1]));					//vector에서 지운다
				std::cout << "Force " << erase->force_name << " deleted" << std::endl;
				delete erase; //동적할당을 헤재한다
			}
		}

		else if (command[0] == "da") //da: delete all particles, sets and forces
		{
			utility.delete_all();
		}

		else if (command[0] == "ct") //ct <tick>: change timetick (in seconds)
		{
			utility.timetick = std::stoi(command[1]);
			std::cout << "timetick set: " << utility.timetick << std::endl;
		}

		else if (command[0] == "cg") //cg <bool>: enable gravity if <bool> is "true", and disable gravity if <bool> is "false"
		{
			if (command[1] == "true")
			{
				utility.enable_gravity = true;
				std::cout << "Gravity enabled" << std::endl;
			}
			else if(command[1] == "false")
			{
				utility.enable_gravity = false;
				std::cout << "Gravity disabled" << std::endl;
			}
			else
			{
				std::cout << "잘못된 명령어 입니다" << std::endl;
			}
		}

		else if (command[0] == "cp") //cp <particle> <bool>: fix or unfix the location of particle <particle>, depending on <bool>
		{
			if (command[2] == "true")
			{
				find_particle(utility, command[1])->fixed = true;
				std::cout << "Particle " << find_particle(utility, command[1])->particle_name << " is set to fixed" << std::endl;
			}
			else if (command[2] == "false")
			{
				find_particle(utility, command[1])->fixed = false;
				std::cout << "Particle " << find_particle(utility, command[1])->particle_name << " is set to movavle" << std::endl;
			}
			else
			{
				std::cout << "잘못된 명령어 입니다" << std::endl;
			}
		}

		else if (command[0] == "ru") //ru <duration>: run the simulation for <duration> seconds
		{
			std::cout << "ru입력됨" << std::endl;
			double duration = atof(command[1].c_str());
			std::cout << duration << std::endl;
			run_simulation_ru(utility, duration);
			std::cout << "simulation started" << std::endl;
		}

		else if (command[0] == "rv") //rv <duration>: run the simulation for <duration> seconds and print out the location of each particle (x and y coordinates) at each tick
		{
			std::cout << "rv입력됨" << std::endl;
		}

		else if (command[0] == "qq") //stop the simulation
		{
			utility.delete_all();
			utility.print_usage();
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