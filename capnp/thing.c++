#include "thing.capnp.h"
#include <capnp/message.h>
#include <capnp/serialize-packed.h>
#include <iostream>
#include <cstdio>
#include <iostream>
#include <random>

void writeThings(int fd) {
  std::random_device rd;
  std::mt19937 e2(rd());
  std::uniform_real_distribution<> dist(0, 1);

  ::capnp::MallocMessageBuilder message;

  AllThings::Builder things = message.initRoot<AllThings>();

  const size_t size = 1000000;

  ::capnp::List<MyThing>::Builder thing_list = things.initThings(size);

  for (size_t i=0; i<size; i++) {
      MyThing::Builder thing = thing_list[i];
      thing.setThing(dist(e2));
  }

  writeMessageToFd(fd, message);
}


int main(int argc, char *argv[]) {

    FILE* f = fopen("out.bin", "w");
    writeThings(fileno(f));

    return 0;
}
