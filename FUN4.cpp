#include "stdafx.h"
#include <iostream>
#include <Eigen/Dense>
#include "FUN4.h"
#include <string>

using namespace Eigen;
using namespace std;


double FUN4::fun_value(VectorXd& v)const {
	double k;
	k = v(0)*v(0)+v(1)*v(1)*2+v(0)*v(0)*v(1)*v(1)+v(2)*v(2)+exp(v(1)*v(1)+v(2)*v(2))-v(1)+v(2);
	return k;
}



MatrixXd FUN4::Hessian(VectorXd& v)const {
	MatrixXd k(dim, dim);
	k << 2+2*v(1)*v(1), 4*v(0)*v(1), 0,
		4*v(0)*v(1), 4+2*v(0)*v(0)+2* exp(v(1)*v(1) + v(2)*v(2))+4*v(1)*v(1)*exp(v(1)*v(1) + v(2)*v(2)),4*v(1)*v(2)*exp(v(1)*v(1) + v(2)*v(2)),
		0, 4*v(1)*v(2)*exp(v(1)*v(1) + v(2)*v(2)), 2* exp(v(1)*v(1) + v(2)*v(2))+4*v(2)*v(2)*exp(v(1)*v(1) + v(2)*v(2))+2;
	return k;
}


VectorXd FUN4::Gradient(VectorXd& v)const {
	VectorXd k(dim);
	k << 2*v(0)+2*v(0)*v(1)*v(1), 4*v(1)+2*v(0)*v(0)*v(1)+2*v(1)*exp(v(1)*v(1)+v(2)*v(2))-1, 2*v(2)+2*v(2)*exp(v(1)*v(1)+v(2)*v(2))+1;
	return k;
}


FUN4::FUN4() {
	dim = 3;
}


string FUN4::func_name() const {
	return std::string("x^2+2y^2+x^2y^2+z^2+exp(y^2+z^2)-y+z");
}

