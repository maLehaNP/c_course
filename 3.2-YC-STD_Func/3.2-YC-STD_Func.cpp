#include <iostream>
#include <vector>
//#include <limits.h>
#include <exception>
#include <functional>
#include <optional>
using namespace std;


std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    int max = INT_MIN;
    std::pair<size_t, size_t> res;
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                res = std::pair<size_t, size_t>{ i, j };
            }
        }
    }
    return res;
}

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
    if (tokens.empty())
        return "";
    else if (tokens.size() == 1)
        return tokens[0];
    string s;
    for (string token : tokens)
        s += token + delimiter;
    s.pop_back();
    return s;
}

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> res(matrix[0].size(), vector<int>(matrix.size()));
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            res[j][i] = matrix[i][j];
        }
    }
    return res;
}

template <typename Result, typename Exception = std::exception>
optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime, bool throwLast) {
    int retry = 0;
    while (true) {
        try {
            return func();
        }
        catch (const Exception& e) {
            retry++;
            if (retry == retryCount + 1) {
                if (throwLast)
                    throw e;
                else
                    return optional<Result>();
            }
            Sleep(sleepTime);
        }
    }
}


int main()
{
    // A. ArgMax в матрице
    /*std::vector<std::vector<int>> matrix = {
        {0, 3, 2, 4},
        {2, 3, 5, 5},
        {5, 1, 2, 3}
    };
    std::pair<size_t, size_t> res = MatrixArgMax(matrix);
    std::cout << res.first << ' ' << res.second;*/


    // B. Функция Join
    //cout << Join({ "What", "is", "your", "name?" }, '_');


    // C. Транспонировать матрицу
    std::vector<std::vector<int>> matrix = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34}
    };
    std::vector<std::vector<int>> res = Transpose(matrix);
    for (std::vector<int> row : res) {
        for (int elem : row)
            cout << elem << ' ';
        cout << endl;
    }
}
