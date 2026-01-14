// 4.4-Контейнеры_и_классы.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <random>

class Player {

};


int main()
{
    /*
     * I Решить одну задачу с использованием вектора, другую – списка. Для обеих теоретически обосновать выбор контейнера (исходя из операций).
     * 1. Перечень студентов. Операции:
     * а) Вызвать отвечать (распечатать) первого\последнего\среднего по списку. Добавить нового студента в конец списка.
     * б) Вызвать отвечать (распечатать) случайного студента. Добавить нового студента в начало списка.
     * 
     * II Выбрать контейнеры, позволяющие добиться максимальной эффективности основного (в первую очередь) и дополнительных действий.
     * Класс "Плеер". Основное: по исполнителю получать список композиций. Дополнительное: добавлять и удалять исполнителей,
     * добавлять композицию заданного исполнителя, удалять и изменять заданную композицию заданного исполнителя.
     * 12. Изменить краткую информацию об исполнителе. Удалить исполнителей, не исполняющих композиции заданного жанра.
     */

    std::vector<std::string> students_vec = { "Pavel", "Mihail", "Artem", "Sasha", "Masha" };
    std::list<std::string> students_list = { "Pavel", "Mihail", "Artem", "Sasha", "Masha" };

    // a)
    // front и back имеют оба, но вектору при обращению к среднему не нужно перебирать.
    std::cout << students_vec.front() << std::endl;
    std::cout << students_vec.back() << std::endl;
    std::cout << students_vec.at(students_vec.size() / 2) << std::endl;
    std::cout << std::endl;
    // Не выделяется память, а меняется ссылка на последний
    students_list.push_back("Bogdan");

    // b)
    // Случайный доступ без перебора
    std::srand(std::time({})); // use current time as seed for random generator
    std::cout << students_vec.at(std::rand() % students_vec.size()) << std::endl;
    // Не выделяется память, а меняется ссылка на первый элемент
    students_list.push_front("Bogdan");


    // II.
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
