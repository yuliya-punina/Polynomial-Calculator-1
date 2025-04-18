#ifndef HEADER_POLYNOMIAL_H
#define HEADER_POLYNOMIAL_H

const int Nmax = 100;
const int max_degree = 10;

struct Polynomial {
	double coefficient;
	int degree;
};

void PolynomialMenu();
void PolynomialAddition();
void PolynomialSubtraction();
void PolynomialMultiplication();
void PolynomialScalarMultiplication();
void PolynomialDivision();
void PolynomialDerivative();

#endif