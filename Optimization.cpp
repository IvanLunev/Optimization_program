#include "stdafx.h"
#include <iostream>
#include <Eigen/Dense>
#include "Area.h"
#include "Stop.h"
#include "Function.h"
#include "Optimization.h"
#include <string>
#include <ctime>

using namespace Eigen;
using namespace std;


/*!  Коструктор. Задает Ar, Fun, St.*/
Optimization::Optimization(Area* Ar0, Function* Fun0, Stop* St0) :Ar(Ar0), Fun(Fun0), St(St0) {}

/*!  Возвращает результат оптимизации случайным поиском.*/
VectorXd Optimization::random_search(VectorXd V,double p) {

	srand(time(0));
	rand();

	VectorXd V_n(Fun->dim);
	VectorXd V0(Fun->dim);

	V_n = V;
	V0 = V;


	int i = 0;
	int j = 0;
	while (St->StopCriterion(Fun, V, j, i)) {
		++j;

		double e = ((double) rand()) / RAND_MAX;

		if (e < p) {
			V_n = Ar->rand_vec();
		}
		else {
			V_n = Ar->rand_vec(V0);
		}


		if (Fun->fun_value(V0) > Fun->fun_value(V_n)) {
			V0 = V_n;

			++i;

		}
	}

	suc_it = i;
	it = j;

	return V0;
}


/*!  Возвращает результат оптимизации методом Ньютона.*/
VectorXd Optimization::newton_optimization(VectorXd V) {
	VectorXd Gr(Fun->dim);
	VectorXd Vec(Fun->dim);
	VectorXd Dir(Fun->dim);

	int i = 0;
	int j = 0;

	while (St->StopCriterion(Fun, V, j, i)) {
		
		Dir = Fun->Hessian(V).colPivHouseholderQr().solve(Fun->Gradient(V));

		Vec = V - Dir;
		while (!(Ar->In(Vec))) {
			Dir = Dir / 2;
			Vec = V - Dir;

		}
		
		
		

		VectorXd l = V, r = Vec;
		double EPS = 0.00001;

		while ((r - l).lpNorm<Infinity>() > EPS) {
			++j;
			VectorXd m1 = l + (r - l) / 3,
				m2 = r - (r - l) / 3;
			if (Fun->fun_value(m1) < Fun->fun_value(m2))
				r = m1;
			else
				l = m2;

		}
		V = l;
		++j;
		++i;

	}

	suc_it = i;
	it = j;

	return V;
}