// 1.2-Исследование_массивов.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>


int main()
{
    /*
     * Исследуемые типы массивов:
     * - одномерный статический массив
     * - одномерный динамический массив
     * - двумерный массив как единый блок памяти
     * - двумерный статический массив
     * - двумерный динамический массив (массив указателей на одномерные массивы)
     * 
     * Для каждого типа массива реализовать следующие возможности:
     * 1. Создание без инициализации:
     * - изучить, чем заполнен массив по умолчанию
     * - исследовать возможность инициализации при создании
     * 2. Заполнение из файла:
     * - прочитать размер(ы) массива
     * - заполнить массив значениями из файла
     * 3. Вывод на консоль:
     * - вывести сами элементы
     * - вывести адреса элементов, отметить особенности/отличия
     * 4. Некоторые операции для работы с массивом:
     * - получить элемент по заданным индексам
     * - найти индекс минимального по абсолютному значению элемента
     * - обменять местами первый и последний элементы (для одномерных), первую и последнюю строки (для двумерных), первый и последний столбцы (для двумерных).
     * 5. Завершить работу: освободить память или пояснить, почему это не требуется.
     */


    // 1. Создание без инициализации

    int a1[3];  // одномерный статический массив
    int* a2 = new int[3];  // одномерный динамический массив
    int a3[3 * 4];  // двумерный массив как единый блок памяти
    int a4[3][4];  // двумерный статический массив
    int** a5 = new int* [3];  // двумерный динамический массив (массив указателей на одномерные массивы)
    for (int i = 0; i < 3; i++)
        a5[i] = new int[4];

    // изучить, чем заполнен массив по умолчанию
    std::cout << "1st elem of static arr a1: " << a1[0] << std::endl;
    std::cout << "1st elem of dynamic arr a2: " << a2[0] << std::endl;
    std::cout << "[0][0] elem of multi-dim. one-block arr a3: " << a3[0 * 4 + 0] << std::endl;
    std::cout << "[0][0] elem of multi-dim. static arr a4: " << a4[0][0] << std::endl;
    std::cout << "[0][0] elem of multi-dim. dynamic arr a5: " << a5[0][0] << std::endl;
    std::cout << std::endl;

    // исследовать возможность инициализации при создании
    int a1_[3] = { 1, 2, 3 };
    int* a2_ = new int[3] { 1, 2, 3 };
    int a3_[3 * 4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int a4_[3][4] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };
    int** a5_ = new int* [3];
    for (int i = 0; i < 3; i++)
        a5_[i] = new int[4]{ 1 + 4 * i, 2 + 4 * i, 3 + 4 * i, 4 + 4 * i };

    std::cout << "2nd elem of static arr a1: " << a1_[1] << std::endl;
    std::cout << "3rd elem of dynamic arr a2: " << a2_[2] << std::endl;
    std::cout << "[2][1] (10th) elem of multi-dim. one-block arr a3: " << a3_[2 * 4 + 1] << std::endl;
    std::cout << "[0][3] elem of multi-dim. static arr a4: " << a4_[0][3] << std::endl;
    std::cout << "[1][2] elem of multi-dim. dynamic arr a5: " << a5_[1][2] << std::endl;
    std::cout << std::endl;


    // 2. Заполнение из файла
    // прочитать размер(ы) массива
    // заполнить массив значениями из файла
    std::ifstream input1("array1.txt");
    int num;
    int n;
    input1 >> n;
    std::cout << n << std::endl;
    for (int i = 0; i < n; i++) {
        input1 >> num;
        a1[i] = num;
        a2[i] = num;
    }

    std::ifstream input2("array2.txt");
    int m;
    input2 >> n; input2 >> m;
    std::cout << n << ' ' << m << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            input2 >> num;
            a3[i * m + j] = num;
            a4[i][j] = num;
            a5[i][j] = num;
        }
    }
    std::cout << std::endl;


    // 3. Вывод на консоль :
    // вывести сами элементы
    std::cout << "a1: ";
    for (int i = 0; i < n; i++) {
        std::cout << a1[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "a2: ";
    for (int i = 0; i < n; i++) {
        std::cout << a2[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "a3:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a3[i * m + j] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "a4:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a4[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "a5:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a5[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    // вывести адреса элементов, отметить особенности / отличия
    std::cout << "a1: ";
    for (int i = 0; i < n; i++) {
        std::cout << &a1[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "a2: ";
    for (int i = 0; i < n; i++) {
        std::cout << &a2[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "a3:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << &a3[i * m + j] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "a4:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << &a4[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "a5:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << &a5[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;


    // 4. Некоторые операции для работы с массивом :
    // - получить элемент по заданным индексам
    std::cout << "2nd elem of static arr a1: " << a1[1] << std::endl;
    std::cout << "3rd elem of dynamic arr a2: " << a2[2] << std::endl;
    std::cout << "[2][1] (10th) elem of multi-dim. one-block arr a3: " << a3[2 * 4 + 1] << std::endl;
    std::cout << "[0][3] elem of multi-dim. static arr a4: " << a4[0][3] << std::endl;
    std::cout << "[1][2] elem of multi-dim. dynamic arr a5: " << a5[1][2] << std::endl;
    std::cout << std::endl;

    // - найти индекс минимального по абсолютному значению элемента
    int min = INT_MAX;
    int min_i;

    for (int i = 0; i < n; i++) {
        if (abs(a1[i]) < min) {
            min = abs(a1[i]);
            min_i = i;
        }
    }
    std::cout << "a1 min index: " << min_i << std::endl;

    min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (abs(a2[i]) < min) {
            min = abs(a2[i]);
            min_i = i;
        }
    }
    std::cout << "a2 min index: " << min_i << std::endl;

    min = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(a3[i * m + j]) < min) {
                min = abs(a3[i * m + j]);
                min_i = i * m + j;
            }
        }
    }
    std::cout << "a3 min index: " << min_i << std::endl;

    min = INT_MAX;
    int min_j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(a4[i][j]) < min) {
                min = abs(a4[i][j]);
                min_i = i;
                min_j = j;
            }
        }
    }
    std::cout << "a4 min index: " << min_i << ' ' << min_j << std::endl;

    min = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(a5[i][j]) < min) {
                min = abs(a5[i][j]);
                min_i = i;
                min_j = j;
            }
        }
    }
    std::cout << "a5 min index: " << min_i << ' ' << min_j << std::endl;

    std::cout << std::endl;

    // - обменять местами первый и последний элементы (для одномерных), первую и последнюю строки (для двумерных), первый и последний столбцы (для двумерных).
    int temp;
    temp = a1[0];
    a1[0] = a1[n - 1];
    a1[n - 1] = temp;

    temp = a2[0];
    a2[0] = a2[n - 1];
    a2[n - 1] = temp;

    for (int j = 0; j < m; j++) {
        temp = a3[0 * m + j];
        a3[0 * m + j] = a3[(n - 1) * m + j];
        a3[(n - 1) * m + j] = temp;
    }

    for (int j = 0; j < m; j++) {
        temp = a4[0][j];
        a4[0][j] = a4[n - 1][j];
        a4[n - 1][j] = temp;
    }

    for (int j = 0; j < m; j++) {
        temp = a5[0][j];
        a5[0][j] = a5[n - 1][j];
        a5[n - 1][j] = temp;
    }

    for (int i = 0; i < n; i++) {
        temp = a3[i * m + 0];
        a3[i * m + 0] = a3[i * m + (m - 1)];
        a3[i * m + (m - 1)] = temp;
    }

    for (int i = 0; i < n; i++) {
        temp = a4[i][0];
        a4[i][0] = a4[i][m - 1];
        a4[i][m - 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        temp = a5[i][0];
        a5[i][0] = a5[i][m - 1];
        a5[i][m - 1] = temp;
    }

    std::cout << "a1: ";
    for (int i = 0; i < n; i++) {
        std::cout << a1[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "a2: ";
    for (int i = 0; i < n; i++) {
        std::cout << a2[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "a3:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a3[i * m + j] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "a4:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a4[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "a5:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a5[i][j] << ' ';
        }
        std::cout << std::endl;
    }


    // 5. Завершить работу: освободить память или пояснить, почему это не требуется.

    // Для статич. одномер. не нужно, т. к. он на стеке.

    delete[] a2;  // Удаляем динамич. одномер. массив

    // Для двумерного как един. блок и статического не нужно, т. к. стек.

    // двумерный динамический массив (массив указателей на одномерные массивы)
    for (int i = 0; i < 3; i++)
        delete[] a5[i];
    delete[] a5;

    delete[] a2_;
    for (int i = 0; i < 3; i++)
        delete[] a5_[i];
    delete[] a5_;
}
