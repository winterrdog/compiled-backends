CXX = g++
CXXFLAGS = -Ofast -std=c++17 -Wall -I/usr/local/include/crow/

SRCS = init.cc
OBJS = $(SRCS:.cc=.o)
TARGET = init.e

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cc
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(TARGET)