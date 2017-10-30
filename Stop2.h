#pragma once

#include "Stop.h"

using namespace Eigen;
using namespace std;


class Stop2 :public Stop
	/*!Наследник класса Stop - критерий остановки по числу успешных итераций или по max кол-ву итераций.*/
{
protected:

	
	/*!  Максимальное число итераций.*/
	int max_iter;
	/*!  Число учпешных итераций.*/
	double eps;

public:


	/*! Коструктор. Задает число учпешных итераций и максимальное число итераций. */
	Stop2(int max, double eps);
	/*!  Возвращает FALSE, если выполнено условие остановки.*/
	bool StopCriterion(Function * FUN, VectorXd& V, int iter, int suc_iter) const override;
};
