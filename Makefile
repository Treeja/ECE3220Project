SOURCES := $(wildcard */*.cpp)
			

TARGET := project

CXXFLAGS := -std=c++11 -ggdb -O0 

OBJS := $(SOURCES:%.cpp=%.o)

$(TARGET) : $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY : clean
clean : 
	-rm -rf $(TARGET) $(OBJS)