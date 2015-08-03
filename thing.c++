#include "thing.capnp.h"
#include <capnp/message.h>
#include <capnp/serialize-packed.h>
#include <iostream>
#include <cstdio>
#include <iostream>

void writeThings(int fd) {
  ::capnp::MallocMessageBuilder message;

  AllThings::Builder things = message.initRoot<AllThings>();

  const size_t size = 30000;

  ::capnp::List<MyThing>::Builder thing_list = things.initThings(size);

  for (size_t i=0; i<size; i++) {
      MyThing::Builder thing = thing_list[i];
      thing.setThing(42.);
  }

  writePackedMessageToFd(fd, message);
}


int main(int argc, char *argv[]) {

    FILE* f = fopen("out.bin", "w");
    writeThings(fileno(f));

    return 0;
}
