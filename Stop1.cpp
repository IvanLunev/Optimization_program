#include "stdafx.h"
#include <iostream>
#include <Eigen/Dense>
#include "Stop1.h"
#include <string>

using namespace Eigen;
using namespace std;

/*!  оструктор. «адает число учпешных итераций и максимальное число итераций. */
Stop1::Stop1(int max, int suc) {
	suc_iter_num = suc;
	max_iter = max;
}
/*!  ¬озвращает FALSE, если выполнено условие остановки. (превышено число успешных итераций или максимальное число итераций)*/
bool Stop1::StopCriterion(Function * FUN, VectorXd& V, int iter, int suc_iter) const{
	return(suc_iter < suc_iter_num && iter < max_iter);
}