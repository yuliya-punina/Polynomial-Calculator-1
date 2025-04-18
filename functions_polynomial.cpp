#include "header_polynomial.h"
#include <iostream>

using namespace std;



void InputPolynomial(Polynomial polynomials[Nmax][Nmax], int& num_of_polynomials, int sizes[Nmax]) {
    do {
        cout << "Введите количество многочленов: "; cin >> num_of_polynomials;
        if (num_of_polynomials < 2) cout << "Операции производятся как минимум над двумя многочленами!" << endl;
    } while (num_of_polynomials < 2);

    cout << endl;

    for (int i = 1; i <= num_of_polynomials; i++) {
        do {
            cout << "Введите количество членов " << i << "-го многочлена: "; cin >> sizes[i];
            if (sizes[i] < 2) cout << "Должно быть хотя бы 2" << endl;
        } while (sizes[i] < 2);

        cout << endl;

        for (int j = 1; j <= sizes[i]; j++) {
            do {
                cout << "Введите коэффициент члена " << j << ": "; cin >> polynomials[i][j].coefficient;
                if (polynomials[i][j].coefficient == 0) cout << "Вводите информацию только о ненулевых членах многочлена" << endl;
            } while (polynomials[i][j].coefficient == 0);

            do {
                cout << "Введите степень x для члена " << j << " (целое число): "; cin >> polynomials[i][j].degree;
                if (polynomials[i][j].degree < 0) cout << "Степень не может быть меньше 0" << endl;
            } while (polynomials[i][j].degree < 0);
            cout << endl;
        }
    }
}


void PolynomialAddition(Polynomial polynomials[Nmax][Nmax], int& num_of_polynomials, int sizes[Nmax]) {
    InputPolynomial(polynomials, num_of_polynomials, sizes);
}

void PolynomialSubtraction(Polynomial polynomials[Nmax][Nmax], int& num_of_polynomials, int sizes[Nmax]) {
    InputPolynomial(polynomials, num_of_polynomials, sizes);
}

void PolynomialMultiplication() {
	cout << "Умножение многочленов" << endl;
}

void PolynomialScalarMultiplication() {
	cout << "Умножение многочлена на число" << endl;
}

void PolynomialDivision() {
	cout << "Деление в столбик" << endl;
}

void PolynomialDerivative() {
	cout << "Производная" << endl;
}