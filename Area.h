#pragma once

#include <Eigen/Dense>

using namespace Eigen;
using namespace std;



class Area
	/*!  ласс Area: абстрактный класс. »меет наследника: пр€моугольна€ область.*/
{
public:

	/*! ¬озвращает случайный вектор в оласти.*/
	virtual VectorXd rand_vec() const=0;

	/*! ¬озвращает случайный вектор в оласти с центром v и "раздутую" на минимальное рассто€ние координат вектора V до границы области.*/
	virtual VectorXd rand_vec(VectorXd& V) const = 0;


};


