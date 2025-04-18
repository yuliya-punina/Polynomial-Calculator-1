#include "header_polynomial.h"
#include <iostream>

using namespace std;



void InputPolinomial() {
    cout << "Введите количество членов многочлена: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        cout << "Введите коэффициент члена " << i + 1 << ": ";
        cin >> polynomial[i].coefficient;

        cout << "Введите степень x для члена " << i + 1 << ": ";
        cin >> polynomial[i].power;
    }
}


void PolynomialAddition() {
	cout << "Сложение" << endl;
}

void PolynomialSubtraction() {
	cout << "Вычитание" << endl;
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