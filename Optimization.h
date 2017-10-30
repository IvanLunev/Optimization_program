#pragma once

#include <Eigen/Dense>
#include "Area.h"
#include "Stop.h"
#include "Function.h"

using namespace Eigen;
using namespace std;



class Optimization
	/*!
	Класс Optimization. Имеет два метода оптимизации: случайный поиск и метод Ньютона.
	*/
{
protected:
	/*! Область оптимизации.*/
	Area * Ar;
	/*! Функция оптимизации.*/
	Function * Fun;
	/*! Критерий остановки оптимизации.*/
	Stop * St;


public:

	/*!  Число успешных итераций.*/
	int suc_it;

	/*!  Число итераций.*/
	int it;

	/*!  Коструктор. Задает Ar, Fun, St.*/
	Optimization(Area* Ar0, Function* Fun0, Stop* St0);

	/*!  Возвращает результат оптимизации случайным поиском(V-начальный вектор, p - параметр).*/
	VectorXd random_search(VectorXd V, double p);
	/*!  Возвращает результат оптимизации методом Ньютона (V-начальный вектор).*/
	VectorXd newton_optimization(VectorXd V);

};


