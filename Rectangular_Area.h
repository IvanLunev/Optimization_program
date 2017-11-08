#pragma once

#include <Eigen/Dense>
#include "Area.h"

using namespace Eigen;
using namespace std;



class Rectangular_Area :public Area
	/*! Наследник Area. Прямоугольная область.*/
{
protected:
	/*! Центр области*/
	VectorXd V0;
	/*! Параметр "растягивания".*/
	VectorXd delta0;

public:

	/*! Конструктор. Задает V0 и delta0.*/
	Rectangular_Area(VectorXd V0, VectorXd delta0);
	/*! Возвращает случайный вектор в оласти.*/
	VectorXd rand_vec() const override;
	/*! Возвращает true, если вектор в оласти.*/
	 bool In(VectorXd& V) const override;
	/*! Возвращает случайный вектор в оласти с центром v и "раздутую" на минимальное расстояние координат вектора V до границы области.*/
	VectorXd rand_vec(VectorXd& V) const override;
};
