#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

float F(float x);
void F(float x, float& y);

int main()
{
    cout << F(2) << endl;

    float y = 0.0f;
    F(2, y);
    cout << y << endl;

    int a, b, h;
    cin >> a; cin >> b; cin >> h;
    cout << "x | y" << endl;
    for (int x = a; x <= b; x += h) {
        printf("%d | %f\n", x, F(x));
    }
}

float F(float x) {
    if (abs(x) < M_PI / 2) {
        return sin(x);
    }
    else if (abs(x) >= M_PI / 2 && abs(x) <= M_PI) {
        return cos(x);
    }
    else if (abs(x) > M_PI) {
        return 0;
    }
}


void F(float x, float& y) {
    if (abs(x) < M_PI / 2) {
        y = sin(x);
    }
    else if (abs(x) >= M_PI / 2 && abs(x) <= M_PI) {
        y = cos(x);
    }
    else if (abs(x) > M_PI) {
        y = 0;
    }
}
