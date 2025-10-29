#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    // 1. A + B
    /*int a, b;
    cin >> a; cin >> b;

    cout << a + b << endl;*/

    // 2. Линейные алгоритмы. Задача 3.2
    /*int n, k, m;
    cin >> n; cin >> k; cin >> m;

    n--;
    int pod = n / (k * m);
    int et = (n - pod * k * m) / m + 1;
    cout << (pod + 1) << " " << (et);*/

    // 3. Прикладная химия
    /*float a, b;
    int x, y;
    cin >> a; cin >> x; cin >> b; cin >> y;
    cout << floor((a * x + b * y) / (a + b));*/

    // 4. Количество чисел по количеству пар
    /*int m;
    int n = 2;
    cin >> m;
    while (true) {
        if (n * (n - 1) == 2*m) {
            cout << n << endl;
            break;
        }
        else n++;
    }*/

    // 5. Вычислительная геометрия. Задача 1
    /*double x1, y1, x2, y2;
    cin >> x1; cin >> y1;
    cin >> x2; cin >> y2;
    cout << fixed << setprecision(4) << sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));*/

    // 6. Условный оператор. Задача 3
    /*string x;
    cin >> x;
    if (x[0] == x[1]) {
        cout << "YES";
    }
    else if (x[0] == x[2]) {
        cout << "YES";
    }
    else if (x[1] == x[2]) {
        cout << "YES";
    }
    else cout << "NO";*/

    // 7. Ветвление. Задача 4 (Кирпич)
    int a, b;
    int x, y, z;
    cin >> a; cin >> b;
    cin >> x; cin >> y; cin >> z;
    if ((x <= a && y <= b)
        || (x <= a && z <= b)
        || (y <= a && z <= b)
        || (x <= b && y <= a)
        || (x <= b && z <= a)
        || (y <= b && z <= a)) cout << "Yes";
    else cout << "No";

    // 8. Условный оператор. Задача 18
    /*double a, b, c;
    cin >> a; cin >> b; cin >> c;
    if (a + b > c && a + c > b && b + c > a) {
        double p = (a + b + c) / 2;
        cout << fixed << sqrt(p * (p - a) * (p - b) * (p - c));
    }
    else cout << -1;*/

    // 9. Вася и работа
    /*int n;
    cin >> n;
    string n_str = to_string(n);
    if (n % 3 == 0 && n_str.rfind('3') + 1 == n_str.size()) cout << 0;
    else if (n % 3 == 0) cout << 1;
    else if (n_str.rfind('3') + 1 == n_str.size()) cout << 1;
    else cout << 0;*/
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
