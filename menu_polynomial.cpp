#include "header_polynomial.h"
#include <iostream>
//#include <Windows.h>
#include <locale.h>


using namespace std;

void PolynomialMenu() {
    //SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Rus");



    int choice;
    bool exit = false;


    while (!exit) {

        cout << endl;
        cout << "КАЛЬКУЛЯТОР МНОГОЧЛЕНОВ" << endl;
        cout << "1. Сложение многочленов" << endl;
        cout << "2. Вычитание многочленов" << endl;
        cout << "3. Умножение многочленов" << endl;
        cout << "4. Умножение многочлена на число" << endl;
        cout << "5. Деление многочленов в столбик" << endl;
        cout << "6. Вычисление производной многочлена" << endl;
        cout << "0. Вернуться в главное меню" << endl;

        cout << "Выберите действие (0-6): "; cin >> choice;

        switch (choice) {
        case 1:
            PolynomialAddition();
            break;
        case 2:
            PolynomialSubtraction();
            break;
        case 3:
            PolynomialMultiplication();
            break;
        case 4:
            PolynomialScalarMultiplication();
            break;
        case 5:
            PolynomialDivision();
            break;
        case 6:
            PolynomialDerivative();
            break;
        case 0:
            exit = true;
            break;
        default:
            cout << "Пункта с таким номером нет!" << endl;
        }
    }

}