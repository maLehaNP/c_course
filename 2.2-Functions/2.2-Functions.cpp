#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


bool isprime(int n);
void ShiftProcedure(int row[], int m);
int MinProcedure(int** arr, int n, int k);
string DelCommas(string s);
string Strip(string s);
vector<int> AllDigitSumK(int K, int N);
int NumLen(int x);
int NumDigitSum(int x);


int main()
{
    // 1. Функции. Все простые трёхзначные
    /*for (int i = 100; i < 1000; i++) {
        if (isprime(i))
            std::cout << i << ' ';
    }*/


    // 2. Процедуры и функции. Задача 13
    /*int n, m;
    cin >> n; cin >> m;

    // Allocate the array on heap
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        ShiftProcedure(arr[i], m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }

    // Deallocate the array
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;*/


    // 3. Процедуры и функции. Задача 14
    /*int n;
    cin >> n;

    // Allocate the array on heap
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        cout << MinProcedure(arr, n, i) << ' ';

    // Deallocate the array
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;*/


    // 4. Процедуры и функции. Задача 17
    /*int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        cout << DelCommas(s) << endl;
    }*/

    // 5. Процедуры и функции. Задача 18
    /*int n;
    cin >> n;
    cin.get();
    string s;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        cout << Strip(s) << endl;
    }*/

    // 6. Процедуры и функции. Задача 19
    /*int n;
    cin >> n;
    int Ns[20];
    for (int i = 0; i < n; i++)
        cin >> Ns[i];
    int K;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> K;
        arr = AllDigitSumK(K, Ns[i]);
        cout << arr.size() << endl;
        for (int num : arr) {
            cout << num << ' ';
        }
    }*/

    // 7. Квадрат наибольшего периметра
    int n;
    cin >> n;
    if (n < 4) {
        cout << 0;
    }
    else {
        int points[50];
        for (int i = 0; i < n; i++) {
            cin >> points[i];
        }
    }
}

bool isprime(int n)
{
    for (int i = 2; i <= std::sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void ShiftProcedure(int row[], int m) {
    int first = row[0];
    for (int i = 1; i < m; i++) {
        row[i - 1] = row[i];
    }
    row[m - 1] = first;
}

int MinProcedure(int** arr, int n, int k) {
    int min = arr[k][k];
    for (int i = k; i < n; i++) {
        for (int j = k; j < n; j++) {
            if (arr[i][j] < min)
                min = arr[i][j];
        }
    }
    return min;
}

string DelCommas(string s) {
    size_t fst = s.find(',', 0);
    string res = s.substr(0, fst);
    size_t snd = s.find(',', fst + 1);
    while (true) {
        if (s.find(',', snd + 1) == string::npos) {
            if (snd + 1 != s.length())
                res += s.substr(snd + 1, s.length() - snd);
            break;
        }
        fst = s.find(',', snd + 1);
        res += s.substr(snd + 1, fst - snd - 1);
        snd = s.find(',', fst + 1);
    }
    return res;
}

string Strip(string s) {
    while (s[0] == ' ') {
        s.erase(0, 1);
    }
    size_t len = s.length();
    int i = 1;
    while (i < len) {
        if (s[i - 1] == ' ' && s[i] == ' ') {
            s.erase(i, 1);
            len--;
        }
        else i++;
    }
    if (s.back() == ' ')
        s.erase(s.rfind(' '));
    return s;
}

vector<int> AllDigitSumK(int K, int N) {
    vector<int> arr;
    int Klen = NumLen(K);
    int Nlen = NumLen(N);
    if (K <= N)
        arr.push_back(K);
    int power = 1;
    for (int i = K + 1; i < N; i++) {
        if (NumDigitSum(i) == K)
            arr.push_back(i);
    }
    return arr;
}

int NumLen(int x) {
    int power = 1;
    int numLen = 1;
    while (power <= x) {
        power *= 10;
        numLen++;
    }
    return numLen;
}

int NumDigitSum(int x) {
    int sum = 0;
    int numLen = NumLen(x);
    for (int power = pow(10, numLen); x != 0; power /= 10) {
        int digit = x / power;
        sum += digit;
        x -= digit * power;
    }
    return sum;
}
