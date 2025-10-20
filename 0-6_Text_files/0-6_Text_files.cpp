#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

int main()
{
    // 20, 21

    // 20) Дан текстовый файл “in.txt”. Дополнить каждую строку справа точками до 20 символов и вывести в выходной файл “out.txt”.
    std::ifstream input("in1.txt");
    std::ofstream output("out1.txt");
    std::string s;
    while (std::getline(input, s)) {
        s.insert(end(s), 20 > s.length() ? 20 - s.length() : 0, '.');
        std::cout << s << std::endl;
        output << s << std::endl;
    }

    // 21) Дан текстовый файл “in.txt”. Переписать в выходной файл “out.txt” только те строки, в которых слово ‘way’ встречается в первой половине строки.
    //std::ifstream input("in2.txt");
    //std::ofstream output("out2.txt");
    //std::string s;
    //std::string::size_type find_pos;
    //while (std::getline(input, s)) {
    //    find_pos = s.find("way");
    //    if (find_pos != s.npos && find_pos < s.length() / 2) {
    //        //std::cout << s.find("way") << std::endl;
    //        output << s << std::endl;
    //    }
    //}
}
