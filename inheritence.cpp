#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() const {
        cout << "Base class display" << endl;
    }
};

class Derived : public Base {
public:
    void display() const override { // Ghi đè phương thức từ lớp cha
        cout << "Derived class display" << endl;
    }
};

int main() {
    Base* obj = new Derived();
    obj->display(); // Gọi phương thức của lớp Derived
    delete obj;
    return 0;
}
