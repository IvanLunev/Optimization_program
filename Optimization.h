#pragma once

#include <Eigen/Dense>
#include "Area.h"
#include "Stop.h"
#include "Function.h"

using namespace Eigen;
using namespace std;



class Optimization
	/*!
	����� Optimization. ����� ��� ������ �����������: ��������� ����� � ����� �������.
	*/
{
protected:
	/*! ������� �����������.*/
	Area * Ar;
	/*! ������� �����������.*/
	Function * Fun;
	/*! �������� ��������� �����������.*/
	Stop * St;


public:

	/*!  ����� �������� ��������.*/
	int suc_it;

	/*!  ����� ��������.*/
	int it;

	/*!  ����������. ������ Ar, Fun, St.*/
	Optimization(Area* Ar0, Function* Fun0, Stop* St0);

	/*!  ���������� ��������� ����������� ��������� �������(V-��������� ������, p - ��������).*/
	VectorXd random_search(VectorXd V, double p);
	/*!  ���������� ��������� ����������� ������� ������� (V-��������� ������).*/
	VectorXd newton_optimization(VectorXd V);

};


