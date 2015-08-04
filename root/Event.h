
#include <TObject.h>
#include <TClonesArray.h>
#include "Particle.h"

class Event: public TObject {
public:
    Event() :
    particles(std::vector<Particle>()) {
    }

    Event(std::vector<Particle> &particles) :
    particles(particles) {
    }

    ClassDef(Event, 1);

    std::vector<Particle> particles;
};

