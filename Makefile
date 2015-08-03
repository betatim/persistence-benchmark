all: run_capnp run_root

run_root:
	cd root; make

run_capnp:
	cd capnp; make

