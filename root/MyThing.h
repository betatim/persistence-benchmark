
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

    void SetThing(float x) {
        this->thing = x;
    }

private:
    float thing;
};

