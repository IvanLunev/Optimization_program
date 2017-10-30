#pragma once

#include <Eigen/Dense>

using namespace Eigen;
using namespace std;



class Function
	/*!
	����� Function: ����������� �����. ����� ��� ����������, ������ �� ������� ������������� ���������� �������.
	*/
{
public:


	int dim;

	/*!  ���������� �������� ������� � ����� v.*/
	virtual double fun_value(VectorXd& v)const = 0;
	/*!  ���������� �������� �������� � ����� v.*/
	virtual MatrixXd Hessian(VectorXd& v) const = 0;
	/*!  ���������� �������� ��������� � ����� v.*/
	virtual VectorXd Gradient(VectorXd& v) const = 0;

	/*!  ���������� ������, � ������� �������� �������.*/
	virtual string func_name() const = 0;

};


