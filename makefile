# Makefile

CXX = g++
#CXX = clang++ 

CXXFLAGS = -std=c++11 -Wall -g

all: prog1.out

prog1: AVLtree.cpp prog1.cpp
	${CXX} ${CXXFLAGS} $^ -o $@