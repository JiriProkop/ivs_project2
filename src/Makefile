# Depedencies:
#	qt5-default		https://wiki.qt.io/Install_Qt_5_on_Ubuntu
# 	g++			   	sudo apt install g++
# 	zip			   	sudo apt install zip
# 	git				sudo apt install git
#	doxygen			sudo apt install doxygen

EXEC1 = calc
EXEC2 = profiling
CXX = g++
CXXFLAGS = -Wall -g -Wextra


all:
	$(CXX) $(CXXFLAGS) $(EXEC1).cpp -o $(EXEC1)
	make profile

pack:
	#TODO zip files to be submitted

clean:
	rm -f $(EXEC1)
	rm -f $(EXEC2)
	rm -rf ./build/
	rm -rf ./qt/Calc/build/
	rm -rf ../doc/

gtest:
	if ! [ -d "./googletest/" ]; then \
	git clone https://github.com/google/googletest.git; fi

test:
	make gtest
	if ! [ -d "./build/" ]; then \
	mkdir build; fi
	cd build; cmake ..; make; ./calc_tests
doc:
	if ! [ -d "../doc/" ]; then \
	mkdir ../doc; fi
	#TODO generate documentation

run:
	if ! [ -d "./qt/build/" ]; then \
	mkdir ./qt/Calc/build; fi
	cd qt/Calc/build; cmake ..; make; ./Calc

profile: calc_funcs.h
	$(CXX) $(CXXFLAGS) $(EXEC2).cpp -g -pg -o $(EXEC2)
