#include "event.capnp.h"
#include <capnp/message.h>
#include <capnp/serialize-packed.h>
#include <iostream>
#include <cstdio>
#include <iostream>
#include <random>

const size_t size = 5000;
const size_t num_particles = 2000;

void writeEvents(std::string fname) {

  int fd = fileno(fopen(fname.c_str(), "w"));

  std::random_device rd;
  std::mt19937 e2(rd());
  std::uniform_real_distribution<> dist(0, 1);

  double x = 0.;

  for (size_t i=0; i<size; i++) {
      capnp::MallocMessageBuilder message;

      auto event = message.initRoot<Event>();

      auto particles = event.initParticles(num_particles);

      for (size_t i=0; i<num_particles; i++) {
          auto part = particles[i];

          auto pos = part.getPos();
          auto mom = part.getMom();
          pos.setX(x++);
          pos.setY(x++);
          pos.setZ(x++);

          mom.setE(x++);
          mom.setPx(x++);
          mom.setPy(x++);
          mom.setPz(x++);

          auto children = part.initChildrenIdx(5);
          children.set(0, (i + num_particles - 1) % num_particles);
          children.set(1, (i + num_particles - 2) % num_particles);
          children.set(2, (i + num_particles - 3) % num_particles);
          children.set(3, (i + num_particles - 4) % num_particles);
          children.set(4, (i + num_particles - 5) % num_particles);
      }

      writePackedMessageToFd(fd, message);
  }
}

int main(int argc, char *argv[]) {

    writeEvents("out.evt");

    return 0;
}
