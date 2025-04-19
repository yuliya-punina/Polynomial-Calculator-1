#ifndef HEADER_POLYNOMIAL_H
#define HEADER_POLYNOMIAL_H

const int Nmax = 10;
const int max_degree = 20;

struct Polynomial {
	int degree;
	double coefficient;
};

void PolynomialMenu();

void InputPolynomial(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax]);
void PrintPolynomial(Polynomial result[Nmax * max_degree], int& rez_size);

void NullCoefficient(Polynomial result[Nmax * max_degree], int& rez_size, int& k);

void PolynomialAddition(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
	Polynomial result[Nmax * max_degree], int& rez_size);
void PolynomialSubtraction(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
	Polynomial result[Nmax * max_degree], int& rez_size);
void PolynomialMultiplication();
void PolynomialScalarMultiplication();
void PolynomialDivision();
void PolynomialDerivative();

#endif