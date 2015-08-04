
all: run

run: event
	bash -c 'time ./event'

event: event.c++ Event_dict.cxx Particle_dict.cxx
	g++ -std=c++11 -O3 `root-config --cflags --libs` -o event event.c++ Event_dict.cxx Particle_dict.cxx

Particle_dict.cxx: Particle.h
	rootcint -f Particle_dict.cxx -c -p Particle.h

Event_dict.cxx: Event.h
	rootcint -f Event_dict.cxx -c -p Event.h

