#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sound {
public:
    int pitch;
    int duration;

    Sound(int pitch, int duration) : pitch{pitch}, duration{duration} {}
};

int main()
{
    vector<Sound> melody1 = {
        Sound{2, 3},
        Sound{10, 7},
        Sound{8, 5},
        Sound{6, 5},
        Sound{4, 9}
    };

    vector<Sound> melody2 = {
        Sound{6, 5},
        Sound{8, 5}
    };

    
    // 8. Проверить, содержатся ли все звуки одной мелодии в другой мелодии (должна совпадать и высота, и длительность).
    cout << ranges::contains_subrange(melody1, melody2, [](Sound a, Sound b) { return (a.pitch == b.pitch) && (a.duration == b.duration); }) << endl;

    // 20. Найти два идущих подряд звука, совпадающих по длительности.
    auto af = adjacent_find(melody1.begin(), melody1.end(), [](Sound a, Sound b) { return a.duration == b.duration; });
    cout << "Index: " << distance(melody1.begin(), af) << endl;

    // 6. Изменить мелодию так, чтобы сначала шли все звуки, которые ниже заданной ноты, потом все остальные.
    // Можно воспользоваться remove_if (в общем я это и реализую)
    int pitch = 7;
    //sort(melody1.begin(), melody1.end(), [](Sound a, Sound b) { return a.pitch < 7; });
    int i = 0;
    int len = melody1.size();
    int count = 0;
    while (i < len - count && i != len) {
        if (melody1[i].pitch >= pitch) {
            count++;
            melody1.push_back(melody1[i]);
            melody1.erase(melody1.begin() + i);
        }
        else i++;
    }
    for (Sound s : melody1) {
        cout << "{" << s.pitch << ", " << s.duration << "} ";
    }
}
