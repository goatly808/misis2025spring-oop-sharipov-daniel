#include <iostream>
#include <memory>
using namespace std;

class Data {
public:
    Data(int value) : value(value) { cout << "Data constructed: " << value << "\n"; }
    ~Data() { cout << "Data destructed: " << value << "\n"; }
    int value;
};

int main() {
    shared_ptr<Data> ptr1 = make_shared<Data>(42);
    cout << "Reference count: " << ptr1.use_count() << "\n";
    {
        shared_ptr<Data> ptr2 = ptr1;
        cout << "Reference count after copy: " << ptr1.use_count() << "\n";
    }
    cout << "Reference count after inner block: " << ptr1.use_count() << "\n";
    return 0;
}

