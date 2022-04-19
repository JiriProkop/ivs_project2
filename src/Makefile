# for test setup, CMake is needed

EXEC1 = calc
EXEC2 = profiling
CXX = g++
CXXFLAGS = -Wall -g -Wextra



all:
	$(CXX) $(CXXFLAGS) $(EXEC1).cpp -o $(EXEC1)
	make profile

pack:
	echo "TODO"

clean:
	rm -f $(EXEC1)
	rm -f $(EXEC2)

test: #zavislosti na calc_funcs.h
	if [ ! -d "./build/" ]; then \
	mkdir build; fi
	cd build; cmake ..; make; ./calc_tests
doc:
	echo "TODO"

run:
	./$(EXEC)

profile: calc_funcs.h
	$(CXX) $(CXXFLAGS) $(EXEC2).cpp -o $(EXEC2)

help:
	echo "TODO"
