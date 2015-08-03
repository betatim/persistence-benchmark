
#include <TObject.h>
#include <TObjArray.h>

class MyThing: public TObject {
public:
    MyThing() {
        this->thing = 0.;
    }
    MyThing(double x) {
        this->thing = x;
    }

    ClassDef(MyThing, 1);

    void SetThing(double x) {
        this->thing = x;
    }

private:
    double thing;
};

