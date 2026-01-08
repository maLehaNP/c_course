#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

// 10.
class Software {
public:
    virtual void show() = 0;
    virtual bool isRegistered() = 0;
};

//struct tm datetime;

class FreeSoftware : public Software {
    const string name;
    const string manufacturer;

public:
    FreeSoftware(string name, string manufacturer) : name{ name }, manufacturer{ manufacturer } {}
    void show() override {
        cout << "Name: " << name << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << endl;
    }
    bool isRegistered() override {
        return true;
    }
};

class SharewareSoftware : public Software {
    const string name;
    const string manufacturer;
    const int freeTrialDays;

public:
    time_t installDate;

    SharewareSoftware(string name, string manufacturer, int freeTrialDays, time_t installDate = time(NULL)) :
        name{ name }, manufacturer{ manufacturer },
        installDate{ installDate }, freeTrialDays{ freeTrialDays } {}
    void show() override {
        cout << "Name: " << name << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Install date: " << ctime(&installDate);
        cout << "Free trial (days): " << freeTrialDays << endl;
        cout << endl;
    }
    bool isRegistered() override {
        struct tm datetime = *localtime(&installDate);
        int lastDay = (datetime.tm_mday + freeTrialDays) % 30;
        int lastMonth = (datetime.tm_mon + (datetime.tm_mday + freeTrialDays) / 30) % 12;
        cout << lastDay << ' ' << lastMonth << endl;
        datetime.tm_mday = lastDay;
        if (datetime.tm_mon == 11 && lastMonth != 11)
            datetime.tm_year = ++datetime.tm_year;
        datetime.tm_mon = lastMonth;
        cout << asctime(&datetime) << endl;
        /*time_t timespamp = mktime(&datetime);
        cout << timespamp << endl;
        time_t curTimestamp = time(NULL);
        cout << ctime(&curTimestamp);
        cout << curTimestamp << endl;
        cout << (time(NULL) >= mktime(&datetime)) << endl;*/
        if (time(NULL) >= mktime(&datetime))
            return false;
        else
            return true;
    }
};

class ProprietarySoftware : public Software {
    const string name;
    const string manufacturer;
    const time_t installDate;
    const int licenceDays;

public:
    ProprietarySoftware(string name, string manufacturer, int licenceDays) :
        name{ name }, manufacturer{ manufacturer },
        installDate{ time(NULL) }, licenceDays{ licenceDays } {
    }
    void show() override {
        cout << "Name: " << name << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Install date: " << ctime(&installDate);
        cout << "Licence (days): " << licenceDays << endl;
        cout << endl;
    }
    bool isRegistered() override {
        struct tm datetime = *localtime(&installDate);
        int lastDay = (datetime.tm_mday + licenceDays) % 30;
        int lastMonth = (datetime.tm_mon + (datetime.tm_mday + licenceDays) / 30) % 12;
        cout << lastDay << ' ' << lastMonth << endl;
        datetime.tm_mday = lastDay;
        if (datetime.tm_mon == 11 && lastMonth != 11)
            datetime.tm_year = ++datetime.tm_year;
        datetime.tm_mon = lastMonth;
        cout << asctime(&datetime) << endl;
        if (time(NULL) >= mktime(&datetime))
            return false;
        else
            return true;
    }
};


int main()
{
    /*struct tm datetime;
    datetime.tm_year = 2023;
    datetime.tm_mon = 12 - 1;
    datetime.tm_mday = 17;
    datetime.tm_hour = 12;
    datetime.tm_min = 30;
    datetime.tm_sec = 1;
    time_t timestamp = mktime(&datetime);*/

    vector<Software*> arr = {
        new FreeSoftware("Visual Studio 2022", "Microsoft"),
        new SharewareSoftware("WinRAR", "win.rar", 87),
        new ProprietarySoftware("Photoshop", "Adobe", 25)
    };
    
    for (const auto& soft : arr) {
        soft->show();
    }

    cout << count_if(arr.begin(), arr.end(), [](Software* soft) { return soft->isRegistered(); }) << endl;

    // Cleaning
    for (auto& soft : arr) {
        delete soft;
    }
}
