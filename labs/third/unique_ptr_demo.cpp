#include <iostream>
#include <memory>
#include <cstdio>

class FileWrapper {
public:
    FileWrapper(const std::string& filename) {
        file = fopen(filename.c_str(), "w");
    }
    ~FileWrapper() {
        if (file) {
            fclose(file);
        }
    }
    void write(const std::string& text) {
        if (file)
            fprintf(file, "%s", text.c_str());
    }
private:
    FILE* file;
};

int main() {
    // Использование std::unique_ptr для управления массивом
    for (int i = 0; i < 10000; ++i) {
        std::unique_ptr<int[]> arr(new int[100]);
    }
    // Пример RAII с уникальным указателем для класса FileWrapper
    {
        std::unique_ptr<FileWrapper> filePtr = std::make_unique<FileWrapper>("example.txt");
        filePtr->write("Hello, RAII!");
    }
    return 0;
}