#ifndef HEADER_POLYNOMIAL_H
#define HEADER_POLYNOMIAL_H

const int Nmax = 100;

struct Polynomial {
	double coefficient;
	int degree;
};

void PolynomialMenu();
void InputPolynomial(Polynomial polynomials[Nmax][Nmax], int& num_of_polynomials, int sizes[Nmax]);
void PolynomialAddition(Polynomial polynomials[Nmax][Nmax], int& num_of_polynomials, int sizes[Nmax]);
void PolynomialSubtraction(Polynomial polynomials[Nmax][Nmax], int& num_of_polynomials, int sizes[Nmax]);
void PolynomialMultiplication();
void PolynomialScalarMultiplication();
void PolynomialDivision();
void PolynomialDerivative();

#endif