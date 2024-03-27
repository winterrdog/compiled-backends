CXX = g++
CXXFLAGS = -Ofast -std=c++17 -Wall -I/usr/local/include/crow/

SRCS = $(wildcard *.cc)
OBJS = $(SRCS:.cc=.o)

# generate target name for each source file. target name ends with .e
TARGET = $(SRCS:.cc=.e)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cc
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(TARGET)