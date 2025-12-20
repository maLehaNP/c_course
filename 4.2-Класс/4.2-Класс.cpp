#include <iostream>
#include <math.h>
using namespace std;

// 1.
class Triangle {
    int a, b, c;
    static unsigned int nCopies;

public:
    Triangle() : a{ 0 }, b{ 0 }, c{ 0 } { nCopies++; };
    Triangle(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
        nCopies++;
    }
    void show() {
        printf("(%d %d %d)\n", a, b, c);
    }
    int perimeter() {
        return a + b + c;
    }
    float area() {
        float p = (float)perimeter() / 2.0f;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    void setSides(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    bool isExists() {
        return (a + b > c && a + c > b && b + c > a);
    }
    static unsigned int getNCopies() {
        return nCopies;
    }
    Triangle& operator++() {
        a++; b++; c++;
        return *this;
    }
    Triangle& operator--() {
        a--; b--; c--;
        return *this;
    }
    Triangle& operator*(int scal) {
        a *= scal;
        b *= scal;
        c *= scal;
        return *this;
    }
};

unsigned int Triangle::nCopies = 0;

int main()
{
    Triangle t1;
    t1.show();
    cout << "Number of copies: " << t1.getNCopies() << endl;

    Triangle t2(2, 2, 3);
    t2.show();
    cout << "Number of copies: " << t2.getNCopies() << endl;

    cout << "Perimeter: " << t2.perimeter() << endl;

    cout << "Area: " << t2.area() << endl;

    cout << "Sides set:" << endl;
    t2.setSides(3, 3, 5);
    t2.show();

    cout << "Is exists?: " << t2.isExists() << endl;

    ++t2;
    t2.show();

    --t2;
    t2.show();

    (t2 * 2).show();
}
