# Depedencies:
#	qt5-default		https://wiki.qt.io/Install_Qt_5_on_Ubuntu
# 	g++			   	sudo apt install g++
# 	zip			   	sudo apt install zip
# 	git				sudo apt install git
#	doxygen			sudo apt install doxygen

EXEC = profiling
CXX = g++
CXXFLAGS = -Wall -g -Wextra
DEPS = $(wildcard *.h)
DEPS := $(DEPS) $(patsubst %.h,%.cpp,$(DEPS))

.PHONY: doc

all:
	make build_test
	make build_gui
	make profile
	make doc

pack:
	make clean
	mkdir ../../xcerba00_xproko47_xczajk01
	mkdir ../../xcerba00_xproko47_xczajk01/repo
	cd ..; cp -r * ../xcerba00_xproko47_xczajk01/repo/
	git log --pretty=format:"%h - %an, %ar : %s" --all > history.txt
	mv history.txt ../../xcerba00_xproko47_xczajk01/repo
	make doc
	cd ..; mv doc/ ../xcerba00_xproko47_xczajk01
	mkdir ../../xcerba00_xproko47_xczajk01/installer
	cd ../..; zip -rm xproko47_xcerba00_xczajk01 xcerba00_xproko47_xczajk01
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

run:
	make build_gui
	cd qt/Calc/build; ./Calc

profile: $(DEPS)
	$(CXX) $(CXXFLAGS) $(EXEC).cpp $(DEPS) -o $(EXEC)
