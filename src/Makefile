# Depedencies:
#	qt5-default		https://wiki.qt.io/Install_Qt_5_on_Ubuntu
# 	g++			   	sudo apt install g++
# 	zip			   	sudo apt install zip
# 	git				sudo apt install git
#	doxygen			sudo apt install doxygen

EXEC = profiling
CXX = g++
CXXFLAGS = -Wall -g -Wextra -pg #TODO remove -pg
DEPS = $(wildcard *.h)
DEPS := $(DEPS) $(patsubst %.h,%.cpp,$(DEPS))
PACK_NAME = xproko47_xcerba00_xczajk01

.PHONY: doc

all:
	make build_test
	make build_gui
	make profile
	make doc

pack:
	make clean
	mkdir ../../$(PACK_NAME)
	mkdir ../../$(PACK_NAME)/repo
	rm -rf ./googletest/
	cd ..; cp -r * ../$(PACK_NAME)/repo/
	git log --pretty=format:"%h - %an, %ar : %s" --all > history.txt
	mv history.txt ../../$(PACK_NAME)/repo
	make doc
	cd ..; mv doc/ ../$(PACK_NAME)
	mkdir ../../$(PACK_NAME)/installer
	cd ../..; zip -rm $(PACK_NAME) $(PACK_NAME)
	#TODO installer

clean:
	rm -f $(EXEC)
	rm -rf ./build/
	rm -rf ./qt/Calc/build/
	rm -rf ../doc/

gtest:
	if ! [ -d "./googletest/" ]; then \
	git clone https://github.com/google/googletest.git; fi

build_test:
	make gtest
	mkdir -p build
	cd build; cmake ..; make

test:
	make build_test
	cd build; ./calc_tests

doc:
	mkdir -p ../doc
	cd ../doc
	doxygen ../src/Doxyfile

build_gui:
	mkdir -p ./qt/Calc/build
	cd qt/Calc/build; cmake ..; make
	mkdir -p ./qt/CalcUninstall/build
	cd qt/CalcUninstall/build; cmake ..; make

run:
	make build_gui
	cd qt/Calc/build; ./Calc

profile: $(DEPS)
	$(CXX) $(CXXFLAGS) $(EXEC).cpp $(DEPS) -o $(EXEC)
