#include <iostream>
#include <string>
#include <clocale>
#include <fcntl.h>
#include <io.h>

using namespace std;

using namespace std;

// Базовий клас Рідина
class Ridyna {
protected:
    wstring nazva;
    double shchilnist;

public:
    Ridyna() : nazva(L"Невідома"), shchilnist(0.0) {
        wcout << L"[Ridyna] Конструктор за замовчуванням\n";
    }

    Ridyna(wstring n, double s) : nazva(n), shchilnist(s) {
        wcout << L"[Ridyna] Конструктор з параметрами\n";
    }

    virtual ~Ridyna() {
        wcout << L"[Ridyna] Деструктор\n";
    }

    virtual void druk() const {
        wcout << L"Назва: " << nazva << L", Щільність: " << shchilnist << L" г/см³\n";
    }

    void zminytyShchilnist(double nova) {
        shchilnist = nova;
    }
};

// Похідний клас Спиртні Напої
class SpyrtniNapoji : public Ridyna {
private:
    double mitsnist;

public:
    SpyrtniNapoji() : Ridyna(), mitsnist(0.0) {
        wcout << L"[SpyrtniNapoji] Конструктор за замовчуванням\n";
    }

    SpyrtniNapoji(wstring n) : Ridyna(n, 0.8), mitsnist(40.0) {
        wcout << L"[SpyrtniNapoji] Конструктор з одним параметром\n";
    }

    SpyrtniNapoji(wstring n, double s, double m) : Ridyna(n, s), mitsnist(m) {
        wcout << L"[SpyrtniNapoji] Конструктор з трьома параметрами\n";
    }

    ~SpyrtniNapoji() {
        wcout << L"[SpyrtniNapoji] Деструктор\n";
    }

    void druk() const override {
        Ridyna::druk();
        wcout << L"Міцність: " << mitsnist << L"%\n";
    }

    void zminytyMitsnist(double nova) {
        mitsnist = nova;
    }
};

// Головна функція
int main() {
    // Налаштування консолі для Windows
    setlocale(LC_ALL, "");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    wcout << L"--- Тест 1: Створення рідини ---\n";
    Ridyna voda(L"Вода", 1.0);
    voda.druk();

    wcout << L"\n--- Тест 2: Створення напою за замовчуванням ---\n";
    SpyrtniNapoji napij1;
    napij1.druk();

    wcout << L"\n--- Тест 3: Напій з одним параметром ---\n";
    SpyrtniNapoji napij2(L"Горілка");
    napij2.druk();

    wcout << L"\n--- Тест 4: Напій з трьома параметрами ---\n";
    SpyrtniNapoji napij3(L"Коньяк", 0.95, 42.0);
    napij3.druk();

    wcout << L"\n--- Тест 5: Зміна значень ---\n";
    napij3.zminytyShchilnist(0.9);
    napij3.zminytyMitsnist(45.0);
    napij3.druk();

    return 0;
}
