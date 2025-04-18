#include "header_polynomial.h"
#include <iostream>

using namespace std;



void InputPolynomial(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax]) {
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
                cout << "Введите степень x для члена " << j << " (целое число): "; cin >> polynomials[i][j].degree;
                if (polynomials[i][j].degree < 0) cout << "Степень не может быть меньше 0" << endl;
            } while (polynomials[i][j].degree < 0);

            do {
                cout << "Введите коэффициент члена " << j << ": "; cin >> polynomials[i][j].coefficient;
                if (polynomials[i][j].coefficient == 0) cout << "Вводите информацию только о ненулевых членах многочлена" << endl;
            } while (polynomials[i][j].coefficient == 0);

            cout << endl;
        }
    }
}


void PrintPolynomial(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax]) {
    cout << "Вывод";
}

void PolynomialAddition(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax], 
    Polynomial result[Nmax * max_degree], int& rez_size) {
    InputPolynomial(polynomials, num_of_polynomials, sizes);

    for (int j = 0; j < sizes[0]; j++) {
        result[j] = polynomials[0][j];
    }
    rez_size = sizes[0];

    for (int i = 0; i < sizes[num_of_polynomials]; i++) {
        bool found = false;
        for (int j = 0; j < rez_size; j++) {
            if (result[j].degree == polynomials[i][j].degree) {
                result[j].coefficient += polynomials[i][j].coefficient;
                found = true;
            }
            if (!found) {
                result[rez_size] = polynomials[i][j];
                rez_size++;
        }
        }
    }
}

void PolynomialSubtraction(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
    Polynomial result[Nmax * max_degree], int& rez_size) {
    InputPolynomial(polynomials, num_of_polynomials, sizes);

    for (int j = 0; j < sizes[0]; j++) {
        result[j] = polynomials[0][j];
    }
    rez_size = sizes[0];

    for (int i = 0; i < sizes[num_of_polynomials]; i++) {
        bool found = false;
        for (int j = 0; j < rez_size; j++) {
            if (result[j].degree == polynomials[i][j].degree) {
                result[j].coefficient -= polynomials[i][j].coefficient;
                found = true;
            }
            if (!found) {
                result[rez_size].degree = polynomials[i][j].degree;
                result[rez_size].coefficient = -polynomials[i][j].coefficient;
                rez_size++;
            }
        }
    }
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