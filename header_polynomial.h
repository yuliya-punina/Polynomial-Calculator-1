#pragma once

const int max_degree = 10;

struct Polynomial {
	double coefficients;
};

void PolynomialMenu();
void PolynomialAddition();
void PolynomialSubtraction();
void PolynomialMultiplication();
void PolynomialScalarMultiplication();
void PolynomialDivision();
void PolynomialDerivative();