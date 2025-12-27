#include <iostream>
using namespace std;

class Container {
    int volume;
public:
    // По умолчанию
    Container() {
        cout << "Default constructor" << endl;
    }

    Container(int volume) {
        cout << "Normal constructor" << endl;
        if (volume < 0) {
            this->volume = 0;
        }
        else this->volume = volume;
    }

    // Копирования
    Container(const Container& c) : Container{ c.getVolume() } {
        cout << "Copy constructor" << endl;
    }

    // Перемещения
    Container(Container&& moved) {
        cout << "Move constructor" << endl;
        volume = moved.volume;
        moved.volume = 0;
    }

    // Оператор перемещения (move assignment operator)
    Container& operator=(Container&& moved) {
        cout << "Move assignment operator" << endl;
        if (&moved != this) {  // Проверка на самоприсваивание
            volume = moved.volume;
            moved.volume = 0;
        }
        return *this;
    }

    // Деструктор
    ~Container() = default;

    int getVolume() const {
        return volume;
    }
};

int main()
{
    /*
     * Создайте минималистичный класс. На примере созданного класса проведите эксперименты с конструктором по умолчанию (default constructor),
     * конструктором копирования (сopy constructor), конструктором перемещения (move constructor), копирующим оператором присваивания (сopy assignment operator),
     * оператором перемещения (move assignment operator), деструктором. Используйте = default, = delete, собственные реализации.
     * 
     * 4. "Ёмкость" с одним числовым полем - объёмом. Значение объёма устанавливается при создании объекта и не может быть отрицательным (вместо отрицательного устанавливается 0).
     * В дальнейшем можно только посмотреть значение объёма методом getVolume.
     */
    
    // Default
    Container c0;
    cout << endl;

    // Normal
    Container c1(5);
    cout << endl;

    // < 0
    Container c2(-5);
    cout << "C2 volume: " << c2.getVolume() << endl;
    cout << endl;

    // Copy
    Container c3(c1);
    cout << "C3 volume: " << c3.getVolume() << endl;
    cout << endl;

    // Move
    Container c4(move(c1));
    cout << "C4 volume: " << c4.getVolume() << endl;
    cout << "C1 volume: " << c1.getVolume() << endl;
    cout << endl;

    // Copy assign
    Container c5(6);
    Container c6 = c5;
    cout << "C6 volume: " << c6.getVolume() << endl;
    cout << endl;

    // Move assign
    c5 = Container{7};
    cout << "C5 volume: " << c5.getVolume() << endl;
    cout << endl;
}
