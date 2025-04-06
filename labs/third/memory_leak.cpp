#include <iostream>

int main() {
    for (int i = 0; i < 10000; ++i) {
        int* leak = new int[100];
        // Утечка памяти: память не освобождается
    }
    return 0;
}