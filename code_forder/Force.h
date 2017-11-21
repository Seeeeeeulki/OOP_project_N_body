#pragma once

class force		//simulation에서 힘을 나타내는 클래스
{
private:
	double x;	//x방향 힘
	double y;	//y방향 힘

public:
	void print_force();		//force의 정보를 출력한다
	double get_force_x();	//x방향의 힘을 반환한다.
	double get_force_y();	//y방향의 힘을 반환한다.
};
