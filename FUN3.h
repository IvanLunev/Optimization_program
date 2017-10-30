#pragma once

#include "Function.h"


using namespace Eigen;
using namespace std;

class FUN3 :public Function
	/*!��������� ������ Function - ������� 100(y-x^3)^2+(1-x)^2.*/
{
public:
	/*! ���������� �������� ������� � ����� v.*/
	double fun_value(VectorXd & v) const override;
	/*! ���������� �������� �������� � ����� v.*/
	MatrixXd Hessian(VectorXd& v) const override;
	/*! ���������� �������� ��������� � ����� v.*/
	VectorXd Gradient(VectorXd& v) const override;

	/*! �����������. ������ �����������.*/
	FUN3();
	/*! ���������� ������ � ��������.*/
	string func_name() const override;
};


