// Optimization_program.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Eigen/Dense>
#include <iostream>
#include <string>
#include "FUN1.h"
#include "FUN2.h"
#include "FUN3.h"
#include "FUN4.h"
#include "Stop1.h"
#include "Stop2.h"
#include "Rectangular_Area.h"
#include <ctime>
#include <cmath>
#include "Optimization.h"

using namespace Eigen;
using namespace std;

int main()
{

	cout << "Choose your method: \n" << "1 - Newton \n" << "2 - random search \n" << endl;

	int method;
	double method0 = 0;
	
	while (!(method0 == 1 || method0 == 2)) {
		while (std::cout << "Please , enter a number (1 or 2)\n"
			&& !(std::cin >> method0)) {
			std::cin.clear();
			std::string line;
			std::getline(std::cin, line);
			std::cout << "I am sorry , but <<" << line
				<< ">> is  not a number \n";
		}		if (!(method0 == 1 || method0 == 2)) std::cout << "This number is not 1 or 2. Try again..." << endl;		else method = method0;	}

	cout << "\n Choose your function: \n" << "1 - x^3+3xy^2-15x-12y \n" << "2 - 100(y-x)^2+(1-x)^2 \n" << "3 - 100(y-x^3)^2+(1-x)^2 \n" 
		<< "4 - x^2+2y^2+x^2y^2+z^2+exp(y^2+z^2)-y+z \n" << endl;

	int choose;

	double choose0 = 0;

	while (!(choose0 == 1 || choose0 == 2 || choose0 == 3 || choose0 == 4)) {
		while (std::cout << "Please , enter a number (1, 2, 3 or 4)\n"
			&& !(std::cin >> choose0)) {
			std::cin.clear();
			std::string line;
			std::getline(std::cin, line);
			std::cout << "I am sorry , but <<" << line
				<< ">> is  not a number \n";
		}		if (!(choose0 == 1 || choose0 == 2 || choose0 == 3 || choose0 == 4)) std::cout << "This number is not 1, 2, 3 or 4. Try again..." << endl;		else choose = choose0;	}


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
	case 4: {
		FF = new FUN4();
		break;
	}
	}

	int dim = FF->dim;

	VectorXd V(dim);


	cout << "\n Initial vector: \n" << endl;

	double * Vec = new double[dim];

	for (int i = 0; i < dim; ++i) {

		double num = 0;

			while (std::cout << "Please , enter a number\n"
				&& !(std::cin >> num)) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << "I am sorry , but <<" << line
					<< ">> is  not a number \n";		}
			Vec[i] = num;			std::cout << "V[" << i << "]=" << Vec[i] << endl;

	}
		


	for (int i = 0; i<dim; ++i)
		V(i) = Vec[i];



	cout << "\n Choose stop criterion: \n" << "1 - Number od success iteration < max_suc and number of iteration < max \n" << "2 - Gradient < eps and number of iteration < max \n" << endl;

	int stop_ch;
	double stop_ch0 = 0;


	while (!(stop_ch0 == 1 || stop_ch0 == 2)) {
		while (std::cout << "Please , enter a number (1 or 2)\n"
			&& !(std::cin >> stop_ch0)) {
			std::cin.clear();
			std::string line;
			std::getline(std::cin, line);
			std::cout << "I am sorry , but <<" << line
				<< ">> is  not a number \n";
		}		if (!(stop_ch0 == 1 || stop_ch0 == 2)) std::cout << "This number is not 1 or 2. Try again..." << endl;		else stop_ch = stop_ch0;	}


	cout << "\n Max iteration: \n" << endl;
	int max_iter;
	double max_iter0 = 0.1;

	double i=0;

	while (max_iter0 <= 0 || !(modf(max_iter0, &i) == 0)) {
		while (std::cout << "Please , enter a positive integer number\n"
			&& !(std::cin >> max_iter0)) {
			std::cin.clear();
			std::string line;
			std::getline(std::cin, line);
			std::cout << "I am sorry , but <<" << line
				<< ">> is  not a number \n";
		}		if (max_iter0 <= 0 || !(modf(max_iter0, &i) == 0)) std::cout << "This number is not positive or is not integer. Try again..." << endl;		else max_iter = max_iter0;	}





	Stop * St;

	switch (stop_ch)
	{
	case 1: {
		cout << "\n Number of uccessful iteration: \n" << endl;
		int suc_iter_num;
		double suc_iter_num0 = 0.1;

		double i = 0;

		while (suc_iter_num0 <= 0 || !(modf(suc_iter_num0, &i) == 0)) {
			while (std::cout << "Please , enter a positive integer number\n"
				&& !(std::cin >> suc_iter_num0)) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << "I am sorry , but <<" << line
					<< ">> is  not a number \n";
			}			if (suc_iter_num0 <= 0 || !(modf(suc_iter_num0, &i) == 0)) std::cout << "This number is not positive or is not integer. Try again..." << endl;			else suc_iter_num = suc_iter_num0;		}


		St = new Stop1(max_iter,suc_iter_num);
		break;
	}
	case 2: {
		cout << "\n Accuracy: \n" << endl;
		double eps;
		double num = 0;

		while (num <= 0) {
			while (std::cout << "Please , enter a positive number\n"
				&& !(std::cin >> num)) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << "I am sorry , but <<" << line
					<< ">> is  not a number \n";
			}			if (num <= 0) std::cout << "This number is not positive. Try again..." << endl;			else			{				eps = num;			}		}


		St = new Stop2(max_iter,eps);
		break;
	}
}

	Area * Ar;

	cout << "\n Enter center of Area (rectangular area) \n" << endl;

	VectorXd V0(dim);



	for (int i = 0; i < dim; ++i) {


		double num = 0;

	
			while (std::cout << "Please , enter a positive number\n"
				&& !(std::cin >> num)) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << "I am sorry , but <<" << line
					<< ">> is  not a number \n";
		}
			Vec[i] = num;			std::cout << "V[" << i << "]=" << Vec[i] << endl;

	}


	for (int i = 0; i<dim; ++i)
		V0(i) = Vec[i];


	cout << "\n Enter scale of area \n" << endl;

	VectorXd delta(dim);



	for (int i = 0; i < dim; ++i) {


		double num = 0;

		while (num <= 0) {
			while (std::cout << "Please , enter a positive number\n"
				&& !(std::cin >> num)) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << "I am sorry , but <<" << line
					<< ">> is  not a number \n";
			}			if (num <= 0) std::cout << "This number is not positive. Try again..." << endl;			else			{				Vec[i] = num;				std::cout << "V[" << i << "]=" << Vec[i] << endl;			}		}

	}


	for (int i = 0; i<dim; ++i)
		delta(i) = Vec[i];



	Ar = new Rectangular_Area(V0,delta);

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
		double num = 0;

		while (num <= 0 || num>=1) {
			while (std::cout << "Please , enter a number from (0;1)\n"
				&& !(std::cin >> num)) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << "I am sorry , but <<" << line
					<< ">> is  not a number \n";
			}			if (num <= 0 | num >= 1) std::cout << "This number is not from (0;1). Try again..." << endl;			else			{				p = num;			}		}

		VectorXd Min = Op.random_search(V, p);

		std::cout << "\n Function: \n" << FF->func_name() << "\n Initial vector: \n" << V << "\n Center of area: \n" << V0
			<< "\n Scale of area: \n" <<delta << "\n\n" << "Min point: \n" << Min << "\n Min: \n" << FF->fun_value(Min) << std::endl;

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

