CXX = g++
CXXFLAGS = -std=c++11 -Istaticlib -Idynamiclib
TARGET = myprogram

$(TARGET): mainprogram/main.cpp staticlib/Number.cpp dynamiclib/Vector.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) mainprogram/main.cpp staticlib/Number.cpp dynamiclib/Vector.cpp

clean:
	rm -f $(TARGET)

.PHONY: clean
