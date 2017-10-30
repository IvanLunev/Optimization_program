// Optimization_program.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Eigen/Dense>
#include <iostream>
#include "FUN1.h"
#include "FUN2.h"
#include "FUN3.h"
#include "Stop1.h"
#include "Stop2.h"
#include "Area1.h"
#include <ctime>
#include "Optimization.h"

using namespace Eigen;

int main()
{

	cout << "Choose your method: \n" << "1 - Newton \n" << "2 - random search \n" << endl;

	int method;

	cin >> method;

	cout << "\n Choose your function: \n" << "1 - x^3+3xy^2-15x-12y \n" << "2 - 100(y-x)^2+(1-x)^2 \n" << "3 - 100(y-x^3)^2+(1-x)^2 \n" << endl;

	int choose;

	cin >> choose;

	

	VectorXd V(2);


	cout << "\n Initial vector: \n" << endl;

	double * Vec = new double[2];

	for (int i = 0; i<2; ++i)
		cin >> Vec[i];

	for (int i = 0; i<2; ++i)
		V(i) = Vec[i];




	Function * FF;
	switch (choose)
	{
	case 1: {
		FF = new FUN1();
		break;
	}
	case 2: {
		FF = new FUN2();
		break;
	}
	case 3: {
		FF = new FUN3();
		break;
	}
	}

	cout << "\n Choose stop criterion: \n" << "1 - Number od success iteration < max_suc and number of iteration < max \n" << "2 - Gradient < eps and number of iteration < max \n" << endl;

	int stop_ch;

	cin >> stop_ch;


	Stop * St;
	switch (stop_ch)
	{
	case 1: {
		cout << "\n Number of uccessful iteration: \n" << endl;
		int suc_iter_num;
		cin >> suc_iter_num;

		cout << "\n Max iteration: \n" << endl;
		int max_iter;
		cin >> max_iter;

		St = new Stop1(max_iter,suc_iter_num);
		break;
	}
	case 2: {
		cout << "\n Accuracy: \n" << endl;
		double eps;
		cin >> eps;

		cout << "\n Max iteration: \n" << endl;
		int max_iter;
		cin >> max_iter;


		St = new Stop2(max_iter,eps);
		break;
	}
}

	Area * Ar;

	cout << "\n Enter center of Area (rectangular area) \n" << endl;

	VectorXd V0(2);



	for (int i = 0; i<2; ++i)
		cin >> Vec[i];

	for (int i = 0; i<2; ++i)
		V0(i) = Vec[i];


	cout << "\n Enter scale of area \n" << endl;

	VectorXd delta(2);


	for (int i = 0; i<2; ++i)
		cin >> Vec[i];

	for (int i = 0; i<2; ++i)
		delta(i) = Vec[i];



	Ar = new Area1(V0,delta);

	Optimization Op(Ar,FF,St);

	switch (method)
	{
	case 1: {

		std::cout << "\n Function: \n" << FF->func_name() << "\n\n" << "Min point: \n" << Op.newton_optimization(V) << std::endl;

		break;
	}
	case 2: {

		cout << "\n Parameter of random search: \n" << endl;
		double p;
		cin >> p;


		std::cout << "\n Function: \n" << FF->func_name() << "\n\n" << "Min point: \n" << Op.random_search(V,p) << std::endl;

		break;
	}
}


	delete Vec;

	delete FF;
	delete St;
	delete Ar;

	system("pause");
    return 0;
}

