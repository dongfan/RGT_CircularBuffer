#include <iostream>
#include <numeric>
#include <algorithm>
#include "CircularBuffer.h"

int main() {
    // 테스트 시나리오
    CircularBuffer<double> tempBuffer(5);

    // 온도 센서 데이터 추가
    tempBuffer.push_back(23.5);
    tempBuffer.push_back(24.1);
    tempBuffer.push_back(23.8);
    tempBuffer.push_back(25.2);
    tempBuffer.push_back(24.7);
    tempBuffer.push_back(26.1);

    // STL 사용
    double maxTemp = *std::max_element(tempBuffer.begin(), tempBuffer.end());
    double avgTemp = std::accumulate(tempBuffer.begin(), tempBuffer.end(), 0.0) / tempBuffer.size();

    // 인덱스 순서대로 출력 (버퍼 내부 배열 기준)
    std::cout << "버퍼 내용(인덱스 순서): [";
    for (const auto& value : tempBuffer) {
        std::cout << value << " ";
        std::cout << ",";
    }
    std::cout << "]" << std::endl;

    // begin()부터 end()까지 순회하며 출력 (실제 데이터 순서)
    std::cout << "begin()부터 순회 시: ";
    for (const auto& value : tempBuffer) {
        std::cout << value << ",";
    }
    std::cout << " (가장 오래된 것부터)" << std::endl;
<<<<<<< HEAD
    std::cout << "]\n";
=======
>>>>>>> 91e98c466ac82a44bafd1ca5b838629b0fdd241c

    // 버퍼 정보 출력
    std::cout << "tempBuffer.size() = " << tempBuffer.size() << std::endl;
    std::cout << "tempBuffer.capacity() = " << tempBuffer.capacity() << std::endl;
    std::cout << "tempBuffer.empty() = " << std::boolalpha << tempBuffer.empty() << std::endl;
    std::cout << "maxTemp = " << maxTemp << std::endl;
    std::cout << "avgTemp = " << avgTemp << std::endl;
    std::cout << "tempBuffer.front() = " << tempBuffer.front() << std::endl;
    std::cout << "tempBuffer.back() = " << tempBuffer.back() << std::endl;

    return 0;
}