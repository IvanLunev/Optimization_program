#pragma once

#include "Stop.h"

using namespace Eigen;
using namespace std;


class Stop1 :public Stop
	/*!��������� ������ Stop - �������� ��������� �� ����� �������� �������� ��� �� max ���-�� ��������.*/
{
protected:

	/*!  ����� �������� ��������.*/
	int suc_iter_num;
	/*!  ������������ ����� ��������.*/
	int max_iter;

public:

	/*! ����������. ������ ����� �������� �������� � ������������ ����� ��������. */
	Stop1(int max,int suc);
	/*!  ���������� FALSE, ���� ��������� ������� ���������.*/
	bool StopCriterion(Function * FUN, VectorXd& V, int iter, int suc_iter) const override;
};

