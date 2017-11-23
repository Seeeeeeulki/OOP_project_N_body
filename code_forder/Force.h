#pragma once
#include <string>
#include <iostream>
class force		//simulation에서 힘을 나타내는 클래스
{
private:
	double x;	//x방향 힘
	double y;	//y방향 힘

public:
	std::string force_name;//force의 이름을 나타낸다
	std::string set_force; //force가 적용되는 set

	force(std::string force_name, std::string set_force, double x, double y); //force 초기화 함수
	void print_force();		//force의 정보를 출력한다
	void set_force_x(double force_x) 
	{
		x = force_x;
	}
	void set_force_y(double force_y)
	{
		y = force_y;
	}
	double get_force_x()	//x방향의 힘을 반환한다.
	{
		return x;
	}
	double get_force_y()	//y방향의 힘을 반환한다.
	{
		return y;
	}
};
