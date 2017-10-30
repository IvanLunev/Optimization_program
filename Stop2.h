#pragma once

#include "Stop.h"

using namespace Eigen;
using namespace std;


class Stop2 :public Stop
	/*!��������� ������ Stop - �������� ��������� �� ����� �������� �������� ��� �� max ���-�� ��������.*/
{
protected:

	
	/*!  ������������ ����� ��������.*/
	int max_iter;
	/*!  ����� �������� ��������.*/
	double eps;

public:


	/*! ����������. ������ ����� �������� �������� � ������������ ����� ��������. */
	Stop2(int max, double eps);
	/*!  ���������� FALSE, ���� ��������� ������� ���������.*/
	bool StopCriterion(Function * FUN, VectorXd& V, int iter, int suc_iter) const override;
};
