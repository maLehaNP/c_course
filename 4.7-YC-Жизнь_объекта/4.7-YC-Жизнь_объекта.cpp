// 4.7-YC-Жизнь_объекта.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "logger.h"
#include <vector>


class A {
public:
    A(int x) {
        std::cout << "Constructor(int): " << x << "\n";
    }
    A(const A&) {
        std::cout << "Copy constructor\n";
    }
    virtual ~A() {
        std::cout << "Destructor\n";
    }
    virtual void foo() const = 0;
};

class B : public A {
public:
    B() : A(42) {};
    void foo() const override {}
};

class B : public A {
public:
    B() : A(42) {};
    void foo() const override {}
};


int main()
{
    // A.
    /*{
        Logger logger;
    }
    {
        Logger logger;
    }*/

    // B.
    /*{
        Logger logger1;
        {
            Logger logger(logger1);
        }
    }*/

    // C.
    /*{
        Logger logger1;
        {
            Logger logger(std::move(logger1));
        }
    }*/

    // D.
    /*{
        Logger logger1;
        {
            Logger logger;
            logger1 = logger;
            logger1 = std::move(logger);
        }
    }*/

    // E.
    /*Logger* logger1{ new Logger };
    Logger* logger2{ new Logger };
    Logger* logger3{ new Logger };
    delete logger2;
    delete logger3;
    delete logger1;*/

    // F.
    /*int n;
    std::cin >> n;
    std::vector<Logger*> loggers;
    for (int i = 0; i < n; i++)
        loggers.push_back(new Logger);
    for (int i = loggers.size() - 1; i >= 0; i--)
        delete loggers[i];*/

    // G.
    /*int n;
    std::cin >> n;
    std::vector<Logger*> loggers;
    for (int i = 0; i < n; i++)
        loggers.push_back(new Logger);
    for (Logger* logger : loggers)
        delete logger;*/

    // H.
    B b;
    const A& a = b;
    a.foo();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
