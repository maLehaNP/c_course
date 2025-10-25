#include <iostream>
#include <iomanip>

int main()
{
    // 1. Второе по величине
    /*int n;
    int x;
    int fir_max = -102;
    int sec_max = -101;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (x > fir_max) {
            sec_max = fir_max;
            fir_max = x;
        }
        else if (x < fir_max && x > sec_max)
            sec_max = x;
    }
    std::cout << sec_max;*/

    // 2. Числа Фибоначчи из отрезка
    /*int a, b;
    std::cin >> a; std::cin >> b;
    int fib = 1;
    int x0 = 0;
    int x1 = 1;
    while (fib < b) {
        if (fib >= a) std::cout << fib << ' ';
        fib = x1 + x0;
        x0 = x1;
        x1 = fib;
    }
    if (fib == b) std::cout << fib;*/

    // 3. Сумма на степенях двоек
    /*int n;
    std::cin >> n;
    int power = 1;
    int a;
    int sum = 0;
    for (int i = 1; i < n + 1; i++) {
        std::cin >> a;
        if (i == power) {
            sum += a;
            power *= 2;
        }
    }
    std::cout << sum;*/

    // 4. Между первым и вторым
    /*int n;
    std::cin >> n;
    double x;
    int neg_count = 0;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (x < 0) {
            neg_count++;
        }
        else if (neg_count == 1)
            sum += x;
    }
    std::cout << std::fixed << std::setprecision(3) << (neg_count == 1 ? 0 : sum);*/

    // 5. Между первым и последним
    /*int n;
    std::cin >> n;
    float x;
    int neg_count = 0;
    float full_sum = 0;
    float sum = 0;
    float last_neg;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (neg_count >= 1)
            sum += x;
        if (x < 0) {
            neg_count++;
            last_neg = x;
            full_sum = sum;
        }
    }
    full_sum -= last_neg;
    std::cout << std::fixed << std::setprecision(3) << (neg_count == 1 ? 0 : full_sum);*/
}
