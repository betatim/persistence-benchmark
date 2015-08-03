@0xb3676cb33073faa5;

struct MyThing {
    thing @0 :Float64;
}

struct AllThings {
    things @0 :List(MyThing);
}

