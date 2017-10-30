#pragma once

#include <Eigen/Dense>

using namespace Eigen;
using namespace std;



class Function
	/*!
	Класс Function: абстрактный класс. Имеет три наследника, каждый из которых соответствует конкретной функции.
	*/
{
public:


	int dim;

	/*!  Возвращает значение функции в точке v.*/
	virtual double fun_value(VectorXd& v)const = 0;
	/*!  Возвращает значение гессиана в точке v.*/
	virtual MatrixXd Hessian(VectorXd& v) const = 0;
	/*!  Возвращает значение градиента в точке v.*/
	virtual VectorXd Gradient(VectorXd& v) const = 0;

	/*!  Возвращает строку, в которой записана функция.*/
	virtual string func_name() const = 0;

};


