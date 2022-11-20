#!/bin/sh

rm -f *.o unit_test_main_d

clang++ -g -std=c++0x -I../math_library/include -I../unit_test/include/ -c ../math_library/src/*.cc ../unit_test/src/*.cc
clang++ -g -std=c++0x -framework OpenGL -framework Cocoa -framework Corevideo -framework IOKit *.o -o unit_test_main_d

#clang++ -m32 -std=c++0x -I../include -I../deps/ESAT/include/ -c ../src/main.cc 
#clang++ -m32 -std=c++0x -L../deps/ESAT/bin -l ESAT -framework OpenGL -framework Cocoa -framework Corevideo -framework IOKit main.o -o main

