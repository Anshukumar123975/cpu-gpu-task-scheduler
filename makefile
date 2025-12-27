CXX = g++
CXXFLAGS = -std=c++17 -pthread -Iinclude

SRC = src/*.cpp
OUT = build/scheduler

all:
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf build
