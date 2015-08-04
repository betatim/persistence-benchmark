
#include <TObject.h>
#include <TClonesArray.h>
#include "Particle.h"

class Event: public TObject {
public:
    Event() :
    particles(TClonesArray("Particle", 0)) {
    }

    Event(TClonesArray &particles) :
    particles(particles) {
    }

    ClassDef(Event, 1);

    TClonesArray particles;
};

