
run: event
	bash -c 'time ./event'

event: event.c++ event.capnp.c++
	g++ -O3 -std=c++11 -lcapnp -lkj -o event event.c++ event.capnp.c++

event.capnp.c++: event.capnp
	capnpc -oc++ $^

