
run: thing
	bash -c 'time ./thing'

thing: thing.c++ thing.capnp.c++
	g++ -O3 -std=c++11 -lcapnp -lkj -o thing thing.c++ thing.capnp.c++

thing.capnp.c++: thing.capnp
	capnpc -oc++ $^

