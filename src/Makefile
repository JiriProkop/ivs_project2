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
DEPS = $(wildcard *.h)

all:
	make $(EXEC1)
	make profile

$(EXEC1): $(DEPS)

pack:
	make clean
	mkdir ../../xcerba00_xproko47_xczajk01
	mkdir ../../xcerba00_xproko47_xczajk01/repo
	cd ..; cp -r * ../xcerba00_xproko47_xczajk01/repo/
	cd ..; cp -r .git ../xcerba00_xproko47_xczajk01/repo/
	make doc
	cd ..; mv doc/ ../xcerba00_xproko47_xczajk01
	mkdir ../../xcerba00_xproko47_xczajk01/installer
	cd ../..; zip -rm xcerba00_xproko47_xczajk01 xcerba00_xproko47_xczajk01
	#TODO installer

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
	cd ../doc
	doxygen ../src/Doxyfile

run:
	if ! [ -d "./qt/build/" ]; then \
	mkdir ./qt/Calc/build; fi
	cd qt/Calc/build; cmake ..; make; ./Calc

profile: $(DEPS)
	$(CXX) $(CXXFLAGS) $(EXEC2).cpp -o $(EXEC2)
