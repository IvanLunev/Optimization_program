#include "stdafx.h"
#include <iostream>
#include <Eigen/Dense>
#include "Stop2.h"
#include <string>

using namespace Eigen;
using namespace std;

/*! ����������. ������ ����� �������� �������� � ������������ ����� ��������. */
Stop2::Stop2(int max, double eps_n) {
	eps = eps_n;
	max_iter = max;
}
/*!  ���������� FALSE, ���� ��������� ������� ���������. (��������� ����� ��������� ��� ������������ ����� ��������)*/
bool Stop2::StopCriterion(Function * FUN, VectorXd& V, int iter, int suc_iter) const {
	return(((FUN->Gradient(V)).norm() > eps) && (iter < max_iter));
}