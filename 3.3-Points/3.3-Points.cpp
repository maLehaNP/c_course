#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


int main()
{
    /* 
     * “очки на плоскости заданы парами целочисленных координат. ƒл€ хранени€ каждой точки и всех точек,
     * а также дл€ выполнени€ заданий используйте подход€щие контейнеры и алгоритмы стандартной библиотеки.
     * 
     * 11.
     * а) удалить все точки из левой половины системы координат
     * б) подсчитать количество точек, лежащих левее и ниже заданной
     * в) найти последнюю точку, удалЄнную от начала координат не менее чем на R
     * г) расположить в пор€дке возрастани€ суммы координат, сохран€€ пор€док точек с одинаковой суммой
     */

    vector<pair<int, int>> points = { {1, 1}, {3, 3}, {-1, 1}, {-2, -1} };

    // б)
    pair<int, int> point(2, 2);
    cout << count_if(points.begin(), points.end(), [point](pair<int, int> p) { return (p.first < point.first && p.second < point.second); }) << endl;

    // в)
    //int R = 15;
    auto pred = [](pair<int, int> p) { return sqrt(p.first * p.first + p.second * p.second) >= 15; };
    auto p = ranges::find_last_if(points, pred);
    //cout << p.begin()->first << ' ' << p.begin()->second << endl;

    // а)
    const auto End = remove_if(points.begin(), points.end(), [](pair<int, int> p) { return p.first < 0; });
    for (pair<int, int> p : points) {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
}
