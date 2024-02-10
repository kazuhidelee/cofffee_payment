CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++17 -Wno-sign-compare -Wno-comment

main.exe: main.cpp employee.h
	$(CXX) $(CXXFLAGS) main.cpp -o main.exe

clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
