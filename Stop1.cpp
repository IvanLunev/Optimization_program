#include "stdafx.h"
#include <iostream>
#include <Eigen/Dense>
#include "Stop1.h"
#include <string>

using namespace Eigen;
using namespace std;

/*! ����������. ������ ����� �������� �������� � ������������ ����� ��������. */
Stop1::Stop1(int max, int suc) {
	suc_iter_num = suc;
	max_iter = max;
}
/*!  ���������� FALSE, ���� ��������� ������� ���������. (��������� ����� �������� �������� ��� ������������ ����� ��������)*/
bool Stop1::StopCriterion(Function * FUN, VectorXd& V, int iter, int suc_iter) const{
	return(suc_iter < suc_iter_num && iter < max_iter);
}