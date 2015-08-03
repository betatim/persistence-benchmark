@0xb3676cb33073faa5;

struct MyThing {
    thing @0 :Float32;
}

struct AllThings {
    things @0 :List(MyThing);
}

