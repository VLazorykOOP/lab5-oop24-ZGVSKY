#include <iostream>
#include <string>
#include <clocale>
#include <fcntl.h>
#include <io.h>

using namespace std;

#define DEFAULT_NAME  L"Невідомо"
#define DEFAULT_AGE   0
#define DEFAULT_SUBJECT L"Без предмета"

// ---------- Базовий клас Людина ----------
class Liudyna {
protected:
    wstring name;
    int age;

public:
    // Конструктор за замовчуванням
    Liudyna(const wstring& n = DEFAULT_NAME, int a = DEFAULT_AGE)
        : name(n), age(a) {}

    // Конструктор копіювання
    Liudyna(const Liudyna& other)
        : name(other.name), age(other.age) {}

    // Оператор присвоєння
    Liudyna& operator=(const Liudyna& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    // Віртуальний деструктор
    virtual ~Liudyna() {}

    // Дружні функції введення/виведення
    friend wostream& operator<<(wostream& os, const Liudyna& l);
    friend wistream& operator>>(wistream& is, Liudyna& l);
};

// Вивід
wostream& operator<<(wostream& os, const Liudyna& l) {
    os << L"Ім'я: " << l.name << L", Вік: " << l.age;
    return os;
}

// Введення
wistream& operator>>(wistream& is, Liudyna& l) {
    wcout << L"Введіть ім’я: ";
    getline(is, l.name);
    wcout << L"Введіть вік: ";
    is >> l.age;
    is.ignore(); // для очистки буфера
    return is;
}

// ---------- Похідний клас Викладач ----------
class Vykaldach : public Liudyna {
private:
    wstring subject;

public:

    // Конструктор за замовчуванням
    Vykaldach(const wstring& n = DEFAULT_NAME, int a = DEFAULT_AGE, const wstring& s = DEFAULT_SUBJECT)
        : Liudyna(n, a), subject(s) {}

    // Конструктор копіювання
    Vykaldach(const Vykaldach& other)
        : Liudyna(other), subject(other.subject) {}

    // Оператор присвоєння
    Vykaldach& operator=(const Vykaldach& other) {
        if (this != &other) {
            Liudyna::operator=(other); // копіюємо базові поля
            subject = other.subject;
        }
        return *this;
    }

    // Дружні функції введення/виведення
    friend wostream& operator<<(wostream& os, const Vykaldach& v);
    friend wistream& operator>>(wistream& is, Vykaldach& v);
};

// Вивід
wostream& operator<<(wostream& os, const Vykaldach& v) {
    os << static_cast<const Liudyna&>(v) << L", Предмет: " << v.subject;
    return os;
}

// Введення
wistream& operator>>(wistream& is, Vykaldach& v) {
    is >> static_cast<Liudyna&>(v); // викликаємо введення базового класу
    wcout << L"Введіть предмет: ";
    getline(is, v.subject);
    return is;
}

// ---------- Тестування ----------
int main() {
    // Налаштування консолі для Windows
    setlocale(LC_ALL, "");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    Vykaldach v1;
    wcout << L"--- Введення викладача ---\n";
    wcin >> v1;

    wcout << L"\n--- Дані викладача ---\n";
    wcout << v1 << endl;

    wcout << L"\n--- Копіювання та присвоєння ---\n";
    Vykaldach v2 = v1; // копіювання
    Vykaldach v3;
    v3 = v1; // присвоєння
    wcout << L"Копія: " << v2 << endl;
    wcout << L"Присвоєння: " << v3 << endl;

    return 0;
}
