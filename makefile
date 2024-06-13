CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = sfml_app

all: $(TARGET)

$(TARGET): main.o
	$(CXX) -o $(TARGET) main.o $(LDFLAGS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)

