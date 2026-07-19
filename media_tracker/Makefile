CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = media_tracker
SRC = main.cpp
HEADERS = $(wildcard *.h)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

tar:
	tar -czf ../$(TARGET).tar.gz *