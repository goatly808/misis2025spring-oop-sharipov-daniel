#include <iostream>
#include <memory>
using namespace std;

class Observer {
public:
    void notify() {
        cout << "Observer notified.\n";
    }
};

int main() {
    shared_ptr<Observer> sp = make_shared<Observer>();
    weak_ptr<Observer> wp = sp;
    if (auto locked = wp.lock()) {
        locked->notify();
    }
    sp.reset();
    if (wp.expired()) {
        cout << "Observer is no longer alive.\n";
    }
    return 0;
}