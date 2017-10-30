#pragma once

#include <Eigen/Dense>
#include "Function.h"

using namespace Eigen;
using namespace std;


class Stop
	/*!
	����� Stop: ����������� �����. ����� ��� ����������, ������ �� ������� ������������� ����������� �������� ���������.
	*/
{
public:


	/*!  ���������� FALSE, ���� ��������� ������� ���������.*/
	virtual bool StopCriterion(Function * FUN, VectorXd& V, int iter, int suc_iter) const = 0;

};