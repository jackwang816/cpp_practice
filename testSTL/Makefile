#!/usr/bin/make -f

CC = g++
CFLAGS = --std=c++11 -Wall
LFLAGS = --std=c++11

SRC:= vectorTest.cpp stlTest.cpp
OBJS:=$(SRC:%.cpp=%.o)

default:$(OBJS)
	@echo 'make STL test'
	$(CC) -o stlTest $(OBJS) $(LFLAGS)

%.o: %.cpp %.h
	$(CC) -c $< -o $@ $(CFLAGS)
