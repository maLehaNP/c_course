#include <iostream>
#include <string>
//#include <iomanip>
//#include <fstream>
//#include <math.h>
//#include <map>
#include <algorithm>

using namespace std;

//bool IsPalindrome(string s);


int main()
{
    // A. Обратная перестановка
    /*int n;
    cin >> n;

    // Allocate the array on heap
    int* arr = new int[n];

    int a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        arr[a - 1] = i;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    
    // Deallocate the array
    delete[] arr;*/


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
    /*string s;
    getline(cin, s);
    cout << (IsPalindrome(s) ? "YES" : "NO");*/


    // D. Soundex
    string s;
    cin >> s;

    s.erase(remove(s.begin() + 1, s.end(), 'a'), s.end());
    s.erase(remove(s.begin() + 1, s.end(), 'e'), s.end());
    s.erase(remove(s.begin() + 1, s.end(), 'h'), s.end());
    s.erase(remove(s.begin() + 1, s.end(), 'i'), s.end());
    s.erase(remove(s.begin() + 1, s.end(), 'o'), s.end());
    s.erase(remove(s.begin() + 1, s.end(), 'u'), s.end());
    s.erase(remove(s.begin() + 1, s.end(), 'w'), s.end());
    s.erase(remove(s.begin() + 1, s.end(), 'y'), s.end());

    replace(s.begin() + 1, s.end(), 'b', '1');
    replace(s.begin() + 1, s.end(), 'f', '1');
    replace(s.begin() + 1, s.end(), 'p', '1');
    replace(s.begin() + 1, s.end(), 'v', '1');

    replace(s.begin() + 1, s.end(), 'c', '2');
    replace(s.begin() + 1, s.end(), 'g', '2');
    replace(s.begin() + 1, s.end(), 'j', '2');
    replace(s.begin() + 1, s.end(), 'k', '2');
    replace(s.begin() + 1, s.end(), 'q', '2');
    replace(s.begin() + 1, s.end(), 's', '2');
    replace(s.begin() + 1, s.end(), 'x', '2');
    replace(s.begin() + 1, s.end(), 'z', '2');

    replace(s.begin() + 1, s.end(), 'd', '3');
    replace(s.begin() + 1, s.end(), 't', '3');

    replace(s.begin() + 1, s.end(), 'l', '4');

    replace(s.begin() + 1, s.end(), 'm', '5');
    replace(s.begin() + 1, s.end(), 'n', '5');

    replace(s.begin() + 1, s.end(), 'r', '6');

    size_t len = s.length();
    int i = 1;
    while (i < len) {
        if (s[i - 1] == s[i]) {
            s.erase(i, 1);
            len--;
        }
        else i++;
    }

    if (s.length() > 4)
        s = s.substr(0, 4);
    else
        s.insert(s.end(), 4 - s.length(), '0');

    cout << s;


    // E. Сортировка точек
    /*int n;
    cin >> n;
    map<float, pair<int, int>> points;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x; cin >> y;
        float dist = sqrt(x*x + y*y);
        points[dist] = pair{ x, y };
    }
    for (const auto& [dist, point] : points) {
        cout << point.first << ' ' << point.second << endl;
    }*/
    /*for (std::map<float, pair<int, int>>::reverse_iterator iter = points.rbegin(); iter != points.rend(); iter++) {
        cout <<
    }*/


    // F. Сапёр
    /*int m, n, k;
    cin >> m; cin >> n; cin >> k;
    
    // Allocate the array on heap
    int** field = new int* [m];
    for (int i = 0; i < m; i++) {
        int* row = new int[n];
        for (int j = 0; j < n; j++)  // Fill with 0
            row[j] = 0;
        field[i] = row;
        //field[i] = new int[n];
    }

    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row; cin >> col;
        row--; col--;
        field[row][col] = 9;
        for (int j = row - 1; j <= row + 1; j++)
            for (int k = col - 1; k <= col + 1; k++)
                if (j >= 0 && j < m && k >= 0 && k < n)
                    field[j][k]++;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << (field[i][j] > 8 ?  "*" : to_string(field[i][j])) << ' ';
        cout << endl;
    }

    // Deallocate the array
    for (int i = 0; i < m; i++)
        delete[] field[i];
    delete[] field;*/
}

//bool IsPalindrome(string s) {
//    s.erase(remove(s.begin(), s.end(), ' '), s.end());
//    for (int i = 0; i < s.size(); i++) {
//        cout << s[i] << ' ' << s[s.size() - 1 - i] << endl;
//        if (s[i] != s[s.size() - 1 - i])
//            return false;
//    }
//    return true;
//}
