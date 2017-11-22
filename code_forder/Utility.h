#pragma once
#include "Set.h"
class utility
{
public:
	std::vector<particle*> all_particle;//��� particle�� �����Ѵ�
	std::vector<set*> all_set;			//��� set�� �����Ѵ�
	std::vector<force*> all_force;		//��� force�� �����Ѵ�
	bool enable_gravity = true;			//gravity ��� ���θ� �����ϴ� ����
	double time=0;						//current time�� �ǹ��ϴ� ����

	void print_usage();				//memory ��뷮 ���
	void delete_particle();			//particle�� �޸𸮿��� ����
	void delete_force();			//force�� �޸𸮿��� ����
	void delete_all();				//�޷θ� �ʱ�ȭ
};