#pragma once

#include "Function.h"


using namespace Eigen;
using namespace std;


class FUN1 :public Function
	/*!Наследник класса Function - функция x^3+3xy^2-15x-12y.*/
{
public:
	/*! Возвращает значение функции в точке v.*/
	double fun_value(VectorXd & v) const override;
	/*! Возвращает значение гессиана в точке v.*/
	MatrixXd Hessian(VectorXd& v) const override;
	/*! Возвращает значение градиента в точке v.*/
	VectorXd Gradient(VectorXd& v) const override;

	/*! Конструктор. Задает размерность.*/
	FUN1();
	/*! Возвращает строку с функцией.*/
	string func_name() const override;
};

