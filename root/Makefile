
all: run


run: thing
	bash -c 'time ./thing'

thing: thing.c++ MyThing_dict.cxx
	g++ -O3 `root-config --cflags --libs` -o thing thing.c++ MyThing_dict.cxx

MyThing_dict.cxx: MyThing.h
	rootcint -f MyThing_dict.cxx -c -p MyThing.h

