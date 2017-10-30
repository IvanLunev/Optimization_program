#pragma once

#include "Function.h"


using namespace Eigen;
using namespace std;


class FUN1 :public Function
	/*!��������� ������ Function - ������� x^3+3xy^2-15x-12y.*/
{
public:
	/*! ���������� �������� ������� � ����� v.*/
	double fun_value(VectorXd & v) const override;
	/*! ���������� �������� �������� � ����� v.*/
	MatrixXd Hessian(VectorXd& v) const override;
	/*! ���������� �������� ��������� � ����� v.*/
	VectorXd Gradient(VectorXd& v) const override;

	/*! �����������. ������ �����������.*/
	FUN1();
	/*! ���������� ������ � ��������.*/
	string func_name() const override;
};

