#include <iostream>
#include <TFile.h>
#include <TObject.h>
#include <TObjArray.h>

class MyThing: public TObject {
public:
    MyThing() {
        this->thing = 0.;
    }
    MyThing(float x) {
        this->thing = x;
    }

    ClassDef(MyThing, 1);

private:
    float thing;
};

int root() {
    TObjArray arr(30000);
    for (int i=0; i<30000; i++) {
        MyThing *thing = new MyThing(42.);
        arr.Add((TObject*) thing);
    }

    std::cout << "Saving..." << std::endl;
    TFile f("out.root", "recreate");
    arr.Write();
    f.Close();
}
