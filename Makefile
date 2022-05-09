SOURCES := $(wildcard */*.cpp)

TARGET := project

CXXFLAGS := -std=c++11 -ggdb -O0 

OBJS := $(SOURCES:%.cpp=%.o)

$(TARGET) : $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY : clean
clean : 
	-rm -rf $(TARGET) $(OBJS)

.PHONY : val
val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(TARGET)
