
#include "stdafx.h"
#include <iostream>
#include <Eigen/Dense>
#include "Rectangular_Area.h"
#include <string>
#include <ctime>

using namespace Eigen;
using namespace std;



/*! �����������. ������ V0 � delta0.*/
Rectangular_Area::Rectangular_Area(VectorXd V0, VectorXd delta0) :V0(V0), delta0(delta0) {}

/*! ���������� true, ���� ������ � ������.*/
bool Rectangular_Area::In(VectorXd& V) const {
	VectorXd Vec = (V - V0).array() / delta0.array();
	return (Vec.lpNorm<Infinity>()<1); // �������� ������ ��������� < 1
};


/*! ���������� ��������� ������ � ������.*/
VectorXd Rectangular_Area::rand_vec() const {

//	srand(time(0));
//	rand();

	int dim = V0.rows();
	VectorXd V(dim);
	VectorXd rand_vec(dim);

	for (int i = 0; i < dim; ++i) {
		rand_vec(i) = 2*((double)rand()) / RAND_MAX-1;
	}

    V =V0.array() + rand_vec.array()*delta0.array() ;

	return V;


}

/*! ���������� ��������� ������ � ������ � ������� v � "��������" �� ����������� ���������� ��������� ������� V �� ������� �������.*/
VectorXd Rectangular_Area::rand_vec(VectorXd& V) const {

//	srand(time(0));
//	rand();

	double epsilon = min(min(((V - (V0 - delta0)).cwiseAbs()).minCoeff(), (((V0 + delta0) - V).cwiseAbs()).minCoeff()), (delta0).maxCoeff() / 50);


	int dim = V0.rows();

	VectorXd V_n(dim);
	VectorXd rand_vec(dim);

	for (int i = 0; i < dim; ++i) {
		rand_vec(i) = 2 * ((double)rand()) / RAND_MAX - 1;
	}

	V_n = V.array() + rand_vec.array()*epsilon;

	return V_n;
}




