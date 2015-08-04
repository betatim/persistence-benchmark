@0xb3676cb33073faa5;

struct Vec3 {
    x @0 :Float64;
    y @1 :Float64;
    z @2 :Float64;
}

struct FourMomentum {
    e @0 :Float64;
    px @1 :Float64;
    py @2 :Float64;
    pz @3 :Float64;
}

struct Particle {
    pos @0 :Vec3;
    mom @1 :FourMomentum;
    childrenIdx @2 :List(Int64);
}

struct Event {
    particles @0 :List(Particle);
}

struct EventStore {
    events @0 :List(Event);
}

