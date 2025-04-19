#include "header_polynomial.h"
#include <iostream>

using namespace std;


// ввод многочлена
void InputPolynomial(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax]) {
    
    do {
        cout << "Введите количество многочленов: "; cin >> num_of_polynomials;
        if (num_of_polynomials < 2) cout << "Операции производятся как минимум над двумя многочленами!" << endl;
    } while (num_of_polynomials < 2);

    cout << endl;

    for (int i = 0; i < num_of_polynomials; i++) {
        do {
            cout << "Введите количество членов " << i + 1 << "-го многочлена: "; cin >> sizes[i];
            if (sizes[i] < 2) cout << "Должно быть хотя бы 2" << endl;
        } while (sizes[i] < 2);

        cout << endl;

        for (int j = 0; j < sizes[i]; j++) {
            bool unique = true;
            do {
                unique = true;
                do {
                    cout << "Введите степень x для члена " << j + 1 << " (целое число): "; cin >> polynomials[i][j].degree;
                    if (polynomials[i][j].degree < 0) cout << "Степень не может быть меньше 0" << endl;
                } while (polynomials[i][j].degree < 0);

                for (int k = 0; k < j; k++) {
                    if (polynomials[i][k].degree == polynomials[i][j].degree) {
                        cout << "Степень " << polynomials[i][j].degree << " уже есть в многочлене. ";
                        cout << "Введите другую степень." << endl;
                        unique = false;
                        break;
                    }
                }
            } while (!unique);

            do {
                cout << "Введите коэффициент члена " << j + 1 << ": "; cin >> polynomials[i][j].coefficient;
                if (polynomials[i][j].coefficient == 0) cout << "Вводите информацию только о ненулевых членах многочлена" << endl;
            } while (polynomials[i][j].coefficient == 0);

            cout << endl;
        }
    }
}

// вывод многочлена
void PrintPolynomial(Polynomial result[Nmax * max_degree], int& rez_size) {
    cout << "Результат: " << endl;

    if (rez_size == 0) {
        cout << "0";
    }
    else {
        for (int i = 0; i < rez_size; i++) {

            if (i == 0 && result[i].coefficient < 0) {
                cout << "-";
            }
            else if (i > 0 && result[i].coefficient > 0) {
                cout << " + ";
            }
            else if (i > 0 && result[i].coefficient < 0) {
                cout << " - ";
            }

            if (result[i].degree == 0 || abs(result[i].coefficient) != 1) {
                cout << abs(result[i].coefficient);
            }

            if (result[i].degree > 0) {
                cout << "x";
                if (result[i].degree > 1) {
                    cout << "^" << result[i].degree;
                }
            }
        }
    }
    cout << endl;
}


// удаление членов с нулевыми коэффициентами
void NullCoefficient(Polynomial result[Nmax * max_degree], int& rez_size, int &k) {

    for (int i = k; i < rez_size - 1; i++) {
        result[i] = result[i + 1];
    }
    rez_size--;
    k--;
}


// сложение
void PolynomialAddition(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax], 
    Polynomial result[Nmax * max_degree], int& rez_size) {

    InputPolynomial(polynomials, num_of_polynomials, sizes);

    for (int j = 0; j < sizes[0]; j++) {
        result[j] = polynomials[0][j];
    }
    rez_size = sizes[0];

    for (int i = 1; i < num_of_polynomials; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            bool found = false;

            for (int k = 0; k < rez_size; k++) {
                if (result[k].degree == polynomials[i][j].degree) {
                    result[k].coefficient += polynomials[i][j].coefficient;
                    found = true;

                    if (result[k].coefficient == 0) NullCoefficient(result, rez_size, k);

                    break;
                }
            }
            if (!found) {
                result[rez_size] = polynomials[i][j];
                rez_size++;
            }
        }
    }
}

// вычитание
void PolynomialSubtraction(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
    Polynomial result[Nmax * max_degree], int& rez_size) {
    
    InputPolynomial(polynomials, num_of_polynomials, sizes);

    for (int j = 0; j < sizes[0]; j++) {
        result[j] = polynomials[0][j];
    }
    rez_size = sizes[0];

    for (int i = 1; i < num_of_polynomials; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            bool found = false;

            for (int k = 0; k < rez_size; k++) {
                if (result[k].degree == polynomials[i][j].degree) {
                    result[k].coefficient -= polynomials[i][j].coefficient;
                    found = true;

                    if (result[k].coefficient == 0) NullCoefficient(result, rez_size, k);

                    break;
                }
            }
            if (!found) {
                result[rez_size].degree = polynomials[i][j].degree;
                result[rez_size].coefficient = -polynomials[i][j].coefficient;
                rez_size++;
            }
        }
    }
}

void PolynomialMultiplication(Polynomial polynomials[Nmax][max_degree], int& num_of_polynomials, int sizes[Nmax],
    Polynomial result[Nmax * max_degree], int& rez_size) {
	
    InputPolynomial(polynomials, num_of_polynomials, sizes);


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