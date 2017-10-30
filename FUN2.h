#pragma once

#include "Function.h"


using namespace Eigen;
using namespace std;



class FUN2 :public Function
	/*!Наследник класса Function - функция 100(y-x)^2+(1-x)^2.*/
{
public:
	/*! Возвращает значение функции в точке v.*/
	double fun_value(VectorXd & v) const override;
	/*! Возвращает значение гессиана в точке v.*/
	MatrixXd Hessian(VectorXd& v) const override;
	/*! Возвращает значение градиента в точке v.*/
	VectorXd Gradient(VectorXd& v) const override;

	/*! Конструктор. Задает размерность.*/
	FUN2();
	/*! Возвращает строку с функцией.*/
	string func_name() const override;
};
