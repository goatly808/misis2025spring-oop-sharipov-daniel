#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>
#include <chrono>
#include <iostream>

using namespace cv;
using namespace std::chrono;

// Функция последовательного размытия (окно 3x3)
void sequentialBlur(const Mat& input, Mat& output) {
    int rows = input.rows, cols = input.cols;
    output = input.clone();
    for(int y = 1; y < rows - 1; ++y) {
        for(int x = 1; x < cols - 1; ++x) {
            Vec3i sum(0, 0, 0);
            for(int dy = -1; dy <= 1; ++dy) {
                for(int dx = -1; dx <= 1; ++dx) {
                    sum += input.at<Vec3b>(y + dy, x + dx);
                }
            }
            output.at<Vec3b>(y, x) = Vec3b(sum[0] / 9, sum[1] / 9, sum[2] / 9);
        }
    }
}

// Обработка диапазона строк для параллельного размытия
void blurRange(const Mat& input, Mat& output, int yStart, int yEnd) {
    int cols = input.cols;
    for(int y = std::max(1, yStart); y < std::min(input.rows - 1, yEnd); ++y) {
        for(int x = 1; x < cols - 1; ++x) {
            Vec3i sum(0, 0, 0);
            for(int dy = -1; dy <= 1; ++dy)
                for(int dx = -1; dx <= 1; ++dx)
                    sum += input.at<Vec3b>(y + dy, x + dx);
            output.at<Vec3b>(y, x) = Vec3b(sum[0] / 9, sum[1] / 9, sum[2] / 9);
        }
    }
}

// Функция параллельного размытия
void parallelBlurThreads(const Mat& input, Mat& output) {
    int rows = input.rows;
    output = input.clone();
    unsigned int numThreads = std::thread::hardware_concurrency();
    int rowsPerThread = rows / numThreads;
    std::vector<std::thread> threads;
    for(unsigned int i = 0; i < numThreads; ++i) {
        int yStart = i * rowsPerThread;
        int yEnd = (i + 1 == numThreads) ? rows : yStart + rowsPerThread;
        threads.emplace_back(blurRange, std::cref(input), std::ref(output), yStart, yEnd);
    }
    for(auto& t : threads) t.join();
}

int main(int argc, char** argv) {
    if(argc < 4) {
        std::cout << "Usage: " << argv[0] << " <input> <output_seq> <output_par>\n";
        return 1;
    }
    Mat image = imread(argv[1]);
    if(image.empty()) {
        std::cerr << "Cannot load image " << argv[1] << std::endl;
        return -1;
    }

    Mat outputSeq, outputPar;

    // Последовательное размытие
    auto start = high_resolution_clock::now();
    sequentialBlur(image, outputSeq);
    auto end = high_resolution_clock::now();
    auto durationSeq = duration_cast<milliseconds>(end - start).count();
    std::cout << "Sequential blur time: " << durationSeq << " ms\n";
    imwrite(argv[2], outputSeq);

    // Параллельное размытие
    start = high_resolution_clock::now();
    parallelBlurThreads(image, outputPar);
    end = high_resolution_clock::now();
    auto durationPar = duration_cast<milliseconds>(end - start).count();
    std::cout << "Parallel blur time: " << durationPar << " ms\n";
    imwrite(argv[3], outputPar);

    return 0;
}
