CXX = clang++
override CXXFLAGS +=  -I. -I./include -std=c++17 -pthread -o main -g -Wno-everything

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) lib/libfmt.a -o main
	rm main.o

clean:
	rm -f $(OBJS) main