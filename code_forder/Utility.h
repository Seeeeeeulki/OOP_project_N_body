#pragma once
#include "Set.h"
class utility
{
public:
	int particle_number=0;			//particle�� ���� �����Ѵ�
	int set_number=0;				//set�� ���� �����Ѵ�
	int force_number=0;				//force�� ���� �����Ѵ�
	bool enable_gravity = false;	//gravity ��� ���θ� �����ϴ� ����

	void print_usage();				//memory ��뷮 ���
	void delete_particle();			//particle�� �޸𸮿��� ����
	void delete_force();			//force�� �޸𸮿��� ����
	void delete_all();				//�޷θ� �ʱ�ȭ
};