#include <iostream>

class Container {
    int volume;
public:
    // По умолчанию
    Container() = default;

    Container(int volume) {
        if (volume < 0) {
            this->volume = 0;
        }
        else this->volume = volume;
    }

    // Копирования
    Container(const Container& c) {
        volume = c.volume;
    }

    // Деструктор
    ~Container() = delete;

    int getVolume() {
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
    

}
