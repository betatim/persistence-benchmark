all: run_capnp run_root

run_root: root.C
	bash -c 'time root -l -b -q root.C+'

run_capnp: thing
	bash -c 'time ./thing'

thing: thing.c++ thing.capnp.c++
	g++ -std=c++11 -lcapnp -lkj -o thing thing.c++ thing.capnp.c++

thing.capnp.c++: thing.capnp
	capnpc -oc++ $^

