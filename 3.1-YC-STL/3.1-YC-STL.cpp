#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    // A. Обратная перестановка


    // B. Сортировка по убыванию
    /*std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    std::string s;
    string a[1000];
    int n = 0;
    while (std::getline(input, s)) {
        a[n] = s;
        n++;
    }
    // Bubble
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1] < a[j]) {
                string temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        output << a[i] << endl;
    }*/

    // C. Палиндромы
    string s;
    cin >> s;
}
