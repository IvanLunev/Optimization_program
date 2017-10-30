#pragma once

#include "Stop.h"

using namespace Eigen;
using namespace std;


class Stop1 :public Stop
	/*!Наследник класса Stop - критерий остановки по числу успешных итераций или по max кол-ву итераций.*/
{
protected:

	/*!  Число учпешных итераций.*/
	int suc_iter_num;
	/*!  Максимальное число итераций.*/
	int max_iter;

public:

	/*! Коструктор. Задает число учпешных итераций и максимальное число итераций. */
	Stop1(int max,int suc);
	/*!  Возвращает FALSE, если выполнено условие остановки.*/
	bool StopCriterion(Function * FUN, VectorXd& V, int iter, int suc_iter) const override;
};

