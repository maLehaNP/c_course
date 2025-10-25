// 0-4_Сontinuation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
//#include <math.h>
//#include <iomanip>
//#include <set>
//#include <thread>

int main()
{
    // 1. Циклы. Знакопеременная сумма II
    /*float a;
    double value = 0;
    int n = 1;
    while (std::cin >> a && a > 0) {
        value += std::pow(-1, n) * a / n;
        n++;
    }
    std::cout << std::fixed << std::setprecision(7) << value;*/

    // 2. Задача 12. Степени пятерки
    /*int n;
    std::cin >> n;
    int a;
    int count = 0;
    std::set<int> powers{ 1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625 };
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        if (powers.count(a) == 1) count++;
    }
    std::cout << count;*/

    // 3. Татьяна Ларина
    /*int o;
    std::cin >> o;
    int sum = 0;
    int i = 1;
    while (sum < o) {
        sum += i;
        i++;
    }
    std::cout << i - 1;*/

    // 4. Вложенные циклы. Задача 1.7
    /*int n;
    std::cin >> n;
    if (isprime(n)) {
        std::cout << n;
        return 0;
    }
    int lowerPrime = n - 1;
    int higherPrime = n + 1;
    int lowerDist = 1;
    int higherDist = 1;
    std::thread t1(near_lover_prime, std::ref(lowerPrime), std::ref(lowerDist));
    std::thread t2(near_higher_prime, std::ref(higherPrime), std::ref(higherDist));
    t1.join();
    t2.join();
    if (lowerDist == higherDist) {
        std::cout << lowerPrime;
    }
    else std::cout << ((lowerDist < higherDist) ? lowerPrime : higherPrime);*/

    // 5. Строки. Задача 20
    /*std::string s;
    std::getline(std::cin, s);
    int count = 0;
    for (char ch : s) {
        if (ch >= 48 && ch <= 57) count++;
    }
    std::cout << count;*/

    // 6. Строки. Задача 1
    /*char c1, c2;
    std::string s;
    std::cin >> c1; std::cin >> c2; std::cin >> s;
    int i = 0;
    int len = s.size();
    while (i != len) {
        if (s[i] == c2) {
            s.insert(i + 1, 1, c1);
            i += 2;
            len++;
        }
        else i++;
    }
    std::cout << s;*/

    // 7. Процедуры и функции. Задача 18
    /*int n;
    std::cin >> n;
    std::cin.get();
    std::string s;
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, s);
        std::cout << rem_extra_spaces(s) << std::endl;
    }*/

    // 8. Поиск букв
    std::string s;
    char c1, c2;
    std::getline(std::cin, s);
    std::cin >> c1; std::cin >> c2;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == c1) {
            std::cout << c1;
            break;
        }
        else if (s[i] == c2) {
            std::cout << c2;
            break;
        }
    }
}

//bool isprime(int n)
//{
//    for (int i = 2; i <= std::sqrt(n); i++)
//    {
//        if (n % i == 0)
//            return false;
//    }
//    return true;
//}

//void near_lover_prime(int& prime, int& dist) {
//    for (prime; prime >= 3; prime--) {
//        if (isprime(prime))
//            break;
//        dist++;
//    }
//}

//void near_higher_prime(int& prime, int& dist) {
//    while (!isprime(prime)) {
//        prime++;
//        dist++;
//    }
//}

//std::string rem_extra_spaces(std::string s) {
//    for (int i = 1; i < s.size(); i++) {
//        if (s[i] == 32 && s[i - 1] == 32)
//            while (s[i] == 32) s.erase(i, 1);
//    }
//    if (s[0] == 32) s.erase(0, 1);
//    if (s[s.size() - 1] == 32) s.erase(s.size() - 1, 1);
//    return s;
//}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
