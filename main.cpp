#include <iostream>
#include <numeric>
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
    std::cout << "Buffer values by index: ";
    for (size_t i = 0; i < tempBuffer.capacity(); ++i) {
        std::cout << tempBuffer.back() << " "; // tempBuffer[i]가 없으므로 back() 예시
    }
    std::cout << std::endl;

    // begin()부터 end()까지 순회하며 출력 (실제 데이터 순서)
    std::cout << "Buffer values by iterator: ";
    for (auto it = tempBuffer.begin(); it != tempBuffer.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

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