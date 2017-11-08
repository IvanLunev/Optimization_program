#pragma once

#include <Eigen/Dense>
#include "Area.h"

using namespace Eigen;
using namespace std;



class Rectangular_Area :public Area
	/*! ��������� Area. ������������� �������.*/
{
protected:
	/*! ����� �������*/
	VectorXd V0;
	/*! �������� "������������".*/
	VectorXd delta0;

public:

	/*! �����������. ������ V0 � delta0.*/
	Rectangular_Area(VectorXd V0, VectorXd delta0);
	/*! ���������� ��������� ������ � ������.*/
	VectorXd rand_vec() const override;
	/*! ���������� true, ���� ������ � ������.*/
	 bool In(VectorXd& V) const override;
	/*! ���������� ��������� ������ � ������ � ������� v � "��������" �� ����������� ���������� ��������� ������� V �� ������� �������.*/
	VectorXd rand_vec(VectorXd& V) const override;
};
