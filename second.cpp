#include <iostream>
#include <vector>
using namespace std;

// Клас колесо
class Koleso {
private:
    double diameter;

public:
    Koleso(double d = 26.0) : diameter(d) {}

    void print() const {
        cout << "Колесо діаметром: " << diameter << " дюймів\n";
    }

    double getDiameter() const { return diameter; }
};

// Базовий клас Транспорт
class Transport {
protected:
    vector<Koleso> kolesa;
    string type;

public:
    Transport(int k, double diameter, string t) : type(t) {
        for (int i = 0; i < k; ++i) {
            kolesa.push_back(Koleso(diameter));
        }
    }

    virtual void print() const {
        cout << "Тип транспорту: " << type << "\n";
        cout << "Кількість коліс: " << kolesa.size() << "\n";
        for (const auto& k : kolesa) {
            k.print();
        }
    }

    virtual ~Transport() {}
};

// Клас велосипед
class Velykyped : public Transport {
public:
    Velykyped() : Transport(2, 26.0, "Велосипед") {}
};

// Клас автомобіль
class Avtomobil : public Transport {
public:
    Avtomobil() : Transport(4, 16.0, "Автомобіль") {}
};

// Головна функція
int main() {
    system("chcp 65001");

    cout << "--- Велосипед ---\n";
    Velykyped v;
    v.print();

    cout << "\n--- Автомобіль ---\n";
    Avtomobil a;
    a.print();

    return 0;
}
