#pragma once

#include <Eigen/Dense>
#include "Function.h"

using namespace Eigen;
using namespace std;


class Stop
	/*!
	Класс Stop: абстрактный класс. Имеет два наследника, каждый из которых соответствует конкретному критерию остановки.
	*/
{
public:


	/*!  Возвращает FALSE, если выполнено условие остановки.*/
	virtual bool StopCriterion(Function * FUN, VectorXd& V, int iter, int suc_iter) const = 0;

};