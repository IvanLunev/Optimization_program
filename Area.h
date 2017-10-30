#pragma once

#include <Eigen/Dense>

using namespace Eigen;
using namespace std;



class Area
	/*! ����� Area: ����������� �����. ����� ����������: ������������� �������.*/
{
public:

	/*! ���������� ��������� ������ � ������.*/
	virtual VectorXd rand_vec() const=0;

	/*! ���������� ��������� ������ � ������ � ������� v � "��������" �� ����������� ���������� ��������� ������� V �� ������� �������.*/
	virtual VectorXd rand_vec(VectorXd& V) const = 0;


};


