CXX = g++
CXXFLAGS = -std=c++11 -pthread -Wall
TARGET = matrix_lab
SOURCES = matrix_functions.cpp main.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run

