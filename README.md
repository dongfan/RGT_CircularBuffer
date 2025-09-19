# RGT_CircularBuffer

## 프로젝트 소개
템플릿과 STL을 활용하여 고정 크기의 원형 버퍼(Circular Buffer)를 구현한 예제 프로젝트입니다.  
센서 데이터와 같이 실시간 스트림 데이터를 효율적으로 저장하고 처리할 수 있도록 설계되었습니다.

## 주요 기능
- 템플릿 기반 CircularBuffer 컨테이너
- 버퍼가 가득 차면 가장 오래된 데이터를 자동으로 덮어쓰기
- STL 호환 forward iterator 제공 (범위 기반 for문, 알고리즘 사용 가능)
- `push_back`, `pop`, `front`, `back`, `size`, `capacity`, `empty`, `full` 등 STL 유사 인터페이스
- `std::max_element`, `std::accumulate` 등 STL 알고리즘과 연동

## 사용 예시
```cpp
CircularBuffer<double> tempBuffer(5);
tempBuffer.push_back(23.5);
tempBuffer.push_back(24.1);
// ...

## 빌드 및 실행
### Windows (MinGW g++)
```sh
g++ -std=c++17 -Wall -fexec-charset=CP949 -o CircularBuffer.exe main.cpp
CircularBuffer.exe
```

## 파일 구성
- `CircularBuffer.h` : CircularBuffer 템플릿 클래스 선언 및 구현
- `main.cpp` : 사용 예제 및 테스트 코드
- `Makefile` : 빌드 자동화 파일
- `README.md` : 프로젝트 설명
